// Copyright 2023 Severin Meyer (@sevmeyer)
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H



enum ik_layers {
   _BASE1,
   _BASE2,
   _RAISE,
   _LOWER
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_BASE1] = LAYOUT(
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_BSPC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        MO(_RAISE),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
        KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  KC_ENT,  KC_BSPC, KC_SPC,  KC_RALT, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
   [_BASE2] = LAYOUT(   //   default  chrumm  layout
        KC_ESC,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC,
        MO(_RAISE),   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_BSLS,
        KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_UP,   KC_RSFT,
        KC_LCTL, XXXXXXX, KC_LGUI, KC_LALT, KC_SPC,  KC_ENT,  KC_BSPC, KC_SPC,  KC_RALT, KC_DEL,  KC_LEFT, KC_DOWN, KC_RIGHT
    ),
    [_RAISE] = LAYOUT(
        KC_GRV,  KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_P7,   KC_P8,   KC_P9,   KC_PMNS, KC_BSPC, KC_ESC,
        KC_CAPS, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_P4,   KC_P5,   KC_P6,   KC_PPLS, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, KC_MSTP, XXXXXXX, KC_P1,   KC_P2,   KC_P3,   KC_PSLS, XXXXXXX, XXXXXXX,
        _______, XXXXXXX, KC_MRWD, KC_CALC, KC_MFFD, KC_MUTE, KC_NUM,  KC_P0,   KC_PDOT, KC_PENT, KC_PAST, KC_PGUP, _______,
        _______, XXXXXXX, _______, _______, _______, _______, _______, _______, _______, KC_INS,  KC_HOME, KC_PGDN, KC_END
    )
};


#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [0] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU) },
    [1] = { ENCODER_CCW_CW(_______, _______) }
};
#endif

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    //  https://getreuer.info/posts/keyboards/macros3/index.html#shift-backspace-delete
    case KC_BSPC: {
      static uint16_t registered_key = KC_NO;
      if (record->event.pressed) {  // On key press.
        const uint8_t mods = get_mods();
#ifndef NO_ACTION_ONESHOT
        uint8_t shift_mods = (mods | get_oneshot_mods()) & MOD_MASK_SHIFT;
#else
        uint8_t shift_mods = mods & MOD_MASK_SHIFT;
#endif  // NO_ACTION_ONESHOT
        if (shift_mods) {  // At least one shift key is held.
          registered_key = KC_DEL;
          // If one shift is held, clear it from the mods. But if both
          // shifts are held, leave as is to send Shift + Del.
          if (shift_mods != MOD_MASK_SHIFT) {
#ifndef NO_ACTION_ONESHOT
            del_oneshot_mods(MOD_MASK_SHIFT);
#endif  // NO_ACTION_ONESHOT
            unregister_mods(MOD_MASK_SHIFT);
          }
        } else {
          registered_key = KC_BSPC;
        }

        register_code(registered_key);
        set_mods(mods);
      } else {  // On key release.
        unregister_code(registered_key);
      }
    } return false; 
    } // end switch case
    return true;
};
