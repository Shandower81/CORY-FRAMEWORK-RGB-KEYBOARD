// Copyright 2022 Framework Computer
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#if defined(RGB_MATRIX_ENABLE)
#define CS19_SW12 0x00
#define CS20_SW12 0x01
#define CS21_SW12 0x02
#define CS22_SW12 0x03
#define CS23_SW12 0x04
#define CS24_SW12 0x05
#define CS25_SW12 0x06
#define CS26_SW12 0x07
#define CS27_SW12 0x08
#define CS28_SW12 0x09
#define CS29_SW12 0x0A
#define CS30_SW12 0x0B
#define CS31_SW12 0x0C
#define CS32_SW12 0x0D
#define CS33_SW12 0x0E
#define CS34_SW12 0x0F
#define CS35_SW12 0x10
#define CS36_SW12 0x11

#define CS19_SW13 0x12
#define CS20_SW13 0x13
#define CS21_SW13 0x14
#define CS22_SW13 0x15
#define CS23_SW13 0x16
#define CS24_SW13 0x17
#define CS25_SW13 0x18
#define CS26_SW13 0x19
#define CS27_SW13 0x1A
#define CS28_SW13 0x1B
#define CS29_SW13 0x1C
#define CS30_SW13 0x1D
#define CS31_SW13 0x1E
#define CS32_SW13 0x1F
#define CS33_SW13 0x20
#define CS34_SW13 0x21
#define CS35_SW13 0x22
#define CS36_SW13 0x23

#define CS19_SW14 0x24
#define CS20_SW14 0x25
#define CS21_SW14 0x26
#define CS22_SW14 0x27
#define CS23_SW14 0x28
#define CS24_SW14 0x29
#define CS25_SW14 0x2A
#define CS26_SW14 0x2B
#define CS27_SW14 0x2C
#define CS28_SW14 0x2D
#define CS29_SW14 0x2E
#define CS30_SW14 0x2F
#define CS31_SW14 0x30
#define CS32_SW14 0x31
#define CS33_SW14 0x32
#define CS34_SW14 0x33
#define CS35_SW14 0x34
#define CS36_SW14 0x35

#define CS19_SW15 0x36
#define CS20_SW15 0x37
#define CS21_SW15 0x38
#define CS22_SW15 0x39
#define CS23_SW15 0x3A
#define CS24_SW15 0x3B
#define CS25_SW15 0x3C
#define CS26_SW15 0x3D
#define CS27_SW15 0x3E
#define CS28_SW15 0x3F
#define CS29_SW15 0x40
#define CS30_SW15 0x41
#define CS31_SW15 0x42
#define CS32_SW15 0x43
#define CS33_SW15 0x44
#define CS34_SW15 0x45
#define CS35_SW15 0x46
#define CS36_SW15 0x47

#define CS19_SW16 0x48
#define CS20_SW16 0x49
#define CS21_SW16 0x4A
#define CS22_SW16 0x4B
#define CS23_SW16 0x4C
#define CS24_SW16 0x4D
#define CS25_SW16 0x4E
#define CS26_SW16 0x4F
#define CS27_SW16 0x50
#define CS28_SW16 0x51
#define CS29_SW16 0x52
#define CS30_SW16 0x53
#define CS31_SW16 0x54
#define CS32_SW16 0x55
#define CS33_SW16 0x56
#define CS34_SW16 0x57
#define CS35_SW16 0x58
#define CS36_SW16 0x59

#define CS19_SW17 0x5A
#define CS20_SW17 0x5B
#define CS21_SW17 0x5C
#define CS22_SW17 0x5D
#define CS23_SW17 0x5E
#define CS24_SW17 0x5F
#define CS25_SW17 0x60
#define CS26_SW17 0x61
#define CS27_SW17 0x62
#define CS28_SW17 0x63
#define CS29_SW17 0x64
#define CS30_SW17 0x65
#define CS31_SW17 0x66
#define CS32_SW17 0x67
#define CS33_SW17 0x68
#define CS34_SW17 0x69
#define CS35_SW17 0x6A
#define CS36_SW17 0x6B

