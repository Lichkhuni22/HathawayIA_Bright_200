#include <FastLED.h>

// Define LED number and pins
#define NUM_STRIP 144
#define NUM_MATRIX 256
#define DELAY 50
#define DATA_0_PIN 22
#define DATA_1_PIN 24
#define DATA_2_PIN 2
#define DATA_3_PIN 3
#define DATA_4_PIN 4
#define DATA_5_PIN 5
#define DATA_6_PIN 6
#define BUTTON_1_PIN 7
#define BUTTON_2_PIN 8
#define BUTTON_3_PIN 9
#define BUTTON_4_PIN 10
#define BUTTON_5_PIN 11
#define BUTTON_6_PIN 12
#define BUTTON_7_PIN 13

#define SCREEN_TYPE_1 255
#define SCREEN_TYPE_2 190

// Define the array of leds
CRGB leds[NUM_STRIP];
CRGB leds1[NUM_MATRIX];
CRGB leds2[NUM_MATRIX];
CRGB leds3[NUM_MATRIX];
CRGB leds4[NUM_MATRIX];
CRGB leds5[NUM_MATRIX];
CRGB leds6[NUM_MATRIX];

byte i = 0;
byte brightness = 200;
bool flag = true;
//int k = 36;

//byte num = 0;//int
byte button_num = 0;

bool pushed_button_1 = false;
bool pushed_button_2 = false;
bool pushed_button_3 = false;
bool pushed_button_4 = false;
bool pushed_button_5 = false;
bool pushed_button_6 = false;
bool pushed_button_7 = false;

//smily eyes
static const byte screen_3_eye_1[] = {84,92,99,107,116,124,131,139,148,156,164,170,182,183,184,185,186};
byte screen_3_eye_1_size = sizeof(screen_3_eye_1) / sizeof(byte);
static const byte screen_4_eye_1[] = {83,91,108,115,140,147,155,132,123,100,171,181,182,183,184,185,165};
byte screen_4_eye_1_size = sizeof(screen_4_eye_1) / sizeof(byte);

//text 1 GIVING WAY
static const byte screen_1_text_1[] = {137,139,142,145,147,149,151,168,170,172,174,175,177,179,181,183,200,204,206,209,211,215,232,236,239};
byte screen_1_text_1_size = sizeof(screen_1_text_1) / sizeof(byte);
static const byte screen_2_text_1[] = {129,133,154,158,160,161,165,186,190,193,196,198,216,220,222,224,227,231};
byte screen_2_text_1_size = sizeof(screen_2_text_1) / sizeof(byte);
static const byte screen_3_text_1[] = {3,4,5,7,8,9,13,17,19,23,26,29,34,36,37,40,43,47,48,52,55,61,66,69,72,75,79,80,84,87,90,93,99,100,103,104,105,107,111};
byte screen_3_text_1_size = sizeof(screen_3_text_1) / sizeof(byte);
static const byte screen_4_text_1[] = {1,2,3,5,8,11,12,13,18,21,23,26,29,34,37,39,40,42,44,45,53,55,58,61,66,69,70,72,74,77,82,85,87,90,93,97,98,99,101,104,107,108};
byte screen_4_text_1_size = sizeof(screen_4_text_1) / sizeof(byte);

//text 2 i am
static const byte screen_3_text_2[] = {136,137,138,142,144,145,150,169,174,177,182,200,201,202,207};
byte screen_3_text_2_size = sizeof(screen_3_text_2) / sizeof(byte);
static const byte screen_4_text_2[] = {129,131,135,152,156,158,159,161,163,165,167,184,185,187,188,190,192,195,199};
byte screen_4_text_2_size = sizeof(screen_4_text_2) / sizeof(byte);

//text 3 GIVING WAY gary choose
static const byte screen_1_text_3[] = {16,20,22,23,24,28,34,36,40,43,47,48,49,52,55,58,62,65,69,72,75,77,79,80,83,84,87,90,94,97,126,101,104,107,111,112,116,118,119,120,122};
byte screen_1_text_3_size = sizeof(screen_1_text_3) / sizeof(byte);
static const byte screen_2_text_3[] = {17,20,22,27,28,29,33,36,40,42,44,46,48,49,51,53,55,59,60,62,65,72,74,76,78,81,83,87,91,94,97,100,104,108,110,112,115,119,124,125};
byte screen_2_text_3_size = sizeof(screen_2_text_3) / sizeof(byte);
static const byte screen_6_text_3[] = {192,193,194,197,198,200,203,206,209,212,215,216,222,225,228,229,231,232,235,238,240,241,242,244,245,246};
byte screen_6_text_3_size = sizeof(screen_6_text_3) / sizeof(byte);
static const byte screen_5_text_3[] = {10,14,17,21,26,30,31,33,37,41,43,46,49,51,55,56,60,63};
byte screen_5_text_3_size = sizeof(screen_5_text_3) / sizeof(byte);

//text 8 i will
static const byte screen_1_text_8[] = {178,180,185,186,187,197,202,204,206,209,211,213,218,229,234,238,241,245,249,250,251};
byte screen_1_text_8_size = sizeof(screen_1_text_8) / sizeof(byte);
static const byte screen_2_text_8[] = {181,182,183,185,186,187,189,190,191,193,196,200,215,219,222,225,228,232,247,251,253,254,255};
byte screen_2_text_8_size = sizeof(screen_2_text_8) / sizeof(byte);

//text 9 MOVE
static const byte screen_1_text_9[] = {18,19,20,24,28,35,39,42,46,49,53,56,60,67,69,71,74,78,81,85,88,89,91,92,99,103,106,110,114,115,116,120,124};
byte screen_1_text_9_size = sizeof(screen_1_text_9) / sizeof(byte);
static const byte screen_2_text_9[] = {19,20,21,22,23,28,34,36,40,55,58,62,65,69,72,73,74,75,87,90,94,97,101,104,115,116,117,118,119,122,126};
byte screen_2_text_9_size = sizeof(screen_2_text_9) / sizeof(byte);

//text 11 I am
static const byte screen_1_text_11[] = {177,181,182,183,201,206,207,209,214,233,238,240,245,246,247};
byte screen_1_text_11_size = sizeof(screen_1_text_11) / sizeof(byte);
static const byte screen_2_text_11[] = {184,188,190,192,193,195,199,216,218,220,222,225,227,228,230,231,248,252,255};
byte screen_2_text_11_size = sizeof(screen_2_text_11) / sizeof(byte);

//icon 1 car
static const byte screen_3_icon_1[] = {23,24,25,37,38,39,40,41,54,55,56,57,58,69,70,71,72,73,74,75,76,77,78,79,81,82,83,84,85,86,87,88,89,90,101,102,103,104,105,106,
107,108,109,111,113,114,115,116,117,122,133,138,139,140,141,142,143,144,145,146,147,148,149,150,151,152,153,154,165,166,167,168,169,170,171,172,173,174,175,184,185,199,
200,214,215,233,234,235,236,237,238,239,240,241,242,243,244,245};//80,110,112,
byte screen_3_icon_1_size = sizeof(screen_3_icon_1) / sizeof(byte);
static const byte screen_4_icon_1[] = {22,23,24,38,39,40,41,42,53,54,55,56,57,64,65,66,67,68,69,70,71,72,73,74,85,86,87,88,89,90,91,92,93,94,96,98,99,100,101,102,103,104,105,106,117,122,123,124,
125,126,128,129,130,131,132,133,138,149,150,151,152,153,154,155,156,157,158,159,160,161,162,163,164,165,166,167,168,169,170,182,183,199,200,216,217,224,225,226,227,228,229,230,250,251,252,253,254,255};
byte screen_4_icon_1_size = sizeof(screen_4_icon_1) / sizeof(byte);

//normal eyes
static const byte screen_3_eye_2[] = {54,55,56,57,58,68,74,84,92,99,107,116,124,131,139,148,156,164,170,182,183,184,185,186};
byte screen_3_eye_2_size = sizeof(screen_3_eye_2) / sizeof(byte);
static const byte screen_4_eye_2[] = {53,54,55,56,57,69,75,83,91,100,108,115,123,132,140,147,155,165,171,181,182,183,184,185};
byte screen_4_eye_2_size = sizeof(screen_4_eye_2) / sizeof(byte);

static const byte screen_3_eye_3[] = {69,70,71,72,73,85,91,99,107,116,124,131,139,149,155,165,166,167,168,169};
byte screen_3_eye_3_size = sizeof(screen_3_eye_3) / sizeof(byte);
static const byte screen_4_eye_3[] = {70,71,72,73,74,84,90,100,108,115,123,132,140,148,154,166,167,168,169,170};
byte screen_4_eye_3_size = sizeof(screen_4_eye_3) / sizeof(byte);

