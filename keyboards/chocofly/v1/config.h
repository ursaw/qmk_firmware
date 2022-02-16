#pragma once

#define VENDOR_ID       0x0001
#define PRODUCT_ID      0x0003
#define DEVICE_VER      0x0003
#define MANUFACTURER    vitvlkv
#define PRODUCT         Chocofly
#define DESCRIPTION     QMK keyboard firmware for Chocofly

#define MATRIX_ROWS 8
#define MATRIX_COLS 8

#define MATRIX_ROW_PINS { D1, D0, D4, C6, D7, E6, B4, B5 }
#define MATRIX_COL_PINS { F4, F5, F6, F7, B1, B3, B2, B6 }

#define DIODE_DIRECTION COL2ROW

#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }
#define ENCODER_RESOLUTION 2