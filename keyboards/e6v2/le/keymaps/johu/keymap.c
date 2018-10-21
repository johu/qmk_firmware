#include QMK_KEYBOARD_H

#define _BL 0
#define _GL 1
#define _FL 2
#define _SL 3
#define _CL 4

// Tap dance defines
#define CTL_ESC     CTL_T(KC_ESC)               // Tap for Esc, hold for Ctrl
#define HPR_TAB     ALL_T(KC_TAB)               // Tap for Tab, hold for Hyper (Super+Ctrl+Shift+Alt)
#define SFT_ENT     SFT_T(KC_ENT)               // Tap for Enter, hold for Shift
#define KC_SPFN     LT(_SL, KC_SPC)             // Tap for space, hold for function layer (aka SpaceFN)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Layer 0: Base layer (Default layer)
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * |Tab/Hyper|  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl/Esc  |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter  |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift/Ent | FN  |
 * |-----------------------------------------------------------------------------------------+
 *           |LGUI | LAlt  |               Space                   | RAlt   | GL  |
 *           `--------------------------------------------------------------------'
 */
  [_BL] = LAYOUT_60_hhkb(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      HPR_TAB, KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      CTL_ESC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          SFT_ENT, MO(_FL),
               KC_LGUI, KC_LALT,                       KC_SPFN,                        KC_RALT, TG(_GL)
      ),

/* Layer 1: Game layer
 * ,-----------------------------------------------------------------------------------------.
 * | Esc |  1  |  2  |  3  |  4  |  5  |  6  |  7  |  8  |  9  |  0  |  -  |  =  |  \  |  `  |
 * |-----------------------------------------------------------------------------------------+
 * |   Tab   |  Q  |  W  |  E  |  R  |  T  |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  Bksp |
 * |-----------------------------------------------------------------------------------------+
 * | Ctrl      |  A  |  S  |  D  |  F  |  G  |  H  |  J  |  K  |  L  |  ;  |  '  |    Enter  |
 * |-----------------------------------------------------------------------------------------+
 * | Shift     |  Z  |  X  |  C  |  V  |  B  |  N  |  M  |  ,  |  .  |  /  | Shift     | FN  |
 * |-----------------------------------------------------------------------------------------+
 *           |     | LAlt  |               Space                   | RAlt   |     |
 *           `--------------------------------------------------------------------'
 */
  [_GL] = LAYOUT_60_hhkb(
      KC_GESC, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSLS, KC_GRV,
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSPC,
      KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,          KC_RSFT, MO(_FL),
               KC_NO,   KC_LALT,                       KC_SPC,                         KC_RALT, TG(_GL)
      ),

/* Layer 1: FN Layer
 * ,-----------------------------------------------------------------------------------------.
 * |  CL | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
 * |-----------------------------------------------------------------------------------------+
 * |        |     |     |     |     |     |     |     | Psc | Slck| Paus| Up  |     | Del    |
 * |-----------------------------------------------------------------------------------------+
 * |         | Vol-| Vol+| Mute|     |     | *   | /   | Home| PgUp| Left|Right|             |
 * |-----------------------------------------------------------------------------------------+
 * |           | Prev| Play| Next|     |     | +   | -   | End  |PgDn| Down|           |     |
 * |-----------------------------------------------------------------------------------------+
 *           |       |       |                                    | Stop  |  GL   |
 *           `--------------------------------------------------------------------'
 */
  [_FL] = LAYOUT_60_hhkb(
      TG(_CL),  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
       _______, _______, _______, _______, _______, _______, _______, _______, KC_PSCR, KC_SLCK, KC_PAUS, KC_UP,   _______, KC_DEL,
       _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_PAST, KC_PSLS, KC_HOME, KC_PGUP, KC_LEFT, KC_RGHT, _______,
       _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_PPLS, KC_PMNS, KC_END,  KC_PGDN, KC_DOWN,          _______, _______,
                _______, _______,                       _______,                        KC_MSTP, TG(_GL)
      ),

/* Layer 2: Space FN Layer
* ,-----------------------------------------------------------------------------------------.
* |  CL | F1  | F2  | F3  | F4  | F5  | F6  | F7  | F8  | F9  | F10 | F11 | F12 | Ins | Del |
* |-----------------------------------------------------------------------------------------+
* |        |     |     |     |     |     |     | PgUp|     | PgDn|     |     |     | Del    |
* |-----------------------------------------------------------------------------------------+
* |         | Vol-| Vol+| Mute|     |     | Left| Down| Up  |Right|     |     |             |
* |-----------------------------------------------------------------------------------------+
* |           | Prev| Play| Next|     |     | Home| End |     |     |     |           |     |
* |-----------------------------------------------------------------------------------------+
*            |       |       |                                    |       |  GL   |
*            `--------------------------------------------------------------------'
*/
  [_SL] = LAYOUT_60_hhkb(
      TG(_CL), KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_INS,  KC_DEL,
      _______, _______, _______, _______, _______, _______, _______, KC_PGUP, _______, KC_PGDN, _______, _______, _______, KC_DEL,
      _______, KC_VOLD, KC_VOLU, KC_MUTE, _______, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______, _______,
      _______, KC_MPRV, KC_MPLY, KC_MNXT, _______, _______, KC_HOME, KC_END,  _______, _______, _______,          _______, _______,
               _______, _______,                        _______,                       _______, TG(_GL)
      ),

/* Layer 3: Control Layer
 * ,-----------------------------------------------------------------------------------------.
 * |     |     |     |     |     |     |     |     |     |     |     |     |     |     |     |
 * |-----------------------------------------------------------------------------------------+
 * |        | BL- | BL+ | BL  |     |     |     |     |     |     |     |     |     | RESET  |
 * |-----------------------------------------------------------------------------------------+
 * |         | RGBT| RGBM|     |     |     |     |     |     |     |     |     |             |
 * |-----------------------------------------------------------------------------------------+
 * |  CAPS     | Hue+| Hue-| Sat+| Sat-| Val+| Val-|     |      |    |     |           |     |
 * |-----------------------------------------------------------------------------------------+
 *           |       |       |                                     |       |      |
 *           `--------------------------------------------------------------------'
 */
  [_CL] = LAYOUT_60_hhkb(
      _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______, _______, _______,
      _______, BL_TOGG, BL_STEP, BL_DEC,  BL_INC,  _______, _______, _______, _______, _______,  _______, _______, _______, RESET,
      _______, RGB_TOG, RGB_MOD, _______, _______, _______, _______, _______, _______, _______,  _______, _______, _______,
      KC_CAPS, RGB_HUI, RGB_HUD, RGB_SAI, RGB_SAD, RGB_VAI, RGB_VAD, _______, _______, _______,  _______,          _______, _______,
               _______, _______,                        _______,                       _______,  _______
      )
};
