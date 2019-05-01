// renderer_definitions.h
// Copyright 2014 - 2019 Alex Dixon.
// License: https://github.com/polymonster/pmtech/blob/master/license.md

#ifndef _renderer_definitions_h
#define _renderer_definitions_h

#include <d3d11_1.h>

enum clear_flags : s32
{
    PEN_CLEAR_COLOUR_BUFFER = 0x01,
    PEN_CLEAR_DEPTH_BUFFER = 0x02,
    PEN_CLEAR_STENCIL_BUFFER = 0x02
};

enum shader_type
{
    PEN_SHADER_TYPE_VS = 0x03,
    PEN_SHADER_TYPE_PS = 0x04,
    PEN_SHADER_TYPE_GS = 0x05,
    PEN_SHADER_TYPE_SO = 0x06,
    PEN_SHADER_TYPE_CS = 0x07
};

enum raster_state : s32
{
    PEN_FILL_SOLID = D3D11_FILL_SOLID,
    PEN_FILL_WIREFRAME = D3D11_FILL_WIREFRAME
};

enum cull_mode : s32
{
    PEN_CULL_NONE = D3D11_CULL_NONE,
    PEN_CULL_FRONT = D3D11_CULL_FRONT,
    PEN_CULL_BACK = D3D11_CULL_BACK
};

enum default_targets : s32
{
    PEN_NULL_COLOUR_BUFFER = 0,
    PEN_NULL_DEPTH_BUFFER = 0,
    PEN_BACK_BUFFER_COLOUR = 1,
    PEN_BACK_BUFFER_DEPTH = 2
};

enum usage : s32
{
    PEN_USAGE_DEFAULT = D3D11_USAGE_DEFAULT,
    PEN_USAGE_IMMUTABLE = D3D11_USAGE_IMMUTABLE,
    PEN_USAGE_DYNAMIC = D3D11_USAGE_DYNAMIC,
    PEN_USAGE_STAGING = D3D11_USAGE_STAGING
};

enum input_classification
{
    PEN_INPUT_PER_VERTEX = 0,
    PEN_INPUT_PER_INSTANCE = 1
};

enum bind_flags : s32
{
    PEN_BIND_VERTEX_BUFFER = D3D11_BIND_VERTEX_BUFFER,
    PEN_BIND_INDEX_BUFFER = D3D11_BIND_INDEX_BUFFER,
    PEN_BIND_CONSTANT_BUFFER = D3D11_BIND_CONSTANT_BUFFER,
    PEN_BIND_SHADER_RESOURCE = D3D11_BIND_SHADER_RESOURCE,
    PEN_BIND_STREAM_OUTPUT = D3D11_BIND_STREAM_OUTPUT,
    PEN_BIND_RENDER_TARGET = D3D11_BIND_RENDER_TARGET,
    PEN_BIND_DEPTH_STENCIL = D3D11_BIND_DEPTH_STENCIL,
    PEN_BIND_UNORDERED_ACCESS = D3D11_BIND_UNORDERED_ACCESS,
    PEN_BIND_DECODER = D3D11_BIND_DECODER,
    PEN_BIND_VIDEO_ENCODER = D3D11_BIND_VIDEO_ENCODER,
    PEN_BIND_SHADER_WRITE = D3D11_BIND_UNORDERED_ACCESS,

    // custom
    PEN_STREAM_OUT_VERTEX_BUFFER = D3D11_BIND_STREAM_OUTPUT | D3D11_BIND_VERTEX_BUFFER,
};

enum cpu_access_flags : s32
{
    PEN_CPU_ACCESS_WRITE = D3D11_CPU_ACCESS_WRITE,
    PEN_CPU_ACCESS_READ = D3D11_CPU_ACCESS_READ,
};

