#include QMK_KEYBOARD_H

#define RGB_OFF 0x00, 0x00, 0x00

enum keyboard_layers {
  _BL = 0, // Base Layer
  _FK  ,   // Function Keys
  _FL  ,   // Function Layer
  _ML      // Mouse Layer
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
   /* Keymap: (Base Layer) Default Layer
   * ,-----------------------------------------------------------.
   * |Esc~| 1|  2|  3|  4|  5|  6|  7|  8|  9|  0|  -|  =|  \| MO|
   * |-----------------------------------------------------------|
   * |Tab  |  Q|  W|  E|  R|  T|  Y|  U|  I|  O|  P|  [|  ]|BCKSP|
   * |-----------------------------------------------------------|
   * |   MO  |  A|  S|  D|  F|  G|  H|  J|  K|  L|  ;|  '|Return |
   * |-----------------------------------------------------------|
   * |Shift   |  Z|  X|  C|  V|  B|  N|  M|  ,|  .|  /|Shift | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |Alt  | LE| DN|RE/CTR|
   * ,-----------------------------------------------------------.
   */
	[_BL] = LAYOUT(
		KC_GESC, KC_1,   KC_2 , KC_3, KC_4, KC_5, KC_6, KC_7, KC_8, KC_9, KC_0, KC_MINS, KC_EQL, KC_BSLS ,MO(_FK) ,
		KC_TAB, KC_Q, KC_W, KC_E, KC_R, KC_T, KC_Y, KC_U, KC_I, KC_O, KC_P, KC_LBRC, KC_RBRC,KC_BSPC ,
		MO(_FL), KC_A, KC_S, KC_D, KC_F, KC_G, KC_H, KC_J, KC_K, KC_L, LT(_ML,KC_SCLN), KC_QUOT, KC_ENT,
		KC_LSFT, KC_NO, KC_Z, KC_X, KC_C, KC_V, KC_B, KC_N, KC_M, KC_COMM, KC_DOT, KC_SLSH, RSFT_T(KC_UP), MO(_FL),
		KC_LCTL, KC_LGUI, KC_LALT, KC_SPC, KC_SPC, KC_SPC, KC_RALT, /*RGUI_T(*/KC_LEFT, KC_NO, KC_DOWN , RCTL_T(KC_RIGHT)
        ),

    // no idea yet on which key to put TG(_FK) - toggles layer, activating it if it’s inactive and vice versa
    [_FK] = LAYOUT(
		KC_ESC, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ ,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
        ),

   /* Keymap: (Functional Layer)
   * ,-----------------------------------------------------------.
   * |Esc~|F1| F2| F3| F4| F5| F6| F7| F8| F9|F10|F11|F12|INS| MO|
   * |-----------------------------------------------------------|
   * | CAPS|   | UP|   |   |   |   |   |   |   |PLY|PRV|NXT| DEL |
   * |-----------------------------------------------------------|
   * |   MO  | LE| DN| RE|   |   | LE| DN| UP| RE|   |   |Return |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |   |MUT|MUP|MDN|  \|  PUP | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |ALT| HOME |PDN |END |
   * ,-----------------------------------------------------------.
   */