static const byte screen_3_eye_4[] = {86,87,88,89,90,100,106,116,124,132,138,150,151,152,153,154};
byte screen_3_eye_4_size = sizeof(screen_3_eye_4) / sizeof(byte);
static const byte screen_4_eye_4[] = {85,86,87,88,89,101,107,115,123,133,139,149,150,151,152,153};
byte screen_4_eye_4_size = sizeof(screen_4_eye_4) / sizeof(byte);

static const byte screen_3_eye_5[] = {116,117,118,119,120,121,122,123,124};
byte screen_3_eye_5_size = sizeof(screen_3_eye_5) / sizeof(byte);
static const byte screen_4_eye_5[] = {115,116,117,118,119,120,121,122,123};
byte screen_4_eye_5_size = sizeof(screen_4_eye_5) / sizeof(byte);

//normal mouth
static const byte screen_1_mouth_1[] = {44,45,46,47,48,49,50,51,72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87};
byte screen_1_mouth_1_size = sizeof(screen_1_mouth_1) / sizeof(byte);
static const byte screen_2_mouth_1[] = {32,33,34,35,60,61,62,63,64,65,66,67,68,69,70,71,88,89,90,91,92,93,94,95};
byte screen_2_mouth_1_size = sizeof(screen_2_mouth_1) / sizeof(byte);

//Looking right
//looking right eyes
static const byte screen_1_eye_6[] = {172,173,174,175,180,191,193,202,213,222,225,234,245,254};
byte screen_1_eye_6_size = sizeof(screen_1_eye_6) / sizeof(byte);
static const byte screen_2_eye_6[] = {160,190,194,221,226,253};
byte screen_2_eye_6_size = sizeof(screen_2_eye_6) / sizeof(byte);
static const byte screen_3_eye_6[] = {1,10,20,31,44,45,46,47};
byte screen_3_eye_6_size = sizeof(screen_3_eye_6) / sizeof(byte);
static const byte screen_4_eye_6[] = {2,30,32};
byte screen_4_eye_6_size = sizeof(screen_4_eye_6) / sizeof(byte);
static const byte screen_5_eye_6[] = {107,108,109,110,111,117,121,134,137,150,153,165,171,172,173,174,175};
byte screen_5_eye_6_size = sizeof(screen_5_eye_6) / sizeof(byte);

//looking right eyebrows
//1
static const byte screen_3_eyebrow_1[] = {76,77,78,79,80,81,82,83,84,107,108,109,110,111,127,128};
byte screen_3_eyebrow_1_size = sizeof(screen_3_eyebrow_1) / sizeof(byte);
static const byte screen_4_eyebrow_1[] = {64,65,66,67,68,69,70,71,88,89,90,91,92,93,94,95,96,97,98,99,100,101,102,103};
byte screen_4_eyebrow_1_size = sizeof(screen_4_eyebrow_1) / sizeof(byte);
static const byte screen_5_eyebrow_1[] = {7,8,9,21,22,23,25,26,27,35,36,37,43,44,45,49,50,51,61,62,63,64,65,78,79};
byte screen_5_eyebrow_1_size = sizeof(screen_5_eyebrow_1) / sizeof(byte);
//2   
static const byte screen_3_eyebrow_4[] = {76,77,80,81,82,83,84,107,108,109,110,111,112,113,127,128};
byte screen_3_eyebrow_4_size = sizeof(screen_3_eyebrow_4) / sizeof(byte);
static const byte screen_4_eyebrow_4[] = {93,94,95,96,97,98,99,100,101,102,103,120,121,122,123,124,125,126,127,132,133,134};
byte screen_4_eyebrow_4_size = sizeof(screen_4_eyebrow_4) / sizeof(byte);
static const byte screen_5_eyebrow_4[] = {7,8,9,21,22,23,25,26,27,35,36,37,43,44,45,49,50,51,61,62,63,64,65,78,79};
byte screen_5_eyebrow_4_size = sizeof(screen_5_eyebrow_4) / sizeof(byte);
//looking right pupils
static const byte screen_1_pupil_1[] = {203,204,205,210,211,212,235,236,237};
byte screen_1_pupil_1_size = sizeof(screen_1_pupil_1) / sizeof(byte);
static const byte screen_5_pupil_1[] = {138,139,140,147,148,149,154,155,156};
byte screen_5_pupil_1_size = sizeof(screen_5_pupil_1) / sizeof(byte);

//Looking left
//looking left eyes
static const byte screen_1_eye_7[] = {175,177,205,210,237,242};
byte screen_1_eye_7_size = sizeof(screen_1_eye_7) / sizeof(byte);
static const byte screen_2_eye_7[] = {160,161,162,163,176,187,197,206,209,218,229,238,241,250};
byte screen_2_eye_7_size = sizeof(screen_2_eye_7) / sizeof(byte);
static const byte screen_3_eye_7[] = {13,17,47};//
byte screen_3_eye_7_size = sizeof(screen_3_eye_7) / sizeof(byte);
static const byte screen_4_eye_7[] = {5,14,16,27,32,33,34,35};//
byte screen_4_eye_7_size = sizeof(screen_4_eye_7) / sizeof(byte);
static const byte screen_6_eye_7[] = {80,81,82,83,84,90,102,105,118,121,134,138,144,145,146,147,148};//
byte screen_6_eye_7_size = sizeof(screen_6_eye_7) / sizeof(byte);
//looking left eyebrows
//1
static const byte screen_3_eyebrow_2[] = {72,73,74,75,76,77,78,79,80,81,82,83,84,85,86,87,104,105,106,107,108,109,110,111};
byte screen_3_eyebrow_2_size = sizeof(screen_3_eyebrow_2) / sizeof(byte);
static const byte screen_4_eyebrow_2[] = {64,65,66,67,91,92,93,94,95,96,97,98,99,100,112,143};
byte screen_4_eyebrow_2_size = sizeof(screen_4_eyebrow_2) / sizeof(byte);
static const byte screen_6_eyebrow_2[] = {176,177,190,191,192,193,194,204,205,206,210,211,212,218,219,220,228,229,230,232,233,234,246,247,248};
byte screen_6_eyebrow_2_size = sizeof(screen_6_eyebrow_2) / sizeof(byte);
//2
static const byte screen_3_eyebrow_5[] = {80,81,82,104,105,106,107,108,109,110,111,112,113,114,115,116,117,118,119,137,138,139};
byte screen_3_eyebrow_5_size = sizeof(screen_3_eyebrow_5) / sizeof(byte);
static const byte screen_4_eyebrow_5[] = {66,67,91,92,93,94,95,96,97,98,99,100,112,126,127,143};
byte screen_4_eyebrow_5_size = sizeof(screen_4_eyebrow_5) / sizeof(byte);
static const byte screen_6_eyebrow_5[] = {176,177,190,191,192,193,194,204,205,206,210,211,212,218,219,220,228,229,230,232,233,234,246,247,248};
byte screen_6_eyebrow_5_size = sizeof(screen_6_eyebrow_5) / sizeof(byte);
//looking left pupils
static const byte screen_2_pupil_2[] = {194,195,196,219,220,221,226,227,228};
byte screen_2_pupil_2_size = sizeof(screen_2_pupil_2) / sizeof(byte);
static const byte screen_6_pupil_2[] = {99,100,101,106,107,108,115,116,117};
byte screen_6_pupil_2_size = sizeof(screen_6_pupil_2) / sizeof(byte);

