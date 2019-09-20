#include "PINMAP.h"
#include "status.h"
#include "Direction.h"

#ifndef _stepmotor_h
#define _stepmotor_h
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#endif


//스텝모터 초기화 1 3 4 5
void step_init() {

	//X PIN
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);

	//X TIMER
	TCCR1A = 0x00;
	TCCR1B = 0x0A;
	TCCR1C = 0x00;

	OCR1A = 400;


	//Y PIN
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);

	//Y TIMER
	TCCR3A = 0x00;
	TCCR3B = 0x0A;
	TCCR3C = 0x00;

	OCR3A = 400;


	//Z1 STEP
	pinMode(Z_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);

	//Z2 STEP (E1)
	pinMode(E1_STEP_PIN, OUTPUT);
	pinMode(E1_DIR_PIN, OUTPUT);
	pinMode(E1_ENABLE_PIN, OUTPUT);

	//E0 STEP
	pinMode(E0_STEP_PIN, OUTPUT);
	pinMode(E0_DIR_PIN, OUTPUT);
	pinMode(E0_ENABLE_PIN, OUTPUT);

}


//x타이머
SIGNAL(TIMER1_COMPA_vect) {

	if (X_GOAL != X_CNT)
	{
		if (endstop_getStatus('x') && (X_DIR != X_DIR_DEF)) {
			X_POS = 0;
			X_MOVE_COM = true;
		}
		else {
			X_STEP = !X_STEP;
			digitalWrite(X_STEP_PIN, X_STEP);
			if (X_STEP) {
				X_CNT++;
			}
		}
	}
	else
	{
		TIMSK1 = 0X00;
		X_MOVE_COM = true;
		//Serial.print("X_COMPLETE : ");
		//Serial.println(X_MOVE_COM);
	}

}


//y타이머
SIGNAL(TIMER3_COMPA_vect) {

	if (Y_GOAL != Y_CNT)
	{
		if (endstop_getStatus('y') && (Y_DIR != Y_DIR_DEF)) {
			Y_POS = 0;
			Y_MOVE_COM = true;
		}
		else {
			Y_STEP = !Y_STEP;
			digitalWrite(Y_STEP_PIN, Y_STEP);
			if (Y_STEP) {
				Y_CNT++;
			}
		}
	}
	else
	{
		TIMSK3 = 0x00;
		Y_MOVE_COM = true;
		//Serial.print("Y_COMPLETE : ");
		//Serial.println(Y_MOVE_COM);
	}

}


//스텝모터 고정 설정 true : 고정 / false : 해제
void step_lock(char pos, bool value) {

	value = !value;

	switch (pos) {

	case 'x':
		X_EN = value;
		digitalWrite(X_ENABLE_PIN, X_EN);
		break;

	case 'y':
		Y_EN = value;
		digitalWrite(Y_ENABLE_PIN, Y_EN);
		break;

	case 'z':
		Z_EN = value;
		digitalWrite(Z_ENABLE_PIN, Z_EN);
		digitalWrite(E1_ENABLE_PIN, Z_EN);
		break;

	case 'e':
		E_EN = value;
		digitalWrite(E0_ENABLE_PIN, E_EN);
		break;

	case 'a':
		X_EN = value;
		Y_EN = value;
		Z_EN = value;
		E_EN = value;

		digitalWrite(X_ENABLE_PIN, X_EN);
		digitalWrite(Y_ENABLE_PIN, Y_EN);
		digitalWrite(Z_ENABLE_PIN, Z_EN);
		digitalWrite(E1_ENABLE_PIN, Z_EN);
		digitalWrite(E0_ENABLE_PIN, E_EN);
		break;

	}
}


//mm를 스텝 카운트로 변환
int step_to_mm(char pos, int mm) {
	return abs(mm * 100);
}

void set_dir(char pos, int mm) {

	switch (pos)
	{

	case 'x':
		if (mm < 0) {
			X_DIR = !X_DIR_DEF;
		}
		else {
			X_DIR = X_DIR_DEF;
		}
		digitalWrite(X_DIR_PIN, X_DIR);
		break;

	case 'y':
		if (mm < 0) {
			Y_DIR = !Y_DIR_DEF;
		}
		else {
			Y_DIR = Y_DIR_DEF;
		}
		digitalWrite(Y_DIR_PIN, Y_DIR);
		break;


	}

}


//mm만큼 스텝모터 동작
void step_move(char pos, int mm) {

	switch (pos)
	{

	case 'x':
		X_CNT = 0;
		set_dir('x', mm);
		X_GOAL = step_to_mm('x', mm);
		break;

	case 'y':
		Y_CNT = 0;
		set_dir('y', mm);
		Y_GOAL = step_to_mm('y', mm);
		break;

	}

}

//mm만큼 스텝모터 동작
void step_move(int x, int y, int z, int e) {

	step_move('x', x);
	step_move('y', y);

	X_MOVE_COM = false;
	Y_MOVE_COM = false;

	TIMSK1 = 0X02;
	TIMSK3 = 0X02;

}

//auto home
void auto_home(char pos) {

	switch (pos) {

	case 'x':
		step_move(-10000,0,0,0);
		break;

	case 'y':
		step_move(0, -10000, 0, 0);
		break;

	case 'a':
		step_move(-10000, -10000, 0, 0);
		break;

	}


}

