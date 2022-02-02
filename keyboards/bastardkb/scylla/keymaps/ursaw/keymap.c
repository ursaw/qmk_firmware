// Copyright 2021 Christian Eiden, cykedev
//
// This program is free software: you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation, either version 2 of the License, or
// (at your option) any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program.  If not, see <http://www.gnu.org/licenses/>.


/*  qmk flash -bl dfu
 *
 *
 * TODO  https://github.com/filterpaper/qmk_userspace
 */

#include QMK_KEYBOARD_H

/* https://getreuer.info/posts/keyboards/caps-word/index.html */
#include "caps_word.h"
/* https://getreuer.info/posts/keyboards/select-word/index.html */
#include "select_word.h"


#define CM_SPAL  LGUI_T(KC_SPC)
#define CM_SPAR  RGUI_T(KC_SPC)

#define SH_ENL  LSFT_T(KC_ENT)
#define SH_ENR  RSFT_T(KC_ENT)
#define SH_SPC  RSFT_T(KC_SPC)


#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)

#define QWERT   DF(_QWERTY)
#define COLEM   DF(_COLEMAK_DH)

enum layer_names {
  _QWERTY,
  _COLEMAK_DH,
  _RAISE,
  _LOWER,
  _ADJUST
};

enum custom_keycodes {
    SELWORD  = SAFE_RANGE
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_split_4x6_5(
  /* QWERTY
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |                                  |   Y  |   U  |   I  |   O  |   P  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Del  |   A  |   S  |   D  |   F  |   G  |                                  |   H  |   J  |   K  |   L  |   ;  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   Z  |   X  |   C  |   V  |   B  |                                  |   N  |   M  |   ,  |   .  |   /  | Shft |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  / RAISE /---------------.    .---------------\ RAISE \
   *                                 /       /        / Shift /     \ Shift \       \       \
   *                                '-------/ Enter / Enter /        \ Enter \ Space \-------'
   *                                       /---------------/          \---------------\
   *                                      /  Alt  / LGUI  /            \ LOWER \  Alt  \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
   KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
   KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LCTRL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                                RAISE  , KC_ENT, SH_ENL , SH_SPC , KC_SPC, RAISE  ,
                                                         KC_LALT, KC_LGUI, LOWER , KC_RALT
   ),
  [_COLEMAK_DH] = LAYOUT_split_4x6_5(
  /* COLEMAK_DH
   * .-----------------------------------------.                                  .-----------------------------------------.
   * | Esc  |   1  |   2  |   3  |   4  |   5  |                                  |   6  |   7  |   8  |   9  |   0  |  Bsp |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   F  |   P  |   B  |                                  |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Del  |   A  |   R  |   S  |   T  |   G  |                                  |   M  |   N  |   E  |   I  |   O  |  '   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * | Shft |   Z  |   X  |   C  |   D  |   V  |                                  |   K  |   H  |   ,  |   .  |   /  | Shft |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  / RAISE /---------------.    .---------------\ RAISE \
   *                                 /       /        / Shift /     \ Shift \       \       \
   *                                '-------/ Enter / Enter /        \ Enter \ Space \-------'
   *                                       /---------------/          \---------------\
   *                                      /  Alt  / LGUI  /            \ LOWER \  Alt  \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   KC_GESC, KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
   KC_TAB , KC_Q   , KC_W   , KC_F   , KC_P   , KC_B   ,                                     KC_J   , KC_L   , KC_U   , KC_Y   , KC_SCLN, KC_BSLS,
   KC_DEL , KC_A   , KC_R   , KC_S   , KC_T   , KC_G   ,                                     KC_M   , KC_N   , KC_E   , KC_I   , KC_O   , KC_QUOT,
   KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_D   , KC_V   ,                                     KC_K   , KC_H   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                                RAISE  , KC_ENT, SH_ENL , SH_SPC , KC_SPC, RAISE  ,
                                                         KC_LALT, KC_LGUI, LOWER , KC_RALT
   ),


   [_RAISE] = LAYOUT_split_4x6_5(
  /* RAISE
   *
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  GUI |  {   |   }  |   +  |  `   |                                  |  PGUP| HOME |   UP |  END |      |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   |  |  [   |   ]  |   -  |  =   |                                  |  PGDN|  LFT |  DWN |  RGT |  -   |  =   |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  UNDO|  GUI |  APP |  SPC |  _   |                                  |  DEL | BSPC |   [  |  ]   |   \  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11  ,
   _______, SELWORD, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F12  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_EQUAL,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_DEL , KC_BSPC, KC_LBRC, KC_RBRC, KC_BSLASH, _______,
                                                _______, _______, KC_SPC,  KC_ENT , _______, _______,
                                                         _______, _______, _______, _______
   ),
  [_LOWER] = LAYOUT_split_4x6_5(
  /* LOWER
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |      |   7  |   8  |   9  |  BS  |                                  |  Mr1 |  Mr2 | Mstp |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |  TAB |   *  |   4  |   5  |   6  |   +  |                                  |  M1  |  M2  |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   /  |   1  |   2  |   3  |  -   |                                  |      | STOP | PREV | NEXT |      | CAPS |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |   0  |   0  |   .  |  ENT |                                  |      | Mute |  V+  | V-   |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                               XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                 XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                                _______, _______, _______, _______, _______, _______,
                                                         _______, _______, _______, _______
   ),
  [_ADJUST] = LAYOUT_split_4x6_5(
  /* ADJUST
   * .-----------------------------------------.                                  .-----------------------------------------.
   * |      |      |      |      |      | QWERT|                                  |COLEM |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |  V+  |                                  |  B + |      |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      |  V-  |                                  |  B - |  <<  | play |  >>  |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |      |      |      | Mute |                                  |      |      |      |      |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   *                                  /       /---------------.    .---------------\       \
   *                                 /       /       /       /      \       \       \       \
   *                                '-------/       /       /        \       \       \-------'
   *                                       /---------------/          \---------------\
   *                                      /       /       /            \       \       \
   *                                     /       /       /              \       \       \
   *                                    '---------------'                '---------------'
   */
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, QWERT  ,                                     COLEM  , XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,                                     KC_BRIU, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,                                     KC_BRID, KC_MRWD, KC_MPLY, KC_MFFD, XXXXXXX, XXXXXXX,
   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE,                                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                                                         XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
   )
};

bool get_ignore_mod_tap_interrupt(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case CM_SPAR:
      return true;
    default:
      return false;
  }
}

layer_state_t layer_state_set_user(layer_state_t state) {
  return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);
}

bool process_record_user(uint16_t keycode, keyrecord_t* record) {


    /* for select word */
    if (!process_select_word(keycode, record, SELWORD)) { return false; }
    /* for caps word */
    if (!process_caps_word(keycode, record)) { return false; }

  // Your macros ...

  return true;
}


// Flexible macOS-friendly Grave Escape
// https://docs.qmk.fm/#/feature_key_overrides?id=flexible-macos-friendly-grave-escape


