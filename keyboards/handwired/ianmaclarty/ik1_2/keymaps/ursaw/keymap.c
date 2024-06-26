#include QMK_KEYBOARD_H

//
//   util/docker_build.sh  handwired/ianmaclarty/ik1_2:ursaw
//
// https://forum.colemak.com/topic/1858-learn-colemak-in-steps-with-the-tarmak-layouts/

//  todo otionally add a enum  SAFE_RANGE

enum ik_layers {
   _BASE1,
   _BASE2,
   _RAISE,
   _LOWER,
   _MOUSE,
   _TARMAK1,
   _TARMAK2,
   _TARMAK3,
   _LBSEL,
   _LATEX
};


enum custom_keycodes {
  TEX_A = SAFE_RANGE,
  TEX_B,
  TEX_C,
  TEX_D,
  TEX_E,
  TEX_F,
  TEX_G,
  TEX_I,
  TEX_K,
  TEX_L,
  TEX_M,
  TEX_N,
  TEX_O,
  TEX_P,
  TEX_S,
  TEX_T,
  TEX_V,
  TEX_X,
  TEX_Z
};

// ---------------- C O M B O S  -------------

//  enum combos {
//    QW_ESC,// = SAFE_RANGE,
//    OPI_DEL,
//    JK_TAB,
//    AB_SFT,
//  //  SD_LAYER
//  };
// const uint16_t PROGMEM ab_combo[] = {KC_A, KC_B, COMBO_END};
// const uint16_t PROGMEM opi_combo[] = {KC_I, KC_O, KC_P, COMBO_END};
// const uint16_t PROGMEM jk_combo[] = {KC_J, KC_K, COMBO_END};
// const uint16_t PROGMEM qw_combo[] = {KC_Q, KC_W, COMBO_END};
// // const uint16_t PROGMEM sd_combo[] = {KC_S, KC_D, COMBO_END};
//
// combo_t key_combos[] = {
//   [QW_ESC]  = COMBO(qw_combo, KC_ESC),
//   [OPI_DEL] = COMBO(opi_combo, KC_DEL),
//   [JK_TAB]  = COMBO(jk_combo, KC_TAB),
//   [AB_SFT]  = COMBO(qw_combo, KC_LSFT),
// //  [SD_LAYER] = COMBO(sd_combo, MO(_LAYER)),
// };
const uint16_t PROGMEM combo_qw[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM combo_kl[] = {KC_K, KC_L, COMBO_END};
const uint16_t PROGMEM combo_iop[] = {KC_I, KC_O, KC_P, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_qw,  KC_ESC),
    COMBO(combo_kl,  KC_ENT),
    COMBO(combo_iop, KC_DEL),
};
// optional ideas to switch layers
// #define TABNUM LT(LNUM, KC_TAB)
// #define ENTNAV LT(LNAV, KC_ENT)
// #define BSNAV LT(LNAV, KC_BSPC)
// #define NAV MO(LNAV)

#define BSSFT MT(MOD_RSFT,KC_BSPC)

#define BASE1 DF(_BASE1)
#define BASE2 DF(_BASE2)
#define BSEL  MO(_LBSEL)

#define LMSE5  LT(_MOUSE, KC_5)


#define SPC_RSE  LT(_RAISE, KC_SPC)
#define SPC_BS2  LT(_BASE2, KC_SPC)
#define ENT_RSE  LT(_RAISE, KC_ENT)
#define ENT_LWR  LT(_LOWER, KC_ENT)
#define SPC_LWR  LT(_LOWER, KC_SPC)

#define QOT_TEX  LT(_LATEX, KC_QUOT)



const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[_BASE1] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       LMSE5,                             KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2, SPC_RSE,    KC_RALT
),

[_BASE2] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
QK_GESC,    KC_Q,       KC_W,       KC_E,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_DEL,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_J,       KC_K,       KC_L,       KC_SCLN,    QOT_TEX,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                 KC_LGUI,    ENT_RSE, MO(_LOWER),     SPC_BS2, SPC_RSE,    KC_RALT
),


