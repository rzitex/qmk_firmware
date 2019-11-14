/* Copyright 2015-2017 Jack Humbert
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
 */

/*#include "planck.h"*/
/*#include "action_layer.h"*/
#include QMK_KEYBOARD_H

#define KC_CAD LALT(LCTL(KC_DEL))
#define KC_LOCK LGUI(LSFT(KC_Q))
#define KC_CTLC LCTL(KC_C)
#define KC_EMU LCTL(KC_GRV)
#define KC_TASK LCTL(LSFT(KC_ESC))
#define KC_ALTF4 LALT(KC_F4)

extern keymap_config_t keymap_config;

enum planck_layers {
   _QWERTY,
   _COLEMAK,
   _LOWER,
   _RAISE,
   _POK3R,
   _ADJUST
};

enum planck_keycodes {
   QWERTY = SAFE_RANGE,
   COLEMAK,
   LOWER,
   RAISE,
   POK3R,
   PASSWD
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

   /* Qwerty
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   E  |   R  |   T  |   Y  |   U  |   I  |   O  |   P  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Bksp |   A  |   S  |   D  |   F  |   G  |   H  |   J  |   K  |   L  |   ;  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   N  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | RCTL |Pok3r |Right |
    * `-----------------------------------------------------------------------------------'
    */
   [_QWERTY] = LAYOUT_planck_grid(
      KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC,
      KC_BSPC, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT),
      KC_LEAD, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RCTL, POK3R,   KC_RGHT
   ),

   /* Colemak
    * ,-----------------------------------------------------------------------------------.
    * | Tab  |   Q  |   W  |   F  |   P  |   G  |   J  |   L  |   U  |   Y  |   ;  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Bksp |   A  |   R  |   S  |   T  |   D  |   H  |   N  |   E  |   I  |   O  |  "   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * | Shift|   Z  |   X  |   C  |   V  |   B  |   K  |   M  |   ,  |   .  |   /  |Enter |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER| Ctrl | GUI  | Alt  |Lower |    Space    |Raise | Left | RCTL |Pok3r |Right |
    * `-----------------------------------------------------------------------------------'
    */
   [_COLEMAK] = LAYOUT_planck_grid(
      KC_TAB , KC_Q,    KC_W,    KC_F,    KC_P,    KC_G,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSPC,
      KC_BSPC, KC_A,    KC_R,    KC_S,    KC_T,    KC_D,    KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
      KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, SFT_T(KC_ENT) ,
      KC_LEAD, KC_LCTL, KC_LALT, KC_LGUI, LOWER,   KC_SPC,  KC_SPC,  RAISE,   KC_LEFT, KC_RCTL, POK3R,   KC_RGHT
   ),

   /* Lower
    * ,-----------------------------------------------------------------------------------.
    * |   ~  |   !  |   @  |   #  |   $  |   %  |   ^  |   &  |   *  |   (  |   )  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | ESC  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   _  |   +  |   {  |   }  |  |   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO ~ |ISO | | Home | End  |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER|      |      |      |      |             |      |      | CAD  |      |      |
    * `-----------------------------------------------------------------------------------'
    */
   [_LOWER] = LAYOUT_planck_grid(
      KC_TILD, KC_EXLM, KC_AT,   KC_HASH, KC_DLR,  KC_PERC, KC_CIRC, KC_AMPR,    KC_ASTR,    KC_LPRN, KC_RPRN, KC_BSPC,
      KC_ESC,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_UNDS,    KC_PLUS,    KC_LCBR, KC_RCBR, KC_PIPE,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  S(KC_NUHS), S(KC_NUBS), KC_HOME, KC_END,  _______,
      KC_LEAD, _______, _______, _______, _______, _______, _______, _______,    _______,    KC_CAD , _______, _______
   ),

   /* Raise
    * ,-----------------------------------------------------------------------------------.
    * |   `  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | Bksp |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | Del  |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |   -  |   =  |   [  |   ]  |  \   |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |ISO # |ISO / |Pg Up |Pg Dn |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER|      |      |      |      |             |      |      | LOCK |      |      |
    * `-----------------------------------------------------------------------------------'
    */
   [_RAISE] = LAYOUT_planck_grid(
      KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_BSPC,
      KC_DEL,  KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_BSLS,
      _______, KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  KC_NUHS, KC_NUBS, KC_PGUP, KC_PGDN, _______,
      KC_LEAD, _______, _______, _______, _______, _______, _______, _______, _______, KC_LOCK, _______, _______

   ),

   /* POK3R
    * ,-----------------------------------------------------------------------------------.
    * | TASK |      |      |      |      |      |      | Calc | PGDN | Home | PGUP |      |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | APP  | MUTE | VOLD | VOLU |      |      |      | Left | Down |  Up  | Right|      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      | CUT  | COPY | PASTE|      |      |      | End  | End  |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER|      |      |      |      |    KC_EMU   |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
   [_POK3R] = LAYOUT_planck_grid(
      KC_TASK, _______, _______, _______,  _______, _______, KC_CALC, KC_PGDN, KC_HOME, KC_PGUP, _______, _______,
      KC_APP , KC_MUTE, KC_VOLD, KC_VOLU,  _______, _______, KC_LEFT, KC_DOWN, KC_UP  , KC_RGHT, _______, _______,
      _______, KC_CUT , KC_COPY, KC_PASTE, _______, _______, KC_END , KC_END , _______, _______, _______, _______,
      KC_LEAD, _______, _______, _______,  _______, _______, _______, _______, _______, _______, _______, _______
   ),

   /* Adjust (Lower + Raise)
    * ,-----------------------------------------------------------------------------------.
    * |      | Reset|      |      |      |      |      |      |      |      |      |  Del |
    * |------+------+------+------+------+-------------+------+------+------+------+------|
    * | CAPS |      |      |Aud on|Audoff|AGnorm|AGswap|Qwerty|Colemk|      |Insert|      |
    * |------+------+------+------+------+------|------+------+------+------+------+------|
    * |      |Voice-|Voice+|Mus on|Musoff|MIDIon|MIDIof|      |      |      |      |      |
    * |------+------+------+------+------+------+------+------+------+------+------+------|
    * |LEADER|      |      |      |      |    KC_EMU   |      |      |      |      |      |
    * `-----------------------------------------------------------------------------------'
    */
   [_ADJUST] = LAYOUT_planck_grid(
      _______, RESET,   _______, _______, _______, _______, _______, _______, _______, KC_PAUS, KC_PSCR, KC_DEL ,
      KC_CAPS, _______, MU_MOD,  AU_ON,   AU_OFF,  AG_NORM, AG_SWAP, QWERTY,  COLEMAK, _______, KC_INS,  _______,
      _______, MUV_DE,  MUV_IN,  MU_ON,   MU_OFF,  MI_ON,   MI_OFF,  _______, _______, _______, _______, _______,
      KC_LEAD, _______, _______, _______, _______, KC_EMU , KC_EMU , _______, _______, PASSWD,  _______, _______
   )

};

