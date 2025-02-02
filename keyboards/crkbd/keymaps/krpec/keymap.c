#include QMK_KEYBOARD_H

extern keymap_config_t keymap_config;

#ifdef RGBLIGHT_ENABLE
//Following line allows macro to read current RGB settings
extern rgblight_config_t rgblight_config;
#endif

extern uint8_t is_master;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
enum crkbd_layers {
  _WORKMAN = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
  _ESCFN,
};

enum custom_keycodes {
  WORKMAN = SAFE_RANGE,
  QWERTY,
  LOWER,
  RAISE,
  ADJUST,
  ESCFN,
  BACKLIT,
  RGBRST,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_WORKMAN] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,  KC_Q,  KC_D,  KC_R,  KC_W,  KC_B,                   KC_J,  KC_F,  KC_U,  KC_P,KC_SCLN,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL,  KC_A,  KC_S,  KC_H,  KC_T,  KC_G,                   KC_Y,  KC_N,  KC_E,  KC_O,   KC_I,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,  KC_Z,  KC_X,  KC_M,  KC_C,  KC_V,                   KC_K,  KC_L,KC_COMM,KC_DOT,KC_SLSH,KC_ENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER, ESCFN,   KC_SPC, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),

  [_QWERTY] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_TAB,  KC_Q,  KC_W,  KC_E,  KC_R,  KC_T,                   KC_Y,  KC_U,  KC_I,  KC_O,  KC_P,KC_BSPC,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LCTL,  KC_A,  KC_S,  KC_D,  KC_F,  KC_G,                   KC_H,  KC_J,  KC_K,  KC_L,KC_SCLN,KC_QUOT,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    KC_LSFT,  KC_Z,  KC_X,  KC_C,  KC_V,  KC_B,                   KC_N,  KC_M,KC_COMM,KC_DOT,KC_SLSH,KC_ENT,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                KC_LGUI, LOWER,ESCFN,   KC_SPC, RAISE,KC_RALT \
                              //`--------------------'  `--------------------'
  ),


  [_LOWER] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,KC_EXLM,KC_AT,KC_HASH,KC_DLR,KC_PERC,              KC_CIRC,KC_AMPR,KC_ASTR,KC_LPRN,KC_RPRN,_______,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, KC_F1, KC_F2, KC_F3, KC_F4, KC_F5,                KC_F6,KC_UNDS,KC_PLUS, KC_LCBR,KC_RCBR,KC_PIPE,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______, KC_F7, KC_F8, KC_F9,KC_F10,KC_F11,                KC_F12, KC_TILD, KC_NO, KC_HOME, KC_END,_______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______,_______,_______, _______,_______,_______ \
                              //`--------------------'  `--------------------'
  ),

  [_RAISE] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     KC_ESC,  KC_1,  KC_2,  KC_3,  KC_4,  KC_5,                   KC_6,  KC_7,  KC_8,  KC_9,  KC_0,KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______,KC_LEFT,KC_DOWN,KC_UP,KC_RGHT,KC_PSCR,              KC_NO,KC_MINS,KC_EQL,KC_LBRC,KC_RBRC,KC_BSLS,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______,KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,KC_PAUS,            KC_NO,KC_GRV,KC_NO,KC_PGUP,KC_PGDN,_______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______,_______,_______, _______,_______,_______ \
                              //`--------------------'  `--------------------'
  ),

  [_ESCFN] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
     LCTL(KC_TAB),LALT(KC_F4),KC_NO,KC_NO,KC_NO,KC_NO,          KC_NO,KC_HOME,KC_UP, KC_END,KC_PGUP,KC_DEL,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    LCTL(LSFT(KC_TAB)),KC_NO,KC_NO,KC_NO,LCTL(LSFT(KC_T)),KC_NO,           KC_NO,KC_LEFT,KC_DOWN,KC_RGHT,KC_PGDN,KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    _______,KC_NO,KC_NO, KC_NO, KC_NO, KC_NO,                   KC_NO,KC_MUTE,KC_VOLD,KC_VOLU,KC_MPLY,_______,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______,_______,_______, _______,_______,_______ \
                              //`--------------------'  `--------------------'
  ),

  [_ADJUST] = LAYOUT( \
  //,-----------------------------------------.                ,-----------------------------------------.
      RESET,RGBRST, KC_NO, KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_TOG,RGB_HUI,RGB_SAI,RGB_VAI,KC_NO,KC_NO,                 KC_NO, WORKMAN, QWERTY, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------|                |------+------+------+------+------+------|
    RGB_MOD,RGB_HUD,RGB_SAD,RGB_VAD,KC_NO,KC_NO,                 KC_NO, KC_NO, KC_NO, KC_NO, KC_NO, KC_NO,\
  //|------+------+------+------+------+------+------|  |------+------+------+------+------+------+------|
                                _______,_______,_______, _______,_______,_______ \
                              //`--------------------'  `--------------------'
  )
};

