# This file intentionally left blank

# RP2040-specific options
ALLOW_WARNINGS = yes
PICO_INTRINSICS_ENABLED = no # ATM Unsupported by ChibiOS.

# Build Options
#   change yes to no to disable
#
#JSON BOOTMAGIC_ENABLE = yes      # Enable Bootmagic Lite
#JSON MOUSEKEY_ENABLE = no        # Mouse keys
#JSON EXTRAKEY_ENABLE = yes       # Audio control and System control
#JSON CONSOLE_ENABLE = no         # Console for debug
#JSON COMMAND_ENABLE = no         # Commands for debug and configuration
#JSON NKRO_ENABLE = no            # Enable N-Key Rollover
BACKLIGHT_ENABLE = no       # Enable keyboard backlight functionality
RGBLIGHT_ENABLE = no        # Enable keyboard RGB underglow
AUDIO_ENABLE = no           # Audio output

AUDIO_SUPPORTED = no        # Audio is not supported
RGB_MATRIX_SUPPORTED = no  # RGB matrix is supported and enabled by default
RGBLIGHT_SUPPORTED = no    # RGB underglow is supported, but not enabled by default
RGB_MATRIX_ENABLE = no     # Enable keyboard RGB matrix functionality
RGB_MATRIX_DRIVER = WS2812

SPLIT_KEYBOARD = no

POINTING_DEVICE_ENABLE = yes # Enable trackball
POINTING_DEVICE_DRIVER = pmw3360

SERIAL_DRIVER = vendor
WS2812_DRIVER = vendor
