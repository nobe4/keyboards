#include QMK_KEYBOARD_H

enum layer_names {
  _CL, // Colemak
  _QW, // Qwerty
  _SY, // symbols
  _OS, // Operating System
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_CL] = LAYOUT_planck_grid(
		KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
		KC_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, MO(_SY), KC_SPC,  KC_SPC,  MO(_OS), KC_RGUI, KC_RALT, KC_RCTL, DF(_QW)
	),
	[_QW] = LAYOUT_planck_grid(
		KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
		KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
		KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT,
		KC_LCTL, KC_LGUI, KC_LALT, KC_LGUI, MO(_SY), KC_SPC,  KC_SPC,  MO(_OS), KC_RGUI, KC_RALT, KC_RCTL, DF(_CL)
	),
	[_SY] =        LAYOUT_planck_grid(
		KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
		_______, KC_AT,   KC_AMPR, KC_ASTR, KC_EXLM, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_LPRN, KC_RPRN, _______,
		_______, _______, KC_PERC, KC_DLR,  KC_HASH, KC_BSLS, KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
	),
	[_OS]      =        LAYOUT_planck_grid(
		KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
		_______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______,
		_______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______,
		_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_PWR
	),
};
// clang-format on
