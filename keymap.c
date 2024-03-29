#include QMK_KEYBOARD_H

// Layer shorthand
#define _QWERTY 0
#define _NAV_KEY 1
#define _NAV_MOUSE 2
#define _MEDIA 3
#define _NUM 4
#define _SYM 5
#define _FN 6
#define _FR 7
#define _QWERTY_NO_HOMEROW 8

// French chars
enum unicode_names {
  E_AIG,
  E_AIG_MAJ,
  E_GRV,
  E_GRV_MAJ,
  E_CIRC,
  E_CIRC_MAJ,
  E_TREMA,
  E_TREMA_MAJ,
  A_CIRC,
  A_CIRC_MAJ,
  A_GRV,
  A_GRV_MAJ,
  C_CEDILLE,
  C_CEDILLE_MAJ,
  CARRE,
  CUBE,
  EURO,
  BAHT,
  COPYRIGHT,
  REGISTERED,
  OMEGA,
  OMEGA_MAJ,
  O_CIRC,
  O_CIRC_MAJ,
  U_GRAV,
  U_GRAV_MAJ,
  OE,
  OE_MAJ,
  PI,
  DEGREE,
  N_TILDE,
  N_TILDE_MAJ,
  MICRO,
  SIGMA,
  INFEQ,
  SUPEQ,
  GUILL_G,
  GUILL_R,
  UNEQUAL,
  PRETTYMUCH,
  INFINIT,
  I_TREMA,
  I_TREMA_MAJ,
  I_CIRC,
  I_CIRC_MAJ
};