//   https://forum.colemak.com/topic/1858-learn-colemak-in-steps-with-the-tarmak-layouts/
[_TARMAK1] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_J,       KC_R,       KC_T,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_F,       KC_G,                              KC_H,       KC_N,       KC_E,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_K,       KC_M,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2, SPC_RSE,    KC_RALT
),
[_TARMAK2] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_R,       KC_G,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_S,       KC_D,       KC_T,       KC_J,                              KC_H,       KC_N,       KC_E,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_K,       KC_MINUS,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2, SPC_RSE,    KC_RALT
),
[_TARMAK3] = LAYOUT_split_4x6_3(
_______,    KC_1,       KC_2,       KC_3,       KC_4,       KC_5,                              KC_6,       KC_7,       KC_8,       KC_9,       KC_0,       _______,
KC_TAB,     KC_Q,       KC_W,       KC_F,       KC_R,       KC_G,                              KC_Y,       KC_U,       KC_I,       KC_O,       KC_P,       KC_BSPC,
KC_LSFT,    KC_A,       KC_R,       KC_S,       KC_T,       KC_D,                              KC_H,       KC_N,       KC_E,       KC_L,       KC_SCLN,    KC_QUOT,
KC_LCTL,    KC_Z,       KC_X,       KC_C,       KC_V,       KC_B,                              KC_N,       KC_K,       KC_COMM,    KC_DOT,     KC_SLSH,    KC_RSFT,
                                                KC_LALT,    ENT_RSE, ENT_LWR,        SPC_BS2, SPC_RSE,    KC_RALT
),

[_LATEX] = LAYOUT_split_4x6_3(
_______,    XXXXXXX,  XXXXXXX,  XXXXXXX,   XXXXXXX,     XXXXXXX,                            XXXXXXX,  XXXXXXX,  XXXXXXX,    XXXXXXX,  XXXXXXX,    _______,
KC_TAB,     XXXXXXX,  XXXXXXX,  TEX_E,     XXXXXXX,     TEX_T,                              XXXXXXX,  XXXXXXX,  TEX_I,      TEX_O,    TEX_P,      KC_BSPC,
KC_LSFT,    TEX_A,    TEX_S,    TEX_D,     TEX_F,       TEX_G,                              XXXXXXX,  XXXXXXX,  TEX_K,      TEX_L,    XXXXXXX,    KC_QUOT,
XXXXXXX,    TEX_Z,    TEX_X,    TEX_C,     TEX_V,       TEX_B,                              TEX_N,    TEX_M,    KC_COMM,    KC_DOT,   KC_SLSH,    KC_RSFT,
                                           XXXXXXX,     XXXXXXX,  XXXXXXX,         XXXXXXX,  XXXXXXX,  XXXXXXX
),

  /* RAISE
   *
   *        .----------------------------------.                                  .----------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |                                  |  F6  |  F7  |  F8  |  F9  |  F10 |
   * .------+------+------+------+------+------|                                  |------+------+------+------+------+------.
   * |      |  ESC |  {   |   }  |   +  |  `   |                                  |  PGUP| HOME |   UP |  END |      |  F11 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |   |  |  [   |   ]  |   -  |  =   |                                  |  PGDN|  LFT |  DWN |  RGT |  -   |  F12 |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |  UNDO|  GUI |  APP |  SPC |  _   |                                  |  DEL | BSPC |   [  |  ]   |   \  |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   */
[_RAISE] = LAYOUT_split_4x6_3(
   _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,_______   ,
   _______, QK_GESC, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_UP  , KC_END , KC_INS  , KC_F11  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_LEFT, KC_DOWN, KC_RGHT, KC_MINUS, KC_F12,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_BSPC,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, KC_BSLS, _______,
                                                  _______,    _______,    _______,    _______,    _______,    _______
),

  /* LOWER
   *        . ---------------------------------.                                  .----------------------------------.
   *        |      |   7  |   8  |   9  |  BS  |                                  |  Mr1 |  Mr2 | Mstp |      |      |
   * .------+------+------+------+------+------|                                  |------+------+------+------+------+------.
   * |  ESC |   *  |   4  |   5  |   6  |  +   |                                  |  M1  |  M2  |      |      |      |      |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |  TAB |   /  |   1  |   2  |   3  |  -   |                                  |      | STOP | PREV | NEXT |      | CAPS |
   * |------+------+------+------+------+------|                                  |------+------+------+------+------+------|
   * |      |      |   0  |   0  |   .  |  ENT |                                  |      | Mute |  V+  | V-   |      |      |
   * '-----------------------------------------/                                  \-----------------------------------------'
   */