enum primitive_topology : s32
{
    PEN_PT_POINTLIST = D3D11_PRIMITIVE_TOPOLOGY_POINTLIST,
    PEN_PT_LINELIST = D3D11_PRIMITIVE_TOPOLOGY_LINELIST,
    PEN_PT_LINESTRIP = D3D11_PRIMITIVE_TOPOLOGY_LINESTRIP,
    PEN_PT_TRIANGLELIST = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLELIST,
    PEN_PT_TRIANGLESTRIP = D3D11_PRIMITIVE_TOPOLOGY_TRIANGLESTRIP
};

enum vertex_format : s32
{
    PEN_VERTEX_FORMAT_FLOAT1 = DXGI_FORMAT_R32_FLOAT,
    PEN_VERTEX_FORMAT_FLOAT2 = DXGI_FORMAT_R32G32_FLOAT,
    PEN_VERTEX_FORMAT_FLOAT3 = DXGI_FORMAT_R32G32B32_FLOAT,
    PEN_VERTEX_FORMAT_FLOAT4 = DXGI_FORMAT_R32G32B32A32_FLOAT,
    PEN_VERTEX_FORMAT_UNORM4 = DXGI_FORMAT_R8G8B8A8_UNORM,
    PEN_VERTEX_FORMAT_UNORM2 = DXGI_FORMAT_R8G8_UNORM,
    PEN_VERTEX_FORMAT_UNORM1 = DXGI_FORMAT_R8_UNORM
};

enum index_buffer_format : s32
{
    PEN_FORMAT_R16_UINT = DXGI_FORMAT_R16_UINT,
    PEN_FORMAT_R32_UINT = DXGI_FORMAT_R32_UINT
};

enum texture_format : s32
{
    PEN_TEX_FORMAT_BGRA8_UNORM = DXGI_FORMAT_B8G8R8A8_UNORM,
    PEN_TEX_FORMAT_RGBA8_UNORM = DXGI_FORMAT_R8G8B8A8_UNORM,
    PEN_TEX_FORMAT_D24_UNORM_S8_UINT = DXGI_FORMAT_R24G8_TYPELESS,

    PEN_TEX_FORMAT_R32G32B32A32_FLOAT = DXGI_FORMAT_R32G32B32A32_FLOAT,
    PEN_TEX_FORMAT_R32_FLOAT = DXGI_FORMAT_R32_FLOAT,
    PEN_TEX_FORMAT_R16G16B16A16_FLOAT = DXGI_FORMAT_R16G16B16A16_FLOAT,
    PEN_TEX_FORMAT_R16_FLOAT = DXGI_FORMAT_R16_FLOAT,
    PEN_TEX_FORMAT_R32_UINT = DXGI_FORMAT_R32_UINT,
    PEN_TEX_FORMAT_R8_UNORM = DXGI_FORMAT_R8_UNORM,
    PEN_TEX_FORMAT_R32G32_FLOAT = DXGI_FORMAT_R32G32_FLOAT,

    PEN_TEX_FORMAT_BC1_UNORM = DXGI_FORMAT_BC1_UNORM,
    PEN_TEX_FORMAT_BC2_UNORM = DXGI_FORMAT_BC2_UNORM,
    PEN_TEX_FORMAT_BC3_UNORM = DXGI_FORMAT_BC3_UNORM,
    PEN_TEX_FORMAT_BC4_UNORM = DXGI_FORMAT_BC4_UNORM,
    PEN_TEX_FORMAT_BC5_UNORM = DXGI_FORMAT_BC5_UNORM
};

enum stencil_op : s32
{
    PEN_STENCIL_OP_KEEP = D3D11_STENCIL_OP_KEEP,
    PEN_STENCIL_OP_ZERO = D3D11_STENCIL_OP_ZERO,
    PEN_STENCIL_OP_REPLACE = D3D11_STENCIL_OP_REPLACE,
    PEN_STENCIL_OP_INCR_SAT = D3D11_STENCIL_OP_INCR_SAT,
    PEN_STENCIL_OP_DECR_SAT = D3D11_STENCIL_OP_DECR_SAT,
    PEN_STENCIL_OP_INVERT = D3D11_STENCIL_OP_INVERT,
    PEN_STENCIL_OP_INCR = D3D11_STENCIL_OP_INCR,
    PEN_STENCIL_OP_DECR = D3D11_STENCIL_OP_DECR
};

