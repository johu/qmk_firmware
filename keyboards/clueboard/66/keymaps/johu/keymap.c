#include "66.h"

#define _BL 0
#define _FL 1
#define _ML 2
#define _CL 3

// Tap dance defines
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define KC_SPFN     LT(_FL, KC_SPC)             // Tap for space, hold for function layer (aka SpaceFN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  /* Layer 0: Base Layer (Default Layer)
   */
[_BL] = KEYMAP(
  KC_GESC,  KC_1,    KC_2,    KC_3,   KC_4,  KC_5,   KC_6,  KC_7,   KC_8,   KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSLS,  KC_GRV,          KC_PGUP, \
  HPR_TAB,  KC_Q,    KC_W,    KC_E,   KC_R,  KC_T,   KC_Y,  KC_U,   KC_I,   KC_O,    KC_P,     KC_LBRC,  KC_RBRC,  KC_BSPC,                   KC_PGDN, \
  CTL_ESC,  KC_A,    KC_S,    KC_D,   KC_F,  KC_G,   KC_H,  KC_J,   KC_K,   KC_L,    KC_SCLN,  KC_QUOT,  XXXXXXX,  KC_ENT,                             \
  KC_LSFT,  XXXXXXX, KC_Z,    KC_X,   KC_C,  KC_V,   KC_B,  KC_N,   KC_M,   KC_COMM, KC_DOT,   KC_SLSH,  KC_RO,    SFT_ENT,          KC_UP,            \
  MO(_ML),  KC_LGUI, KC_LALT, XXXXXXX,          KC_SPFN,KC_SPFN,                     XXXXXXX,  KC_RALT,  KC_RGUI,  KC_LCTL, KC_LEFT, KC_DOWN, KC_RGHT),

  /* Layer 1: Function Layer
   */
[_FL] = LAYOUT(
  KC_GRV,  KC_F1,   KC_F2,  KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,   KC_F10,   KC_F11,   KC_F12,   _______, KC_DEL,           KC_HOME, \
  _______, _______, _______,_______,_______,_______,_______,KC_PGUP,_______,  KC_PGDN, KC_PSCR,  KC_SLCK,  KC_PAUS,  KC_DEL,                    KC_END,  \
  _______, _______, MO(_CL),_______,_______,_______,KC_LEFT,KC_DOWN, KC_UP , KC_RGHT, KC_INS,   KC_DEL,   _______,  _______,                            \
  _______, _______, _______,_______,_______,_______,KC_HOME,KC_END, _______,_______, _______,  _______,  _______,  KC_CAPS,          KC_PGUP,          \
  MO(_ML), _______, _______, _______,        _______,_______,                        _______,  _______,  _______,  _______, KC_INS,  KC_PGDN, KC_DEL),

  /* Layer 2: Media layer
   */
[_ML] = LAYOUT(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______, KC_MUTE,          KC_VOLU, \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   KC_VOLD, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  KC_MSEL,                            \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,          KC_MSTP,          \
  MO(_ML), _______, _______,_______,         _______,_______,                        _______,  _______,  _______,  _______, KC_MPRV, KC_MPLY, KC_MNXT),

  /* Layer 3: Control layer
   */
[_CL] = LAYOUT(
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  BL_STEP, RGB_TOG,          RGB_VAI, \
  _______, _______, _______,_______,RESET,  _______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                   RGB_VAD, \
  _______, _______, MO(_CL),_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,                            \
  _______, _______, _______,_______,_______,_______,_______,_______,_______,_______, _______,  _______,  _______,  _______,          RGB_SAI,          \
  MO(_ML), _______, _______,_______,        RGB_MOD,   RGB_MOD,                      _______,  _______,  _______,  _______, RGB_HUD, RGB_SAD, RGB_HUI),
};
