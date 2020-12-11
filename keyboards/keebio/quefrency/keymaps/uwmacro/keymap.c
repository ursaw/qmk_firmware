#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.


// //  make  keebio/quefrency/rev2:uwmacro
// qmk config user.keyboard=keebio/quefrency/rev2
// qmk config user.keymap=uwmacro

#define _BASE 0
#define _FN1 1

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_BASE] = LAYOUT_65(
    KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_F1,    KC_F1, KC_F1,   KC_F1,  KC_F1, KC_HOME, \
    KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_NO,    KC_END,             KC_RIGHT,  KC_NO, RCS(KC_F5), KC_NO,   \
    KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_UP,                      KC_DOWN, KC_NO,  KC_F5, \
    KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_HOME, KC_LEFT,                    KC_NO, KC_NO,   KC_F10, \
    KC_LCTL, KC_LALT, KC_LGUI, MO(_FN1),KC_SPC,           MO(_FN1),KC_SPC,  KC_PGUP, KC_PGDN,  KC_NO  ,                   KC_LGUI,   KC_F11,  LSFT(KC_F11)
  ),

  [_FN1] = LAYOUT_65(
    KC_GESC, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_DEL,  KC_BSPC, _______, \
    RGB_TOG, RGB_MOD, _______, KC_UP,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
    KC_TILD, _______, _______, _______, _______,          _______, _______, _______, _______, _______, _______, _______, _______
  )
};

void encoder_update_user(uint8_t index, bool clockwise) {
   // if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
  //  }
  //  else if (index == 1) {
  //      if (clockwise) {
  //          tap_code(KC_VOLU);
  //      } else {
  //          tap_code(KC_VOLD);
  //      }
  //  }
}