enum sampler_filters : s32
{
    PEN_FILTER_MIN_MAG_MIP_POINT = D3D11_FILTER_MIN_MAG_MIP_POINT,
    PEN_FILTER_MIN_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MIN_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MIN_POINT_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MIN_POINT_MAG_MIP_LINEAR = D3D11_FILTER_MIN_POINT_MAG_MIP_LINEAR,
    PEN_FILTER_MIN_LINEAR_MAG_MIP_POINT = D3D11_FILTER_MIN_LINEAR_MAG_MIP_POINT,
    PEN_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MIN_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MIN_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MIN_MAG_MIP_LINEAR = D3D11_FILTER_MIN_MAG_MIP_LINEAR,
    PEN_FILTER_ANISOTROPIC = D3D11_FILTER_ANISOTROPIC,
    PEN_FILTER_COMPARISON_MIN_MAG_MIP_POINT = D3D11_FILTER_COMPARISON_MIN_MAG_MIP_POINT,
    PEN_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR = D3D11_FILTER_COMPARISON_MIN_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT = D3D11_FILTER_COMPARISON_MIN_POINT_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR = D3D11_FILTER_COMPARISON_MIN_POINT_MAG_MIP_LINEAR,
    PEN_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT = D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_MIP_POINT,
    PEN_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR = D3D11_FILTER_COMPARISON_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT = D3D11_FILTER_COMPARISON_MIN_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR = D3D11_FILTER_COMPARISON_MIN_MAG_MIP_LINEAR,
    PEN_FILTER_COMPARISON_ANISOTROPIC = D3D11_FILTER_COMPARISON_ANISOTROPIC,
    PEN_FILTER_MINIMUM_MIN_MAG_MIP_POINT = D3D11_FILTER_MINIMUM_MIN_MAG_MIP_POINT,
    PEN_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MINIMUM_MIN_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MINIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR = D3D11_FILTER_MINIMUM_MIN_POINT_MAG_MIP_LINEAR,
    PEN_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT = D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_MIP_POINT,
    PEN_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MINIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MINIMUM_MIN_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR = D3D11_FILTER_MINIMUM_MIN_MAG_MIP_LINEAR,
    PEN_FILTER_MINIMUM_ANISOTROPIC = D3D11_FILTER_MINIMUM_ANISOTROPIC,
    PEN_FILTER_MAXIMUM_MIN_MAG_MIP_POINT = D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_POINT,
    PEN_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MAXIMUM_MIN_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR = D3D11_FILTER_MAXIMUM_MIN_POINT_MAG_MIP_LINEAR,
    PEN_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT = D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_MIP_POINT,
    PEN_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR = D3D11_FILTER_MAXIMUM_MIN_LINEAR_MAG_POINT_MIP_LINEAR,
    PEN_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT = D3D11_FILTER_MAXIMUM_MIN_MAG_LINEAR_MIP_POINT,
    PEN_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR = D3D11_FILTER_MAXIMUM_MIN_MAG_MIP_LINEAR,
    PEN_FILTER_MAXIMUM_ANISOTROPIC = D3D11_FILTER_MAXIMUM_ANISOTROPIC
};

enum texture_address_mode : s32
{
    PEN_TEXTURE_ADDRESS_WRAP = D3D11_TEXTURE_ADDRESS_WRAP,
    PEN_TEXTURE_ADDRESS_MIRROR = D3D11_TEXTURE_ADDRESS_MIRROR,
    PEN_TEXTURE_ADDRESS_CLAMP = D3D11_TEXTURE_ADDRESS_CLAMP,
    PEN_TEXTURE_ADDRESS_BORDER = D3D11_TEXTURE_ADDRESS_BORDER,
    PEN_TEXTURE_ADDRESS_MIRROR_ONCE = D3D11_TEXTURE_ADDRESS_MIRROR_ONCE
};

