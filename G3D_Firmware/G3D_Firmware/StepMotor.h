#pragma once

#include "StepBuffer.h"

//스텝모터 고정 설정 true : 고정 / false : 해제
void step_lock(char pos, bool value) {

	value = value;

	switch (pos) {

	case 'x':
		X_EN = !value;
		digitalWrite(X_ENABLE_PIN, X_EN);
		break;

	case 'y':
		Y_EN = !value;
		digitalWrite(Y_ENABLE_PIN, Y_EN);
		break;

	case 'z':
		Z_EN = !value;
		digitalWrite(Z_ENABLE_PIN, Z_EN);
		digitalWrite(E1_ENABLE_PIN, Z_EN);
		break;

	case 'e':
		E_EN = !value;
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


void endstop_init() {
	pinMode(X_MIN_PIN, INPUT_PULLUP);
	pinMode(Y_MIN_PIN, INPUT_PULLUP);
	pinMode(Z_MIN_PIN, INPUT_PULLUP);
}

//원하는 축의 endstop 상태 받아오기.
int endstop_getStatus(char pos) {
	switch (pos)
	{
	case 'x':
		return digitalRead(X_MIN_PIN);
	case 'y':
		return digitalRead(Y_MIN_PIN);
	case 'z':
		return digitalRead(Z_MIN_PIN);
	default:
		return -1;
	}
}

void set_step() {

	if (X_MOVE_COM && Y_MOVE_COM) {

		if (!stepbuffer.Empty()) {

			//Serial.println("run");
			//Serial.println(stepbuffer.Back().X_STEP_CNT);
			//Serial.println(stepbuffer.Back().Y_STEP_CNT);
			//Serial.println(stepbuffer.Back().X_SPEED);
			//Serial.println(stepbuffer.Back().Y_SPEED);
			//Serial.println(stepbuffer.Back().X_DIR);
			//Serial.println(stepbuffer.Back().Y_DIR);

			X_GOAL = stepbuffer.Back().X_STEP_CNT*2;
			Y_GOAL = stepbuffer.Back().Y_STEP_CNT*2;
			Z_GOAL = stepbuffer.Back().Z_STEP_CNT*2;
			E_GOAL = stepbuffer.Back().E_STEP_CNT*2;

			X_DIR = stepbuffer.Back().X_DIR;
			Y_DIR = stepbuffer.Back().Y_DIR;
			Z_DIR = stepbuffer.Back().Z_DIR;
			E_DIR = stepbuffer.Back().E_DIR;

			X_SPEED = stepbuffer.Back().X_SPEED;
			Y_SPEED = stepbuffer.Back().Y_SPEED;
			Z_SPEED = stepbuffer.Back().Z_SPEED;
			E_SPEED = stepbuffer.Back().E_SPEED;

			digitalWrite(X_DIR_PIN,X_DIR);
			digitalWrite(Y_DIR_PIN, Y_DIR);
			digitalWrite(Z_DIR_PIN, Z_DIR);
			digitalWrite(E1_DIR_PIN, E_DIR);

			OCR1A = X_SPEED;
			OCR3A = Y_SPEED;
			OCR4A = Z_SPEED;
			OCR5A = E_SPEED;

			X_MOVE_COM = false;
			Y_MOVE_COM = false;

			stepbuffer.Erase(0);

			TIMSK1 = 0x02;
			TIMSK3 = 0x02;
			TIMSK4 = 0x02;
			TIMSK5 = 0x02;

		}
	}

}

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

	if ((X_GOAL) != X_CNT)
	{
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
		X_CNT++;
	}
	else
	{
		TIMSK1 = 0X00;
		X_MOVE_COM = true;
		X_CNT = 0;
		set_step();

	}

}


//y타이머
SIGNAL(TIMER3_COMPA_vect) {

	if ((Y_GOAL) != Y_CNT)
	{
		digitalWrite(Y_STEP_PIN, (Y_STEP = !Y_STEP));
		Y_CNT++;
	}
	else
	{
		TIMSK3 = 0X00;
		Y_MOVE_COM = true;
		Y_CNT = 0;
		set_step();
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
	}

}