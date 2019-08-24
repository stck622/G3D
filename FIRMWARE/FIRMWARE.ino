/*
 Name:		FIRMWARE.ino
 Created:	2019-08-24 오후 12:11:14
 Author:	stck6
*/

#pragma region defines

#define X_STEP_PIN         54
#define X_DIR_PIN          55
#define X_ENABLE_PIN       38
#define X_MIN_PIN           3
#define X_MAX_PIN           2
#define Y_STEP_PIN         60
#define Y_DIR_PIN          61
#define Y_ENABLE_PIN       56
#define Y_MIN_PIN          14
#define Y_MAX_PIN          15
#define Z_STEP_PIN         46
#define Z_DIR_PIN          48
#define Z_ENABLE_PIN       62
#define Z_MIN_PIN          18
#define Z_MAX_PIN          19
#define E_STEP_PIN         26
#define E_DIR_PIN          28
#define E_ENABLE_PIN       24
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
#include <math.h>
#include "gcode_480.h"
#pragma endregion
//1125->266us
//4800->63us
//750->400us
#pragma region values
bool toggle_GcodeDrawing;
bool toggle_start_x, toggle_start_y; // 작동 시작 토글
bool toggle_PWM_x, toggle_PWM_y, toggle_PWM_e; // PWM 토글 변수
int count_x, count_y; // 움직일 값만큼 움직여주는 변수
int position_x, position_y; // 현재 위치
int moving_x, moving_y; // 움직일 값
int gcode_count;
double radius;
int Feedrate;

#pragma endregion

void set200()
{
  OCR1A = 200;
  OCR3A = 200;
}

#pragma region choice_direction
void choice_dir(int stepx, int stepy) {
  if (stepx < 0) digitalWrite(X_DIR_PIN, 1);
  else digitalWrite(X_DIR_PIN, 0);
  if (stepy < 0) digitalWrite(Y_DIR_PIN, 1);
  else digitalWrite(Y_DIR_PIN, 0);
}
#pragma endregion
//Moving에서 숫자가 음수이면 좌측, 양수이면 우측으로 바꾸어주는 메서드


#pragma region Moving
void Moving(int stepx, int stepy)
{
  choice_dir(stepx, stepy);
  if (stepx == 0)
  {
    toggle_start_y = true;
    moving_y = stepy;
  }
  else if (stepy == 0)
  {
    toggle_start_x = true;
    moving_x = stepx;
  }
  else
  {
    toggle_start_x = true;
    toggle_start_y = true;
    moving_x = stepx;
    moving_y = stepy;
  }
}
#pragma endregion
//인자 stepx 만큼 x스텝, stepy 만큼 y스텝 움직이는 메서드

void setup() {
  Serial.begin(115200);
  Serial.print("p");
  ////////////////// MOTOR PINMODE
  #pragma region pinMode
  pinMode(X_STEP_PIN, OUTPUT);
  pinMode(X_DIR_PIN, OUTPUT);
  pinMode(X_ENABLE_PIN, OUTPUT);
  pinMode(Y_STEP_PIN, OUTPUT);
  pinMode(Y_DIR_PIN, OUTPUT);
  pinMode(Y_ENABLE_PIN, OUTPUT);
  pinMode(X_MIN_PIN, INPUT);
  pinMode(Y_MIN_PIN, INPUT);
#pragma endregion
  ////////////////// FIRST PIN SETTINGS
  #pragma region PinSetting
  digitalWrite(X_MIN_PIN, 1);
  digitalWrite(Y_MIN_PIN, 1);
  digitalWrite(X_ENABLE_PIN, 0);
  digitalWrite(Y_ENABLE_PIN, 0);
  digitalWrite(X_DIR_PIN, 1);
  digitalWrite(Y_DIR_PIN, 1);
#pragma endregion

  ////////////////// TIMER 1 SETTING
  TCCR1A = 0x00;
  TCCR1B = 0x0A; // 0x0A CTC, 8분주
  TCCR1C = 0x00;
  OCR1A = 200;
  TIMSK1 = 0x02;
  ////////////////// TIMER 3 SETTING
  TCCR3A = 0x00;
  TCCR3B = 0x0A; // 0x0A CTC, 8분주
  TCCR3C = 0x00;
  OCR3A = 200;
  TIMSK3 = 0x02;
  ////////////////// TIMER 4 SETTING
  TCCR4A = 0x00;
  TCCR4B = 0x0A;
  TCCR4C = 0x00;
  OCR4A = 200;
  TIMSK4 = 0x02;
  ////////////////// GCODE SETTING
  #pragma region GcodeSetting
  for (int i = 0; i < 40; i++) {
    
    renew_xy_pos[i][0] = (int((star[i][0] - star[i - 1][0]) > 0 ? (star[i][0] - star[i - 1][0])/0.01 + 0.5 : (star[i][0] - star[i - 1][0])/0.01 - 0.5));
    renew_xy_pos[i][1] = (int((star[i][1] - star[i - 1][1]) > 0 ? (star[i][1] - star[i - 1][1]) / 0.01 + 0.5 : (star[i][1] - star[i - 1][1]) / 0.01 - 0.5));
    Serial.print(i);
    Serial.print("  ");
    Serial.print(renew_xy_pos[i][0]);
    Serial.print("  ");
    Serial.print(((star[i][0] - star[i - 1][0]) / 0.01));
    Serial.print("  ");
    Serial.print(((star[i][0] - star[i - 1][0]) / 0.01)-renew_xy_pos[i][0]);
    acc += ((star[i][0] - star[i - 1][0]) / 0.01) - renew_xy_pos[i][0];
    Serial.print("  ");
    Serial.println(acc);
    
  }
#pragma endregion
  Moving(-30000, -30000);
  Feedrate = 266;
}

