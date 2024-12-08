#pragma once
#include QMK_KEYBOARD_H

// Key Overrides boilerplate
#define KO_SHIFT(key, replacement)                                             \
  &ko_make_basic(MOD_MASK_SHIFT, key, replacement),

// Tap dance boilerplate
#define TD_DEF(name, tap, hold)                                                \
  [name] = {                                                                   \
      .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset},     \
      .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}),            \
  },

#define TAP_DANCE_UPDATE                                                       \
  action = &tap_dance_actions[TD_INDEX(keycode)];                              \
  if (!record->event.pressed && action->state.count &&                         \
      !action->state.finished) {                                               \
    tap_dance_tap_hold_t *tap_hold =                                           \
        (tap_dance_tap_hold_t *)action->user_data;                             \
    tap_code16(tap_hold->tap);                                                 \
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

#define ___ KC_NO

enum layouts {
  LY_CL, // Colemak
  LY_SY, // Symbols
  LY_OS, // Operating System
  LY_AS, // ASDW
};

enum tap_dance {
  START, // keep first

  Q_HASH,
  Y_DLR,
  QO_GR,

  K_AMP,

  Z_AST,
  V_CIR,
  X_PRC,
  C_AT,
  M_UND,
  CO_QES,
  DO_EX,

  END, // keep last
};

#define B_GUI MT(MOD_LGUI, KC_B)
#define BSP_CTL MT(MOD_LCTL, KC_BSPC)

// clang-format off
tap_dance_action_t tap_dance_actions[] = {
  TD_DEF(Q_HASH, KC_Q,    KC_HASH)
  TD_DEF(Y_DLR,  KC_Y,    KC_DLR)
  TD_DEF(QO_GR,  KC_QUOT, KC_GRV)
  TD_DEF(X_PRC,  KC_X,    KC_PERC)
  TD_DEF(C_AT,   KC_C,    KC_AT)
  TD_DEF(Z_AST,  KC_Z,    KC_ASTR)
  TD_DEF(K_AMP,  KC_K,    KC_AMPR)
  TD_DEF(V_CIR,  KC_V,    KC_CIRC)
  TD_DEF(M_UND,  KC_M,    KC_UNDS)
  TD_DEF(CO_QES, KC_COMM, KC_QUES)
  TD_DEF(DO_EX,  KC_DOT,  KC_EXLM)
};

// Key Overrides
const key_override_t *key_overrides[] = {
    KO_SHIFT(BSP_CTL,    KC_DEL)
    KO_SHIFT(TD(CO_QES), KC_SCLN)
    KO_SHIFT(TD(DO_EX),  KC_COLN)
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  tap_dance_action_t *action;

  if (TD(START) <= keycode && keycode <= TD(END)) {
    TAP_DANCE_UPDATE
  }

  return true;
}
