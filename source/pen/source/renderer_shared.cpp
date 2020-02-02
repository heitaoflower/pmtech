#include "renderer_shared.h"
#include "data_struct.h"
#include "pen.h"
#include "types.h"

extern pen::window_creation_params pen_window;

using namespace pen;

#define CBUFFER_ALIGNMENT 256
#define VBUFFER_ALIGNMENT 1

namespace
{
    namespace e_shared_flags
    {
        enum shared_flags_t
        {
            backbuffer_resize = 1
        };
    }
    
    struct managed_rt
    {
        pen::texture_creation_params* tcp;
        u32 rt;
    };
    
    struct renderer_shared
    {
        managed_rt*                  managed_rts = nullptr;
        u32                          flags = 0;
        a_u64                        frame_index = { 0 };
        a_u64                        resize_index = { 0 };
        pen::stretchy_dynamic_buffer dynamic_cbuffer;
        pen::stretchy_dynamic_buffer dynamic_vbuffer;
    };
    renderer_shared s_shared_ctx;
    
    void _commit_stretchy_dynamic_buffer(pen::stretchy_dynamic_buffer* buf)
    {
        // update buffer and reset
        direct::renderer_update_buffer(buf->_gpu_buffer, buf->_cpu_data, buf->_write_offset, 0);
        buf->_write_offset = 0;
    }
    
    void _create_stretchy_dynamic_buffer(pen::stretchy_dynamic_buffer* buf, u32 slot, size_t reserve, size_t align)
    {
        // cpu
        buf->_cpu_data = (u8*)pen::memory_alloc(reserve);
        buf->_gpu_capacity = reserve;
        
        // gpu
        pen::buffer_creation_params bcp;
        bcp.usage_flags = PEN_USAGE_DYNAMIC;
        bcp.bind_flags = PEN_BIND_CONSTANT_BUFFER;
        bcp.cpu_access_flags = PEN_CPU_ACCESS_WRITE;
        bcp.buffer_size = reserve;
        bcp.data = nullptr;
                
        direct::renderer_create_buffer(bcp, slot);
        
        buf->_gpu_buffer = slot;
        buf->_cpu_capacity = reserve;
        buf->_write_offset = 0;
        
        buf->_alignment = align;
    }
}

namespace pen
{
    void _renderer_shared_init()
    {
        // create a stretchy buffer for dynamic draw data on vertices
        _create_stretchy_dynamic_buffer(&s_shared_ctx.dynamic_cbuffer, 6, 32, CBUFFER_ALIGNMENT);
        _create_stretchy_dynamic_buffer(&s_shared_ctx.dynamic_vbuffer, 7, 32, VBUFFER_ALIGNMENT);
    }
    
    void _renderer_new_frame()
    {
        _renderer_resize_managed_targets();
    }
    
    void _renderer_end_frame()
    {
        s_shared_ctx.frame_index++;
    }
    
    void _renderer_commit_stretchy_dynamic_buffers()
    {
        // update stretchy buffers
        _commit_stretchy_dynamic_buffer(&s_shared_ctx.dynamic_cbuffer);
        _commit_stretchy_dynamic_buffer(&s_shared_ctx.dynamic_vbuffer);
        
    }
    
    texture_creation_params _renderer_tcp_resolve_ratio(const texture_creation_params& tcp)
    {
        texture_creation_params _tcp = tcp;

        if (_tcp.width == -1)
        {
            _tcp.width = pen_window.width / _tcp.height;
            _tcp.height = pen_window.height / _tcp.height;
        }

        return _tcp;
    }
    
    void _renderer_resize_backbuffer(u32 width, u32 height)
    {
        // no need to do anything if the size is the same
        if (pen_window.width == width && pen_window.height == height)
            return;

        // want to remove this global extern in favour of function calls.
        pen_window.width = width;
        pen_window.height = height;
        
        // trigger render target resize
        s_shared_ctx.flags |= e_shared_flags::backbuffer_resize;
        s_shared_ctx.resize_index++;
    }

    void _renderer_track_managed_render_target(const texture_creation_params& tcp, u32 texture_handle)
    {
        // PEN_INVALID_HANDLE denotes a backbuffer ratio target
        if(tcp.width == PEN_INVALID_HANDLE)
        {
            managed_rt rt = {
                new texture_creation_params(tcp),
                texture_handle
            };
            sb_push(s_shared_ctx.managed_rts, rt);
        }
    }
        
    void _renderer_resize_managed_targets()
    {
        if (!(s_shared_ctx.flags & e_shared_flags::backbuffer_resize))
            return;

        u32 couunt = sb_count(s_shared_ctx.managed_rts);
        for (u32 i = 0; i < couunt; ++i)
        {
            auto& manrt = s_shared_ctx.managed_rts[i];
            direct::renderer_release_render_target(manrt.rt);
            direct::renderer_create_render_target(*manrt.tcp, manrt.rt, false);
        }
        
        s_shared_ctx.flags &= ~e_shared_flags::backbuffer_resize;
    }
    
    u64 _renderer_frame_index()
    {
        return s_shared_ctx.frame_index.load();
    }
    
    u64 _renderer_resize_index()
    {
        return s_shared_ctx.resize_index.load();
    }
    
    size_t _renderer_buffer_multi_update(stretchy_dynamic_buffer* buf, const void* data, size_t size)
    {
        // grow double the capactity
        size_t new_size = PEN_ALIGN(buf->_write_offset + size, buf->_alignment)*2;
        if(new_size > buf->_cpu_capacity)
        {
            // resize cpu
            buf->_cpu_data = (u8*)realloc(buf->_cpu_data, new_size);
            buf->_cpu_capacity = new_size;
            memcpy(buf->_cpu_data+buf->_write_offset, data, size);
            
            // resize gpu
            pen::buffer_creation_params bcp;
            bcp.usage_flags = PEN_USAGE_DYNAMIC;
            bcp.bind_flags = PEN_BIND_CONSTANT_BUFFER;
            bcp.cpu_access_flags = PEN_CPU_ACCESS_WRITE;
            bcp.buffer_size = buf->_cpu_capacity;
            bcp.data = buf->_cpu_data;
            
            direct::renderer_release_buffer(buf->_gpu_buffer);
            direct::renderer_create_buffer(bcp, buf->_gpu_buffer);
            buf->_gpu_capacity = buf->_cpu_capacity;
        }
        else
        {
            memcpy(buf->_cpu_data+buf->_write_offset, data, size);
        }
        buf->_read_offset = buf->_write_offset;
        buf->_write_offset = PEN_ALIGN((buf->_write_offset + size), buf->_alignment);
        return buf->_read_offset;
    }
    
    stretchy_dynamic_buffer* _renderer_get_stretchy_dynamic_buffer(u32 bind_flags)
    {
        // do one for vertices, which will have different alignment
        if(bind_flags & PEN_BIND_CONSTANT_BUFFER)
        {
            return &s_shared_ctx.dynamic_cbuffer;
        }
        else
        {
            return &s_shared_ctx.dynamic_vbuffer;
        }
    }
}
