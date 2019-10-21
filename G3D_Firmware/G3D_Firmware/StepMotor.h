#pragma once

#include "StepBuffer.h"

//x타이머
SIGNAL(TIMER1_COMPA_vect) {

	if ((X_CNT_GOAL) != (X_CNT_POS))
	{
		digitalWrite(X_DIR_PIN, X_GOAL > X_POS);
		X_POS = ((X_GOAL > X_POS) ? X_POS + 1 : X_POS - 1);
		X_CNT_POS++;
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
	}
	else
	{
		X_MOVE_COM = true;
		Y
		set_step();
	}

}


//y타이머
SIGNAL(TIMER3_COMPA_vect) {

	if ((Y_CNT_GOAL) != (Y_CNT_POS))
	{
		digitalWrite(Y_DIR_PIN, Y_GOAL > Y_POS);
		Y_POS = ((Y_GOAL > Y_POS) ? Y_POS + 1 : Y_POS - 1);
		Y_CNT_POS++;
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
				//Z_CNT++;
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

	if ((E_GOAL) != E_CNT)
	{
		digitalWrite(E0_STEP_PIN, (E_STEP = !E_STEP));
		E_CNT++;
	}
	else
	{
		TIMSK5 = 0X00;
		E_MOVE_COM = true;
		E_CNT = 0;
		set_step();

	}

}