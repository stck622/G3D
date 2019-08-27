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

//스텝모터 고정
void step_lock() {

}

//스텝모터 고정해제
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