enum comparison : s32
{
    PEN_COMPARISON_NEVER = D3D11_COMPARISON_NEVER,
    PEN_COMPARISON_LESS = D3D11_COMPARISON_LESS,
    PEN_COMPARISON_EQUAL = D3D11_COMPARISON_EQUAL,
    PEN_COMPARISON_LESS_EQUAL = D3D11_COMPARISON_LESS_EQUAL,
    PEN_COMPARISON_GREATER = D3D11_COMPARISON_GREATER,
    PEN_COMPARISON_NOT_EQUAL = D3D11_COMPARISON_NOT_EQUAL,
    PEN_COMPARISON_GREATER_EQUAL = D3D11_COMPARISON_GREATER_EQUAL,
    PEN_COMPARISON_ALWAYS = D3D11_COMPARISON_ALWAYS
};

enum blending_factor : s32
{
    PEN_BLEND_ZERO = D3D11_BLEND_ZERO,
    PEN_BLEND_ONE = D3D11_BLEND_ONE,
    PEN_BLEND_SRC_COLOR = D3D11_BLEND_SRC_COLOR,
    PEN_BLEND_INV_SRC_COLOR = D3D11_BLEND_INV_SRC_COLOR,
    PEN_BLEND_SRC_ALPHA = D3D11_BLEND_SRC_ALPHA,
    PEN_BLEND_INV_SRC_ALPHA = D3D11_BLEND_INV_SRC_ALPHA,
    PEN_BLEND_DEST_ALPHA = D3D11_BLEND_DEST_ALPHA,
    PEN_BLEND_INV_DEST_ALPHA = D3D11_BLEND_INV_DEST_ALPHA,
    PEN_BLEND_DEST_COLOR = D3D11_BLEND_DEST_COLOR,
    PEN_BLEND_INV_DEST_COLOR = D3D11_BLEND_INV_DEST_COLOR,
    PEN_BLEND_SRC_ALPHA_SAT = D3D11_BLEND_SRC_ALPHA_SAT,
    PEN_BLEND_BLEND_FACTOR = D3D11_BLEND_BLEND_FACTOR,
    PEN_BLEND_INV_BLEND_FACTOR = D3D11_BLEND_INV_BLEND_FACTOR,
    PEN_BLEND_SRC1_COLOR = D3D11_BLEND_SRC1_COLOR,
    PEN_BLEND_INV_SRC1_COLOR = D3D11_BLEND_INV_SRC1_COLOR,
    PEN_BLEND_SRC1_ALPHA = D3D11_BLEND_SRC1_ALPHA,
    PEN_BLEND_INV_SRC1_ALPHA = D3D11_BLEND_INV_SRC1_ALPHA
};

enum blend_op : s32
{
    PEN_BLEND_OP_ADD = D3D11_BLEND_OP_ADD,
    PEN_BLEND_OP_SUBTRACT = D3D11_BLEND_OP_SUBTRACT,
    PEN_BLEND_OP_REV_SUBTRACT = D3D11_BLEND_OP_REV_SUBTRACT,
    PEN_BLEND_OP_MIN = D3D11_BLEND_OP_MIN,
    PEN_BLEND_OP_MAX = D3D11_BLEND_OP_MAX
};

enum query_marker : s32
{
    PEN_QUERY_BEGIN = 1,
    PEN_QUERY_END = 2
};

