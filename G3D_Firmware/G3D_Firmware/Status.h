#pragma once

#define multi_speed 2

volatile unsigned long header = 1;

bool X_DIR = true;
bool Y_DIR = true;
bool Z_DIR = true;
bool E_DIR = true;

bool X_EN = true;
bool Y_EN = true;
bool Z_EN = true;
bool E_EN = true;

volatile long X_GOAL = 0;
volatile long Y_GOAL = 0;
volatile long Z_GOAL = 0;
volatile long E_GOAL = 0;

volatile bool X_STEP = true;
volatile bool Y_STEP = true;
volatile bool Z_STEP = true;
volatile bool E_STEP = true;

volatile long X_POS ;
volatile long Y_POS ;
volatile long Z_POS ;
volatile long E_POS;

bool X_HOME = false;
bool Y_HOME = false;
bool Z_HOME = false;

bool X_MOVE_COM = true; //완료면 true, 미완료만 false
bool Y_MOVE_COM = true;
bool Z_MOVE_COM = true;
bool E_MOVE_COM = true;

int DEF_SPEED = 700;
int X_SPEED = DEF_SPEED;
int Y_SPEED = DEF_SPEED;
int Z_SPEED = DEF_SPEED;
int E_SPEED = DEF_SPEED;

bool X_DIR_DEF = false;
bool Y_DIR_DEF = false;
bool Z_DIR_DEF = true;
bool E_DIR_DEF = true;

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38

#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56

#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62

#define E0_STEP_PIN         26
#define E0_DIR_PIN          28
#define E0_ENABLE_PIN       24

#define E1_STEP_PIN         36
#define E1_DIR_PIN          34
#define E1_ENABLE_PIN       30

#define Z_MIN_PIN          18
#define Z_MAX_PIN          19

#define Y_MIN_PIN          14
#define Y_MAX_PIN          15

#define X_MIN_PIN           3
#define X_MAX_PIN           2

#define SDPOWER            -1
#define SDSS               53
#define LED_PIN            13

#define FAN_PIN            9

#define PS_ON_PIN          12
#define KILL_PIN           -1

#define HEATER_0_PIN       10
#define HEATER_1_PIN       8
#define TEMP_0_PIN          13   // ANALOG NUMBERING
#define TEMP_1_PIN          14   // ANALOG NUMBERING