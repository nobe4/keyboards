#pragma once

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