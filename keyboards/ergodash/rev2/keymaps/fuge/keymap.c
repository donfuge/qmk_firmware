#include QMK_KEYBOARD_H
#include "action_layer.h"
#include "eeconfig.h"
#include "keymap_hungarian.h"

extern keymap_config_t keymap_config;

#define _QWERTY 0
#define _LOWER 1
#define _RAISE 2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST,
};
enum {
  TD_TAB_UNDO = 0
};


// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO
#define KC_JPN LALT(KC_GRV)
#define UNDO LCTL(HU_Z)

	

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* Qwerty
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  0 |   1  |   2  |   3  |   4  |   5  |   [  |                    |   ]  |   6  |   7  |   8  |   9  |   HU_OE  | HU_UE |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Tab  |   Q  |   W  |   E  |   R  |   T  |   -  |                    |   =  |   Y  |   U  |   I  |   O  |   P  |  Bksp   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | ESC  |   A  |   S  |   D  |   F  |   G  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   É  |  Á   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   Z  |   X  |   C  |   V  |   B  |  _______ |                    | Enter|   N  |   M  |   ,  |   .  |   -  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Adjust|||||||| Raise| Lower| Space     |||||||| Enter     | | Raise|||||||| Left | Down |  Up  | Right|
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_QWERTY] = LAYOUT( \
    HU_0,  HU_1,    HU_2,    HU_3,    HU_4,    HU_5,    HU_LBRC,                        HU_RBRC, HU_6,    HU_7,    HU_8,    HU_9,    HU_OE,    HU_UE, \
    KC_TAB,  HU_Q,    HU_W,    HU_E,    HU_R,    HU_T,    HU_MINS,                        HU_EQL , HU_Y,    HU_U,    HU_I,    HU_O,    HU_P,    KC_BSPC, \
    KC_ESC,  HU_A,    HU_S,    HU_D,    HU_F,    HU_G,    KC_DEL ,                        KC_BSPC, HU_H,    HU_J,    HU_K,    HU_L,    HU_EE, HU_AA, \
    KC_LSFT, HU_Z,    HU_X,    HU_C,    HU_V,    HU_B,    _______ ,                        KC_ENT , HU_N,    HU_M,    HU_COMM, HU_DOT,  HU_MINS, KC_ENT, \
    KC_LCTL, KC_LGUI, KC_LALT, ADJUST,     RAISE,      LOWER,  KC_SPC,        KC_ENT,LOWER , RAISE,            KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT  \
  ),

  /* Lower
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  F6  |  F7  |  F8  |  F9  |  F10 |  F11 |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   ^  |   &  |   *  |   (  |   )  |  |   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Undo  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |  _______ |                    |      |   N  |   M  |   <  |   >  |   ?  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Adjust|||||||| Raise| Lower    |      ||||||||      | Raise     | Lower|||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_LOWER] = LAYOUT(
    KC_F12,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_LCBR,                        KC_RCBR, KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  \
    KC_TAB, HU_EXLM, HU_AT,   HU_HASH, HU_DLR,  HU_PERC, HU_UNDS,                        HU_PLUS, HU_CIRC, HU_AMPR, HU_ASTR, HU_LPRN, HU_RPRN, HU_PIPE, \
    UNDO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    HU_COLN, HU_DQOT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ ,                        _______ , KC_N,    KC_M,    HU_LESS,   HU_MORE,   HU_QST, KC_ENT, \
    KC_LCTL, KC_LGUI, KC_LALT, ADJUST,              RAISE ,LOWER,_______,        _______,RAISE,LOWER ,            KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Raise
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |  F11 |  F1  |  F2  |  F3  |  F4  |  F5  |   {  |                    |   }  |  .  |  HU_UU  |  HU_II  |  HU_OEE  |  HU_UEE |  HU_OO |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * |  Tab   |   !  |   @  |   #  |   $  |   %  |   _  |                    |   +  |   .  |   HU_UU  |   HU_II  |   HU_OEE  |   HU_UEE  |  Bspace   |
   * |------+------+------+------+------+------+------+--------------------+------+------+------+------+------+------+------|
   * | Undo  |   1  |   2  |   3  |   4  |   5  |  Del |                    | Bksp |   H  |   J  |   K  |   L  |   :  |  "   |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * | Shift|   6  |   7  |   8  |   9  |   0  |  _______ |                    | Enter|   N  |   M  |   <  |   >  |   ?  | Enter|
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * | Ctrl |  GUI |  ALt |Adjust|||||||| Raise |Lower | Space     ||||||||  Enter    | Raise| Lower |||||||| Home |PageDn|PageUp|  End |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_RAISE] = LAYOUT(
    KC_F11,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   HU_LCBR,                        HU_RCBR, HU_DOT,    HU_UU,    HU_II,    HU_OEE,    HU_UEE,    HU_OO,   \
    KC_TAB, HU_EXLM, HU_AT,   HU_HASH, HU_DLR,  HU_PERC, HU_UNDS,                          HU_DOT,    HU_UU,    HU_II,    HU_OEE,    HU_UEE,    HU_OO, KC_BSPC,  \
    UNDO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_DEL ,                        KC_BSPC, KC_H,    KC_J,    KC_K,    KC_L,    KC_COLN, HU_DQOT , \
    KC_LSFT, KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    _______ ,                        KC_ENT , KC_N,    KC_M,    HU_LESS,   HU_MORE,   HU_QST, KC_ENT, \
    KC_LCTL, KC_LGUI, KC_LALT, ADJUST,     RAISE,      LOWER,   KC_SPC ,        KC_ENT , RAISE,  LOWER,         KC_HOME, KC_PGDN, KC_PGUP, KC_END   \
  ),

  /* Adjust
   * ,----------------------------------------------------------------------------------------------------------------------.
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      | Reset|RGB ON|  MODE|  HUE-|  HUE+|      |                    |      |  SAT-|  SAT+|  VAL-|  VAL+|      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |------+------+------+------+------+------+---------------------------+------+------+------+------+------+------+------|
   * |      |      |      |      |      |      |      |                    |      |      |      |      |      |      |      |
   * |-------------+------+------+------+------+------+------+------+------+------+------+------+------+------+-------------|
   * |      |      |      |      ||||||||      |      |      ||||||||      |      |      ||||||||      |      |      |      |
   * ,----------------------------------------------------------------------------------------------------------------------.
   */
  [_ADJUST] = LAYOUT(
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, RESET  , RGB_TOG, RGB_MOD, RGB_HUD, RGB_HUI,_______,                       _______, RGB_SAD, RGB_SAI, RGB_VAD, RGB_VAI, _______, _______, \
    _______, _______, BL_TOGG, BL_BRTG, BL_INC , BL_DEC ,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______, _______, _______,_______,                       _______, _______, _______, _______, _______, _______, _______, \
    _______, _______, _______, _______,          _______,_______,_______,       _______,_______, _______,          _______, _______, _______, _______  \
  )
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
         print("mode just switched to qwerty and this is a huge string\n");
        set_single_persistent_default_layer(_QWERTY);
      }
      return false;
      break;
    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      return false;
      break;
    case ADJUST:
      if (record->event.pressed) {
        layer_on(_ADJUST);
      } else {
        layer_off(_ADJUST);
      }
      return false;
      break;
  }
  return true;
}
