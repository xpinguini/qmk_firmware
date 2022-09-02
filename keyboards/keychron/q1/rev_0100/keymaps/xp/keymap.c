/* Copyright 2021 @ Mike Killewald
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.




 FN Swap Version*/

#include QMK_KEYBOARD_H
#include "keymap_user.h"
#ifdef RGB_MATRIX_ENABLE
#    include "rgb_matrix_user.h"
#endif

// clang-format off

typedef union {
  uint32_t raw;
  struct {
    bool caps_lock_light_tab :1;
    bool caps_lock_light_alphas :1;
    bool fn_layer_transparent_keys_off :1;
    bool fn_layer_color_enable :1;
  };
} user_config_t;

user_config_t user_config;

enum custom_keycodes {
#ifdef VIA_ENABLE
    KC_MISSION_CONTROL = USER00,
#else
    KC_MISSION_CONTROL = SAFE_RANGE,
#endif
    KC_LAUNCHPAD,
    KC_LIGHT_TAB_TOGGLE,
    KC_LIGHT_ALPHAS_TOGGLE,
    KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE,
    KC_FN_LAYER_COLOR_TOGGLE
};

#define KC_MCTL KC_MISSION_CONTROL
#define KC_LPAD KC_LAUNCHPAD
#define KC_LTTOG KC_LIGHT_TAB_TOGGLE
#define KC_LATOG KC_LIGHT_ALPHAS_TOGGLE
#define KC_TKTOG KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE
#define KC_FCTOG KC_FN_LAYER_COLOR_TOGGLE
#define KC_TASK LGUI(KC_TAB)
#define KC_FLXP LGUI(KC_E)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

[MAC_BASE] = LAYOUT_ansi_82(
     KC_ESC,             KC_BRID,  KC_BRIU,  KC_MCTL,  KC_LPAD,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_DEL,   KC_INS,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_PGUP,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGDN,
     KC_CAPS,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_HOME,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
     KC_LCTL,  KC_LALT,  KC_LGUI,                                KC_SPC,                                 KC_RGUI, MO(MAC_FN),KC_RCTL,  KC_LEFT,  KC_DOWN,  KC_RGHT),

[MAC_FN] = LAYOUT_ansi_82(
     KC_TRNS,            KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     RGB_TOG,  RGB_MOD,  RGB_VAI,  RGB_HUI,  RGB_SAI,  RGB_SPI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  RGB_RMOD, RGB_VAD,  RGB_HUD,  RGB_SAD,  RGB_SPD,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            KC_LTTOG, KC_LATOG, KC_TKTOG, KC_FCTOG, KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS),

[WIN_BASE] = LAYOUT_ansi_82(
     KC_ESC,             KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,   KC_DEL,   KC_HOME,
     KC_GRV,   KC_1,     KC_2,     KC_3,     KC_4,     KC_5,     KC_6,     KC_7,     KC_8,     KC_9,     KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,            KC_END,
     KC_TAB,   KC_Q,     KC_W,     KC_E,     KC_R,     KC_T,     KC_Y,     KC_U,     KC_I,     KC_O,     KC_P,     KC_LBRC,  KC_RBRC,  KC_BSLS,            KC_PGUP,
     KC_LCTL,  KC_A,     KC_S,     KC_D,     KC_F,     KC_G,     KC_H,     KC_J,     KC_K,     KC_L,     KC_SCLN,  KC_QUOT,            KC_ENT,             KC_PGDN,
     KC_LSFT,            KC_Z,     KC_X,     KC_C,     KC_V,     KC_B,     KC_N,     KC_M,     KC_COMM,  KC_DOT,   KC_SLSH,            KC_RSFT,  KC_UP,
     MO(WIN_FN),  KC_LGUI,  KC_LALT,                KC_SPC,                 KC_RALT, KC_RCTL, MO(WIN_FN), KC_LEFT,  KC_DOWN,  KC_RGHT),

[WIN_FN] = LAYOUT_ansi_82(
     TO(WIN_BASE),            KC_BRID,  KC_BRIU,  KC_TASK,  KC_FLXP,  RGB_VAD,  RGB_VAI,  KC_MPRV,  KC_MPLY,  KC_MNXT,  KC_MUTE,  KC_VOLD,  KC_VOLU,  KC_TRNS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            RGB_TOG,
     KC_TRNS,  LCTL(KC_Q),  LCTL(KC_W),  LCTL(KC_E),  LCTL(KC_R),  LCTL(KC_Z),  LCTL(KC_Z),  KC_EQL,  KC_UP,  KC_PLUS,  KC_MINS,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_TRNS,
     KC_TRNS,  LCTL(KC_A), LCTL(KC_S),  LCTL(KC_D),  LCTL(KC_F),  LCTL(KC_G),  LCTL(KC_H),  KC_LEFT,  KC_DOWN,  KC_RGHT,  KC_UNDS,  KC_TRNS,            KC_TRNS,            KC_TRNS,
     KC_TRNS,            LCTL(KC_Z), LCTL(KC_X), LCTL(KC_C), LCTL(KC_V), LCTL(KC_B),  LCTL(KC_N),  KC_AMPR,  KC_TRNS,  KC_TRNS,  KC_TRNS,            KC_CAPS,  KC_TRNS,
     KC_TRNS,  KC_TRNS,  KC_TRNS,                                KC_TRNS,                                KC_TRNS,  KC_RGUI,  KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS)

};

// clang-format on

void matrix_init_user(void) {
#ifdef RGB_MATRIX_ENABLE
    rgb_matrix_init_user();
#endif
}

void keyboard_post_init_user(void) {
    user_config.raw = eeconfig_read_user();
}

void eeconfig_init_user(void) {
    user_config.raw = 0;
    user_config.caps_lock_light_tab = true;
    user_config.caps_lock_light_alphas = false;
    user_config.fn_layer_transparent_keys_off = true;
    user_config.fn_layer_color_enable = false;
    eeconfig_update_user(user_config.raw);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_MISSION_CONTROL:
            if (record->event.pressed) {
                host_consumer_send(0x29F);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LAUNCHPAD:
            if (record->event.pressed) {
                host_consumer_send(0x2A0);
            } else {
                host_consumer_send(0);
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_TAB_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_tab ^= 1; // bitwise xor to toggle status bit
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_LIGHT_ALPHAS_TOGGLE:
            if (record->event.pressed) {
                user_config.caps_lock_light_alphas ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_TRANSPARENT_KEYS_TOGGLE:
            if (record->event.pressed) {
                user_config.fn_layer_transparent_keys_off ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        case KC_FN_LAYER_COLOR_TOGGLE:
            if (record->event.pressed) {
                user_config.fn_layer_color_enable ^= 1;
                eeconfig_update_user(user_config.raw);
            }
            return false;  // Skip all further processing of this key
        default:
            return true;  // Process all other keycodes normally
    }
}

bool get_caps_lock_light_tab(void) {
    return user_config.caps_lock_light_tab;
}

bool get_caps_lock_light_alphas(void) {
    return user_config.caps_lock_light_alphas;
}

bool get_fn_layer_transparent_keys_off(void) {
    return user_config.fn_layer_transparent_keys_off;
}

bool get_fn_layer_color_enable(void) {
    return user_config.fn_layer_color_enable;
}
