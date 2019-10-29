 #pragma once

#include "StepBuffer.h"

//x타이머
SIGNAL(TIMER1_COMPA_vect) {

	if ((X_POS) != (X_GOAL))
	{
		digitalWrite(X_DIR_PIN, X_GOAL > X_POS);
		if (X_STEP)
		X_POS = ((X_GOAL > X_POS) ? X_POS + 1 : X_POS - 1);
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
	}
	else
	{
		X_MOVE_COM = true;
		set_step();
	}

}


//y타이머
SIGNAL(TIMER3_COMPA_vect) {

	if ((Y_POS) != (Y_GOAL))
	{
		digitalWrite(Y_DIR_PIN, Y_GOAL > Y_POS);
		if (Y_STEP)
		Y_POS = ((Y_GOAL > Y_POS) ? Y_POS + 1 : Y_POS - 1);
		digitalWrite(Y_STEP_PIN, (Y_STEP = !Y_STEP));
	}
	else
	{
		Y_MOVE_COM = true;
		set_step();
	}

}

//Z타이머
SIGNAL(TIMER4_COMPA_vect) {

	if ((Z_POS) != (Z_GOAL))
	{
		digitalWrite(Z_DIR_PIN, Z_GOAL > Z_POS);
		if (Z_STEP)
			Z_POS = ((Z_GOAL > Z_POS) ? Z_POS + 1 : Z_POS - 1);
		digitalWrite(Z_STEP_PIN, (Z_STEP = !Z_STEP));
	}
	else
	{
		Z_MOVE_COM = true;
		set_step();
	}

}

//E0타이머
SIGNAL(TIMER5_COMPA_vect) {

	if ((E_POS) != (E_GOAL))
	{
		digitalWrite(E0_DIR_PIN, E_GOAL > E_POS);
		if (E_STEP)
			E_POS = ((E_GOAL > E_POS) ? E_POS + 1 : E_POS - 1);
		digitalWrite(E0_STEP_PIN, (E_STEP = !E_STEP));
	}
	else
	{
		E_MOVE_COM = true;
	}

}