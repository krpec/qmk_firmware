
#include QMK_KEYBOARD_H
#include <stdio.h>
#include "crkbd.h"

// in the future, should use (1U<<_LAYER_NAME) instead, but needs to be moved to keymap,c
#define L_WORKMAN (1 << _WORKMAN)
#define L_LOWER (1 << _LOWER)
#define L_RAISE (1 << _RAISE)
#define L_ADJUST (1 << _ADJUST)
#define L_ADJUST_TRI (L_ADJUST|L_LOWER|L_RAISE)
#define L_ESCFN (1 << _ESCFN)
#define L_QWERTY (1 << _QWERTY)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state)
  {
  case L_WORKMAN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: _WORKMAN");
    break;
  case L_RAISE:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
    break;
  case L_LOWER:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
    break;
  case L_ADJUST:
  case L_ADJUST_TRI:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
    break;
  case L_ESCFN:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Fn");
    break;
  case L_QWERTY:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
    break;
  default:
    snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
  }

  return layer_state_str;
}