void update_quad_layer(uint8_t layer1, uint8_t layer2, uint8_t layer3, uint8_t layer4) {
  if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
    layer_on(layer3);
  } else if (IS_LAYER_ON(layer4)) {
    layer_on(layer4);
  } else {
    layer_off(layer3);
  }
}


/*layer_state_t layer_state_set_user(layer_state_t state) {*/
  /*return update_tri_layer_state(state, _LOWER, _RAISE, _ADJUST);*/
/*}*/


// LEADER KEY SECTION

bool did_leader_succeed;

#ifdef AUDIO_ENABLE
float leader_starter[][2] = SONG(VIOLIN_SOUND);
float leader_succeed[][2] = SONG(ONE_UP_SOUND);
float leader_failure[][2] = SONG(MINOR_SOUND);
#endif

LEADER_EXTERNS();

void matrix_scan_user(void) {
   LEADER_DICTIONARY() {
      did_leader_succeed = leading = false;

      SEQ_ONE_KEY(PASSWD) {
         SEND_STRING("tsraTSRA!@#$1234");
         did_leader_succeed = true;
      } 
      /*SEQ_TWO_KEYS(KC_W, KC_Q) {*/
         /*SEND_STRING(SS_LCTRL("w")SS_LALT(X_F4));*/
         /*did_leader_succeed = true;*/
      /*}*/
      SEQ_ONE_KEY(KC_W) {
         SEND_STRING(SS_LCTRL("w"));
         did_leader_succeed = true;
      } 
      /*SEQ_ONE_KEY(KC_BSPC) {*/
         /*SEND_STRING(SS_LGUI(SS_LSFT(KC_BSPC)));*/
         /*did_leader_succeed = true;*/
      /*}*/
      
      leader_end();
   }
}

void leader_start(void) {
#ifdef AUDIO_ENABLE
   PLAY_SONG(leader_starter);
#endif
}

void leader_end(void) {
   if (did_leader_succeed) {
#ifdef AUDIO_ENABLE
      PLAY_SONG(leader_succeed);
#endif
   } else {
#ifdef AUDIO_ENABLE
      PLAY_SONG(leader_failure);
#endif
   }
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
   switch (keycode) {
      case QWERTY:
         if (record->event.pressed) {
            set_single_persistent_default_layer(_QWERTY);
         }
         return false;
         break;
      case COLEMAK:
         if (record->event.pressed) {
            set_single_persistent_default_layer(_COLEMAK);
         }
         return false;
         break;
      case LOWER:
         if (record->event.pressed) {
            layer_on(_LOWER);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         } else {
            layer_off(_LOWER);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         }
         return false;
         break;
      case RAISE:
         if (record->event.pressed) {
            layer_on(_RAISE);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         } else {
            layer_off(_RAISE);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         }
         return false;
         break;
      case POK3R:
         if (record->event.pressed) {
            layer_on(_POK3R);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         } else {
            layer_off(_POK3R);
            update_quad_layer(_LOWER, _RAISE, _ADJUST, _POK3R);
         }
         return false;
         break;
   }
   return true;
}
