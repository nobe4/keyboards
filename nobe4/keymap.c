#include QMK_KEYBOARD_H

#define _MG(kc) MT(MOD_LGUI, kc) // Mod Tap GUI
#define _MC(kc) MT(MOD_LCTL, kc) // Mod Tap Control
#define _MS(kc) MT(MOD_LSFT, kc) // Mod Tap Shift
#define _MA(kc) MT(MOD_LALT, kc) // Mod Tap Alt

enum layer_names {
  _CL, // Colemak
  _SY, // Symbols
  _OS, // Operating System
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CL] = LAYOUT_planck_grid(
    KC_Q,       KC_W,         KC_F,         KC_P,         KC_G,    _______, /**/ _______, KC_J,    KC_L,         KC_U,        KC_Y,         KC_SCLN,
    _MS(KC_A),  _MA(KC_R),    _MC(KC_S),    _MG(KC_T),    KC_D,    _______, /**/ _______, KC_H,    _MG(KC_N),    _MC(KC_E),   _MA(KC_I),    _MS(KC_O),
    KC_Z,       KC_X,         KC_C,         KC_V,         KC_B,    _______, /**/ _______, KC_K,    KC_M,         KC_COMM,     KC_DOT,       KC_SLSH,
    _______,    _______,      _______,      MO(_SY),      KC_SPC,  KC_ESC,  /**/ KC_ENT,  KC_BSPC, MO(_OS),      _______,     _______,      _______
  ),
  [_SY] = LAYOUT_planck_grid(
    KC_1,       KC_2,         KC_3,         KC_4,         KC_5,    _______, /**/ _______, KC_6,    KC_7,         KC_8,        KC_9,         KC_0,
    _MS(KC_AT), _MA(KC_AMPR), _MC(KC_ASTR), _MG(KC_EXLM), KC_UNDS, _______, /**/ _______, KC_MINS, _MG(KC_PLUS), _MC(KC_EQL), _MA(KC_LPRN), _MS(KC_RPRN),
    KC_GRV,     KC_PERC,      KC_DLR,       KC_HASH,      KC_BSLS, _______, /**/ _______, KC_CIRC, KC_LCBR,      KC_RCBR,     KC_LBRC,      KC_RBRC,
    _______,    _______,      _______,      _______,      _______, _______, /**/ KC_TAB,  KC_DEL,  KC_QUOT,      _______,     _______,      _______
  ),
  [_OS] = LAYOUT_planck_grid(
    KC_F1,      KC_F2,        KC_F3,        KC_F4,        KC_F5,   KC_F6,   /**/ KC_F7,   KC_F8,   KC_F9,        KC_F10,      KC_F11,       KC_F12,
    _______,    KC_MUTE,      KC_VOLD,      KC_VOLU,      _______, _______, /**/ _______, KC_LEFT, KC_DOWN,      KC_UP,       KC_RGHT,      _______,
    _______,    KC_MRWD,      KC_MPLY,      KC_MFFD,      _______, _______, /**/ _______, KC_HOME, KC_PGDN,      KC_PGUP,     KC_END,       _______,
    _______,    _______,      _______,      _______,      _______, _______, /**/ _______, _______, KC_PWR,       _______,     _______,      _______
  ),
};
// clang-format on
