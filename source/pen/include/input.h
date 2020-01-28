// input.h
// Copyright 2014 - 2019 Alex Dixon.
// License: https://github.com/polymonster/pmtech/blob/master/license.md

#pragma once

// Simple input api for getting keyboard and mouse presses + unicode characters
// Implemented with win32, NS and xlib
// Gamepad api using libstemgamepad

#include "pen.h"
#include "str/Str.h"

extern pen::window_creation_params pen_window;

enum gamepad_button
{
    PGP_BUTTON_A = 0,
    PGP_BUTTON_B,
    PGP_BUTTON_X,
    PGP_BUTTON_Y,
    PGP_BUTTON_L1,
    PGP_BUTTON_R1,
    PGP_BUTTON_BACK,
    PGP_BUTTON_START,
    PGP_BUTTON_L3,
    PGP_BUTTON_R3,
    PGP_BUTTON_DLEFT,
    PGP_BUTTON_DRIGHT,
    PGP_BUTTON_DUP,
    PGP_BUTTON_DDOWN,
    PGP_BUTTON_TOUCH_PAD, // ds4 touch pad
    PGP_BUTTON_PLATFORM,  // ps button, xbox button etc
    PGP_BUTTON_COUNT
};

enum gamepad_axis
{
    PGP_AXIS_LEFT_STICK_X = 0,
    PGP_AXIS_LEFT_STICK_Y,
    PGP_AXIS_RIGHT_STICK_X,
    PGP_AXIS_RIGHT_STICK_Y,
    PGP_AXIS_LTRIGGER,
    PGP_AXIS_RTRIGGER,
    PGP_AXIS_COUNT
};

namespace pen
{
    struct mouse_state
    {
        f32 x;
        f32 y;
        f32 wheel;
        u8  buttons[3];
    };

    struct raw_gamepad_state
    {
        u32 device_id = PEN_INVALID_HANDLE;
        u32 vendor_id = PEN_INVALID_HANDLE;
        u32 product_id = PEN_INVALID_HANDLE;
        u32 mapping = PEN_INVALID_HANDLE;
        u8  button[PGP_BUTTON_COUNT] = {0};
        f32 axis[PGP_AXIS_COUNT] = {0};
    };

    struct gamepad_state
    {
        u32 device_index;
        u8  button[PGP_BUTTON_COUNT];
        f32 axis[PGP_AXIS_COUNT];
    };
    
    void input_set_unicode_key_down(u32 key_index);
    void input_set_unicode_key_up(u32 key_index);
    bool input_get_unicode_key(u32 key_index);
    
    void input_add_unicode_input(const c8* utf8);
    Str  input_get_unicode_input();
    void input_clear_unicode_input();
    void input_unicode_swap_buffers();

    void input_set_key_down(u32 key_index);
    void input_set_key_up(u32 key_index);
    bool input_is_key_down(u32 key_index);

    void input_set_mouse_down(u32 button_index);
    void input_set_mouse_up(u32 button_index);
    void input_set_mouse_pos(f32 x, f32 y);
    void input_set_mouse_wheel(f32 wheel);

    void input_gamepad_init();
    void input_gamepad_shutdown();
    u32  input_get_num_gamepads();
    void input_gamepad_update();
    void input_get_gamepad_state(u32 device_index, gamepad_state& gs);
    void input_get_raw_gamepad_state(u32 device_index, raw_gamepad_state& gs);

    const mouse_state& input_get_mouse_state();
    bool               input_is_mouse_down(u32 button_index);

    bool input_key(u32 key_index);
    bool input_mouse(u32 button_index);

    void input_set_cursor_pos(u32 client_x, u32 client_y);
    void input_show_cursor(bool show);

    bool mouse_coords_valid(u32 x, u32 y);

    const c8* input_get_key_str(u32 key_index);

    // Special os specific functions

    bool input_undo_pressed();
    bool input_redo_pressed();

    inline bool mouse_coords_valid(u32 x, u32 y)
    {
        return x < pen_window.width && y < pen_window.height;
    }

    inline bool input_key(u32 key_index)
    {
        return pen::input_is_key_down(key_index);
    }

    inline bool input_mouse(u32 button_index)
    {
        return pen::input_is_mouse_down(button_index);
    }
    
    inline bool press_debounce(u32 key, bool& db)
    {
        if(pen::input_key(key))
        {
            if(!db)
            {
                db = true;
                return true;
            }
        }
        else
        {
            db = false;
        }
        
        return false;
    }

} // namespace pen

