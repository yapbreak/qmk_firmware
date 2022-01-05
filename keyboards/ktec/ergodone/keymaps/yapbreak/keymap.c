#include QMK_KEYBOARD_H
#include "version.h"

#include <print.h>

#define BASE 0 // default layer
#define FN   1 // function layer
#define MDIA 2 // media keys

enum custom_keycodes {
    PLACEHOLDER = SAFE_RANGE, // can always be here
    EPRM,
    VRSN,
    RVRSN,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* Keymap 0: Basic layer
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |   ~    |   1  |   2  |   3  |   4  |   5  | ESC  |           | Del  |   6  |   7  |   8  |   9  |   0  |   -/=  |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * | Tab    |   Q  |   W  |   E  |   R  |   T  |Backsp|           |Backsp|   Y  |   U  |   I  |   O  |   P  |   [    |
 * |--------+------+------+------+------+------|ace   |           |ace   |------+------+------+------+------+--------|
 * | LShift |   A  |   S  |   D  |   F  |   G  |------|           |------|   H  |   J  |   K  |   L  |   ;  |'/RShift|
 * |--------+------+------+------+------+------|Enter |           |Enter |------+------+------+------+------+--------|
 * | Ctrl   |   Z  |   X  |   C  |   V  |   B  |      |           |      |   N  |   M  |   ,  |   .  |   /  |\/Ctrl  |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |Fn    |      |      | Meta | Alt  |                                       |AltGR |      |      |      |   ]  |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        | Left | Up   |       | Down | Right|
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      | Cut  |       |      |      |      |
 *                                 | Space| Home |------|       |------| End  |Space |
 *                                 |      |      | Copy |       | Paste|      |      |
 *                                 `--------------------'       `--------------------'
 */
// If it accepts an argument (i.e, is a function), it doesn't need KC_.
// Otherwise, it needs KC_*
[BASE] = LAYOUT_ergodox(  // layer 0 : default
        // left hand
        KC_TILD, KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_ESC,
        KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_BSPC,
        KC_LSFT, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,
        KC_LCTL, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_ENT,
        MO(FN),  _______, _______, KC_LGUI, KC_LALT,
                                                     KC_LEFT, KC_UP,
                                                              KC_CUT,
                                            KC_SPC,  KC_HOME, KC_COPY,
        // right hand
        KC_DEL,     KC_6,     KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS,
        KC_BSPC,    KC_Y,     KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC,
                    KC_H,     KC_J,    KC_K,    KC_L,    KC_SCLN, RSFT_T(KC_QUOT),
        KC_ENT,     KC_N,     KC_M,    KC_COMM, KC_DOT,  KC_SLSH, CTL_T(KC_BSLS),
                              KC_RALT, _______, _______, KC_EQL,  KC_RBRC,
        KC_DOWN,    KC_RIGHT,
        _______,
        KC_PASTE,   KC_END,   KC_SPC
    ),
/* Keymap 1: Function Layer
 *
 * ,---------------------------------------------------.           ,--------------------------------------------------.
 * |Version  |  F1  |  F2  |  F3  |  F4  |  F5  |      |           |      |  F6  |  F7  |  F8  |  F9  |  F10 |   F11  |
 * |---------+------+------+------+------+------+------|           |------+------+------+------+------+------+--------|
 * |EPRM     |      |      |      |      |      |      |           |      |   Up |   7  |   8  |   9  |   *  |   F12  |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |DEBUG    |      |      |      |      |      |------|           |------| Down |   4  |   5  |   6  |   +  |        |
 * |---------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |RawVers  |      |      |      |      |      |      |           |      |   &  |   1  |   2  |   3  |   \  |        |
 * `---------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |       |      |      |      |      |                                       |      |    . |   0  |   =  |      |
 *   `-----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |Animat|      |       |Toggle|Solid |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |Bright|Bright|      |       |      |Hue-  |Hue+  |
 *                                 |ness- |ness+ |------|       |------|      |      |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// Function
[FN] = LAYOUT_ergodox(
       // left hand
       VRSN,    KC_F1,    KC_F2,   KC_F3,   KC_F4,   KC_F5,   _______,
       EPRM,    _______,  _______, _______, _______, _______, _______,
       DEBUG,   _______,  _______, _______, _______, _______,
       RVRSN,   _______,  _______, _______, _______, _______, _______,
       _______, MO(MDIA), _______, _______, _______,
                                                     _______, _______,
                                                              _______,
                                            _______, _______, _______,
       // right hand
       _______, KC_F6,   KC_F7,       KC_F8,    KC_F9, KC_F10,  KC_F11,
       _______, KC_UP,   KC_P7,       KC_P8,    KC_P9, KC_ASTR, KC_F12,
                KC_DOWN, KC_P4,       KC_P5,    KC_P6, KC_PPLS, _______,
       _______, KC_AMPR, KC_P1,       KC_P2,    KC_P3, KC_PSLS, _______,
                         KC_KP_COMMA, KC_PDOT,  KC_P0, KC_PEQL, _______,
       _______, _______,
       _______,
       _______, _______, _______
),
/* Keymap 2: Media and mouse keys
 *
 * ,--------------------------------------------------.           ,--------------------------------------------------.
 * |        |      |      |      |      |      |      |           |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+-------------|           |------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |Lclk  |Mclk  |Rclk  |      |        |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |------|           |------|MsLeft|MsDown|MsUp  |MsRght|      |  Play  |
 * |--------+------+------+------+------+------|      |           |      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |           |      |      |      | Prev | Next |      |        |
 * `--------+------+------+------+------+-------------'           `-------------+------+------+------+------+--------'
 *   |      |      |      |      |      |                                       |VolUp |VolDn | Mute |      |      |
 *   `----------------------------------'                                       `----------------------------------'
 *                                        ,-------------.       ,-------------.
 *                                        |      |      |       |      |      |
 *                                 ,------|------|------|       |------+------+------.
 *                                 |      |      |      |       |      |      |Brwser|
 *                                 |      |      |------|       |------|      |Back  |
 *                                 |      |      |      |       |      |      |      |
 *                                 `--------------------'       `--------------------'
 */
// MEDIA AND MOUSE
[MDIA] = LAYOUT_ergodox(
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______, _______, _______,
       _______, _______, _______, _______, _______,
                                           _______, _______,
                                                    _______,
                                  _______, _______, _______,
    // right hand
       _______,  _______, _______, _______, _______, _______, _______,
       _______,  _______, KC_BTN1, KC_BTN3, KC_BTN2, _______, _______,
                 KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, _______, KC_MPLY,
       _______,  _______, _______, KC_MPRV, KC_MNXT, _______, _______,
                          KC_VOLU, KC_VOLD, KC_MUTE, _______, _______,
       _______, _______,
       _______,
       _______, _______, KC_WBAK
),
};

