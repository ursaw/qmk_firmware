/**
 * Copyright 2021 Charly Delay <charly@codesink.dev> (@0xcharly)
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */
#include QMK_KEYBOARD_H

/*      qmk compile -kb bastardkb/charybdis/4x6/v2/elitec -km ursaw
 *
 */

/* https://getreuer.info/posts/keyboards/select-word/index.html */
#include "select_word.h"



enum charybdis_keymap_layers {
    _QWERTY = 0,
    _LOWER,
    _RAISE,
};

enum custom_keycodes {
    SELWORD  = SAFE_RANGE
};


#define LOWER   MO(_LOWER)
#define RAISE   MO(_RAISE)
#define SPC_RSE LT(_RAISE, KC_SPC)

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT_charybdis_4x6(
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
   KC_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
   KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
   KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LCTRL, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                                RAISE  , KC_ENT, LOWER ,     RAISE , SPC_RSE,
                                                         KC_LALT, KC_LGUI,   KC_RALT
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
  //                                 KC_LGUI, KC_SPC,   LOWER,      RAISE,  KC_ENT,
  //                                         KC_LALT, KC_BSPC,     KC_DEL
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_LOWER] = LAYOUT_charybdis_4x6(

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
   */
   XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                               XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                 XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                                _______, _______, _______,      _______, _______,
                                                         _______, _______,      _______

  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  //     KC_TILD, KC_EXLM,   KC_AT, KC_HASH,  KC_DLR, KC_PERC,    KC_CIRC, KC_AMPR, KC_ASTR, KC_LPRN, KC_RPRN, KC_UNDS,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //     RGB_MOD, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    KC_LBRC,   KC_P7,   KC_P8,   KC_P9, KC_RBRC, XXXXXXX,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //     RGB_TOG, KC_LGUI, KC_LALT, KC_LCTL, KC_LSFT, XXXXXXX,    KC_PPLS,   KC_P4,   KC_P5,   KC_P6, KC_PMNS, KC_PEQL,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //    RGB_RMOD, XXXXXXX, XXXXXXX, XXXXXXX, EEP_RST, QK_BOOT,    KC_PAST,   KC_P1,   KC_P2,   KC_P3, KC_PSLS, KC_PDOT,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
  //                                XXXXXXX, XXXXXXX, _______,    XXXXXXX, _______,
  //                                         XXXXXXX, XXXXXXX,      KC_P0
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),

  [_RAISE] = LAYOUT_charybdis_4x6(
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
   */
  // ╭──────────────────────────────────────────────────────╮ ╭──────────────────────────────────────────────────────╮
  //      KC_F12,   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,      KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //     KC_MNXT, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLU,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //     KC_MPLY, KC_LEFT,   KC_UP, KC_DOWN, KC_RGHT, XXXXXXX,    XXXXXXX, KC_RSFT, KC_RCTL, KC_RALT, KC_RGUI, KC_MUTE,
  // ├──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────┤
  //     KC_MPRV, KC_HOME, KC_PGUP, KC_PGDN,  KC_END, XXXXXXX,    QK_BOOT, EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, KC_VOLD,
  // ╰──────────────────────────────────────────────────────┤ ├──────────────────────────────────────────────────────╯
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11  ,
   _______, SELWORD, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F12  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_EQUAL,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_DEL , KC_BSPC, KC_LBRC, KC_RBRC, KC_BSLASH, _______,
                                  _______, _______, KC_SPC,    KC_MS_BTN1, KC_MS_BTN1,
                                           _______, _______,    _______
  //                            ╰───────────────────────────╯ ╰──────────────────╯
  ),
};


// clang-format on
bool process_record_user(uint16_t keycode, keyrecord_t* record) {
    // Your macros ...

    // for select word
    if (!process_select_word(keycode, record, SELWORD)) { return false; }

    return true;
}