	[_FL] = LAYOUT(
		KC_GRV, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5, KC_F6, KC_F7, KC_F8, KC_F9, KC_F10, KC_F11, KC_F12, KC_INS, _______,
		KC_CAPS, XXXXXXX, KC_UP,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MPLY, KC_MPRV, KC_MNXT, KC_DEL ,
		            /* WASD for cursor */                        /*  VI for cursor  */
        _______, KC_LEFT, KC_DOWN, KC_RIGHT,XXXXXXX, XXXXXXX, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT, _______, _______, _______,
		_______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, KC_BSLS, KC_PGUP, _______,
		_______, _______, _______, _______, _______, _______, _______, KC_HOME, _______,            KC_PGDOWN, KC_END
        ),
   /* Keymap: (Mouse Layer) incl Macros TODO
   * ,-----------------------------------------------------------.
   * |Esc~|M1| M2| M3| M4| M5| M6| M7| M8| M9|M10|<F>11|F12| |RST|
   * |-----------------------------------------------------------|
   * |     |  L| UP|  R|   |   |   |   |   |   |PLY|PRV|NXT| DEL |
   * |-----------------------------------------------------------|
   * |   MO  | LE| DN| RE|   |   | LE| DN| UP| RE|   |   |Return |
   * |-----------------------------------------------------------|
   * |Shift   |   |   |   |   |   |   |MUT|MUP|MDN|  \|  PUP | MO|
   * |-----------------------------------------------------------|
   * |Ctrl|Gui |Alt |      Space            |ALT| HOME |PDN |END |
   * ,-----------------------------------------------------------.
   */
	[_ML] = LAYOUT(    // Mouse and macro
		KC_TRNS, M(1), M(2), M(3), M(4), M(5), M(6), M(7), M(8), M(9), M(10), M(11), M(12), KC_TRNS, RESET,
		XXXXXXX,            KC_MS_BTN1,  KC_MS_UP,     KC_MS_BTN2,   XXXXXXX, RGB_TOG, RGB_MOD, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, _______, RGB_VAD, RGB_MODE_PLAIN,
		_______,            KC_MS_LEFT, KC_MS_DOWN,   KC_MS_RIGHT,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, _______,
		XXXXXXX, XXXXXXX, KC_MS_ACCEL0, KC_MS_ACCEL1, KC_MS_ACCEL2,  XXXXXXX, BL_DEC,  BL_TOGG, BL_INC,  BL_STEP, XXXXXXX, XXXXXXX, _______, _______,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),
};

/*
 *   R G B   N U M B E R s
 *
 *   [USB]
 *   0   1   2   3   4   5   6   7
 *
 *   8   9  11  12  13  14  15  16
 *
 */



// =================== Back lightening

// Light LEDs 6 to 9 and 12 to 15 red when caps lock is active. Hard to ignore!
const rgblight_segment_t PROGMEM my_capslock_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 3, HSV_RED},       // Light 4 LEDs, starting with LED 6
    { 3,10, RGB_OFF},
    {13, 3, HSV_RED}       // Light 4 LEDs, starting with LED 12

 );
// Light LEDs 9 & 10 in cyan when keyboard layer 1 is active
const rgblight_segment_t PROGMEM my_layer1_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 2, RGB_ORANGE},
    { 2, 2, RGB_OFF},
    { 4, 8, RGB_YELLOW},
    { 8, 4, RGB_OFF}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer2_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 2, HSV_GREEN},
    { 2, 4, RGB_OFF},
    { 6, 4, HSV_GREEN},
    {10, 4, RGB_OFF},
    {14, 2, HSV_GREEN}
);
// Light LEDs 11 & 12 in purple when keyboard layer 2 is active
const rgblight_segment_t PROGMEM my_layer3_layer[] = RGBLIGHT_LAYER_SEGMENTS(
    { 0, 2, HSV_BLUE},
    { 2, 4, RGB_OFF},
    { 6, 4, HSV_BLUE},
    {10, 4, RGB_OFF},
    {14, 2, HSV_BLUE}
);
// Now define the array of layers. Later layers take precedence
const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(
    my_capslock_layer,
    my_layer1_layer,    // Overrides caps lock layer
    my_layer2_layer,    // Overrides caps lock layer
    my_layer3_layer     // Overrides other layers
);
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;
}
layer_state_t layer_state_set_user(layer_state_t state) {
    // Both layers will light up if both kb layers are active
    rgblight_set_layer_state(1, layer_state_cmp(state, 1));
    rgblight_set_layer_state(2, layer_state_cmp(state, 2));
    rgblight_set_layer_state(3, layer_state_cmp(state, 3));
    return state;
}

bool led_update_user(led_t led_state) {

    rgblight_set_layer_state(0, led_state.caps_lock);
    return true;
}