const uint8_t ascii_us_to_bepo[128] = {
    // NUL   SOH      STX      ETX      EOT      ENQ      ACK      BEL
    0x00,    0x01,    0x02,    0x03,    0x04,    0x05,    0x06,    0x07,
    // BS    TAB      LF       VT       FF       CR       SO       SI
    0x08,    0x09,    0x0a,    0x0b,    0x0c,    0x0d,    0x0e,    0x0f,
    // DLE   DC1      DC2      DC3      DC4      NAK      SYN      ETB
    0x10,    0x11,    0x12,    0x13,    0x14,    0x15,    0x16,    0x17,
    // CAN   EM       SUB      ESC      FS       GS       RS       US
    0x18,    0x19,    0x1a,    0x1b,    0x1c,    0x1d,    0x1e,    0x1f,
    //       !        "        #        $        %        &        '
    0x20,    'Y',     '1',     '~',     '`',     '=',     ' ',     'n',
    // (     )        *        +        ,        -        .        /
    '4',     '5',     '0',     '7',     'g',     '8',     'v',     '9',
    // 0     1        2        3        4        5        6        7
    ')',     '!',     '@',     '#',     '$',     '%',     '^',     '&',
    // 8     9        :        ;        <        =        >        ?
    '*',     '(',     'V',     'G',     ' ',     '-',     ' ',     'N',
    // @     A        B        C        D        E        F        G
    '6',     'A',     'Q',     'H',     'I',     'F',     '?',     '<',
    // H     I        J        K        L        M        N        O
    '>',     'D',     'P',     'B',     'O',     '"',     ':',     'R',
    // P     Q        R        S        T        U        V        W
    'E',     'M',     'L',     'K',     'J',     'S',     'U',     '}',
    // X     Y        Z        [        \        ]        ^        _
    'C',     'X',     '{',     ' ',     ' ',     ' ',     ' ',     ' ',
    // `     a        b        c        d        e        f        g
    ' ',     'a',     'q',     'h',     'i',     'f',     '/',     ',',
    // h     i        j        k        l        m        n        o
    '.',     'd',     'p',     'b',     'o',     '\'',    ';',     'r',
    // p     q        r        s        t        u        v        w
    'e',     'm',     'l',     'k',     'j',     's',     'u',     ']',
    // x     y        z        {        |        }        ~        DEL
    'c',     'x',     '[',     ' ',     ' ',     ' ',     ' ',     0x7f
};

static char qwerty_to_bepo_ascii(const char input)
{
    return input < 0x80 ? ascii_us_to_bepo[(size_t) input] : input;
}

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        // dynamically generate these.
        case EPRM:
            if (record->event.pressed)
                eeconfig_init();
            return false;
        case VRSN:
            if (record->event.pressed) {
                const char version[] = QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION;
                char bepo_version[sizeof(version)] = {};
                const char *pch_version = version;
                char *pch_bepo_version = bepo_version;
                while (*pch_version != '\0') {
                    *(pch_bepo_version++) = qwerty_to_bepo_ascii(*pch_version);
                    pch_version++;
                }
                send_string(bepo_version);
            }
            return false;
        case RVRSN:
            if (record->event.pressed)
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
            return false;
        case KC_LSFT:
        case KC_RSFT:
            // TODO: this is an attempt but does not work well as expected.
            if (IS_PRESSED(record->event))
                ergodox_board_led_on();
            else if (IS_RELEASED(record->event))
                ergodox_board_led_off();
  }
  return true;
}

// Runs constantly in the background, in a loop.
void matrix_scan_user(void) {

    uint8_t layer = biton32(layer_state);

    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();
    switch (layer) {
        case 1:
            ergodox_right_led_1_on();
            break;
        case 2:
            ergodox_right_led_2_on();
            break;
        default:
            // none
            break;
    }
}