//attention eyes
//1
static const byte screen_1_eye_8[] = {165,166,167,168,169,181,187,195,203,212,220,227,235,244,252};
byte screen_1_eye_8_size = sizeof(screen_1_eye_8) / sizeof(byte);
static const byte screen_2_eye_8[] = {166,167,168,169,170,180,186,196,204,211,219,228,236,243,251};
byte screen_2_eye_8_size = sizeof(screen_2_eye_8) / sizeof(byte);
static const byte screen_3_eye_8[] = {3,11,21,27,37,38,39,40,41};
byte screen_3_eye_8_size = sizeof(screen_3_eye_8) / sizeof(byte);
static const byte screen_4_eye_8[] = {4,12,20,26,38,39,40,41,42};
byte screen_4_eye_8_size = sizeof(screen_4_eye_8) / sizeof(byte);
//2
static const byte screen_1_eye_11[] = {182,183,184,185,186,196,202,212,220,227,235,244,252};
byte screen_1_eye_11_size = sizeof(screen_1_eye_11) / sizeof(byte);
static const byte screen_2_eye_11[] = {181,182,183,184,185,197,203,211,219,228,236,243,251};
byte screen_2_eye_11_size = sizeof(screen_2_eye_11) / sizeof(byte);
static const byte screen_3_eye_11[] = {4,10,22,23,24,25,26};
byte screen_3_eye_11_size = sizeof(screen_3_eye_11) / sizeof(byte);
static const byte screen_4_eye_11[] = {5,11,21,22,23,24,25};
byte screen_4_eye_11_size = sizeof(screen_4_eye_11) / sizeof(byte);
//pupil
static const byte screen_1_pupil_4[] = {198,199,200,215,216,217,230,231,232};
byte screen_1_pupil_4_size = sizeof(screen_1_pupil_4) / sizeof(byte);
static const byte screen_2_pupil_4[] = {199,200,201,214,215,216,231,232,233};
byte screen_2_pupil_4_size = sizeof(screen_2_pupil_4) / sizeof(byte);
//3
static const byte screen_1_eye_12[] = {197,198,199,200,201,213,219,227,235,245,251};
byte screen_1_eye_12_size = sizeof(screen_1_eye_12) / sizeof(byte);
static const byte screen_2_eye_12[] = {198,199,200,201,202,212,218,228,236,244,250};
byte screen_2_eye_12_size = sizeof(screen_2_eye_12) / sizeof(byte);
static const byte screen_3_eye_12[] = {5,6,7,8,9};
byte screen_3_eye_12_size = sizeof(screen_3_eye_12) / sizeof(byte);
static const byte screen_4_eye_12[] = {6,7,8,9,10};
byte screen_4_eye_12_size = sizeof(screen_4_eye_12) / sizeof(byte);
//pupil
static const byte screen_1_pupil_5[] = {215,216,217,230,231,232};
byte screen_1_pupil_5_size = sizeof(screen_1_pupil_5) / sizeof(byte);
static const byte screen_2_pupil_5[] = {214,215,216,231,232,233};
byte screen_2_pupil_5_size = sizeof(screen_2_pupil_5) / sizeof(byte);
//4
static const byte screen_1_eye_13[] = {227,228,229,230,231,232,233,234,235};
byte screen_1_eye_13_size = sizeof(screen_1_eye_13) / sizeof(byte);
static const byte screen_2_eye_13[] = {228,229,230,231,232,233,234,235,236};
byte screen_2_eye_13_size = sizeof(screen_2_eye_13) / sizeof(byte);

//attention eyebrows
static const byte screen_3_eyebrow_3[] = {104,105,117,118,119,120,121,122,123,124,128,129,130,131,132,133,134,135,136,137,138,152,153,154,155,156,157,158,159,160,161};
byte screen_3_eyebrow_3_size = sizeof(screen_3_eyebrow_3) / sizeof(byte);
static const byte screen_4_eyebrow_3[] = {102,103,115,116,117,118,119,120,121,122,133,134,135,136,137,138,139,140,141,142,143,144,145,146,147,148,149,150,151,174,175};
byte screen_4_eyebrow_3_size = sizeof(screen_4_eyebrow_3) / sizeof(byte);
static const byte screen_5_eyebrow_3[] = {47,48,49,62,63};
byte screen_5_eyebrow_3_size = sizeof(screen_5_eyebrow_3) / sizeof(byte);
static const byte screen_6_eyebrow_3[] = {192,193,206,207,208};
byte screen_6_eyebrow_3_size = sizeof(screen_6_eyebrow_3) / sizeof(byte);
//attention pupils
static const byte screen_1_pupil_3[] = {198,199,200,215,216,217,230,231,232};
byte screen_1_pupil_3_size = sizeof(screen_1_pupil_3) / sizeof(byte);
static const byte screen_2_pupil_3[] = {199,200,201,214,215,216,231,232,233};
byte screen_2_pupil_3_size = sizeof(screen_2_pupil_3) / sizeof(byte);

//right yielding eyes
static const byte screen_1_eye_9[] = {208,213,223,224,234,239,240,245,255};
byte screen_1_eye_9_size = sizeof(screen_1_eye_9) / sizeof(byte);
static const byte screen_3_eye_9[] = {0,10,15,17,18,19,20};
byte screen_3_eye_9_size = sizeof(screen_3_eye_9) / sizeof(byte);
static const byte screen_5_eye_9[] = {112,113,114,115,123,132,139,148};
byte screen_5_eye_9_size = sizeof(screen_5_eye_9) / sizeof(byte);
//right yielding mouth
static const byte screen_1_mouth_2[] = {3,4,5,6,7,21,22,23,24,25,26,27,28,29,30,31,32,33,41,42,43,51,52,75,76};
byte screen_1_mouth_2_size = sizeof(screen_1_mouth_2) / sizeof(byte);
static const byte screen_5_mouth_2[] = {222,223,224,225,239};
byte screen_5_mouth_2_size = sizeof(screen_5_mouth_2) / sizeof(byte);

//left yielding eyes
static const byte screen_2_eye_10[] = {208,218,223,224,229,239,240,250,255};
byte screen_2_eye_10_size = sizeof(screen_2_eye_10) / sizeof(byte);
static const byte screen_4_eye_10[] = {0,5,15,27,28,29,30};
byte screen_4_eye_10_size = sizeof(screen_4_eye_10) / sizeof(byte);
static const byte screen_6_eye_10[] = {107,116,123,132,140,141,142,143};
byte screen_6_eye_10_size = sizeof(screen_6_eye_10) / sizeof(byte);
//left yielding mouth
static const byte screen_2_mouth_3[] = {8,9,10,11,12,16,17,18,19,20,21,22,23,24,25,26,36,37,38,46,47,59,60,67,68};
byte screen_2_mouth_3_size = sizeof(screen_2_mouth_3) / sizeof(byte);
static const byte screen_6_mouth_3[] = {16,30,31,32,33};
byte screen_6_mouth_3_size = sizeof(screen_6_mouth_3) / sizeof(byte);

//bubble 1
static const byte screen_1_bubble_1[] = {96,97,98,99,100,101,102,103,104,105,106,107,108,109,110,111};
byte screen_1_bubble_1_size = sizeof(screen_1_bubble_1) / sizeof(byte);
static const byte screen_3_bubble_1[] = {224,225,226,227,228,229,230,231,232,233,234,235,236,237,238,239};
byte screen_3_bubble_1_size = sizeof(screen_3_bubble_1) / sizeof(byte);
static const byte screen_5_bubble_1[] = {11,12,13,14,15,21,25,38,41,54,57,70,73,86,89,102,105,118,121,134,137,150,153,166,169,182,185,197,203};
byte screen_5_bubble_1_size = sizeof(screen_5_bubble_1) / sizeof(byte);
static const byte screen_6_bubble_1[] = {52,58,70,73,86,89,102,105,118,121,134,137,150,153,166,169,182,185,198,201,214,217,230,234,240,241,242,243,244};
byte screen_6_bubble_1_size = sizeof(screen_6_bubble_1) / sizeof(byte);

//left speaking arrow 1
static const byte screen_5_arrow_1[] = {204,205,206,207};
byte screen_5_arrow_1_size = sizeof(screen_5_arrow_1) / sizeof(byte);
static const byte screen_6_arrow_1[] = {11,19,20,27,29,33,36,43,47};
byte screen_6_arrow_1_size = sizeof(screen_6_arrow_1) / sizeof(byte);
//right speaking arrow 2
static const byte screen_5_arrow_2[] = {208,212,219,222,226,228,235,236,244};
byte screen_5_arrow_2_size = sizeof(screen_5_arrow_2) / sizeof(byte);
static const byte screen_6_arrow_2[] = {48,49,50,51};
byte screen_6_arrow_2_size = sizeof(screen_6_arrow_2) / sizeof(byte);

//eye14
static const byte screen_1_eye_14[] = {224,235,244,255};
byte screen_1_eye_14_size = sizeof(screen_1_eye_14) / sizeof(byte);
static const byte screen_2_eye_14[] = {225,254};
byte screen_2_eye_14_size = sizeof(screen_2_eye_14) / sizeof(byte);
static const byte screen_3_eye_14[] = {0,11,20,31,44,45,46,47};
byte screen_3_eye_14_size = sizeof(screen_3_eye_14) / sizeof(byte);
static const byte screen_4_eye_14[] = {1,30,32};
byte screen_4_eye_14_size = sizeof(screen_4_eye_14) / sizeof(byte);
static const byte screen_5_eye_14[] = {107,108,109,110,111,117,122,133,138};
byte screen_5_eye_14_size = sizeof(screen_5_eye_14) / sizeof(byte);
//mouth4
static const byte screen_1_mouth_4[] = {4,5,6,7,21,22,23,24,25,26,27,28,29,30,32,33,34,41,42,43,51,52,63,64,75,76};
byte screen_1_mouth_4_size = sizeof(screen_1_mouth_4) / sizeof(byte);
static const byte screen_5_mouth_4[] = {223,224};
byte screen_5_mouth_4_size = sizeof(screen_5_mouth_4) / sizeof(byte);