enum query_type : s32
{
    PEN_QUERY_EVENT = 0,
    PEN_QUERY_OCCLUSION = (PEN_QUERY_EVENT + 1),
    PEN_QUERY_TIMESTAMP = (PEN_QUERY_OCCLUSION + 1),
    PEN_QUERY_TIMESTAMP_DISJOINT = (PEN_QUERY_TIMESTAMP + 1),
    PEN_QUERY_PIPELINE_STATISTICS = (PEN_QUERY_TIMESTAMP_DISJOINT + 1),
    PEN_QUERY_OCCLUSION_PREDICATE = (PEN_QUERY_PIPELINE_STATISTICS + 1),
    PEN_QUERY_SO_STATISTICS = (PEN_QUERY_OCCLUSION_PREDICATE + 1),
    PEN_QUERY_SO_OVERFLOW_PREDICATE = (PEN_QUERY_SO_STATISTICS + 1),
    PEN_QUERY_SO_STATISTICS_STREAM0 = (PEN_QUERY_SO_OVERFLOW_PREDICATE + 1),
    PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM0 = (PEN_QUERY_SO_STATISTICS_STREAM0 + 1),
    PEN_QUERY_SO_STATISTICS_STREAM1 = (PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM0 + 1),
    PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM1 = (PEN_QUERY_SO_STATISTICS_STREAM1 + 1),
    PEN_QUERY_SO_STATISTICS_STREAM2 = (PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM1 + 1),
    PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM2 = (PEN_QUERY_SO_STATISTICS_STREAM2 + 1),
    PEN_QUERY_SO_STATISTICS_STREAM3 = (PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM2 + 1),
    PEN_QUERY_SO_OVERFLOW_PREDICATE_STREAM3 = (PEN_QUERY_SO_STATISTICS_STREAM3 + 1)
};

enum misc_flags : s32
{
    PEN_RESOURCE_MISC_GENERATE_MIPS = 0x1L,
    PEN_RESOURCE_MISC_SHARED = 0x2L,
    PEN_RESOURCE_MISC_TEXTURECUBE = 0x4L,
    PEN_RESOURCE_MISC_DRAWINDIRECT_ARGS = 0x10L,
    PEN_RESOURCE_MISC_BUFFER_ALLOW_RAW_VIEWS = 0x20,
    PEN_RESOURCE_MISC_BUFFER_STRUCTURED = 0x40L,
    PEN_RESOURCE_MISC_RESOURCE_CLAMP = 0x80L,
    PEN_RESOURCE_MISC_SHARED_KEYEDMUTEX = 0x100L,
    PEN_RESOURCE_MISC_GDI_COMPATIBLE = 0x200L,
    PEN_RESOURCE_MISC_SHARED_NTHANDLE = 0x800L,
    PEN_RESOURCE_MISC_RESTRICTED_CONTENT = 0x1000L,
    PEN_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE = 0x2000L,
    PEN_RESOURCE_MISC_RESTRICT_SHARED_RESOURCE_DRIVER = 0x4000L,
    PEN_RESOURCE_MISC_GUARDED = 0x8000L,
    PEN_RESOURCE_MISC_TILE_POOL = 0x20000L,
    PEN_RESOURCE_MISC_TILED = 0x40000L
};

#endif