const uint32_t PROGMEM unicode_map[] = {
    [E_AIG] = 0x00E9,         // 0 é
    [E_AIG_MAJ] = 0x00C9,     // 1 É
    [E_GRV] = 0x00E8,         // 2 è
    [E_GRV_MAJ] = 0x00C8,     // 3 È
    [E_CIRC] = 0x00EA,        // 4 ê
    [E_CIRC_MAJ] = 0x00CA,    // 5 Ê
    [E_TREMA] = 0x00EB,       // 6 ë
    [E_TREMA_MAJ] = 0x00CB,   // 7 Ë
    [A_CIRC] = 0x00E2,        // 8 â
    [A_CIRC_MAJ] = 0x00C2,    // 9 Ê
    [A_GRV] = 0x00E0,         // 10 à
    [A_GRV_MAJ] = 0x00C0,     // 11 À
    [C_CEDILLE] = 0x00E7,     // 12 ç
    [C_CEDILLE_MAJ] = 0x00C7, // 13 Ç
    [CARRE] = 0x00B2,         // 14 ²
    [CUBE] = 0x00B3,          // 15 ³
    [EURO] = 0x20AC,          // 16 €
    [BAHT] = 0x0E3F,          // 17 ฿
    [COPYRIGHT] = 0x00A9,     // 18 ©
    [REGISTERED] = 0x00AE,    // 19 ®
    [OMEGA] = 0x03C9,         // 20 ω
    [OMEGA_MAJ] = 0x03A9,     // 21 Ω
    [O_CIRC] = 0x00F4,        // 22 ô
    [O_CIRC_MAJ] = 0x00D4,    // 23 Ô
    [U_GRAV] = 0x00F9,        // 24 ù
    [U_GRAV_MAJ] = 0x00D9,    // 25 Ù
    [OE] = 0x0153,            // 26 œ
    [OE_MAJ] = 0x0152,        // 27 Œ
    [PI] = 0x03C0,            // 28 π
    [DEGREE] = 0x00B0,        // 29 °
    [N_TILDE] = 0x00F1,       // 30 ñ
    [N_TILDE_MAJ] = 0x00D1,   // 31 Ñ
    [MICRO] = 0x00B5,         // 32 µ
    [SIGMA] = 0x03C3,         // 33 σ
    [INFEQ] = 0x2264,         // 34 ≤
    [SUPEQ] = 0x2265,         // 35 ≥
    [GUILL_G] = 0x00AB,       // 36 «
    [GUILL_R] = 0x00BB,       // 37 »
    [UNEQUAL] = 0x2260,       // 38 ≠
    [PRETTYMUCH] = 0x2248,    // 39 ≈
    [INFINIT] = 0x221E,       // 40 ∞
    [I_TREMA] = 0x00EF,       // 41
    [I_TREMA_MAJ] = 0x00CF,   // 42
    [I_CIRC] = 0x00EE,        // 43
    [I_CIRC_MAJ] = 0x00CE,    // 44
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* QWERTY
    * ,-----------------------------------------.                    ,-----------------------------------------.
    * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ~   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * | Alt  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
    * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
    * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
    * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
    * |LCTRL |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
    * `-----------------------------------------/       /     \      \-----------------------------------------'
    *                   | LT 8 | LT 3 | LT 2 | / LT 1  /       \ LT 5 \  | LT 4 | LT 6 | LT 7 |
    *                   |      | ESC  | Tab  |/ Space /         \Enter \ |BackSP| DEL  |      |
    *                   `-------------------''-------'           '------''--------------------'
    */
    [_QWERTY] = LAYOUT(
    KC_ESC,     KC_1,           KC_2,          KC_3,          KC_4,            KC_5,                                          KC_6,           KC_7,             KC_8,            KC_9,              KC_0,              KC_GRV, 
    KC_LALT,    KC_Q,           KC_W,          KC_E,          KC_R,            KC_T,                                          KC_Y,           KC_U,             KC_I,            KC_O,              KC_P,              KC_MINS, 
    KC_LSFT,    LGUI_T(KC_A),   LALT_T(KC_S),  LCTL_T(KC_D),  LSFT_T(KC_F),    KC_G,                                          KC_H,           LSFT_T(KC_J),     LCTL_T(KC_K),    LALT_T(KC_L),      LGUI_T(KC_SCLN),   KC_QUOT, 
    KC_LCTL,    KC_Z,           RALT_T(KC_X),  KC_C,          KC_V,            KC_B,           KC_LBRC,      KC_RBRC,         KC_N,           KC_M,             KC_COMM,         RALT_T(KC_DOT),    KC_SLSH,           KC_RSFT, 
                                TG(8),         LT(3,KC_ESC),  LT(2,KC_TAB),    LT(1,KC_SPC),                                  LT(5,KC_ENT),   LT(4,KC_BSPC),    LT(6,KC_DEL),    LT(7,KC_NO)),
    [_NAV_KEY] = LAYOUT(
    QK_RBT,     KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO,
    KC_NO,      KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_AGIN,        KC_UNDO,          KC_CUT,          KC_COPY,           KC_PSTE,           KC_NO, 
    KC_NO,      KC_LGUI,        KC_LALT,       KC_LCTL,       KC_LSFT,         KC_NO,                                         KC_LEFT,        KC_DOWN,          KC_UP,           KC_RGHT,           KC_CAPS,           KC_NO,
    KC_NO,      KC_NO,          KC_RALT,       KC_NO,         KC_NO,           KC_NO,          KC_NO,        KC_NO,           KC_INS,         KC_HOME,          KC_PGUP,         KC_PGDN,           KC_END,            KC_NO, 
                                KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_ENT,         KC_BSPC,          KC_DEL,          KC_NO),
    [_NAV_MOUSE] = LAYOUT(
    QK_RBT,     KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO, 
    KC_NO,      KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_WH_L,        KC_WH_D,          KC_WH_U,         KC_WH_R,           KC_NO,             KC_NO, 
    KC_NO,      KC_LGUI,        KC_LALT,       KC_LCTL,       KC_LSFT,         KC_NO,                                         KC_MS_L,        KC_MS_D,          KC_MS_U,         KC_MS_R,           KC_NO,             KC_NO, 
    KC_NO,      KC_NO,          KC_RALT,       KC_NO,         KC_NO,           KC_NO,          KC_NO,        KC_NO,           KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO,  
                                KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_BTN1,        KC_BTN2,          KC_BTN3,         KC_NO),
    [_MEDIA] = LAYOUT(
    QK_RBT,     KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO,
    KC_NO,      KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO,  
    KC_NO,      KC_LGUI,        KC_LALT,       KC_LCTL,       KC_LSFT,         KC_NO,                                         KC_MPRV,        KC_VOLD,          KC_VOLU,         KC_MNXT,           KC_NO,             KC_NO, 
    KC_NO,      KC_NO,          KC_RALT,       KC_NO,         KC_NO,           KC_NO,          KC_NO,        KC_NO,           KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO, 
                                KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_MSTP,        KC_MPLY,          KC_MUTE,         KC_NO),
    [_NUM] = LAYOUT(
    KC_NO,      KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             QK_RBT,
    KC_NO,      KC_LBRC,        KC_7,          KC_8,          KC_9,            KC_RBRC,                                       KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO, 
    KC_NO,      KC_SCLN,        KC_4,          KC_5,          KC_6,            KC_EQL,                                        KC_NO,          KC_LSFT,          KC_LCTL,         KC_LALT,           KC_LGUI,           KC_NO,
    KC_NO,      KC_GRV,         KC_1,          KC_2,          KC_3,            KC_BSLS,        KC_NO,        KC_NO,           KC_NO,          KC_NO,            KC_NO,           KC_RALT,           KC_NO,             KC_NO,
                                KC_DOT,        KC_MINS,       KC_0,            KC_SPC,                                        KC_NO,          KC_NO,            KC_NO,           KC_NO),
    [_SYM] = LAYOUT(
    KC_NO,      KC_NO,          KC_NO,         KC_NO,         KC_NO,           KC_NO,                                         KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             QK_RBT,             
    KC_NO,      KC_LCBR,        KC_AMPR,       KC_ASTR,       KC_LPRN,         KC_RCBR,                                       KC_NO,          KC_NO,            KC_NO,           KC_NO,             KC_NO,             KC_NO, 
    KC_NO,      KC_COLN,        KC_DLR,        KC_PERC,       KC_CIRC,         KC_PLUS,                                       KC_NO,          KC_LSFT,          KC_LCTL,         KC_LALT,           KC_LGUI,           KC_NO, 
    KC_NO,      KC_TILD,        KC_EXLM,       KC_AT,         KC_HASH,         KC_PIPE,        KC_NO,        KC_NO,           KC_NO,          KC_NO,            KC_NO,           KC_RALT,           KC_NO,             KC_NO,
                                KC_UNDS,       KC_LPRN,       KC_RPRN,         KC_SPC,                                        KC_NO,          KC_NO,            KC_NO,           KC_NO),
    [_FN] = LAYOUT(
    KC_NO,      KC_NO,          KC_F10,        KC_F11,        KC_F12,          KC_PSCR,                                       KC_NO,           KC_NO,            KC_NO,          KC_NO,              KC_NO,            QK_RBT, 
    KC_NO,      KC_NO,          KC_F7,         KC_F8,         KC_F9,           KC_NO,                                         KC_NO,           KC_NO,            KC_NO,          KC_NO,              KC_NO,            KC_NO, 
    KC_NO,      KC_NO,          KC_F4,         KC_F5,         KC_F6,           KC_PAUS,                                       KC_NO,           KC_LSFT,          KC_LCTL,        KC_LALT,            KC_LGUI,          KC_NO, 
    KC_NO,      KC_NO,          KC_F1,         KC_F2,         KC_F3,           KC_NO,          KC_NO,        KC_NO,           KC_NO,           KC_NO,            KC_NO,          KC_RALT,            KC_NO,            KC_NO, 
                                KC_NO,         KC_APP,        KC_TAB,          KC_SPC,                                        KC_NO,           KC_NO,            KC_NO,          KC_NO),
    [_FR] = LAYOUT(
    KC_NO,      KC_NO,          KC_NO,         X(16),         KC_NO,           KC_NO,                                         KC_NO,           KC_NO,            XP(41,42),      KC_NO,              KC_NO,            KC_NO, 
    KC_NO,      XP(26,27),      UC_M_WC,       XP(0,1),       XP(2,3),         XP(4,5),                                       KC_NO,           XP(24,25),        XP(43,44),      XP(22,23),          KC_NO,            KC_NO, 
    KC_NO,      XP(10,11),      XP(8,9),       KC_NO,         LSFT_T(KC_NO),   XP(6,7),                                       KC_NO,           LSFT_T(KC_NO),    KC_NO,          UC_M_LN,            KC_NO,            KC_NO, 
    KC_NO,      KC_NO,          KC_NO,         XP(12,13),     KC_NO,           KC_NO,          KC_NO,        KC_NO,           KC_NO,           KC_NO,            KC_NO,          KC_NO,              KC_NO,            KC_NO,
    	                          KC_NO,         KC_NO,         KC_NO,           KC_SPC,                                        KC_NO,           KC_NO,            KC_NO,          KC_NO),
    [_QWERTY_NO_HOMEROW] = LAYOUT(
    KC_ESC,     KC_1,           KC_2,          KC_3,          KC_4,            KC_5,                                          KC_6,            KC_7,             KC_8,           KC_9,               KC_0,             KC_GRV, 
    KC_LALT,    KC_Q,           KC_W,          KC_E,          KC_R,            KC_T,                                          KC_Y,            KC_U,             KC_I,           KC_O,               KC_P,             KC_MINS, 
    KC_LSFT,    KC_A,           KC_S,          KC_D,          KC_F,            KC_G,                                          KC_H,            KC_J,             KC_K,           KC_L,               KC_SCLN,          KC_QUOT, 
    KC_LCTL,    KC_Z,           KC_X,          KC_C,          KC_V,            KC_B,           KC_LBRC,      KC_RBRC,         KC_N,            KC_M,             KC_COMM,        KC_DOT,             KC_SLSH,          KC_RSFT, 
                                TG(8),         KC_ESC,        KC_TAB,          KC_SPC,                                        KC_ENT,          KC_BSPC,          KC_DEL,         KC_NO),
};