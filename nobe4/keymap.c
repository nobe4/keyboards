#include QMK_KEYBOARD_H

enum {
  // Layouts
  LY_CL, // Colemak
  LY_QW, // Qwerty for gaming
  LY_SY, // Symbols
  LY_OS, // Operating System

  // Tap dance
  Q_TAB,
  O_SCL,
};

#define _SY(kc) LT(LY_SY, kc) // Layout switch to Symbols
#define _OS(kc) LT(LY_OS, kc) // Layout switch to OS
#define _MG(kc) MT(MOD_LGUI, kc) // Mod Tap GUI
#define _MC(kc) MT(MOD_LCTL, kc) // Mod Tap Control
#define _MS(kc) MT(MOD_LSFT, kc) // Mod Tap Shift
#define _MA(kc) MT(MOD_LALT, kc) // Mod Tap Alt

// Tap dance boilerplate
#define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)                                   \
  {                                                                            \
    .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset},       \
    .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),              \
  }

typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
} tap_dance_tap_hold_t;

void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (state->pressed) {
    if (state->count == 1
#ifndef PERMISSIVE_HOLD
        && !state->interrupted
#endif
    ) {
      register_code16(tap_hold->hold);
      tap_hold->held = tap_hold->hold;
    } else {
      register_code16(tap_hold->tap);
      tap_hold->held = tap_hold->tap;
    }
  }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (tap_hold->held) {
    unregister_code16(tap_hold->held);
    tap_hold->held = 0;
  }
}
// Tap dance boilerplate

tap_dance_action_t tap_dance_actions[] = {
    [Q_TAB] = ACTION_TAP_DANCE_TAP_HOLD(KC_Q, KC_TAB),
    [O_SCL] = ACTION_TAP_DANCE_TAP_HOLD(KC_O, KC_SCLN),
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [LY_CL] = LAYOUT_planck_grid(
    TD(Q_TAB), KC_W,      KC_F,      KC_P,        KC_G,        _______, /**/ _______, KC_J,    KC_L,        KC_U,      KC_Y,      KC_QUOT,
    KC_A,      _MA(KC_R), _MC(KC_S), _MG(KC_T),   KC_D,        _______, /**/ _______, KC_H,    _MG(KC_N),   _MC(KC_E), _MA(KC_I), TD(O_SCL),
    KC_Z,      KC_X,      KC_C,      KC_V,        _MG(KC_B),   _______, /**/ _______, KC_K,    KC_M,        KC_COMM,   KC_DOT,    KC_SLSH,
    _______,   _______,   _______,   _SY(KC_ESC), _MS(KC_SPC), _______, /**/ _______, KC_BSPC, _OS(KC_ENT), _______,   _______,   DF(LY_QW)
  ),
  // keep QWERTY for gaming
  [LY_QW] = LAYOUT_planck_grid(
    TD(Q_TAB), KC_W,      KC_E,      KC_R,        KC_T,        _______, /**/ _______, KC_Y,    KC_U,        KC_I,      KC_O,      KC_P,
    KC_A,      _MA(KC_S), _MC(KC_D), _MG(KC_F),   KC_G,        _______, /**/ _______, KC_H,    _MG(KC_J),   _MC(KC_K), _MA(KC_L), TD(O_SCL),
    KC_Z,      KC_X,      KC_C,      KC_V,        _MG(KC_B),   _______, /**/ _______, KC_N,    KC_M,        KC_COMM,   KC_DOT,    KC_SLSH,
    _______,   _______,   _______,   _SY(KC_ESC), _MS(KC_SPC), _______, /**/ _______, KC_BSPC, _OS(KC_ENT), _______,   _______,   DF(LY_CL)
  ),
  [LY_SY] = LAYOUT_planck_grid(
    KC_1,      KC_2,      KC_3,      KC_4,        KC_5,        _______, /**/ _______, KC_6,    KC_7,        KC_8,      KC_9,      KC_0,
    KC_AT,     KC_AMPR,   KC_ASTR,   KC_EXLM,     KC_UNDS,     _______, /**/ _______, KC_MINS, KC_PLUS,     KC_EQL,    KC_LPRN,   KC_RPRN,
    KC_GRV,    KC_PERC,   KC_DLR,    KC_HASH,     KC_BSLS,     _______, /**/ _______, KC_CIRC, KC_LCBR,     KC_RCBR,   KC_LBRC,   KC_RBRC,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, KC_DEL,  _______,     _______,   _______,   _______
  ),
  [LY_OS] = LAYOUT_planck_grid(
    KC_F1,     KC_F2,     KC_F3,     KC_F4,       KC_F5,       KC_F6,   /**/ KC_F7,   KC_F8,   KC_F9,       KC_F10,    KC_F11,    KC_F12,
    _______,   KC_MUTE,   KC_VOLD,   KC_VOLU,     _______,     _______, /**/ _______, KC_LEFT, KC_DOWN,     KC_UP,     KC_RGHT,   _______,
    _______,   KC_MRWD,   KC_MPLY,   KC_MFFD,     _______,     _______, /**/ _______, KC_HOME, KC_PGDN,     KC_PGUP,   KC_END,    _______,
    _______,   _______,   _______,   _______,     _______,     _______, /**/ _______, KC_PWR,  _______,     _______,   _______,   _______
  ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  switch (keycode) {

  case TD(Q_TAB):
  case TD(O_SCL):
    action = &tap_dance_actions[TD_INDEX(keycode)];
    if (!record->event.pressed && action->state.count &&
        !action->state.finished) {
      tap_dance_tap_hold_t *tap_hold =
          (tap_dance_tap_hold_t *)action->user_data;
      tap_code16(tap_hold->tap);
    }
  }

  return true;
}