[_LOWER] = LAYOUT_split_4x6_3(
   _______, XXXXXXX, KC_7  , KC_8  , KC_9  , KC_BSPC,                                DM_REC1, DM_REC1, DM_RSTP, XXXXXXX, BSEL   , XXXXXXX,
   QK_GESC, KC_PAST, KC_4  , KC_5  , KC_6  , KC_PLUS,                                DM_PLY1, DM_PLY2, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
   KC_TAB  ,KC_PSLS, KC_1  , KC_2  , KC_3  , KC_MINUS,                              XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, XXXXXXX, KC_CAPS,
   XXXXXXX, XXXXXXX, KC_0  , KC_0  ,KC_DOT , KC_ENT,                                XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, XXXXXXX, XXXXXXX,
                                                _______,    _______,    _______,    _______,    _______,    _______
),


// WIP
[_MOUSE] = LAYOUT_split_4x6_3(
 _______, KC_F1  , KC_F2  , KC_F3  , KC_F4   , KC_F5   ,                                 KC_F6  , KC_F7  , KC_F8  , KC_F9  , KC_F10  ,_______   ,
   _______, QK_GESC, KC_LCBR, KC_RCBR, KC_PLUS , KC_GRV  ,                                 KC_PGUP, KC_HOME, KC_MS_U	  , KC_END , KC_INS  , KC_F11  ,
   _______, KC_PIPE, KC_LBRC, KC_RBRC, KC_MINUS, KC_EQUAL,                                 KC_PGDN, KC_MS_L	, KC_MS_D	, KC_MS_R	, KC_MINUS, KC_F12,
   _______, KC_UNDO, KC_LGUI, KC_APP , KC_SPC  , KC_UNDS ,                                 KC_BSPC,KC_MS_BTN1,KC_MS_BTN3,KC_MS_BTN2, KC_BSLS, _______,
                                                _______,    _______,    _______,    KC_BTN1 ,    KC_BTN2,    KC_MS_BTN3
),

[_LBSEL] = LAYOUT_split_4x6_3(
_______,    DF(_TARMAK1),  DF(_TARMAK2), DF(_TARMAK3),    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    BASE1,      _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
_______,    _______,    _______,    _______,    _______,    _______,                            _______,    _______,    _______,    _______,    _______,    _______,
                                                _______,    _______,    _______,    _______,    _______,    _______
),

};


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
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Delta ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\delta ");}
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
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Lamda ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\lambda ");}
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
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Omega ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\omega ");}
            }
      return true;

   case TEX_P:
            if (record->event.pressed) {
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Pi ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\pi ");}
            }
      return true;

   case TEX_S:
            if (record->event.pressed) {
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Sigma ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\sigma ");}
            }
      return true;

   case TEX_T:
            if (record->event.pressed) {
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Theta ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\theata ");}
            }
      return true;

   case TEX_V:
            if (record->event.pressed) {
                SEND_STRING("\\varphi ");
            }
      return true;

   case TEX_X:
            if (record->event.pressed) {
                if( get_mods() & MOD_BIT(MOD_MASK_SHIFT) ) { clear_mods(); SEND_STRING("\\Xi ");add_mods(MOD_MASK_SHIFT);}
                else                                       { SEND_STRING("\\xi ");}
            }
      return true;

   case TEX_Z:
            if (record->event.pressed) {
                SEND_STRING("\\zeta ");
            }
      return true;

    }
    return true;
};
