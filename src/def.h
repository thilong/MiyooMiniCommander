#ifndef _DEF_H_
#define _DEF_H_

//~ #define INHIBIT(X) X
#define INHIBIT(X) /* X */

#define SCREEN_WIDTH          640
#define SCREEN_HEIGHT         480
#define SCREEN_BPP            32
#define SURFACE_FLAGS         SDL_HWSURFACE | SDL_DOUBLEBUF
#define MS_PER_FRAME          33
// Panel
#define LINE_HEIGHT           30
#define NB_VISIBLE_LINES      14
#define Y_LIST                34
#define Y_HEADER              4
#define Y_FOOTER              456
#define H_FOOTER              26
// Dialogs
#define DIALOG_BORDER         2
#define DIALOG_MARGIN         8
// Colors
#define COLOR_KEY             255,0,255
#define COLOR_TEXT_NORMAL     70,27,10
#define COLOR_TEXT_TITLE      233,229,227
#define COLOR_TEXT_DIR        75,70,164
#define COLOR_TEXT_SELECTED   255,0,0
#define COLOR_CURSOR_1        232,152,80
#define COLOR_CURSOR_2        232,201,173
#define COLOR_BG_1            255,255,255
#define COLOR_BG_2            232,228,224
#define COLOR_BORDER          102,85,74

#if defined(PLATFORM_DINGOO)
// Keys for Dingoo


#define MYKEY_UP            SDLK_UP           // Up
#define MYKEY_RIGHT         SDLK_RIGHT        // Right
#define MYKEY_DOWN          SDLK_DOWN         // Down
#define MYKEY_LEFT          SDLK_LEFT         // Left
#define MYKEY_SYSTEM        SDLK_LSHIFT       // Y
#define MYKEY_PAGEUP        SDLK_TAB          // L
#define MYKEY_PAGEDOWN      SDLK_BACKSPACE    // R
#define MYKEY_OPEN          SDLK_LCTRL        // A
#define MYKEY_PARENT        SDLK_LALT         // B
#define MYKEY_OPERATION     SDLK_SPACE        // X
#define MYKEY_SELECT        SDLK_ESCAPE       // SELECT
#define MYKEY_TRANSFER      SDLK_RETURN       // START
#define PATH_DEFAULT        "/boot/local"
#define FILE_SYSTEM         "/dev/mmcblk0p1"

#elif defined(DEVICE_MIYOO_MINI)

#include "miyoo_keys.h"

#define MYKEY_UP            btn_up           // Up
#define MYKEY_RIGHT         btn_right        // Right
#define MYKEY_DOWN          btn_down         // Down
#define MYKEY_LEFT          btn_left         // Left
#define MYKEY_SYSTEM        btn_menu       // Y
#define MYKEY_PAGEUP        btn_l1          // L
#define MYKEY_PAGEDOWN      btn_r1    // R
#define MYKEY_OPEN          btn_a        // A
#define MYKEY_PARENT        btn_b         // B
#define MYKEY_OPERATION     btn_x        // X
#define MYKEY_SELECT        btn_select       // SELECT
#define MYKEY_TRANSFER      btn_start       // START
#define PATH_DEFAULT        "/mnt/SDCARD"
#define FILE_SYSTEM         "/dev/mmcblk0p1"


#elif defined(PLATFORM_GCW0)
// Keys for GCW Zero
#define MYKEY_UP            SDLK_UP           // Up
#define MYKEY_RIGHT         SDLK_RIGHT        // Right
#define MYKEY_DOWN          SDLK_DOWN         // Down
#define MYKEY_LEFT          SDLK_LEFT         // Left
#define MYKEY_SYSTEM        SDLK_LSHIFT       // X
#define MYKEY_PAGEUP        SDLK_TAB          // L
#define MYKEY_PAGEDOWN      SDLK_BACKSPACE    // R
#define MYKEY_OPEN          SDLK_LCTRL        // A
#define MYKEY_PARENT        SDLK_LALT         // B
#define MYKEY_OPERATION     SDLK_SPACE        // Y
#define MYKEY_SELECT        SDLK_ESCAPE       // SELECT
#define MYKEY_TRANSFER      SDLK_RETURN       // START
#define PATH_DEFAULT        "/"
#define FILE_SYSTEM         "/dev/mmcblk0p1"
#else
// Keys for PC keyboard
#define MYKEY_UP            SDLK_UP
#define MYKEY_RIGHT         SDLK_RIGHT
#define MYKEY_DOWN          SDLK_DOWN
#define MYKEY_LEFT          SDLK_LEFT
#define MYKEY_SYSTEM        SDLK_q
#define MYKEY_PAGEUP        SDLK_PAGEUP
#define MYKEY_PAGEDOWN      SDLK_PAGEDOWN
#define MYKEY_OPEN          SDLK_RETURN
#define MYKEY_PARENT        SDLK_BACKSPACE
#define MYKEY_OPERATION     SDLK_a
#define MYKEY_SELECT        SDLK_INSERT
#define MYKEY_TRANSFER      SDLK_w
#define PATH_DEFAULT        "/"
#define FILE_SYSTEM         "/dev/sda4"
#endif

#endif
