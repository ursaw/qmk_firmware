#pragma once

#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0xBEAF
#define PRODUCT_ID      0x6069
#define DEVICE_VER      0x0001
#define MANUFACTURER    QMK Community
#define PRODUCT         Dactyl Monoblock

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 12

/* key matrix pins */
#define MATRIX_ROW_PINS { D7, E6, B4, B5, B6 }
#define MATRIX_COL_PINS { D3, D2, D1, D0, D4, C6, F4, F5, F6, F7, B1, B3}
#define UNUSED_PINS

/* COL2ROW or ROW2COL */
#define DIODE_DIRECTION COL2ROW

/* Set 0 if debouncing isn't needed */
#define DEBOUNCE 5  // 5 is default