//eye15
static const byte screen_1_eye_15[] = {238,241};
byte screen_1_eye_15_size = sizeof(screen_1_eye_15) / sizeof(byte);
static const byte screen_2_eye_15[] = {228,239,240,251};
byte screen_2_eye_15_size = sizeof(screen_2_eye_15) / sizeof(byte);
static const byte screen_3_eye_15[] = {14,17,47};
byte screen_3_eye_15_size = sizeof(screen_3_eye_15) / sizeof(byte);
static const byte screen_4_eye_15[] = {4,15,16,27,32,33,34,35};
byte screen_4_eye_15_size = sizeof(screen_4_eye_15) / sizeof(byte);
static const byte screen_6_eye_15[] = {117,122,133,138,144,145,146,147,148};
byte screen_6_eye_15_size = sizeof(screen_6_eye_15) / sizeof(byte);
//mouth5
static const byte screen_2_mouth_5[] = {8,9,10,11,17,18,19,20,21,22,23,24,25,26,36,37,38,45,46,47,48,59,60,67,68,79};
byte screen_2_mouth_5_size = sizeof(screen_2_mouth_5) / sizeof(byte);
static const byte screen_6_mouth_5[] = {31,32};
byte screen_6_mouth_5_size = sizeof(screen_6_mouth_5) / sizeof(byte);



/***********************************************/
void setup()
{
    FastLED.addLeds<WS2812, DATA_0_PIN, RGB>(leds, NUM_STRIP);  // GRB ordering is typical
    FastLED.addLeds<WS2812, DATA_1_PIN, RGB>(leds1, NUM_MATRIX);
    FastLED.addLeds<WS2812, DATA_2_PIN, RGB>(leds2, NUM_MATRIX);
    FastLED.addLeds<WS2812, DATA_3_PIN, RGB>(leds3, NUM_MATRIX);
    FastLED.addLeds<WS2812, DATA_4_PIN, RGB>(leds4, NUM_MATRIX);
    FastLED.addLeds<WS2812, DATA_5_PIN, RGB>(leds5, NUM_MATRIX);
    FastLED.addLeds<WS2812, DATA_6_PIN, RGB>(leds6, NUM_MATRIX);
//    FastLED.addLeds<WS2812, DATA_5_PIN, RGB>(leds5, 1024);
//    FastLED.addLeds<WS2812, DATA_6_PIN, RGB>(leds6, 1024);
    // FastLED.addLeds<WS2852, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    // FastLED.addLeds<WS2812B, DATA_PIN, RGB>(leds, NUM_LEDS);  // GRB ordering is typical
    FastLED.setBrightness(brightness);
    //pinMode(keyIn,INPUT_PULLUP);  //set the keyIn as an input
    pinMode(BUTTON_1_PIN,INPUT_PULLUP);
    pinMode(BUTTON_2_PIN,INPUT_PULLUP);
    pinMode(BUTTON_3_PIN,INPUT_PULLUP);
    pinMode(BUTTON_4_PIN,INPUT_PULLUP);
    pinMode(BUTTON_5_PIN,INPUT_PULLUP);
    pinMode(BUTTON_6_PIN,INPUT_PULLUP);
    pinMode(BUTTON_7_PIN,INPUT_PULLUP);

    //pinMode(keyIn4,INPUT_PULLUP);
    Serial.begin(9600);  // start serial port at 9600 bps:
}
/************************************************/

void loop()
{
  //Initial Buttons
  


    readButtons();

    
    switch (button_num){
      case 1:
          Serial.println("Mode 1 On.");
          ledBarLitFull();

          FastLED.show();
          
        break;
      case 2:
          Serial.println("Mode 2 On.");
          
          ledMode10On();

        break;
      case 3:
          Serial.println("Mode 3 On.");
          
          text3On();
          ledMode11On();
          
        break;
      case 4:
          Serial.println("Mode 4 On.");
          
          text3On();
          ledMode12On();
          
        break;
      case 5:
          Serial.println("Mode 5 On.");
          text3On();
          
          ledMode1On();
      
        break;
//      case 6:
//          //text9On();
//          
//          turnOffLed2();
//          attentionStatus();
//          FastLED.show();
//
//          
//          break;
////      case 7:
////        normalStatus();
          
      default:
//      ledMode10On();
      //ledMode1On();
        //normalStatus();
      ledBarLitFull();

      FastLED.show();

    }
}

void turnOffLed1(){
  for(byte l=0;l<144;l++){
        leds[l] = CRGB::Black;
  }
}

void turnOffScreen1(){
  for(int l=0;l<256;l++){
        leds1[l] = CRGB::Black;
  }
}

void turnOffScreen2(){
  for(int l=0;l<256;l++){
        leds2[l] = CRGB::Black;
  }
}

void turnOffScreen3(){
  for(int l=0;l<256;l++){
        leds3[l] = CRGB::Black;
  }
}
void turnOffScreen4(){
  for(int l=0;l<256;l++){
        leds4[l] = CRGB::Black;
  }
}
void turnOffScreen5(){
  for(int l=0;l<256;l++){
        leds5[l] = CRGB::Black;
  }
}
void turnOffScreen6(){
  for(int l=0;l<256;l++){
        leds6[l] = CRGB::Black;
  }
}

void turnOffLed2(){
  turnOffScreen1();
  turnOffScreen2();
  turnOffScreen3();
  turnOffScreen4();
  turnOffScreen5();
  turnOffScreen6();
}

void turnOffAll(){
  turnOffLed1();
  turnOffLed2();
}

