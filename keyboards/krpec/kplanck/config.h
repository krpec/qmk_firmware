#ifndef CONFIG_H
#define CONFIG_H

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEEF
#define PRODUCT_ID      0x0420
#define MANUFACTURER    krpec
#define PRODUCT         k-Planck
#define DESCRIPTION     A compact ortholinear keyboard
#define DEVICE_VER			1

/* key matrix size */
#define MATRIX_ROWS 4
#define MATRIX_COLS 12

/* Planck PCB default pin-out */
#define MATRIX_ROW_PINS { B1, B0, F0, F1 }
#define MATRIX_COL_PINS { B7, D0, D1, D2, D3, D5, D4, D6, D7, B4, B5, B6 }
#define UNUSED_PINS

#define QMK_ESC_OUTPUT F1 //B1?
#define QMK_ESC_INPUT D5 //B7?
//#define QMK_LED     E6
//#define QMK_SPEAKER C6

//#define AUDIO_VOICES
//#define C6_AUDIO

//#define BACKLIGHT_PIN B7

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* define if matrix has ghost */
//#define MATRIX_HAS_GHOST

/* number of backlight levels */
//#define BACKLIGHT_LEVELS 3

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
//#define NO_ACTION_MACRO
//#define NO_ACTION_FUNCTION

#endif