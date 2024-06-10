

//enum {  TEX_A,  TEX_B,  TEX_C,  TEX_D,  TEX_E,  TEX_F,  TEX_G,  TEX_I,  TEX_K,
//         TEX_L,  TEX_M,  TEX_N,  TEX_O,  TEX_P,  TEX_S,  TEX_T,  TEX_V,  TEX_X,  TEX_Z
//     };


#include QMK_KEYBOARD_H
#include "latex_greek.h"


bool process_latex_greek(uint16_t keycode, keyrecord_t* record,
                         uint16_t sel_keycode) {
   switch (keycode) {

   case TEX_A:
            if (record->event.pressed) {
                SEND_STRING("\\alpha ");
            }
      return true;

   case TEX_B:
            if (record->event.pressed) {
                SEND_STRING("\\beta ");
            }
      return true;

   case TEX_C:
            if (record->event.pressed) {
                SEND_STRING("\\chi ");
            }
      return true;

   case TEX_D:
            if (record->event.pressed) {
                SEND_STRING("\\delta ");
            }
      return true;

   case TEX_E:
            if (record->event.pressed) {
                SEND_STRING("\\epsilon ");
            }
      return true;

   case TEX_F:
            if (record->event.pressed) {
                SEND_STRING("\\frac ");
            }
      return true;

   case TEX_G:
            if (record->event.pressed) {
                SEND_STRING("\\gamma ");
            }
      return true;

   case TEX_I:
            if (record->event.pressed) {
                SEND_STRING("\\iota ");
            }
      return true;

   case TEX_K:
            if (record->event.pressed) {
                SEND_STRING("\\kappa ");
            }
      return true;

   case TEX_L:
            if (record->event.pressed) {
                SEND_STRING("\\lambda ");
            }
      return true;

   case TEX_M:
            if (record->event.pressed) {
                SEND_STRING("\\mu ");
            }
      return true;

   case TEX_N:
            if (record->event.pressed) {
                SEND_STRING("\\nu ");
            }
      return true;

   case TEX_O:
            if (record->event.pressed) {
                SEND_STRING("\\omega ");
            }
      return true;

   case TEX_P:
            if (record->event.pressed) {
                SEND_STRING("\\pi ");
            }
      return true;

   case TEX_S:
            if (record->event.pressed) {
                SEND_STRING("\\sigma ");
            }
      return true;

   case TEX_T:
            if (record->event.pressed) {
                SEND_STRING("\\theata ");
            }
      return true;

   case TEX_V:
            if (record->event.pressed) {
                SEND_STRING("\\varphi ");
            }
      return true;

   case TEX_X:
            if (record->event.pressed) {
                SEND_STRING("\\xi ");
            }
      return true;

   case TEX_Z:
            if (record->event.pressed) {
                SEND_STRING("\\zeta ");
            }
      return true;
   }

   return false;
}
