
#pragma once

#include QMK_KEYBOARD_H

bool process_latex_greek(uint16_t keycode, keyrecord_t* record,
                         uint16_t sel_keycode);

enum { TEX_XXX=SAFE_RANGE, TEX_A,  TEX_B,  TEX_C,  TEX_D,  TEX_E,  TEX_F,  TEX_G,  TEX_I,  TEX_K,
         TEX_L,  TEX_M,  TEX_N,  TEX_O,  TEX_P,  TEX_S,  TEX_T,  TEX_V,  TEX_X,  TEX_Z
     };
