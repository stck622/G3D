#pragma once

//���ܸ��� ���� ���� true : ���� / false : ����
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

//���ϴ� ���� endstop ���� �޾ƿ���.
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


//xŸ�̸�
SIGNAL(TIMER1_COMPA_vect) {

	if ((X_GOAL) != X_POS)
	{
		//Serial.println("start X");
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
		X_POS = ((X_GOAL > X_POS) ? X_POS + 1 : X_POS - 1);
		//Serial.println("X_POS  : " + String(X_POS));
		//Serial.println("X_GOAL : " + String(X_GOAL));
	}
	else
	{
		X_MOVE_COM = false;
		TIMSK1 = 0X00;
		//Serial.println("end X");
	}

}


//yŸ�̸�
SIGNAL(TIMER3_COMPA_vect) {

	if (Y_GOAL != Y_POS)
	{
		//Serial.println("start Y");
		digitalWrite(Y_STEP_PIN, (Y_STEP = !Y_STEP));
		Y_POS = ((Y_GOAL > Y_POS) ? Y_POS + 1 : Y_POS - 1);
		//Serial.println("Y_POS  : " + String(Y_POS));
		//Serial.println("Y_GOAL : " + String(Y_GOAL));
	}
	else
	{
		Y_MOVE_COM = false;
		TIMSK3 = 0X00;
		//Serial.println("end Y");
	}

}

//ZŸ�̸�
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

//E0Ÿ�̸�
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