#define CS19_SW18 0x6C
#define CS20_SW18 0x6D
#define CS21_SW18 0x6E
#define CS22_SW18 0x6F
#define CS23_SW18 0x70
#define CS24_SW18 0x71
#define CS25_SW18 0x72
#define CS26_SW18 0x73
#define CS27_SW18 0x74
#define CS28_SW18 0x75
#define CS29_SW18 0x76
#define CS30_SW18 0x77
#define CS31_SW18 0x78
#define CS32_SW18 0x79
#define CS33_SW18 0x7A
#define CS34_SW18 0x7B
#define CS35_SW18 0x7C
#define CS36_SW18 0x7D

#define CS19_SW19 0x7E
#define CS20_SW19 0x7F
#define CS21_SW19 0x80
#define CS22_SW19 0x81
#define CS23_SW19 0x82
#define CS24_SW19 0x83
#define CS25_SW19 0x84
#define CS26_SW19 0x85
#define CS27_SW19 0x86
#define CS28_SW19 0x87
#define CS29_SW19 0x88
#define CS30_SW19 0x89
#define CS31_SW19 0x8A
#define CS32_SW19 0x8B
#define CS33_SW19 0x8C
#define CS34_SW19 0x8D
#define CS35_SW19 0x8E
#define CS36_SW19 0x8F

#define CS19_SW20 0x90
#define CS20_SW20 0x91
#define CS21_SW20 0x92
#define CS22_SW20 0x93
#define CS23_SW20 0x94
#define CS24_SW20 0x95
#define CS25_SW20 0x96
#define CS26_SW20 0x97
#define CS27_SW20 0x98
#define CS28_SW20 0x99
#define CS29_SW20 0x9A
#define CS30_SW20 0x9B
#define CS31_SW20 0x9C
#define CS32_SW20 0x9D
#define CS33_SW20 0x9E
#define CS34_SW20 0x9F
#define CS35_SW20 0xA0
#define CS36_SW20 0xA1

