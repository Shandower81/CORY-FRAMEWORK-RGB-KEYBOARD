// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

// The layouts are all mostly the same, except for the extra keys that the different layouts have
#define LAYOUT( \
    K1,    K2,    K3,    K4,    K5,    K6,    K7,    K8,    K9,    K10,   K11,   K12,   K13,   K14, \
    K15,   K16,   K17,   K18,   K19,   K20,   K21,   K22,   K23,   K24,   K25,   K26,   K27,   K28, \
    K29,   K30,   K31,   K32,   K33,   K34,   K35,   K36,   K37,   K38,   K39,   K40,   K41,   K42, \
    K43,   K44,   K45,   K46,   K47,   K48,   K49,   K50,   K51,   K52,   K53,   K54,          K55, \
    K56,   K57,   K58,   K59,   K60,   K61,   K62,   K63,   K64,   K65,   K66,                 K67, \
    K68,   K69,   K70,   K71,             K72,              K73,   K74,   K75,   K76,   K77,   K78  \
) \
{ \
  { K59,   K14,   K30,   K73,   KC_NO, K58,   K60,   K63,   K65,   K67,   K64,   KC_NO, K74,   K66,   K54,   KC_NO }, \
  { KC_NO, KC_NO, KC_NO, K71,   K72,   K57,   K61,   K62,   K77,   K56,   KC_NO, KC_NO, K68,   K76,   K55,   K9    }, \
  { KC_NO, KC_NO, K69,   KC_NO, K32,   K3,    K48,   K49,   K42,   KC_NO, K8,    KC_NO, KC_NO, K26,   KC_NO, K78   }, \
  { KC_NO, K70,   K29,   KC_NO, K5,    K2,    K34,   K35,   K38,   KC_NO, K7,    K10,   KC_NO, K13,   KC_NO, KC_NO }, \
  { KC_NO, KC_NO, K15,   KC_NO, K43,   K45,   K20,   K21,   K11,   KC_NO, K6,    KC_NO, KC_NO, K25,   K27,   KC_NO }, \
  { KC_NO, KC_NO, K16,   KC_NO, K18,   K17,   K19,   K22,   K24,   KC_NO, K23,   KC_NO, KC_NO, K39,   K28,   KC_NO }, \
  { KC_NO, KC_NO, KC_NO, KC_NO, K4,    K31,   K33,   K36,   K12,   KC_NO, K37,   K75,   KC_NO, K40,   K41,   KC_NO }, \
  { KC_NO, KC_NO, K44,   KC_NO, KC_NO, K1,    K47,   K50,   K52,   KC_NO, K51,   KC_NO, KC_NO, K53,   K46,   KC_NO }  \
}
