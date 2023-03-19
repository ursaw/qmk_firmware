// Copyright 2023 ursaw (@ursaw)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// TODO why do I have to define the numbers of the pins here?
#define MATRIX_COLS 12
#define MATRIX_ROWS 5
/* Key matrix configuration. */
#define MATRIX_COL_PINS     {GP15, GP14, GP13, GP12, GP11, GP10, GP9, GP8, GP7, GP6, GP5, GP4 }
#define MATRIX_ROW_PINS     { GP28, GP21, GP6, GP7, GP8 }
//    "matrix_pins": {
//        "cols": ["GP15", "GP14", "GP13", "GP12", "GP11", "GP10", "GP9", "GP8", "GP7", "GP6", "GP5", "GP4"],
//        "rows": ["GP16", "GP17", "GP18", "GP19", "GP20"]
//    },

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



// clang-format off
#define LAYOUT(                                                   \
  k00, k01, k02, k03, k04, k05,     k55, k54, k53, k52, k51, k50, \
  k10, k11, k12, k13, k14, k15,     k65, k64, k63, k62, k61, k60, \
  k20, k21, k22, k23, k24, k25,     k75, k74, k73, k72, k71, k70, \
  k30, k31, k32, k33, k34, k35,     k85, k84, k83, k82, k81, k80, \
                 k43, k44, k41,     k91, k93,                     \
                      k45, k42,     k95                           \
)                                                                 \
{                                                                 \
  {   k00,   k01,   k02,   k03,   k04,   k05 },                   \
  {   k10,   k11,   k12,   k13,   k14,   k15 },                   \
  {   k20,   k21,   k22,   k23,   k24,   k25 },                   \
  {   k30,   k31,   k32,   k33,   k34,   k35 },                   \
  { KC_NO,   k41,   k42,   k43,   k44,   k45 },                   \
  {   k50,   k51,   k52,   k53,   k54,   k55 },                   \
  {   k60,   k61,   k62,   k63,   k64,   k65 },                   \
  {   k70,   k71,   k72,   k73,   k74,   k75 },                   \
  {   k80,   k81,   k82,   k83,   k84,   k85 },                   \
  { KC_NO,   k91, KC_NO,   k93, KC_NO,   k95 },                   \
}
// clang-format on


/* Pointing device configuration. */

// Enable use of pointing device on slave split.
//#define SPLIT_POINTING_ENABLE

// Pointing device is on the right split.
//#define POINTING_DEVICE_RIGHT

// Limits the frequency that the sensor is polled for motion.
#define POINTING_DEVICE_TASK_THROTTLE_MS 1

// Invert X axis on mouse reports.
#define POINTING_DEVICE_INVERT_X

/* RGB matrix support. */
#ifdef RGB_MATRIX_ENABLE
#    define SPLIT_TRANSPORT_MIRROR
#    define RGB_MATRIX_MAXIMUM_BRIGHTNESS 255
#    define RGB_DISABLE_WHEN_USB_SUSPENDED
#    define RGB_MATRIX_KEYPRESSES

// Startup values.
#    define RGB_MATRIX_DEFAULT_HUE 0
#    define RGB_MATRIX_DEFAULT_SAT 255
#    define RGB_MATRIX_DEFAULT_VAL 64

// Rainbow swirl as startup mode.
#    define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#    define RGB_MATRIX_DEFAULT_MODE RGB_MATRIX_CYCLE_LEFT_RIGHT

// Slow swirl at startup.
#    define RGB_MATRIX_DEFAULT_SPD 32

#    ifndef __arm__
// Disable control of RGB matrix by keycodes (must use firmware implementation
// to control the feature).
#        define RGB_MATRIX_DISABLE_KEYCODES
#    else // __arm__
// Enable all animations on ARM boards since they have plenty of memory
// available for it.
#        define ENABLE_RGB_MATRIX_ALPHAS_MODS
#        define ENABLE_RGB_MATRIX_GRADIENT_UP_DOWN
#        define ENABLE_RGB_MATRIX_GRADIENT_LEFT_RIGHT
#        define ENABLE_RGB_MATRIX_BREATHING
#        define ENABLE_RGB_MATRIX_BAND_SAT
#        define ENABLE_RGB_MATRIX_BAND_VAL
#        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_SAT
#        define ENABLE_RGB_MATRIX_BAND_PINWHEEL_VAL
#        define ENABLE_RGB_MATRIX_BAND_SPIRAL_SAT
#        define ENABLE_RGB_MATRIX_BAND_SPIRAL_VAL
#        define ENABLE_RGB_MATRIX_CYCLE_ALL
#        define ENABLE_RGB_MATRIX_CYCLE_LEFT_RIGHT
#        define ENABLE_RGB_MATRIX_CYCLE_UP_DOWN
#        define ENABLE_RGB_MATRIX_RAINBOW_MOVING_CHEVRON
#        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN
#        define ENABLE_RGB_MATRIX_CYCLE_OUT_IN_DUAL
#        define ENABLE_RGB_MATRIX_CYCLE_PINWHEEL
#        define ENABLE_RGB_MATRIX_CYCLE_SPIRAL
#        define ENABLE_RGB_MATRIX_DUAL_BEACON
#        define ENABLE_RGB_MATRIX_RAINBOW_BEACON
#        define ENABLE_RGB_MATRIX_RAINBOW_PINWHEELS
#        define ENABLE_RGB_MATRIX_RAINDROPS
#        define ENABLE_RGB_MATRIX_JELLYBEAN_RAINDROPS
#        define ENABLE_RGB_MATRIX_HUE_BREATHING
#        define ENABLE_RGB_MATRIX_HUE_PENDULUM
#        define ENABLE_RGB_MATRIX_HUE_WAVE
#        define ENABLE_RGB_MATRIX_TYPING_HEATMAP
#        define ENABLE_RGB_MATRIX_DIGITAL_RAIN
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_SIMPLE
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_WIDE
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTIWIDE
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_CROSS
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTICROSS
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_NEXUS
#        define ENABLE_RGB_MATRIX_SOLID_REACTIVE_MULTINEXUS
#        define ENABLE_RGB_MATRIX_SPLASH
#        define ENABLE_RGB_MATRIX_MULTISPLASH
#        define ENABLE_RGB_MATRIX_SOLID_SPLASH
#        define ENABLE_RGB_MATRIX_SOLID_MULTISPLASH
#    endif // !__arm__
#endif

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


#include "charybdis.h"