// TODO: Should have attribute __flash. But won't compile if I add it
const is31_led g_is31_leds[RGB_MATRIX_LED_COUNT] = {
/* Refer to IS31 manual for these locations
 *   driver
 *   |    R location
 *   |    |          G location
 *   |    |          |          B location
 *   |    |          |          | */
    // Re-arranged in LED ID order so it matches with the physical location array
    {0,   CS9_SW8,   CS8_SW8,   CS7_SW8}, // LED 1     (26)
    {0,   CS9_SW6,   CS8_SW6,   CS7_SW6}, // LED 2     (24)

    {0,   CS9_SW4,   CS8_SW4,   CS7_SW4}, // LED 3     (22)
    {0,   CS9_SW2,   CS8_SW2,   CS7_SW2}, // LED 4     (20)
    {0,   CS9_SW1,   CS8_SW1,   CS7_SW1}, // LED 5     (19)
    {0,   CS9_SW3,   CS8_SW3,   CS7_SW3}, // LED 6     (21)
    {0,   CS9_SW5,   CS8_SW5,   CS7_SW5}, // LED 7     (23)
    {0,   CS9_SW7,   CS8_SW7,   CS7_SW7}, // LED 8     (25)
    {0,   CS9_SW9,   CS8_SW9,   CS7_SW9}, // LED 9     (27)
    {1, CS27_SW13, CS26_SW13, CS25_SW13}, // LED 10    (68)
    {1, CS27_SW14, CS26_SW14, CS25_SW14}, // LED 11    (75)
    {1, CS27_SW15, CS26_SW15, CS25_SW15}, // LED 12    (69)

    {1, CS27_SW12, CS26_SW12, CS25_SW12}, // LED 13    (67)
    {1, CS27_SW18, CS26_SW18, CS25_SW18}, // LED 14    (72)
    {1, CS27_SW17, CS26_SW17, CS25_SW17}, // LED 15    (71)
    {1, CS27_SW19, CS26_SW19, CS25_SW19}, // LED 16    (73)
    {1, CS27_SW20, CS26_SW20, CS25_SW20}, // LED 17    (74)

    {0,   CS6_SW8,   CS5_SW8,   CS4_SW8}, // LED 18    (17)
    {0,   CS6_SW6,   CS5_SW6,   CS4_SW6}, // LED 19    (16)
    {0,   CS6_SW4,   CS5_SW4,   CS4_SW4}, // LED 20    (14)
    {0,   CS6_SW2,   CS5_SW2,   CS4_SW2}, // LED 21    (13)
    {0,   CS6_SW1,   CS5_SW1,   CS4_SW1}, // LED 22    (12)
    {0,   CS6_SW3,   CS5_SW3,   CS4_SW3}, // LED 23    (10)
    {0,   CS6_SW5,   CS5_SW5,   CS4_SW5}, // LED 24    (15)
    {0,   CS6_SW7,   CS5_SW7,   CS4_SW7}, // LED 25    (11)
    {0,   CS6_SW9,   CS5_SW9,   CS4_SW9}, // LED 26    (18)
    {1, CS27_SW16, CS26_SW16, CS25_SW16}, // LED 27    (70)
    {1, CS24_SW16, CS23_SW16, CS22_SW16}, // LED 28    (62)
    {1, CS24_SW18, CS23_SW18, CS22_SW18}, // LED 29    (64)
    {1, CS24_SW17, CS23_SW17, CS22_SW17}, // LED 30    (63)

    {1, CS24_SW19, CS23_SW19, CS22_SW19}, // LED 31    (65)
    {1, CS24_SW20, CS23_SW20, CS22_SW20}, // LED 32    (66)

    {0,   CS3_SW8,   CS2_SW8,   CS1_SW8}, // LED 33    (2)
    {0,   CS3_SW6,   CS2_SW6,   CS1_SW6}, // LED 34    (1)

    {0,   CS3_SW4,   CS2_SW4,   CS1_SW4}, // LED 35    (6)
    {0,   CS3_SW2,   CS2_SW2,   CS1_SW2}, // LED 36    (4)
    {0,   CS3_SW1,   CS2_SW1,   CS1_SW1}, // LED 37    (3)
    {0,   CS3_SW3,   CS2_SW3,   CS1_SW3}, // LED 38    (5)
    {0,   CS3_SW5,   CS2_SW5,   CS1_SW5}, // LED 39    (8)
    {0,   CS3_SW7,   CS2_SW7,   CS1_SW7}, // LED 40    (9)
    {0,   CS3_SW9,   CS2_SW9,   CS1_SW9}, // LED 41    (7)
    {1, CS24_SW13, CS23_SW13, CS22_SW13}, // LED 42    (59)
    {1, CS24_SW14, CS23_SW14, CS22_SW14}, // LED 43    (60)
    {1, CS24_SW15, CS23_SW15, CS22_SW15}, // LED 44    (61)
    {1, CS24_SW12, CS23_SW12, CS22_SW12}, // LED 45    (58)
    {1, CS21_SW18, CS20_SW18, CS19_SW18}, // LED 46    (55)

    {1, CS21_SW19, CS20_SW19, CS19_SW19}, // LED 47    (56)

    {0,  CS15_SW8,  CS14_SW8,  CS13_SW8}, // LED 48    (45)
    {0,  CS15_SW6,  CS14_SW6,  CS13_SW6}, // LED 49    (39)
    {0,  CS15_SW4,  CS14_SW4,  CS13_SW4}, // LED 50    (43)

    {0,  CS15_SW2,  CS14_SW2,  CS13_SW2}, // LED 51    (37)
    {0,  CS15_SW1,  CS14_SW1,  CS13_SW1}, // LED 52    (42)
    {0,  CS15_SW3,  CS14_SW3,  CS13_SW3}, // LED 53    (38)
    {0,  CS15_SW5,  CS14_SW5,  CS13_SW5}, // LED 54    (44)
    {0,  CS15_SW7,  CS14_SW7,  CS13_SW7}, // LED 55    (40)
    {0,  CS15_SW9,  CS14_SW9,  CS13_SW9}, // LED 56    (41)
    {1, CS21_SW13, CS20_SW13, CS19_SW13}, // LED 57    (50)
    {1, CS21_SW14, CS20_SW14, CS19_SW14}, // LED 58    (51)
    {1, CS21_SW15, CS20_SW15, CS19_SW15}, // LED 59    (52)
    {1, CS21_SW12, CS20_SW12, CS19_SW12}, // LED 60    (49)
    {1, CS21_SW16, CS20_SW16, CS19_SW16}, // LED 61    (53)

    {1, CS21_SW17, CS20_SW17, CS19_SW17}, // LED 62    (54)
    {1, CS21_SW20, CS20_SW20, CS19_SW20}, // LED 63    (57)

    {0,  CS12_SW6,  CS11_SW6,  CS10_SW6}, // LED 64    (33)
    {0,  CS12_SW4,  CS11_SW4,  CS10_SW4}, // LED 65    (31)
    {0,  CS12_SW2,  CS11_SW2,  CS10_SW2}, // LED 66    (29)

    {0,  CS12_SW1,  CS11_SW1,  CS10_SW1}, // LED 67    (28)
    {0,  CS12_SW3,  CS11_SW3,  CS10_SW3}, // LED 68    (30)
    {0,  CS12_SW5,  CS11_SW5,  CS10_SW5}, // LED 69    (32)
    {0,  CS12_SW7,  CS11_SW7,  CS10_SW7}, // LED 70    (34)
    {0,  CS12_SW9,  CS11_SW9,  CS10_SW9}, // LED 71    (36)
    {1, CS30_SW13, CS29_SW13, CS28_SW13}, // LED 72    (77)
    {1, CS30_SW14, CS29_SW14, CS28_SW14}, // LED 73    (78)
    {1, CS30_SW15, CS29_SW15, CS28_SW15}, // LED 74    (79)
    {1, CS30_SW12, CS29_SW12, CS28_SW12}, // LED 75    (76)
    {1, CS30_SW16, CS29_SW16, CS28_SW16}, // LED 76    (80)

    {1, CS30_SW17, CS29_SW17, CS28_SW17}, // LED 77    (81)
    {1, CS30_SW19, CS29_SW19, CS28_SW19}, // LED 78    (83)
    {1, CS30_SW20, CS29_SW20, CS28_SW20}, // LED 79    (84)
    {1, CS33_SW20, CS32_SW20, CS31_SW20}, // LED 80    (93)

    {0,  CS12_SW8,  CS11_SW8,  CS10_SW8}, // LED 81    (35)
    {0,  CS18_SW1,  CS17_SW1,  CS16_SW1}, // LED 82    (46)
    {1, CS36_SW12, CS35_SW12, CS34_SW12}, // LED 83    (94)
    {0,  CS18_SW2,  CS17_SW2,  CS16_SW2}, // LED 84    (47)
    {0,  CS18_SW3,  CS17_SW3,  CS16_SW3}, // LED 85    (48)
    {1, CS36_SW13, CS35_SW13, CS34_SW13}, // LED 86    (95)
    {1, CS36_SW14, CS35_SW14, CS34_SW14}, // LED 87    (96)
    {1, CS36_SW15, CS35_SW15, CS34_SW15}, // LED 88    (97)
    {1, CS33_SW13, CS32_SW13, CS31_SW13}, // LED 89    (86)
    {1, CS33_SW14, CS32_SW14, CS31_SW14}, // LED 90    (87)
    {1, CS33_SW15, CS32_SW15, CS31_SW15}, // LED 91    (88)
    {1, CS33_SW12, CS32_SW12, CS31_SW12}, // LED 92    (85)
    {1, CS33_SW16, CS32_SW16, CS31_SW16}, // LED 93    (89)
    {1, CS33_SW17, CS32_SW17, CS31_SW17}, // LED 94    (90)
    {1, CS33_SW18, CS32_SW18, CS31_SW18}, // LED 95    (91)
    {1, CS30_SW18, CS29_SW18, CS28_SW18}, // LED 96    (82)
    {1, CS33_SW19, CS32_SW19, CS31_SW19}, // LED 97    (92)
};

