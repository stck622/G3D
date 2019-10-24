#pragma once

void endstop_init() {
	pinMode(X_MIN_PIN, INPUT_PULLUP);
	pinMode(Y_MIN_PIN, INPUT_PULLUP);
	pinMode(Z_MIN_PIN, INPUT_PULLUP);
}

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
	}
}

void step_init() {

	//X PIN
	pinMode(X_STEP_PIN, OUTPUT);
	pinMode(X_DIR_PIN, OUTPUT);
	pinMode(X_ENABLE_PIN, OUTPUT);
	digitalWrite(X_DIR_PIN, X_DIR_DEF);

	//X TIMER
	TCCR1A = 0x00;
	TCCR1B = 0x0A;
	TCCR1C = 0x00;

	OCR1A = 100;


	//Y PIN
	pinMode(Y_STEP_PIN, OUTPUT);
	pinMode(Y_DIR_PIN, OUTPUT);
	pinMode(Y_ENABLE_PIN, OUTPUT);
	digitalWrite(Y_DIR_PIN, Y_DIR_DEF);

	//Y TIMER
	TCCR3A = 0x00;
	TCCR3B = 0x0A;
	TCCR3C = 0x00;

	OCR3A = 100;


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

	OCR4A = 100;


	//E0 STEP
	pinMode(E0_STEP_PIN, OUTPUT);
	pinMode(E0_DIR_PIN, OUTPUT);
	pinMode(E0_ENABLE_PIN, OUTPUT);
	digitalWrite(E0_DIR_PIN, E_DIR_DEF);

	//E0 TIMER
	TCCR5A = 0x00;
	TCCR5B = 0x0A;
	TCCR5C = 0x00;

	OCR5A = 172;


	//TIMSK1 = 0x02;
	//TIMSK3 = 0x02;

}