void eye2On(){
  for(int j=0;j<screen_3_eye_2_size;j++){
    leds3[screen_3_eye_2[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_2_size;j++){
    leds4[screen_4_eye_2[j]] = CRGB(255,0,190);//cyan
  }
}

void eye3On(){
  for(int j=0;j<screen_3_eye_3_size;j++){
    leds3[screen_3_eye_3[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_3_size;j++){
    leds4[screen_4_eye_3[j]] = CRGB(255,0,190);//cyan
  }
}

void eye4On(){
  for(int j=0;j<screen_3_eye_4_size;j++){
    leds3[screen_3_eye_4[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_4_size;j++){
    leds4[screen_4_eye_4[j]] = CRGB(255,0,190);//cyan
  }
}

void eye5On(){
  for(int j=0;j<screen_3_eye_5_size;j++){
    leds3[screen_3_eye_5[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_5_size;j++){
    leds4[screen_4_eye_5[j]] = CRGB(255,0,190);//cyan
  }
}

void mouth1On(){
  for(int j=0;j<screen_1_mouth_1_size;j++){
    leds1[screen_1_mouth_1[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_2_mouth_1_size;j++){
    leds2[screen_2_mouth_1[j]] = CRGB(255,0,255);//cyan
  }
}

void eye6On(){
  for(int j=0;j<screen_1_eye_6_size;j++){
    leds1[screen_1_eye_6[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_6_size;j++){
    leds2[screen_2_eye_6[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_6_size;j++){
    leds3[screen_3_eye_6[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_6_size;j++){
    leds4[screen_4_eye_6[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_5_eye_6_size;j++){
    leds5[screen_5_eye_6[j]] = CRGB(255,0,190);//cyan
  }
}

void eyebrow1On(){
  for(int j=0;j<screen_3_eyebrow_1_size;j++){
    leds3[screen_3_eyebrow_1[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eyebrow_1_size;j++){
    leds4[screen_4_eyebrow_1[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_5_eyebrow_1_size;j++){
    leds5[screen_5_eyebrow_1[j]] = CRGB(255,0,190);//cyan
  }
}
void eyebrow4On(){
  for(int j=0;j<screen_3_eyebrow_4_size;j++){
    leds3[screen_3_eyebrow_4[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eyebrow_4_size;j++){
    leds4[screen_4_eyebrow_4[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_5_eyebrow_4_size;j++){
    leds5[screen_5_eyebrow_4[j]] = CRGB(255,0,190);//cyan
  }
}
void pupil1On(){
  for(int j=0;j<screen_1_pupil_1_size;j++){
    leds1[screen_1_pupil_1[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_5_pupil_1_size;j++){
    leds5[screen_5_pupil_1[j]] = CRGB(255,0,190);//cyan
  }
}

void lookingRight(){
  eye6On();
  //eyebrow1On();
  eyebrow4On();
  pupil1On();
}

void eye7On(){
  for(int j=0;j<screen_1_eye_7_size;j++){
    leds1[screen_1_eye_7[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_7_size;j++){
    leds2[screen_2_eye_7[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_7_size;j++){
    leds3[screen_3_eye_7[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_7_size;j++){
    leds4[screen_4_eye_7[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_6_eye_7_size;j++){
    leds6[screen_6_eye_7[j]] = CRGB(255,0,190);//cyan
  }
}

void eyebrow2On(){
  for(int j=0;j<screen_3_eyebrow_2_size;j++){
    leds3[screen_3_eyebrow_2[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eyebrow_2_size;j++){
    leds4[screen_4_eyebrow_2[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_6_eyebrow_2_size;j++){
    leds6[screen_6_eyebrow_2[j]] = CRGB(255,0,190);//cyan
  }
}
void eyebrow5On(){
  for(int j=0;j<screen_3_eyebrow_5_size;j++){
    leds3[screen_3_eyebrow_5[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eyebrow_5_size;j++){
    leds4[screen_4_eyebrow_5[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_6_eyebrow_5_size;j++){
    leds6[screen_6_eyebrow_5[j]] = CRGB(255,0,190);//cyan
  }
}
void pupil2On(){
  for(int j=0;j<screen_2_pupil_2_size;j++){
    leds2[screen_2_pupil_2[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_6_pupil_2_size;j++){
    leds6[screen_6_pupil_2[j]] = CRGB(255,0,190);//cyan
  }
}
void lookingLeft(){
  eye7On();
  //eyebrow2On();
  eyebrow5On();
  pupil2On();
}

void eye8On(){
  for(int j=0;j<screen_1_eye_8_size;j++){
    leds1[screen_1_eye_8[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_8_size;j++){
    leds2[screen_2_eye_8[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_8_size;j++){
    leds3[screen_3_eye_8[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_8_size;j++){
    leds4[screen_4_eye_8[j]] = CRGB(255,0,190);//cyan 150
  }
}
void eye11On(){
  for(int j=0;j<screen_1_eye_11_size;j++){
    leds1[screen_1_eye_11[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_11_size;j++){
    leds2[screen_2_eye_11[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_11_size;j++){
    leds3[screen_3_eye_11[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_11_size;j++){
    leds4[screen_4_eye_11[j]] = CRGB(255,0,190);//cyan 150
  }
}
void pupil4On(){
  for(int j=0;j<screen_1_pupil_4_size;j++){
    leds1[screen_1_pupil_4[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_pupil_4_size;j++){
    leds2[screen_2_pupil_4[j]] = CRGB(255,0,255);//cyan 150
  }
}
void eye12On(){
  for(int j=0;j<screen_1_eye_12_size;j++){
    leds1[screen_1_eye_12[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_12_size;j++){
    leds2[screen_2_eye_12[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_12_size;j++){
    leds3[screen_3_eye_12[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_12_size;j++){
    leds4[screen_4_eye_12[j]] = CRGB(255,0,190);//cyan 150
  }
}
void pupil5On(){
  for(int j=0;j<screen_1_pupil_5_size;j++){
    leds1[screen_1_pupil_5[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_pupil_5_size;j++){
    leds2[screen_2_pupil_5[j]] = CRGB(255,0,255);//cyan 150
  }
}
void eye13On(){
  for(int j=0;j<screen_1_eye_13_size;j++){
    leds1[screen_1_eye_13[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_eye_13_size;j++){
    leds2[screen_2_eye_13[j]] = CRGB(255,0,255);//cyan 150
  }
}
void eyebrow3On(){
  for(int j=0;j<screen_3_eyebrow_3_size;j++){
    leds3[screen_3_eyebrow_3[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eyebrow_3_size;j++){
    leds4[screen_4_eyebrow_3[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_5_eyebrow_3_size;j++){
    leds5[screen_5_eyebrow_3[j]] = CRGB(255,0,190);//cyan
  }
  for(int j=0;j<screen_6_eyebrow_3_size;j++){
    leds6[screen_6_eyebrow_3[j]] = CRGB(255,0,190);//cyan
  }
}
void pupil3On(){
  for(int j=0;j<screen_1_pupil_3_size;j++){
    leds1[screen_1_pupil_3[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_2_pupil_3_size;j++){
    leds2[screen_2_pupil_3[j]] = CRGB(255,0,255);//cyan 150
  }
}
void attentionStatus(){
  eye8On();
  eyebrow3On();
  pupil3On();
}

void eye9On(){
  for(int j=0;j<screen_1_eye_9_size;j++){
    leds1[screen_1_eye_9[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_3_eye_9_size;j++){
    leds3[screen_3_eye_9[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_5_eye_9_size;j++){
    leds5[screen_5_eye_9[j]] = CRGB(255,0,190);//cyan
  }
}
void mouth2On(){
  for(int j=0;j<screen_1_mouth_2_size;j++){
    leds1[screen_1_mouth_2[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_5_mouth_2_size;j++){
    leds5[screen_5_mouth_2[j]] = CRGB(255,0,190);//cyan
  }
}

void yieldingRight1(){
  eyebrow1On();
  eye9On();
  mouth2On();
}
//GIVING WAY
void text1On(){
  for(int j=0;j<screen_1_text_1_size;j++){
    leds1[screen_1_text_1[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_2_text_1_size;j++){
    leds2[screen_2_text_1[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_3_text_1_size;j++){
    leds3[screen_3_text_1[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_4_text_1_size;j++){
    leds4[screen_4_text_1[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
}

void text2On(){
   for(int j=0;j<screen_3_text_2_size;j++){
    leds3[screen_3_text_2[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_4_text_2_size;j++){
    leds4[screen_4_text_2[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
}

void bubble1On(){
  for(int j=0;j<screen_1_bubble_1_size;j++){
    leds1[screen_1_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
    leds2[screen_1_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_1);
  }
  for(int j=0;j<screen_3_bubble_1_size;j++){
    leds3[screen_3_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
    leds4[screen_3_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_2);
  }
  for(int j=0;j<screen_5_bubble_1_size;j++){
    leds5[screen_5_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
  for(int j=0;j<screen_6_bubble_1_size;j++){
    leds6[screen_6_bubble_1[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
}
void arrow1On(){
  for(int j=0;j<screen_5_arrow_1_size;j++){
    leds5[screen_5_arrow_1[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
  for(int j=0;j<screen_6_arrow_1_size;j++){
    leds6[screen_6_arrow_1[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
}
void arrow2On(){
  for(int j=0;j<screen_5_arrow_2_size;j++){
    leds5[screen_5_arrow_2[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
  for(int j=0;j<screen_6_arrow_2_size;j++){
    leds6[screen_6_arrow_2[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
}
void leftSpeakOn(){
  bubble1On();
  arrow1On();
}
void rightSpeakOn(){
  bubble1On();
  arrow2On();
}
void eye10On(){
  for(int j=0;j<screen_2_eye_10_size;j++){
    leds2[screen_2_eye_10[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_10_size;j++){
    leds4[screen_4_eye_10[j]] = CRGB(255,0,190);//cyan 150
  }
  for(int j=0;j<screen_6_eye_10_size;j++){
    leds6[screen_6_eye_10[j]] = CRGB(255,0,190);//cyan
  }
}
void mouth3On(){
  for(int j=0;j<screen_2_mouth_3_size;j++){
    leds2[screen_2_mouth_3[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_6_mouth_3_size;j++){
    leds6[screen_6_mouth_3[j]] = CRGB(255,0,190);//cyan
  }
}
void mouth4On(){
  for(int j=0;j<screen_1_mouth_4_size;j++){
    leds1[screen_1_mouth_4[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_5_mouth_4_size;j++){
    leds5[screen_5_mouth_4[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan
  }
}
void mouth5On(){
  for(int j=0;j<screen_2_mouth_5_size;j++){
    leds2[screen_2_mouth_5[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_6_mouth_5_size;j++){
    leds6[screen_6_mouth_5[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan
  }
}
void yieldingLeft1(){
  eyebrow2On();
  eye10On();
  mouth3On();
}
void eye14On(){
  for(int j=0;j<screen_1_eye_14_size;j++){
    leds1[screen_1_eye_14[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_2_eye_14_size;j++){
    leds2[screen_2_eye_14[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_3_eye_14_size;j++){
    leds3[screen_3_eye_14[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_4_eye_14_size;j++){
    leds4[screen_4_eye_14[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
  for(int j=0;j<screen_5_eye_14_size;j++){
    leds5[screen_5_eye_14[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan
  }
}
void eye15On(){
  for(int j=0;j<screen_1_eye_15_size;j++){
    leds1[screen_1_eye_15[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_2_eye_15_size;j++){
    leds2[screen_2_eye_15[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_3_eye_15_size;j++){
    leds3[screen_3_eye_15[j]] = CRGB(255,0,SCREEN_TYPE_1);//cyan 150
  }
  for(int j=0;j<screen_4_eye_15_size;j++){
    leds4[screen_4_eye_15[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan 150
  }
  for(int j=0;j<screen_6_eye_15_size;j++){
    leds6[screen_6_eye_15[j]] = CRGB(255,0,SCREEN_TYPE_2);//cyan
  }
}
//void yieldingLeft(){
//  eyebrow5On();
//  eye15On();
//  //eye10On();
//  mouth5On();
//}
//void yieldingRight(){
//  eyebrow4On();
//  eye14On();
//  mouth4On();
//}
void yieldingLeft(){
  eyebrow5On();
  eye15On();
  //eye10On();
  mouth5On();
}
void yieldingRight(){
  eyebrow4On();
  eye14On();
  mouth4On();
}


void text3On(){
  for(int j=0;j<screen_1_text_3_size;j++){
    leds1[screen_1_text_3[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_2_text_3_size;j++){
    leds2[screen_2_text_3[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_3_icon_1_size;j++){
    leds3[screen_3_icon_1[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_icon_1_size;j++){
    leds4[screen_4_icon_1[j]] = CRGB(255,0,190);//cyan
  }
  for(int j=0;j<screen_5_text_3_size;j++){
    leds6[screen_5_text_3[j]] = CRGB(255,0,190);//cyan 255，0，190
  }
  for(int j=0;j<screen_6_text_3_size;j++){
    leds5[screen_6_text_3[j]] = CRGB(255,0,190);//cyan
  }
}

void text8On(){
  for(int j=0;j<screen_1_mouth_1_size;j++){
    leds1[screen_1_mouth_1[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_2_mouth_1_size;j++){
    leds2[screen_2_mouth_1[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_3_eye_2_size;j++){
    leds3[screen_3_eye_2[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_2_size;j++){
    leds4[screen_4_eye_2[j]] = CRGB(255,0,190);//cyan,170
  }
}
void text9On(){
  for(int j=0;j<screen_1_text_8_size;j++){
    leds1[screen_1_text_8[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_1_text_9_size;j++){
    leds1[screen_1_text_9[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_2_text_8_size;j++){
    leds2[screen_2_text_8[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_2_text_9_size;j++){
    leds2[screen_2_text_9[j]] = CRGB(255,0,255);//cyan
  }
  for(int j=0;j<screen_3_eye_1_size;j++){
    leds3[screen_3_eye_1[j]] = CRGB(255,0,255);//cyan 150
  }
  for(int j=0;j<screen_4_eye_1_size;j++){
    leds4[screen_4_eye_1[j]] = CRGB(255,0,170);//cyan,170
  }
}

void leftBlinking(){
  leds[i+24] = CRGB(255,0,255);
        leds[i+25] = CRGB(255,0,255);
        leds[i+26] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        FastLED.show();
        delay(500);
        leds[i+24] = CRGB::Black;
        leds[i+25] = CRGB::Black;
        leds[i+26] = CRGB::Black;
        leds[i+27] = CRGB::Black;
        leds[i+28] = CRGB::Black;
        leds[i+29] = CRGB::Black;
        leds[i+30] = CRGB::Black;
        leds[i+31] = CRGB::Black;
        leds[i+32] = CRGB::Black;
        leds[i+33] = CRGB::Black;
        leds[i+34] = CRGB::Black;
        FastLED.show();
        delay(500);
        leds[i+24] = CRGB(255,0,255);
        leds[i+25] = CRGB(255,0,255);
        leds[i+26] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        leds[i+28] = CRGB(255,0,255);
        leds[i+29] = CRGB(255,0,255);
        leds[i+30] = CRGB(255,0,255);
        leds[i+31] = CRGB(255,0,255);
        leds[i+32] = CRGB(255,0,255);
        leds[i+33] = CRGB(255,0,255);
        leds[i+34] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        FastLED.show();
        delay(500);
        leds[i+24] = CRGB::Black;
        leds[i+25] = CRGB::Black;
        leds[i+26] = CRGB::Black;
        leds[i+27] = CRGB::Black;
        leds[i+28] = CRGB::Black;
        leds[i+29] = CRGB::Black;
        leds[i+30] = CRGB::Black;
        leds[i+31] = CRGB::Black;
        leds[i+32] = CRGB::Black;
        leds[i+33] = CRGB::Black;
        leds[i+34] = CRGB::Black;
        FastLED.show();
        delay(500);//1000,2500
        leds[i+24] = CRGB(255,0,255);
        leds[i+25] = CRGB(255,0,255);
        leds[i+26] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        leds[i+28] = CRGB(255,0,255);
        leds[i+29] = CRGB(255,0,255);
        leds[i+30] = CRGB(255,0,255);
        leds[i+31] = CRGB(255,0,255);
        leds[i+32] = CRGB(255,0,255);
        leds[i+33] = CRGB(255,0,255);
        leds[i+34] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        FastLED.show();
        delay(250);
}
void rightBlinking(){
  byte POSITION = 27;
  leds[i+POSITION] = CRGB(255,0,255);
        leds[i+POSITION+1] = CRGB(255,0,255);
        leds[i+POSITION+2] = CRGB(255,0,255);
        leds[i+POSITION+3] = CRGB(255,0,255);
        FastLED.show();
        delay(500);
        leds[i+20] = CRGB::Black;
        leds[i+21] = CRGB::Black;
        leds[i+22] = CRGB::Black;
        leds[i+23] = CRGB::Black;
        leds[i+24] = CRGB::Black;
        leds[i+25] = CRGB::Black;
        leds[i+26] = CRGB::Black;
        leds[i+27] = CRGB::Black;
        leds[i+28] = CRGB::Black;
        leds[i+29] = CRGB::Black;
        leds[i+30] = CRGB::Black;
        FastLED.show();
        delay(500);//wait 500ms

        leds[i+20] = CRGB(255,0,255);
        leds[i+21] = CRGB(255,0,255);
        leds[i+22] = CRGB(255,0,255);
        leds[i+23] = CRGB(255,0,255);
        leds[i+24] = CRGB(255,0,255);
        leds[i+25] = CRGB(255,0,255);
        leds[i+26] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        leds[i+28] = CRGB(255,0,255);
        leds[i+29] = CRGB(255,0,255);
        leds[i+30] = CRGB(255,0,255);
        //leds[i+28] = CRGB(255,0,255);
        FastLED.show();
        delay(500);
        leds[i+20] = CRGB::Black;
        leds[i+21] = CRGB::Black;
        leds[i+22] = CRGB::Black;
        leds[i+23] = CRGB::Black;
        leds[i+24] = CRGB::Black;
        leds[i+25] = CRGB::Black;
        leds[i+26] = CRGB::Black;
        leds[i+27] = CRGB::Black;
        leds[i+28] = CRGB::Black;
        leds[i+29] = CRGB::Black;
        leds[i+30] = CRGB::Black;
//        leds[i+17] = CRGB::Black;
//        leds[i+18] = CRGB::Black;
//        leds[i+19] = CRGB::Black;
//        leds[i+20] = CRGB::Black;
//        leds[i+21] = CRGB::Black;
//        leds[i+22] = CRGB::Black;
//        leds[i+23] = CRGB::Black;
//        leds[i+24] = CRGB::Black;
//        leds[i+25] = CRGB::Black;
//        leds[i+26] = CRGB::Black;
//        leds[i+27] = CRGB::Black;
        FastLED.show();
        delay(500);//1000,2500
        leds[i+20] = CRGB(255,0,255);
        leds[i+21] = CRGB(255,0,255);
        leds[i+22] = CRGB(255,0,255);
        leds[i+23] = CRGB(255,0,255);
        leds[i+24] = CRGB(255,0,255);
        leds[i+25] = CRGB(255,0,255);
        leds[i+26] = CRGB(255,0,255);
        leds[i+27] = CRGB(255,0,255);
        leds[i+28] = CRGB(255,0,255);
        leds[i+29] = CRGB(255,0,255);
        leds[i+30] = CRGB(255,0,255);
        //leds[i+28] = CRGB(255,0,255);
        FastLED.show();
        delay(500);
//        leds[i+17] = CRGB(255,0,255);
//        leds[i+18] = CRGB(255,0,255);
//        leds[i+19] = CRGB(255,0,255);
//        leds[i+20] = CRGB(255,0,255);
//        leds[i+21] = CRGB(255,0,255);
//        leds[i+22] = CRGB(255,0,255);
//        leds[i+23] = CRGB(255,0,255);
//        leds[i+24] = CRGB(255,0,255);
//        leds[i+25] = CRGB(255,0,255);
//        leds[i+26] = CRGB(255,0,255);
//        leds[i+27] = CRGB(255,0,255);
//        FastLED.show();
//        delay(250);
}

void led2Mode3On(){
//  sadMouthOn();
//  eyes1On();
    //text1On();
    //text3On();
    //text4On();
    //text6On();
    text8On();
}

void ledBarLitFull(){
  for(int j=0;j<NUM_STRIP;j++){
    leds[j] = CRGB(255,0,255);//cyan 150
  }
}

void ledMode1On(){
  //text8On();
  if(flag){
    
        if (i < 92){//67,Mode1Size,136//100--16 32--84
leds[i+24-4] = CRGB::Black;//36,30
      leds[i+25-4] = CRGB::Black;//position
      leds[i+26-4] = CRGB::Black;//POSITION
      leds[i+27-4] = CRGB::Black;
      leds[i+28-4] = CRGB::Black;
      leds[i+29-4] = CRGB::Black;
      leds[i+30-4] = CRGB::Black;



leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);
          
      
      FastLED.show();

      
    
      //i++;
      i=i+4;//SPEED 4
      //Serial.println(i);
      if(i==92){//139//66//72-5//67//65//==100>100
        rightBlinking();
        flag=false;
      }
    }
  }
  else{
    //text8On();
    if (i > 0){//0//25
      leds[i+24+4] = CRGB::Black;//36,30
      leds[i+25+4] = CRGB::Black;//position
      leds[i+26+4] = CRGB::Black;
      leds[i+27+4] = CRGB::Black;
      leds[i+28+4] = CRGB::Black;
      leds[i+29+4] = CRGB::Black;
      leds[i+30+4] = CRGB::Black;

//      FastLED.show();

leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);


      
      FastLED.show();

      
    
      // Now turn the LED off, then pause
      //i--;
      i=i-4;
      //Serial.println(i);
      if(i==0){//0//25
        leftBlinking();
        flag=true;
      }
    }
  }
}

void ledMode10On(){
  //text8On();
  if(flag){
    
        if (i < 92){//67,Mode1Size,136//100--16 32--84
leds[i+24-4] = CRGB::Black;//36,30
      leds[i+25-4] = CRGB::Black;//position
      leds[i+26-4] = CRGB::Black;//POSITION
      leds[i+27-4] = CRGB::Black;
      leds[i+28-4] = CRGB::Black;
      leds[i+29-4] = CRGB::Black;
      leds[i+30-4] = CRGB::Black;



leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);
          
      
      FastLED.show();

      
    
      //i++;
      i=i+4;//SPEED 4
      //Serial.println(i);
      if(i==92){//139//66//72-5//67//65//==100>100 92
        //rightBlinking();
        leds[119] = CRGB(255,0,255);
      leds[120] = CRGB(255,0,255);
      leds[121] = CRGB(255,0,255);
      leds[122] = CRGB(255,0,255);
      FastLED.show();
        delay(250);
        flag=false;
      }
    }
  }
  else{
    //text8On();
    if (i > 0){//0//25
      leds[i+24+4] = CRGB::Black;//36,30
      leds[i+25+4] = CRGB::Black;//position
      leds[i+26+4] = CRGB::Black;
      leds[i+27+4] = CRGB::Black;
      leds[i+28+4] = CRGB::Black;
      leds[i+29+4] = CRGB::Black;
      leds[i+30+4] = CRGB::Black;

//      FastLED.show();

leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);


      
      FastLED.show();

      
    
      // Now turn the LED off, then pause
      //i--;
      i=i-4;
      //Serial.println(i);
      if(i==0){//0//25
        //leftBlinking();
        leds[24] = CRGB(255,0,255);//36,30
      leds[25] = CRGB(255,0,255);
      leds[26] = CRGB(255,0,255);
      leds[27] = CRGB(255,0,255);
      FastLED.show();
        delay(250);
        flag=true;
      }
    }
  }
}

void ledMode11On(){
  //text8On();
  if(flag){
    
        if (i < 92){//67,Mode1Size,136//100--16 32--84
leds[i+24-4] = CRGB::Black;//36,30
      leds[i+25-4] = CRGB::Black;//position
      leds[i+26-4] = CRGB::Black;//POSITION
      leds[i+27-4] = CRGB::Black;
      leds[i+28-4] = CRGB::Black;
      leds[i+29-4] = CRGB::Black;
      leds[i+30-4] = CRGB::Black;



leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);
          
      
      FastLED.show();

      
    
      //i++;
      i=i+4;//SPEED 4
      //Serial.println(i);
      if(i==92){//139//66//72-5//67//65//==100>100
        leds[119] = CRGB(255,0,255);
      leds[120] = CRGB(255,0,255);
      leds[121] = CRGB(255,0,255);
      leds[122] = CRGB(255,0,255);
      FastLED.show();
        delay(250);
        flag=false;
      }
    }
  }
  else{
    //text8On();
    if (i > 0){//0//25
      leds[i+24+4] = CRGB::Black;//36,30
      leds[i+25+4] = CRGB::Black;//position
      leds[i+26+4] = CRGB::Black;
      leds[i+27+4] = CRGB::Black;
      leds[i+28+4] = CRGB::Black;
      leds[i+29+4] = CRGB::Black;
      leds[i+30+4] = CRGB::Black;

//      FastLED.show();

leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);


      
      FastLED.show();

      
    
      // Now turn the LED off, then pause
      //i--;
      i=i-4;
      //Serial.println(i);
      if(i==0){//0//25
        leftBlinking();
        flag=true;
      }
    }
  }
}

void ledMode12On(){
  //text8On();
  if(flag){
    
        if (i < 92){//67,Mode1Size,136//100--16 32--84
leds[i+24-4] = CRGB::Black;//36,30
      leds[i+25-4] = CRGB::Black;//position
      leds[i+26-4] = CRGB::Black;//POSITION
      leds[i+27-4] = CRGB::Black;
      leds[i+28-4] = CRGB::Black;
      leds[i+29-4] = CRGB::Black;
      leds[i+30-4] = CRGB::Black;



leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);
          
      
      FastLED.show();

      
    
      //i++;
      i=i+4;//SPEED 4
      //Serial.println(i);
      if(i==92){//139//66//72-5//67//65//==100>100
        rightBlinking();
        flag=false;
      }
    }
  }
  else{
    //text8On();
    if (i > 0){//0//25
      leds[i+24+4] = CRGB::Black;//36,30
      leds[i+25+4] = CRGB::Black;//position
      leds[i+26+4] = CRGB::Black;
      leds[i+27+4] = CRGB::Black;
      leds[i+28+4] = CRGB::Black;
      leds[i+29+4] = CRGB::Black;
      leds[i+30+4] = CRGB::Black;

//      FastLED.show();

leds[i+24] = CRGB(255,0,255);//36,30
      leds[i+25] = CRGB(255,0,255);
      leds[i+26] = CRGB(255,0,255);
      leds[i+27] = CRGB(255,0,255);
      leds[i+28] = CRGB(255,0,255);
      leds[i+29] = CRGB(255,0,255);
      leds[i+30] = CRGB(255,0,255);


      
      FastLED.show();

      
    
      // Now turn the LED off, then pause
      //i--;
      i=i-4;
      //Serial.println(i);
      if(i==0){//0//25
        leds[24] = CRGB(255,0,255);//36,30
      leds[25] = CRGB(255,0,255);
      leds[26] = CRGB(255,0,255);
      leds[27] = CRGB(255,0,255);
      FastLED.show();
        delay(250);
        flag=true;
      }
    }
  }
}

void ledMode2On(){
  //text6On();
  if(flag){
    if (i < 67){
      //led2Mode2On();
      
      leds[i] = CRGB(255,0,255);
      leds[i+1] = CRGB(255,0,255);
      leds[i+2] = CRGB(255,0,255);
      leds[i+3] = CRGB(255,0,255);
      leds[i+4] = CRGB(255,0,255);
      leds[i+72] = CRGB(224,64,208);
      leds[i+73] = CRGB(224,64,208);
      leds[i+74] = CRGB(224,64,208);
      leds[i+75] = CRGB(224,64,208);
      leds[i+76] = CRGB(224,64,208);
      

      //leds[i] = CRGB(224,64,208);//Turquoise
      FastLED.show();
      //delay(DELAY);
      // Now turn the LED off, then pause
      leds[i] = CRGB::Black;
      leds[i+72] = CRGB::Black;
      FastLED.show();
      i++;
      //Serial.println(i);
      if(i==67){//139//66//72-5//67
        leds[143] = CRGB(224,64,208);
        FastLED.show();
        delay(2000);
        flag=false;
      }
    }
  }
  else{
    if (i > 0){//0//25
      //led2Mode2On();
      //text6On();
      leds[i] = CRGB(255,0,255);
      leds[i+1] = CRGB(255,0,255);
      leds[i+2] = CRGB(255,0,255);
      leds[i+3] = CRGB(255,0,255);
      leds[i+4] = CRGB(255,0,255);
      leds[i+72] = CRGB(224,64,208);
      leds[i+73] = CRGB(224,64,208);
      leds[i+74] = CRGB(224,64,208);
    
      FastLED.show();
      //delay(DELAY);
      // Now turn the LED off, then pause
      leds[i+4] = CRGB::Black;
      leds[i+74] = CRGB::Black;
      FastLED.show();
      i--;
      //Serial.println(i);
      if(i==0){//0//25
        flag=true;
      }
    }
  }
}




void normalStatus(){
  if(flag){
        if (i < 67){
            //turnOffLed2();
            attentionStatus();
            //led2Mode3On();//Text8On();
            //leds[72+i] = CRGB(255,0,255);
            leds[73] = CRGB(255,0,255);
            leds[74] = CRGB(255,0,255);
            leds[75] = CRGB(255,0,255);
            //leds[76] = CRGB(255,0,255);
            leds[71] = CRGB(255,0,255);
            leds[70] = CRGB(255,0,255);
            leds[69] = CRGB(255,0,255);
            leds[68] = CRGB(255,0,255);
            leds[72] = CRGB(255,0,255);
            leds[72+i] = CRGB(255,0,255);//::Black;
            leds[72-i] = CRGB(255,0,255);//::Black;
            FastLED.show();
            
            i++;
            //Serial.println(i);
            if(i==67){//139//66//72-5//67
              flag=false;
              //delay(1500);
            }
          }
        }
        else{
          if (i > 0){
            //led2Mode3On();
            leds[72] = CRGB(255,0,255);
            leds[73] = CRGB(255,0,255);
            leds[74] = CRGB(255,0,255);
            leds[75] = CRGB(255,0,255);
            leds[76] = CRGB(255,0,255);
            leds[71] = CRGB(255,0,255);
            leds[70] = CRGB(255,0,255);
            leds[69] = CRGB(255,0,255);
            leds[68] = CRGB(255,0,255);
            leds[i+76] = CRGB::Black;
            leds[67-i] = CRGB::Black;
            if(i>30){
              //eye2On();
              //led2Mode3On();
              FastLED.show();
            }
            
            if(i<30 && i>28){
              turnOffLed2();
              eye11On();
              pupil4On();
              eyebrow3On();

              FastLED.show();
            }
            if(i<28 && i>26){
              turnOffLed2();
              eye12On();
              pupil5On();
              eyebrow3On();

              FastLED.show();
            }
            if(i<26 && i>22){
              turnOffLed2();
              eye13On();
              eyebrow3On();

              FastLED.show();
            }
            if(i<22 && i>20){
              turnOffLed2();
              eye12On();
              pupil5On();
              eyebrow3On();

              FastLED.show();
            }
            if(i<20 && i>18){//
              turnOffLed2();
              eye11On();
              pupil4On();
              eyebrow3On();

              FastLED.show();
            }
            if(i<18){
              turnOffLed2();
              attentionStatus();

              FastLED.show();
            }
            
            
            i--;
            
            if(i==0){//139//66//72-5//67
              flag=true;
              //delay(2*DELAY);
            }
          }
      }
}

void readButtons(){
  //Initial Buttons
  bool prev_button_1 = pushed_button_1;
  bool prev_button_2 = pushed_button_2;
  bool prev_button_3 = pushed_button_3;
  bool prev_button_4 = pushed_button_4;
  bool prev_button_5 = pushed_button_5;
  bool prev_button_6 = pushed_button_6;
  bool prev_button_7 = pushed_button_7;

  pushed_button_1 = digitalRead (BUTTON_1_PIN) == LOW;
  pushed_button_2 = digitalRead (BUTTON_2_PIN) == LOW;
  pushed_button_3 = digitalRead (BUTTON_3_PIN) == LOW;
  pushed_button_4 = digitalRead (BUTTON_4_PIN) == LOW;
  pushed_button_5 = digitalRead (BUTTON_5_PIN) == LOW;
  pushed_button_6 = digitalRead (BUTTON_6_PIN) == LOW;
  pushed_button_7 = digitalRead (BUTTON_7_PIN) == LOW;

  //temp = num;

  if (prev_button_1 != pushed_button_1)
    {
      if (pushed_button_1)                                        // blue button just pushed
        {
          button_num = 1;

          turnOffLed1();

          leds[72] = CRGB(255,0,255);
          leds[73] = CRGB(255,0,255);
          leds[74] = CRGB(255,0,255);
          leds[75] = CRGB(255,0,255);
          leds[76] = CRGB(255,0,255);
          leds[71] = CRGB(255,0,255);
          leds[70] = CRGB(255,0,255);
          leds[69] = CRGB(255,0,255);
          leds[68] = CRGB(255,0,255);

          FastLED.show();
          
//          turnOffLed1();
//          turnOffLed2();
          i=0;

          while (i<67){
            leds[i+76] = CRGB(255,0,255);
            leds[67-i] = CRGB(255,0,255);
            FastLED.show();
            i++;
          }
          flag = true;
          //Serial.println(button_num);
        }
      else                                                           // blue button just released
        {

        }
    }

 if (prev_button_2 != pushed_button_2)
    {
      if (pushed_button_2)                                         // red button just pushed
        {
          //delay(15000);
          button_num = 2;
          i=67;
          while (i > 0){
                //led2Mode3On();
                leds[72] = CRGB(255,0,255);
                leds[73] = CRGB(255,0,255);
                leds[74] = CRGB(255,0,255);
                leds[75] = CRGB(255,0,255);
                leds[76] = CRGB(255,0,255);
                leds[71] = CRGB(255,0,255);
                leds[70] = CRGB(255,0,255);
                leds[69] = CRGB(255,0,255);
                leds[68] = CRGB(255,0,255);
                leds[i+76] = CRGB::Black;
                leds[67-i] = CRGB::Black;
                FastLED.show();
                i--;
          }
          delay(150);
          for(int k=44;k>=0;k=k-4){//k-- k=k-2
            leds[k+20] = CRGB(255,0,255);
            leds[k+21] = CRGB(255,0,255);
            leds[k+22] = CRGB(255,0,255);
            leds[k+23] = CRGB(255,0,255);
            //leds[k+22] = CRGB(255,0,255);
            leds[k+32] = CRGB::Black;
            leds[k+31] = CRGB::Black;
            leds[k+30] = CRGB::Black;
            leds[k+29] = CRGB::Black;
            //leds[k+31] = CRGB::Black;
            FastLED.show();
          }
    
          delay(200);

          
          turnOffLed1();
          turnOffLed2();
          //attentionStatus();
          FastLED.show();
          //i = 0;
          flag = true;

//          attentionStatus();
//          FastLED.show();
          
          //Serial.println(button_num);
        }
      else                                                           // red button just released
        {

        }
    }

 if (prev_button_3 != pushed_button_3)
    {
      if (pushed_button_3)                                     // green button just pushed
        {
          //delay(15000);
          button_num = 3;
          turnOffLed1();
          turnOffLed2();
          i = 0;
          flag = true;

          //attentionStatus();
          //FastLED.show();
          //delay(15000);
          //Serial.println(num);
        }
      else                                                           // green button just released
        {

        }
    }

    if (prev_button_4 != pushed_button_4)
    {
      if (pushed_button_4)                                        // cyan button just pushed
        {
          //delay(15000);
          button_num = 4;
          turnOffLed1();
          turnOffLed2();
          i = 0;
          flag = true;

          //attentionStatus();
          //FastLED.show();
          //delay(15000);
          
          //Serial.println(num);
        }
      else                                                           // cyan button just released
        {

        }
    }
    if (prev_button_5 != pushed_button_5)
    {
      if (pushed_button_5)                                        // blue button just pushed
        {
          //delay(15000);
          button_num = 5;
          turnOffLed2();
          i = 0;
          flag = true;

          //attentionStatus();
          //FastLED.show();
          //delay(15000);

          //Serial.println(num);
        }
      else                                                           // blue button just released
        {

        }
    }
    if (prev_button_6 != pushed_button_6)
    {
      if (pushed_button_6)                                        // blue button just pushed
        {
          //delay(8000);
          button_num = 6;
          turnOffLed2();
          i = 0;
          flag = true;
          //Serial.println(num);
        }
      else                                                           // blue button just released
        {

        }
    }
    if (prev_button_7 != pushed_button_7)
    {
      if (pushed_button_7)                                        // blue button just pushed
        {
          button_num = 7;
          i = 0;
          turnOffLed2();
          flag = true;
          //Serial.println(num);
          // ...
        }
      else                                                           // blue button just released
        {
          
        }
    }
}
