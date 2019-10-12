#pragma once

#include "Arduino.h"
#include "PinMap.h"
#include "Status.h"
#include "EndStop.h"

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

	//Z TIMER
	TCCR4A = 0x00;
	TCCR4B = 0x0A;
	TCCR4C = 0x00;

	OCR4A = 400;


	//E0 STEP
	pinMode(E0_STEP_PIN, OUTPUT);
	pinMode(E0_DIR_PIN, OUTPUT);
	pinMode(E0_ENABLE_PIN, OUTPUT);

	//E0 TIMER
	TCCR5A = 0x00;
	TCCR5B = 0x0A;
	TCCR5C = 0x00;

	OCR5A = 800;

}


//x타이머
SIGNAL(TIMER1_COMPA_vect) {

	if (X_GOAL != X_CNT)
	{
		if (endstop_getStatus('x') && (X_DIR != X_DIR_DEF)) {
			X_POS = 0;
			X_MOVE_COM = true;
			TIMSK1 = 0X00;
			X_GOAL = 0;
			X_CNT = 0;
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
	}

}


//y타이머
SIGNAL(TIMER3_COMPA_vect) {

	if (Y_GOAL != Y_CNT)
	{
		if (endstop_getStatus('y') && (Y_DIR != Y_DIR_DEF)) {
			Y_POS = 0;
			Y_MOVE_COM = true;
			TIMSK3 = 0X00;
			Y_GOAL = 0;
			Y_CNT = 0;
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
	}

}

//Z타이머
SIGNAL(TIMER4_COMPA_vect) {

	if (Z_GOAL != Z_CNT)
	{
		if (endstop_getStatus('z') && (Z_DIR != Z_DIR_DEF)) {
			Z_POS = 0;
			TIMSK4 = 0X00;
			Z_GOAL = 0;
			Z_CNT = 0;
		}
		else {
			Z_STEP = !Z_STEP;
			digitalWrite(E1_STEP_PIN, Z_STEP);
			if (Z_STEP) {
				Z_CNT++;
			}
		}
	}
	else
	{
		TIMSK4 = 0x00;
	}

}

//E0타이머
SIGNAL(TIMER5_COMPA_vect) {

	if (E_GOAL != E_CNT)
	{
		E_STEP = !E_STEP;
		digitalWrite(E0_STEP_PIN, E_STEP);
		if (E_STEP) {
			E_CNT++;
		}

	}
	else
	{
		TIMSK5 = 0x00;
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
		step_lock('x', value);
		step_lock('y', value);
		step_lock('z', value);
		step_lock('e', value);
		break;

	}
}


//mm를 스텝 카운트로 변환
int step_to_mm(char pos, double mm) {
	return abs(mm * 100) + 0.5;
}


void set_dir(char pos, double mm) {

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

	case 'z':
		if (mm < 0) {
			Z_DIR = !Z_DIR_DEF;
		}
		else {
			Z_DIR = Z_DIR_DEF;
		}
		digitalWrite(E1_DIR_PIN, Z_DIR);
		break;


	case 'e':
		if (mm < 0) {
			E_DIR = !E_DIR_DEF;
		}
		else {
			E_DIR = E_DIR_DEF;
		}
		digitalWrite(E0_DIR_PIN, E_DIR);
		break;


	}

}


//mm만큼 스텝모터 동작
void step_move(char pos, double mm, int speed = DEF_SPEED) {

	switch (pos)
	{

	case 'x':
		X_CNT = 0;
		set_dir('x', mm);
		X_GOAL = step_to_mm('x', mm);
		X_MOVE_COM = false;
		OCR1A = speed;
		//Serial.print(" , SPEED : ");
		//Serial.println(speed);
		TIMSK1 = 0X02;
		break;

	case 'y':
		Y_CNT = 0;
		set_dir('y', mm);
		Y_GOAL = step_to_mm('y', mm);
		Y_MOVE_COM = false;
		OCR3A = speed;
		//Serial.print(" , SPEED : ");
		//Serial.println(speed);
		TIMSK3 = 0X02;
		break;

	case 'z':
		Z_CNT = 0;
		set_dir('z', mm);
		Z_GOAL = step_to_mm('z', mm);
		OCR4A = speed;
		TIMSK4 = 0X02;
		break;

	case 'e':
		E_CNT = 0;
		set_dir('e', mm);
		E_GOAL = step_to_mm('e', mm);
		OCR5A = 6400;

		TIMSK5 = 0X02;
		break;

	}
}

void step_move(double x, double y, double z, double e) {

	if ((x != 0) && (y != 0)) {

		double angle = atan2(x, y);

		step_move('x', x, abs((cos(angle) * DEF_SPEED)));
		step_move('y', y, abs((sin(angle) * DEF_SPEED)));

		return;

	}

	step_move('x', x);
	step_move('y', y);
	step_move('z', z);
	step_move('e', e);

}

void auto_home(char pos) {

	switch (pos) {

	case 'x':
		step_move(-10000, 0, 0, 0);
		break;

	case 'y':
		step_move(0, -10000, 0, 0);
		break;

	case 'a':
		step_move(-10000, -10000, 0, 0);
		break;

	}


}