#include "planck.h"
#include "action_layer.h"

extern keymap_config_t keymap_config;

enum planck_layers {
	_QWERTY,
	_SYMBOLS,
	_OS,
};

enum planck_keycodes {
	QWERTY = SAFE_RANGE,
	SYMBOLS,
	OS,
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_QWERTY] = {
		{KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC },
		{KC_ESC,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT },
		{KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_ENT  },
		{KC_LCTL, KC_LGUI, KC_LALT, KC_LALT, SYMBOLS, KC_SPC,  KC_SPC,  OS,      KC_RGUI, KC_RALT, KC_RCTL, KC_SLEP }
	},

	[_SYMBOLS] = {
		{KC_GRV , KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL },
		{_______, KC_AT,   KC_AMPR, KC_ASTR, KC_EXLM, KC_UNDS, KC_MINS, KC_PLUS, KC_EQL,  KC_LPRN, KC_RPRN, _______},
		{_______, _______, KC_PERC, KC_DLR,  KC_HASH, KC_BSLS, KC_CIRC, KC_LCBR, KC_RCBR, KC_LBRC, KC_RBRC, _______},
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______}
	},

	[_OS] = {
		{KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12  },
		{_______, _______, KC_MUTE, KC_VOLD, KC_VOLU, _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______, _______ },
		{_______, _______, KC_MRWD, KC_MPLY, KC_MFFD, _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______, _______ },
		{_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______ }
	},

};

bool switch_layer(uint8_t layer, bool pressed){
	if (pressed) {
		layer_on(layer);
	} else {
		layer_off(layer);
	}
	return false;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
	switch (keycode) {
		case QWERTY:
			if (record->event.pressed) {
				set_single_persistent_default_layer(_QWERTY);
			}
			return false;

		case SYMBOLS:
			return switch_layer(_SYMBOLS, record->event.pressed);

		case OS:
			return switch_layer(_OS, record->event.pressed);
	}
	return true;
}
