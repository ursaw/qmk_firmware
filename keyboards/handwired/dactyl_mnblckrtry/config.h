// Copyright 2022 ursaw (@ursaw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

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


#define VENDOR_ID       0x0001
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0003
// #define MANUFACTURER    ursaw
// #define PRODUCT         Dactyl monoblock rotary encoder
// #define DESCRIPTION     QMK keyboard firmware for Dactyl monoblock

#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS { D1, D0, D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 2


#define K__ KC_NO

