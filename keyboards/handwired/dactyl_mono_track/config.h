// Copyright 2023 ursaw (@ursaw)
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
// TODO why do I have to define the numbers of the pins here?
///#define MATRIX_COLS 12
///#define MATRIX_ROWS 5
////* Key matrix configuration. */
///#define MATRIX_COL_PINS     {GP15, GP14, GP13, GP12, GP11, GP10, GP9, GP8, GP7, GP6, GP5, GP4 }
///#define MATRIX_ROW_PINS     { GP28, GP21, GP6, GP7, GP8 }
/////    "matrix_pins": {
/////        "cols": ["GP15", "GP14", "GP13", "GP12", "GP11", "GP10", "GP9", "GP8", "GP7", "GP6", "GP5", "GP4"],
/////        "rows": ["GP16", "GP17", "GP18", "GP19", "GP20"]
/////    },

/* Trackball angle adjustment.
#define ROTATIONAL_TRANSFORM_ANGLE -25
 */

/* SPI & PMW3360 settings. */
#define SPI_DRIVER SPID0
#define SPI_SCK_PIN GP22
#define SPI_MISO_PIN GP20
#define SPI_MOSI_PIN GP23
#define POINTING_DEVICE_CS_PIN GP16

/* Reset. */
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_LED GP17
#define RP2040_BOOTLOADER_DOUBLE_TAP_RESET_TIMEOUT 1000U