int RGB_current_mode;

void matrix_init_user(void) {
  #ifdef RGBLIGHT_ENABLE
    RGB_current_mode = rgblight_config.mode;
  #endif
  //SSD1306 OLED init, make sure to add #define SSD1306OLED in config.h
  #ifdef SSD1306OLED
      iota_gfx_init(!has_usb());   // turns on the display
  #endif
}

// Setting ADJUST layer RGB back to default
void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else {
    layer_off(layer3);
  }
}

//SSD1306 OLED update loop, make sure to add #define SSD1306OLED in config.h
#ifdef SSD1306OLED

  // When add source files to SRC in rules.mk, you can use functions.
  const char *read_layer_state(void);
  const char *read_logo(void);
  void set_keylog(uint16_t keycode, keyrecord_t *record);
  const char *read_keylog(void);
  const char *read_keylogs(void);

  // const char *read_mode_icon(bool swap);
  // const char *read_host_led_state(void);
  // void set_timelog(void);
  // const char *read_timelog(void);

  // void keyboard_pre_init_user(void)
  // {
  //   eeconfig_init_kb();
  //   eeconfig_init_user();
  // }

  void matrix_scan_user(void) {
     iota_gfx_task();
  }

  void matrix_render_user(struct CharacterMatrix *matrix) {
    if (is_master) {
      // If you want to change the display of OLED, you need to change here
      matrix_write_ln(matrix, read_layer_state());
      matrix_write_ln(matrix, read_keylog());
      //matrix_write_ln(matrix, read_keylogs());
      //matrix_write_ln(matrix, read_mode_icon(keymap_config.swap_lalt_lgui));
      //matrix_write_ln(matrix, read_host_led_state());
      //matrix_write_ln(matrix, read_timelog());
    } else {
      matrix_write(matrix, read_logo());
    }
  }

  void matrix_update(struct CharacterMatrix *dest, const struct CharacterMatrix *source) {
    if (memcmp(dest->display, source->display, sizeof(dest->display))) {
      memcpy(dest->display, source->display, sizeof(dest->display));
      dest->dirty = true;
    }
  }

  void iota_gfx_task_user(void) {
    struct CharacterMatrix matrix;
    matrix_clear(&matrix);
    matrix_render_user(&matrix);
    matrix_update(&display, &matrix);
  }
#endif//SSD1306OLED

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef SSD1306OLED
    set_keylog(keycode, record);
#endif
  }

  switch (keycode) {
    case WORKMAN:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_WORKMAN);
      }
      return false;
      break;
    case QWERTY:
      if (record->event.pressed) {
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed)
      {
        layer_on(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      else {
        layer_off(_LOWER);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed)
      {
        layer_on(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      else {
        layer_off(_RAISE);
        update_tri_layer_RGB(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ESCFN:
      if (record->event.pressed) {
        layer_on(_ESCFN);
      }
      else {
        layer_off(_ESCFN);
      }
      return false;
      break;
    case RGB_MOD:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          rgblight_mode(RGB_current_mode);
          rgblight_step();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      return false;
    case RGBRST:
      #ifdef RGBLIGHT_ENABLE
        if (record->event.pressed) {
          eeconfig_update_rgblight_default();
          rgblight_enable();
          RGB_current_mode = rgblight_config.mode;
        }
      #endif
      break;
  }
  return true;
}

#define L_BASE 0
#define L_QWERTY (1U << _QWERTY)
#define L_LOWER (1U << _LOWER)
#define L_RAISE (1U << _RAISE)
#define L_ADJUST 28 //(1U << _ADJUST) //this didn't work
#define L_ESCFN (1U << _ESCFN)

char layer_state_str[24];

const char *read_layer_state(void) {
  switch (layer_state) {
    case L_BASE:
      //test this..
      if (biton32(default_layer_state) == _WORKMAN) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Workman");
      }
      else if (biton32(default_layer_state) == _QWERTY) {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: QWERTY");
      }
      else {
        snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Default");
      }
      break;
    case L_LOWER:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Lower");
      break;
    case L_RAISE:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Raise");
      break;
    case L_ADJUST:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Adjust");
      break;
    case L_ESCFN:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Fn");
      break;
    default:
      snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state);
      break;
  }

  return layer_state_str;
}