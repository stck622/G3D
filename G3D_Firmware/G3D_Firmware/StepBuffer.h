#pragma once

class StepBuffer
{

public:

	int X_STEP_CNT;
	int X_SPEED;

	int Y_STEP_CNT;
	int Y_SPEED;

	int Z_STEP_CNT;
	int Z_SPEED;

	int E_STEP_CNT;
	int E_SPEED;

	void Set_StepBuffer(double X_MM, double Y_MM, double Z_MM, double  E_MM, int FEEDRATE) {

		X_STEP_CNT = X_MM * 100;
		Y_STEP_CNT = Y_MM * 100;
		Z_STEP_CNT = Z_MM * 100;
		E_STEP_CNT = E_MM * 110;

		if (FEEDRATE > 1) {
			DEF_SPEED = ((1000.0 * 1000.0) / ((FEEDRATE / 60.0) * 100.0));
		}

		X_SPEED = DEF_SPEED * 2;
		Y_SPEED = DEF_SPEED * 2;
		Z_SPEED = DEF_SPEED * 2;
		E_SPEED = DEF_SPEED * 2;

	}

};

#include "Vector.h"
static Vector<StepBuffer> stepbuffer;

volatile long addX, addY;
volatile long counter = 0;

volatile long dx;
volatile long dy;

volatile long x;
volatile long y;

volatile long brm_i;
volatile bool brm_com = true;

void Set_Bresenham(long x1, long y1, long x2, long y2) {

	Serial.println(String(x1) + ", "+ String(y1) + " TO  " + String(x2) + ", " + String(y2));

	dx = x2 - x1;
	dy = y2 - y1;

	x = x1;
	y = y1;
	brm_i = 0;

	if (dx < 0)
	{
		addX = -1;
		dx = -dx;
	}
	else
	{
		addX = 1;
	}

	if (dy < 0)
	{
		addY = -1;
		dy = -dy;
	}
	else
	{
		addY = 1;
	}
	brm_com = false;
}



void Calc_Bresenham()
{

	if (dx >= dy)
	{
		if (brm_i < dx)
		{
			x += addX;
			counter += dy;

			if (counter >= dx)
			{
				y += addY;
				counter -= dx;
			}
			X_CNT_GOAL = x * 2;
			Y_CNT_GOAL = y * 2;
			X_GOAL = x;
			Y_GOAL = y;
			brm_i++;
		} else 
		brm_com = true;
	}
	else
	{
		if (brm_i < dy)
		{
			y += addY;
			counter += dx;

			if (counter >= dy)
			{
				x += addX;
				counter -= dy;
			}
			X_CNT_GOAL = x *2;
			Y_CNT_GOAL = y *2;
			X_GOAL = x;
			Y_GOAL = y;
			brm_i++;
		} else 
		brm_com = true;
	}
}


void set_step() {

	if (!stepbuffer.Empty()) {

		if (X_MOVE_COM && Y_MOVE_COM) {

			if (brm_com) {

				if (stepbuffer.Back().X_STEP_CNT != 0 && stepbuffer.Back().Y_STEP_CNT != 0) {
					Set_Bresenham(X_POS, Y_POS, stepbuffer.Back().X_STEP_CNT, stepbuffer.Back().Y_STEP_CNT);
				}
				else {
					X_CNT_GOAL = stepbuffer.Back().X_STEP_CNT * 2;
					Y_CNT_GOAL = stepbuffer.Back().Y_STEP_CNT * 2;
					X_GOAL = stepbuffer.Back().X_STEP_CNT;
					Y_GOAL = stepbuffer.Back().X_STEP_CNT;
				}
				OCR1A = stepbuffer.Back().X_SPEED;
				OCR3A = stepbuffer.Back().Y_SPEED;
				//OCR4A = Z_SPEED;
				//OCR5A = E_SPEED;

				X_MOVE_COM = false;
				Y_MOVE_COM = false;
				E_MOVE_COM = false;

				stepbuffer.Erase(0);

				Serial.println("read ok");
			} else {
				Calc_Bresenham();
			}

		}
	}

}