// Copyright 2023 QMK
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

/* https://getreuer.info/posts/keyboards/select-word/index.html */
// #include "select_word.h"


enum layer_names {
  _QWERTY,
  _RAISE,
  _LOWER,
  _ADJUST
};

#define RAISE   MO(_RAISE)
#define LOWER   MO(_LOWER)
#define SH_ENL  LSFT_T(KC_ENT)
#define SH_ENR  RSFT_T(KC_ENT)
#define SH_SPC  RSFT_T(KC_SPC)


enum custom_keycodes {
    SELWORD  = SAFE_RANGE
};
 

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* Qwerty
 * +-----------------------------------------+      +-----------------------------------------+
 * | ESC  |   1  |   2  |   3  |   4  |   5  |      |   6  |   7  |   8  |   9  |   0  | Bksp |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |      |   Y  |   U  |   I  |   O  |   P  | Del  |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | Shift|   A  |   S  |   D  |   F  |   G  |      |   H  |   J  |   K  |   L  |   ;  |  "   |
 * |------+------+------+------+------+------|      |------+------+------+------+------+------|
 * | CNTRL|   Z  |   X  |   C  |   V  |   B  |      |   N  |   M  |   ,  |   .  |   /  |Shift |
 * +-------------+------+------+------+------|      |------+------+------+------+-------------+
 *   TODO            |Lower | SPC  | Alt  | GUI  |      | Alt  | GUI  | SPC  |Raise |
 *               +---------------------------+      +---------------------------+
     */
    [_QWERTY] = LAYOUT_ortho_5x12(
   QK_GESC , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   ,                                     KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_DEL,
   KC_TAB  , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   ,                                     KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSPC,
   KC_LSFT , KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                                     KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
   KC_LCTL , KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   ,                                     KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
                                      RAISE  , KC_ENT, SH_ENL ,      KC_NO, KC_NO,      SH_SPC , KC_SPC, RAISE  ,
                                               KC_LALT, KC_LGUI,                       LOWER , KC_RALT    ),

   [_RAISE] = LAYOUT_ortho_5x12(
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
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                          KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  , KC_F11  ,
   _______, _______, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                          KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F12  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                          KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_EQUAL,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                          KC_DEL , KC_BSPC, KC_LBRC, KC_RBRC, KC_BSLS , _______,
                                         _______, _______, KC_SPC,   _______, _______,     KC_ENT , _______, _______,
                                                  _______, _______,                                 _______, _______
   ),
  [_LOWER] = LAYOUT_ortho_5x12(
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
   XXXXXXX, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                                 DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, XXXXXXX, XXXXXXX,
   _______, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                                 DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   XXXXXXX ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                                                XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                                  XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                         _______, _______, _______,   _______, _______,     _______ , _______, _______,
                                                  _______, _______,                                   _______, _______   )


};
