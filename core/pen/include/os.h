// os.h
// Copyright 2014 - 2019 Alex Dixon.
// License: https://github.com/polymonster/pmtech/blob/master/license.md

// Tiny api with some window and os specific abstractions.

#pragma once

#include "pen.h"

namespace pen
{
    struct window_frame
    {
        u32 x, y, width, height;
    };

    struct user_info
    {
        const c8* user_name = nullptr;
        const c8* full_user_name = nullptr;
        const c8* working_directory = nullptr;
    };

    // Window
    u32       window_init(void* params);
    void*     window_get_primary_display_handle();
    void      window_get_frame(window_frame& f);
    void      window_set_frame(const window_frame& f);
    void      window_get_size(s32& width, s32& height);
    void      window_set_size(s32 width, s32 height);
    f32       window_get_aspect();
    const c8* window_get_title();
    hash_id   window_get_id();

    // OS
    void             os_terminate(u32 return_code);
    bool             os_update();
    void             os_set_cursor_pos(u32 client_x, u32 client_y);
    void             os_show_cursor(bool show);
    const c8*        os_path_for_resource(const c8* filename);
    const user_info& os_get_user_info();

} // namespace pen