led_config_t g_led_config = { {
  // Key Matrix to LED Index      (Zeroed LED ID's Used)
  {64,     15,     37,     78,     NO_LED, 65,     63,     71,     10,     96,     72,     NO_LED, 90,     73,     58,     NO_LED, }, // 13
  {NO_LED, NO_LED, NO_LED, 83,     82,     8,      80,     74,     93,     68,     NO_LED, NO_LED, 69,     76,     46,     12,     }, // 11
  {NO_LED, NO_LED, 79,     NO_LED, 32,     4,      48,     54,     45,     NO_LED, 0,      NO_LED, NO_LED, 29,     NO_LED, 94,     }, // 9
  {NO_LED, 81,     33,     NO_LED, 3,      5,      40,     38,     41,     NO_LED, 1,      16,     NO_LED, 26,     NO_LED, NO_LED, }, // 10
  {NO_LED, NO_LED, 18,     NO_LED, 53,     55,     39,     19,     9,      NO_LED, 2,      NO_LED, NO_LED, 43,     27,     NO_LED, }, // 9
  {NO_LED, NO_LED, 23,     NO_LED, 21,     20,     24,     22,     11,     NO_LED, 17,     NO_LED, NO_LED, 42,     30,     NO_LED, }, // 9
  {NO_LED, NO_LED, NO_LED, NO_LED, 25,     36,     35,     34,     31,     NO_LED, 44,     92,     NO_LED, 62,     61,     NO_LED, }, // 9
  {NO_LED, NO_LED, 70,     NO_LED, NO_LED, 7,      49,     59,     57,     NO_LED, 56,     NO_LED, NO_LED, 84,     50,     NO_LED, }, // 8
}, {
  // LED Index to Physical Position
  //                   (NonZeroed    (Old NonZeroed
  //                     LED ID's)         LED ID's)
  {   7.534,   4.664 }, // LED 1      (26) *
  {  16.775,   4.664 }, // LED 2      (24) *
  {  29.331,   4.664 }, // LED 3      (22) *
  {  44.398,   4.664 }, // LED 4      (20) *
  {  59.466,   4.664 }, // LED 5      (19) *
  {  74.332,   4.664 }, // LED 6      (21) *
  {  89.399,   4.664 }, // LED 7      (23)
  { 104.969,   4.664 }, // LED 8      (25) *
  { 120.036,   4.664 }, // LED 9      (27) *
  { 134.601,   4.664 }, // LED 10     (68) *
  { 149.668,   4.664 }, // LED 11     (75) *
  { 164.735,   4.664 }, // LED 12     (69) *
  { 179.602,   3.587 }, // LED 13     (67) *
  { 179.602,   5.74  }, // LED 14     (72)
  { 194.87,    4.664 }, // LED 15     (71)
  { 207.727,   4.664 }, // LED 16     (73) *
  { 216.969,   4.664 }, // LED 17     (74) *    End of First Row with 17 LED's
  {   8.839,  13.848 }, // LED 18     (17) *
  {  23.907,  13.848 }, // LED 19     (16) *
  {  38.974,  13.848 }, // LED 20     (14) *
  {  53.941,  13.848 }, // LED 21     (13) *
  {  69.008,  13.848 }, // LED 22     (12) *
  {  83.975,  13.848 }, // LED 23     (10) *
  {  98.942,  13.848 }, // LED 24     (15) *
  { 114.009,  13.848 }, // LED 25     (11) *
  { 128.775,  13.848 }, // LED 26     (18) *
  { 144.144,  13.848 }, // LED 27     (70) *
  { 159.01,   13.848 }, // LED 28     (62) *
  { 174.379,  13.848 }, // LED 29     (64)
  { 189.064,  13.848 }, // LED 30     (63) *
  { 194.89,   13.848 }, // LED 31     (65) *
  { 206.542,  13.848 }, // LED 32     (66) *    End of Second Row with 15 LED's
  {   7.514,  24.251 }, // LED 33     (2)  *
  {  17.277,  24.251 }, // LED 34     (1)  *
  {  31.24,   24.251 }, // LED 35     (6)  *
  {  46.106,  24.251 }, // LED 36     (4)  *
  {  61.173,  24.251 }, // LED 37     (3)  *
  {  76.04,   24.251 }, // LED 38     (5)  *
  {  91.207,  24.251 }, // LED 39     (8)  *
  { 106.074,  24.251 }, // LED 40     (9)  *
  { 121.342,  24.251 }, // LED 41     (7)  *
  { 136.309,  24.251 }, // LED 42     (59) *
  { 151.275,  24.251 }, // LED 43     (60) *
  { 166.041,  24.251 }, // LED 44     (61) *
  { 181.008,  24.251 }, // LED 45     (58) *
  { 195.975,  24.251 }, // LED 46     (55) *
  { 213.353,  24.251 }, // LED 47     (56) *    End of Third Row with 15 LED's
  {   8.357,  35.085 }, // LED 48     (45)
  {  14.224,  35.085 }, // LED 49     (39) *
  {  20.07,   35.085 }, // LED 50     (43) *
  {  34.856,  35.085 }, // LED 51     (37) *
  {  50.023,  35.085 }, // LED 52     (42)
  {  64.99,   35.085 }, // LED 53     (38)
  {  80.158,  35.085 }, // LED 54     (44) *
  {  95.225,  35.085 }, // LED 55     (40) *
  { 110.092,  35.085 }, // LED 56     (41) *
  { 125.058,  35.085 }, // LED 57     (50) *
  { 140.025,  35.085 }, // LED 58     (51) *
  { 155.193,  35.085 }, // LED 59     (52) *
  { 170.059,  35.085 }, // LED 60     (49) *
  { 185.026,  35.085 }, // LED 61     (53)
  { 203.073,  35.085 }, // LED 62     (54) *
  { 212.181,  35.085 }, // LED 63     (57) *    End of Fourth Row with 16 LED's
  {  10.447,  45.848 }, // LED 64     (33) *
  {  18.282,  45.848 }, // LED 65     (31) *
  {  26.117,  45.848 }, // LED 66     (29) *
  {  42.992,  45.848 }, // LED 67     (28)
  {  57.858,  45.848 }, // LED 68     (30)
  {  73.126,  45.848 }, // LED 69     (32) *
  {  87.892,  45.848 }, // LED 70     (34) *
  { 103.06,   45.848 }, // LED 71     (36) *
  { 118.127,  45.848 }, // LED 72     (77) *
  { 132.893,  45.848 }, // LED 73     (78) *
  { 147.659,  45.848 }, // LED 74     (79) *
  { 162.727,  45.848 }, // LED 75     (76) *
  { 177.593,  45.848 }, // LED 76     (80)
  { 193.544,  45.848 }, // LED 77     (81) *
  { 200.455,  45.848 }, // LED 78     (83)
  { 207.366,  45.848 }, // LED 79     (84) *
  { 214.277,  45.848 }, // LED 80     (93) *    End of Fifth Row with 17 LED's
  {   7.935,  56.395 }, // LED 81     (35) *
  {  13.36,   56.395 }, // LED 82     (46) *
  {  27.824,  56.395 }, // LED 83     (94) *
  {  42.59,   56.395 }, // LED 84     (47) *
  {  57.858,  56.395 }, // LED 85     (48) *
  {  77.058,  56.395 }, // LED 86     (95)
  {  87.419,  56.395 }, // LED 87     (96)
  {  97.779,  56.395 }, // LED 88     (97)
  { 108.14,   56.395 }, // LED 89     (86)
  { 118.501,  56.395 }, // LED 90     (87)
  { 128.861,  56.395 }, // LED 91     (88) *
  { 147.86,   56.395 }, // LED 92     (85)
  { 162.827,  56.395 }, // LED 93     (89) *
  { 179.501,  58.834 }, // LED 94     (90) *
  { 196.578,  58.834 }, // LED 95     (91) *
  { 196.578,  54.357 }, // LED 96     (82)
  { 213.754,  58.834 }, // LED 97     (92) *    End of Sixth Row with 17 LED's
}, {
  // LED Index to Flag
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4,
  4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4, 4
} };

#endif
