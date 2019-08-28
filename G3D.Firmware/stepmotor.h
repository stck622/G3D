#include "PINMAP.h"
#include "status.h"

#ifndef _stepmotor_h
#define _stepmotor_h
#if defined(ARDUINO) && ARDUINO >= 100
#include "arduino.h"
#else
#include "WProgram.h"
#endif
#endif

//스텝모터 초기화
void step_init() {

	//X STEP
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);

	TCCR0A = 0b00000010;
	TCCR0B = 0b00000011;
	OCR0A = 50;
	TIMSK0 = 0b00000010;


	//Y STEP
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);

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
SIGNAL(TIMER0_COMPA_vect) {

	if (X_GOAL != X_CNT) {
		X_STEP = !X_STEP;
		digitalWrite(X_STEP_PIN, X_STEP);
		if (X_STEP) {
			X_CNT++;
		}
	}

}

//스텝모터 고정 설정
void step_lock(char pos,bool value) {

	value = !value;

	switch (pos) {
	case 'x':
		X_EN = value;
		digitalWrite(X_ENABLE_PIN, X_EN);
		break;
	case 'y':
		Y_EN = value;
		digitalWrite(Y_ENABLE_PIN,Y_EN);
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
int step_to_mm(char pos,int mm) {
	return mm;
}

//mm만큼 스텝모터 동작
void step_move(char pos, int mm) {

	switch (pos)
	{
	case 'x':
		X_GOAL = step_to_mm('x',1000);
		break;
	default:
		break;
	}

}

//auto home
void auto_home(char pos) {
	switch (pos) {
	case 'x':
		
		break;
	}
}