enum mouse_button
{
    PEN_MOUSE_L = 0,
    PEN_MOUSE_R = 1,
    PEN_MOUSE_M = 2
};

enum virtual_key
{
    PK_CANCEL = 0x03,
    PK_BACK = 0x08,
    PK_TAB = 0x09,
    PK_CLEAR = 0x0C,
    PK_RETURN = 0x0D,
    PK_SHIFT = 0x10,
    PK_CONTROL = 0x11,
    PK_MENU = 0x12,
    PK_PAUSE = 0x13,
    PK_CAPITAL = 0x14,
    PK_ESCAPE = 0x1B,
    PK_SPACE = 0x20,
    PK_PRIOR = 0x21,
    PK_NEXT = 0x22,
    PK_END = 0x23,
    PK_HOME = 0x24,
    PK_LEFT = 0x25,
    PK_UP = 0x26,
    PK_RIGHT = 0x27,
    PK_DOWN = 0x28,
    PK_SELECT = 0x29,
    PK_EXECUTE = 0x2B,
    PK_SNAPSHOT = 0x2C,
    PK_INSERT = 0x2D,
    PK_DELETE = 0x2E,
    PK_HELP = 0x2F,
    PK_0 = 0x30,
    PK_1 = 0x31,
    PK_2 = 0x32,
    PK_3 = 0x33,
    PK_4 = 0x34,
    PK_5 = 0x35,
    PK_6 = 0x36,
    PK_7 = 0x37,
    PK_8 = 0x38,
    PK_9 = 0x39,
    PK_A = 0x41,
    PK_B = 0x42,
    PK_C = 0x43,
    PK_D = 0x44,
    PK_E = 0x45,
    PK_F = 0x46,
    PK_G = 0x47,
    PK_H = 0x48,
    PK_I = 0x49,
    PK_J = 0x4A,
    PK_K = 0x4B,
    PK_L = 0x4C,
    PK_M = 0x4D,
    PK_N = 0x4E,
    PK_O = 0x4F,
    PK_P = 0x50,
    PK_Q = 0x51,
    PK_R = 0x52,
    PK_S = 0x53,
    PK_T = 0x54,
    PK_U = 0x55,
    PK_V = 0x56,
    PK_W = 0x57,
    PK_X = 0x58,
    PK_Y = 0x59,
    PK_Z = 0x5A,
    PK_NUMPAD0 = 0x60,
    PK_NUMPAD1 = 0x61,
    PK_NUMPAD2 = 0x62,
    PK_NUMPAD3 = 0x63,
    PK_NUMPAD4 = 0x64,
    PK_NUMPAD5 = 0x65,
    PK_NUMPAD6 = 0x66,
    PK_NUMPAD7 = 0x67,
    PK_NUMPAD8 = 0x68,
    PK_NUMPAD9 = 0x69,
    PK_MULTIPLY = 0x6A,
    PK_ADD = 0x6B,
    PK_SEPARATOR = 0x6C,
    PK_SUBTRACT = 0x6D,
    PK_DECIMAL = 0x6E,
    PK_DIVIDE = 0x6F,
    PK_F1 = 0x70,
    PK_F2 = 0x71,
    PK_F3 = 0x72,
    PK_F4 = 0x73,
    PK_F5 = 0x74,
    PK_F6 = 0x75,
    PK_F7 = 0x76,
    PK_F8 = 0x77,
    PK_F9 = 0x78,
    PK_F10 = 0x79,
    PK_F11 = 0x7A,
    PK_F12 = 0x7B,
    PK_NUMLOCK = 0x90,
    PK_SCROLL = 0x91,
    PK_COMMAND = 0x92,
    PK_OPEN_BRACKET = 0xDB,
    PK_CLOSE_BRACKET = 0xDD,
    PK_SEMICOLON = 0xBA,
    PK_APOSTRAPHE = 0xC0,
    PK_BACK_SLASH = 0xDC,
    PK_FORWARD_SLASH = 0xBF,
    PK_COMMA = 0xBC,
    PK_PERIOD = 0xBE,
    PK_TILDE = 0xDE,
    PK_MINUS = 0xBD,
    PK_EQUAL = 0xBB,
    PK_GRAVE = 223,
    PK_WINDOWS = 91,
    PK_COUNT = 512
};