// all texture formats
/*
 enum format : s32
 {
 PEN_FORMAT_UNKNOWN = DXGI_FORMAT_UNKNOWN,
 PEN_FORMAT_R32G32B32A32_TYPELESS = DXGI_FORMAT_R32G32B32A32_TYPELESS,
 PEN_FORMAT_R32G32B32A32_FLOAT = DXGI_FORMAT_R32G32B32A32_FLOAT,
 PEN_FORMAT_R32G32B32A32_UINT = DXGI_FORMAT_R32G32B32A32_UINT,
 PEN_FORMAT_R32G32B32A32_SINT = DXGI_FORMAT_R32G32B32A32_SINT,
 PEN_FORMAT_R32G32B32_TYPELESS = DXGI_FORMAT_R32G32B32_TYPELESS,
 PEN_FORMAT_R32G32B32_FLOAT = DXGI_FORMAT_R32G32B32_FLOAT,
 PEN_FORMAT_R32G32B32_UINT = DXGI_FORMAT_R32G32B32_UINT,
 PEN_FORMAT_R32G32B32_SINT = DXGI_FORMAT_R32G32B32_SINT,
 PEN_FORMAT_R16G16B16A16_TYPELESS = DXGI_FORMAT_R16G16B16A16_TYPELESS,
 PEN_FORMAT_R16G16B16A16_FLOAT = DXGI_FORMAT_R16G16B16A16_FLOAT,
 PEN_FORMAT_R16G16B16A16_UNORM = DXGI_FORMAT_R16G16B16A16_UNORM,
 PEN_FORMAT_R16G16B16A16_UINT = DXGI_FORMAT_R16G16B16A16_UINT,
 PEN_FORMAT_R16G16B16A16_SNORM = DXGI_FORMAT_R16G16B16A16_SNORM,
 PEN_FORMAT_R16G16B16A16_SINT = DXGI_FORMAT_R16G16B16A16_SINT,
 PEN_FORMAT_R32G32_TYPELESS = DXGI_FORMAT_R32G32_TYPELESS,
 PEN_FORMAT_R32G32_FLOAT = DXGI_FORMAT_R32G32_FLOAT,
 PEN_FORMAT_R32G32_UINT = DXGI_FORMAT_R32G32_UINT,
 PEN_FORMAT_R32G32_SINT = DXGI_FORMAT_R32G32_SINT,
 PEN_FORMAT_R32G8X24_TYPELESS = DXGI_FORMAT_R32G8X24_TYPELESS,
 PEN_FORMAT_D32_FLOAT_S8X24_UINT = DXGI_FORMAT_D32_FLOAT_S8X24_UINT,
 PEN_FORMAT_R32_FLOAT_X8X24_TYPELESS = DXGI_FORMAT_R32_FLOAT_X8X24_TYPELESS,
 PEN_FORMAT_X32_TYPELESS_G8X24_UINT = DXGI_FORMAT_X32_TYPELESS_G8X24_UINT,
 PEN_FORMAT_R10G10B10A2_TYPELESS = DXGI_FORMAT_R10G10B10A2_TYPELESS,
 PEN_FORMAT_R10G10B10A2_UNORM = DXGI_FORMAT_R10G10B10A2_UNORM,
 PEN_FORMAT_R10G10B10A2_UINT = DXGI_FORMAT_R10G10B10A2_UINT,
 PEN_FORMAT_R11G11B10_FLOAT = DXGI_FORMAT_R11G11B10_FLOAT,
 PEN_FORMAT_R8G8B8A8_TYPELESS = DXGI_FORMAT_R8G8B8A8_TYPELESS,
 PEN_FORMAT_R8G8B8A8_UNORM = DXGI_FORMAT_R8G8B8A8_UNORM,
 PEN_FORMAT_R8G8B8A8_UNORM_SRGB = DXGI_FORMAT_R8G8B8A8_UNORM_SRGB,
 PEN_FORMAT_R8G8B8A8_UINT = DXGI_FORMAT_R8G8B8A8_UINT,
 PEN_FORMAT_R8G8B8A8_SNORM = DXGI_FORMAT_R8G8B8A8_SNORM,
 PEN_FORMAT_R8G8B8A8_SINT = DXGI_FORMAT_R8G8B8A8_SINT,
 PEN_FORMAT_R16G16_TYPELESS = DXGI_FORMAT_R16G16_TYPELESS,
 PEN_FORMAT_R16G16_FLOAT = DXGI_FORMAT_R16G16_FLOAT,
 PEN_FORMAT_R16G16_UNORM = DXGI_FORMAT_R16G16_UNORM,
 PEN_FORMAT_R16G16_UINT = DXGI_FORMAT_R16G16_UINT,
 PEN_FORMAT_R16G16_SNORM = DXGI_FORMAT_R16G16_SNORM,
 PEN_FORMAT_R16G16_SINT = DXGI_FORMAT_R16G16_SINT,
 PEN_FORMAT_R32_TYPELESS = DXGI_FORMAT_R32_TYPELESS,
 PEN_FORMAT_D32_FLOAT = DXGI_FORMAT_D32_FLOAT,
 PEN_FORMAT_R32_FLOAT = DXGI_FORMAT_R32_FLOAT,
 PEN_FORMAT_R32_UINT = DXGI_FORMAT_R32_UINT,
 PEN_FORMAT_R32_SINT = DXGI_FORMAT_R32_SINT,
 PEN_FORMAT_R24G8_TYPELESS = DXGI_FORMAT_R24G8_TYPELESS,
 PEN_FORMAT_D24_UNORM_S8_UINT = DXGI_FORMAT_D24_UNORM_S8_UINT,
 PEN_FORMAT_R24_UNORM_X8_TYPELESS = DXGI_FORMAT_R24_UNORM_X8_TYPELESS,
 PEN_FORMAT_X24_TYPELESS_G8_UINT = DXGI_FORMAT_X24_TYPELESS_G8_UINT,
 PEN_FORMAT_R8G8_TYPELESS = DXGI_FORMAT_R8G8_TYPELESS,
 PEN_FORMAT_R8G8_UNORM = DXGI_FORMAT_R8G8_UNORM,
 PEN_FORMAT_R8G8_UINT = DXGI_FORMAT_R8G8_UINT,
 PEN_FORMAT_R8G8_SNORM = DXGI_FORMAT_R8G8_SNORM,
 PEN_FORMAT_R8G8_SINT = DXGI_FORMAT_R8G8_SINT,
 PEN_FORMAT_R16_TYPELESS = DXGI_FORMAT_R16_TYPELESS,
 PEN_FORMAT_R16_FLOAT = DXGI_FORMAT_R16_FLOAT,
 PEN_FORMAT_D16_UNORM = DXGI_FORMAT_D16_UNORM,
 PEN_FORMAT_R16_UNORM = DXGI_FORMAT_R16_UNORM,
 PEN_FORMAT_R16_UINT = DXGI_FORMAT_R16_UINT,
 PEN_FORMAT_R16_SNORM = DXGI_FORMAT_R16_SNORM,
 PEN_FORMAT_R16_SINT = DXGI_FORMAT_R16_SINT,
 PEN_FORMAT_R8_TYPELESS = DXGI_FORMAT_R8_TYPELESS,
 PEN_FORMAT_R8_UNORM = DXGI_FORMAT_R8_UNORM,
 PEN_FORMAT_R8_UINT = DXGI_FORMAT_R8_UINT,
 PEN_FORMAT_R8_SNORM = DXGI_FORMAT_R8_SNORM,
 PEN_FORMAT_R8_SINT = DXGI_FORMAT_R8_SINT,
 PEN_FORMAT_A8_UNORM = DXGI_FORMAT_A8_UNORM,
 PEN_FORMAT_R1_UNORM = DXGI_FORMAT_R1_UNORM,
 PEN_FORMAT_R9G9B9E5_SHAREDEXP = DXGI_FORMAT_R9G9B9E5_SHAREDEXP,
 PEN_FORMAT_R8G8_B8G8_UNORM = DXGI_FORMAT_R8G8_B8G8_UNORM,
 PEN_FORMAT_G8R8_G8B8_UNORM = DXGI_FORMAT_G8R8_G8B8_UNORM,
 PEN_FORMAT_BC1_TYPELESS = DXGI_FORMAT_BC1_TYPELESS,
 PEN_FORMAT_BC1_UNORM = DXGI_FORMAT_BC1_UNORM,
 PEN_FORMAT_BC1_UNORM_SRGB = DXGI_FORMAT_BC1_UNORM_SRGB,
 PEN_FORMAT_BC2_TYPELESS = DXGI_FORMAT_BC2_TYPELESS,
 PEN_FORMAT_BC2_UNORM = DXGI_FORMAT_BC2_UNORM,
 PEN_FORMAT_BC2_UNORM_SRGB = DXGI_FORMAT_BC2_UNORM_SRGB,
 PEN_FORMAT_BC3_TYPELESS = DXGI_FORMAT_BC3_TYPELESS,
 PEN_FORMAT_BC3_UNORM = DXGI_FORMAT_BC3_UNORM,
 PEN_FORMAT_BC3_UNORM_SRGB = DXGI_FORMAT_BC3_UNORM_SRGB,
 PEN_FORMAT_BC4_TYPELESS = DXGI_FORMAT_BC4_TYPELESS,
 PEN_FORMAT_BC4_UNORM = DXGI_FORMAT_BC4_UNORM,
 PEN_FORMAT_BC4_SNORM = DXGI_FORMAT_BC4_SNORM,
 PEN_FORMAT_BC5_TYPELESS = DXGI_FORMAT_BC5_TYPELESS,
 PEN_FORMAT_BC5_UNORM = DXGI_FORMAT_BC5_UNORM,
 PEN_FORMAT_BC5_SNORM = DXGI_FORMAT_BC5_SNORM,
 PEN_FORMAT_B5G6R5_UNORM = DXGI_FORMAT_B5G6R5_UNORM,
 PEN_FORMAT_B5G5R5A1_UNORM = DXGI_FORMAT_B5G5R5A1_UNORM,
 PEN_FORMAT_B8G8R8A8_UNORM = DXGI_FORMAT_B8G8R8A8_UNORM,
 PEN_FORMAT_B8G8R8X8_UNORM = DXGI_FORMAT_B8G8R8X8_UNORM,
 PEN_FORMAT_R10G10B10_XR_BIAS_A2_UNORM = DXGI_FORMAT_R10G10B10_XR_BIAS_A2_UNORM,
 PEN_FORMAT_B8G8R8A8_TYPELESS = DXGI_FORMAT_B8G8R8A8_TYPELESS,
 PEN_FORMAT_B8G8R8A8_UNORM_SRGB = DXGI_FORMAT_B8G8R8A8_UNORM_SRGB,
 PEN_FORMAT_B8G8R8X8_TYPELESS = DXGI_FORMAT_B8G8R8X8_TYPELESS,
 PEN_FORMAT_B8G8R8X8_UNORM_SRGB = DXGI_FORMAT_B8G8R8X8_UNORM_SRGB,
 PEN_FORMAT_BC6H_TYPELESS = DXGI_FORMAT_BC6H_TYPELESS,
 PEN_FORMAT_BC6H_UF16 = DXGI_FORMAT_BC6H_UF16,
 PEN_FORMAT_BC6H_SF16 = DXGI_FORMAT_BC6H_SF16,
 PEN_FORMAT_BC7_TYPELESS = DXGI_FORMAT_BC7_TYPELESS,
 PEN_FORMAT_BC7_UNORM = DXGI_FORMAT_BC7_UNORM,
 PEN_FORMAT_BC7_UNORM_SRGB = DXGI_FORMAT_BC7_UNORM_SRGB,
 PEN_FORMAT_AYUV = DXGI_FORMAT_AYUV,
 PEN_FORMAT_Y410 = DXGI_FORMAT_Y410,
 PEN_FORMAT_Y416 = DXGI_FORMAT_Y416,
 PEN_FORMAT_NV12 = DXGI_FORMAT_NV12,
 PEN_FORMAT_P010 = DXGI_FORMAT_P010,
 PEN_FORMAT_P016 = DXGI_FORMAT_P016,
 PEN_FORMAT_420_OPAQUE = DXGI_FORMAT_420_OPAQUE,
 PEN_FORMAT_YUY2 = DXGI_FORMAT_YUY2,
 PEN_FORMAT_Y210 = DXGI_FORMAT_Y210,
 PEN_FORMAT_Y216 = DXGI_FORMAT_Y216,
 PEN_FORMAT_NV11 = DXGI_FORMAT_NV11,
 PEN_FORMAT_AI44 = DXGI_FORMAT_AI44,
 PEN_FORMAT_IA44 = DXGI_FORMAT_IA44,
 PEN_FORMAT_P8 = DXGI_FORMAT_P8,
 PEN_FORMAT_A8P8 = DXGI_FORMAT_A8P8,
 PEN_FORMAT_B4G4R4A4_UNORM = DXGI_FORMAT_B4G4R4A4_UNORM,
 PEN_FORMAT_FORCE_UINT = DXGI_FORMAT_FORCE_UINT
 };
 */