void loop() {
  if (!toggle_start_x && !toggle_start_y) { draw_gcode(); }
  Input_Key();
  delayMicroseconds(10);
}

#pragma region Drawing_Gcode
void draw_gcode() {
  if (toggle_GcodeDrawing) {

    radius = abs(atan(renew_xy_pos[gcode_count + 1][1] / renew_xy_pos[gcode_count + 1][0]));
    OCR1A = abs((int)((Feedrate * 2) / cos(radius)));
    OCR3A = abs((int)((Feedrate * 2) / sin(radius)));
    Moving((renew_xy_pos[gcode_count + 1][0]), (renew_xy_pos[gcode_count + 1][1]));

    TCNT1 = 0;
    TCNT3 = 0;

    gcode_count++;
    ////if (gcode_count == 103) Feedrate = 100;
    //if (gcode_count == 104) Feedrate = 400;
    ////if (gcode_count == 206) Feedrate = 100;
    //if (gcode_count == 207) Feedrate = 200;
    ////if (gcode_count == 242) Feedrate = 100;
    //if (gcode_count == 243) Feedrate = 400;
    ////if (gcode_count == 278) Feedrate = 100;
    //if (gcode_count == 279) Feedrate = 200;
    if (gcode_count > 40)
    {
      toggle_GcodeDrawing = false;
      gcode_count = 0;
    }
  }
}
#pragma endregion
//GCODE에 따라 그리기를 시작하는 메서드

#pragma region InputKey
void Input_Key()
{
  if (Serial.available())
  {
    char key = Serial.read();
    if (key == 'a') {
      Moving(-200, 1);
      set200();
    }
    if (key == 'd') {
      Moving(200, 1);
      set200();
    }
    if (key == 'w') {
      Moving(1, -200);
      set200();
    }
    if (key == 's') {
      Moving(1, 200);
      set200();
    }
    if (key == 'r') {
      moving_zero(position_x, position_y);
      set200();
    }
    if (key == 'o') {
      moving_center(position_x, position_y);
      set200();
    }
    if (key == 'm') {
      toggle_GcodeDrawing = true;
    }
  }
}
#pragma endregion
//키를 받을때마다 실행되는 메서드


#pragma region moving_to_center
void moving_center(int center_x, int center_y)
{
  center_x = 14000 - position_x;
  center_y = 12000 - position_y;
  Moving(center_x, center_y);
}
#pragma endregion

#pragma region moving_to_zero
void moving_zero(int center_x, int center_y)
{
  center_x = -30000;
  center_y = -30000;
  Moving(center_x, center_y);
}
#pragma endregion


#pragma region X_stepmotor
SIGNAL(TIMER1_COMPA_vect)
{
  if (!(digitalRead(X_MIN_PIN)))
  {
    if (digitalRead(X_DIR_PIN)) toggle_start_x = 0;
    else toggle_start_x = 1;
    position_x = 0;
  }
  if (toggle_start_x) {
    if (toggle_PWM_x == true)
    {
      count_x++;
      if (digitalRead(X_DIR_PIN)) position_x--;
      else position_x++;

      if (count_x >= abs(moving_x))
      {
        toggle_start_x = false;
        count_x = 0;
      }
      digitalWrite(X_STEP_PIN, 1);
      toggle_PWM_x = false;
    }
    else
    {
      digitalWrite(X_STEP_PIN, 0);
      toggle_PWM_x = true;
    }
  }
}
#pragma endregion
//OCR1A x 0.5us마다 X 모터 PWM제어

#pragma region Y_stepmotor
SIGNAL(TIMER3_COMPA_vect)
{
  if (!(digitalRead(Y_MIN_PIN)))
  {
    if (digitalRead(Y_DIR_PIN)) toggle_start_y = 0;
    else toggle_start_y = 1;
    position_y = 0;
  }
  if (toggle_start_y) {
    if (toggle_PWM_y == true)
    {
      count_y++;
      if (digitalRead(Y_DIR_PIN)) position_y--;
      else position_y++;

      if (count_y >= abs(moving_y))
      {
        toggle_start_y = false;
        count_y = 0;
      }
      digitalWrite(Y_STEP_PIN, 1);
      toggle_PWM_y = false;
    }
    else
    {
      digitalWrite(Y_STEP_PIN, 0);
      toggle_PWM_y = true;
    }
  }
}
#pragma endregion
//OCR3A x 0.5us마다 Y 모터 PWM제어
SIGNAL(TIMER4_COMPA_vect)
{
  if (true/*toggle_start_y*/) {
    if (toggle_PWM_e == true)
    {
      digitalWrite(E_STEP_PIN, 1);
      toggle_PWM_e = false;
    }
    else
    {
      digitalWrite(E_STEP_PIN, 0);
      toggle_PWM_e = true;
    }
  }
}
