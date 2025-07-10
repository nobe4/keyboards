#pragma once
#include QMK_KEYBOARD_H
#include "keymap_eurkey.h"

// Key Overrides boilerplate
#define KO_SHIFT(key, replacement)                                             \
  &ko_make_basic(MOD_MASK_SHIFT, key, replacement),

// Tap dance boilerplate
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data);
void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data);

#define TD_DEF(name, tap, hold)                                                \
  [name] = {                                                                   \
      .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset},     \
      .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0, 0}),         \
  },

#define TD_LEAD(name, tap)                                                     \
  [name] = {                                                                   \
      .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset},     \
      .user_data = (void *)&((tap_dance_tap_hold_t){tap, 0, 0, 1}),            \
  },

// Leader boilerplate

#define L_AC(l, m, r)                                                          \
  else if (leader_sequence_two_keys(l, m)) {                                   \
    tap_code16(r);                                                             \
  }

// With dead key
#define L_AD(l, m, d)                                                          \
  else if (leader_sequence_two_keys(l, m)) {                                   \
    tap_code16(d);                                                             \
    tap_code16(l);                                                             \
  }

typedef struct {
  uint16_t tap;
  uint16_t hold;
  uint16_t held;
  uint16_t leader;
} tap_dance_tap_hold_t;

#define ___ KC_NO

enum layouts {
  LY_CL, // Colemak
  LY_AC, // Accents
  LY_SY, // Symbols
  LY_OS, // Operating System
  LY_AS, // ASDW
};

enum tap_dance {
  START, // keep first

  Q_HASH,
  Y_DLR,
  QO_GR,

  H_AC,

  Z_AST,
  X_PRC,
  C_AT,
  V_CIR,

  K_AMP,
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

  TD_LEAD(H_AC,  KC_H)

  TD_DEF(Z_AST,  KC_Z,    KC_ASTR)
  TD_DEF(X_PRC,  KC_X,    KC_PERC)
  TD_DEF(C_AT,   KC_C,    KC_AT)
  TD_DEF(V_CIR,  KC_V,    KC_CIRC)

  TD_DEF(K_AMP,  KC_K,    KC_AMPR)
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
  if (TD(START) <= keycode && keycode <= TD(END)) {
    tap_dance_action_t *action = &tap_dance_actions[TD_INDEX(keycode)];

    // This block executes only if the TD keycode has been tapped and not
    // held. The held state is handled by tap_dance_tap_hold_finished.
    if (!record->event.pressed && action->state.count &&
        !action->state.finished) {
      tap_dance_tap_hold_t *tap_hold =
          (tap_dance_tap_hold_t *)action->user_data;
      tap_code16(tap_hold->tap);
    }
  }

  return true;
}

// This block executes when the TD key is held for long enough.
void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  if (state->pressed) {
    if (state->count == 1 && !state->interrupted) {
      // Special case: the leader sequence for accents require a special layer
      // to disable TD(...).
      if (tap_hold->leader == 1) {
        leader_start();
        layer_on(LY_AC);
      } else {
        tap_code16(tap_hold->hold);
      }

      tap_hold->held = tap_hold->hold;
    } else {
      tap_code16(tap_hold->tap);
      tap_hold->held = tap_hold->tap;
    }
  }
}

void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
  tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

  tap_hold->held = 0;
}

void leader_end_user(void) {
  if (0) {
    /* kept for simplified macros */
  }

  // TODO, how to enable this for uppercase?
  L_AC(KC_A, KC_A, EU_AACU)
  L_AC(KC_A, KC_G, EU_AGRV)
  L_AC(KC_A, KC_U, EU_ADIA)
  L_AD(KC_A, KC_T, EU_DCIR)
  L_AC(KC_A, KC_E, EU_AE)

  L_AC(KC_C, KC_C, EU_CCED)

  L_AC(KC_E, KC_A, EU_EACU)
  L_AC(KC_E, KC_G, EU_EGRV)
  L_AC(KC_E, KC_U, EU_EDIA)
  L_AD(KC_E, KC_T, EU_DCIR)

  L_AC(KC_O, KC_A, EU_OACU)
  L_AC(KC_O, KC_G, EU_OGRV)
  L_AC(KC_O, KC_U, EU_ODIA)
  L_AD(KC_O, KC_T, EU_DCIR)
  L_AD(KC_O, KC_E, EU_OE)

  L_AC(KC_P, KC_O, EU_PND)
  L_AC(KC_E, KC_R, EU_EURO)

  L_AC(KC_S, KC_S, EU_SS)

  L_AC(KC_U, KC_A, EU_UACU)
  L_AC(KC_U, KC_G, EU_UGRV)
  L_AC(KC_U, KC_U, EU_UDIA)
  L_AD(KC_U, KC_T, EU_DCIR)

  // Tests after
  else if (leader_sequence_one_key(KC_F)) {
    tap_code16(EU_DCIR);
    tap_code16(KC_A);
  }
  // else if (leader_sequence_one_key(KC_F)) {
  //   SEND_STRING("no shift");
  // }
  else if (leader_sequence_one_key(S(KC_F))) {
    SEND_STRING("S");
  }
  else if (leader_sequence_one_key(LSFT(KC_F))) {
    SEND_STRING("LSFT");
  }

  layer_off(LY_AC);
}
