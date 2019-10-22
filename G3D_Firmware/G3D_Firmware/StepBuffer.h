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

	int G_CODE;

	void Set_StepBuffer(int code, double X_MM, double Y_MM, double Z_MM, double  E_MM, int FEEDRATE) {
		G_CODE = code;
		switch (code) {
		case 1:
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

			break;

		case 92:
			E_STEP_CNT = E_MM;

			break;
		}

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

	//Serial.println(String(x1) + ", "+ String(y1) + " TO  " + String(x2) + ", " + String(y2));

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

	if (dx >= dy) {
		OCR5A = abs(stepbuffer.Back().X_SPEED * (((long)(abs(stepbuffer.Back().X_STEP_CNT - X_GOAL) * 100)) / 100)) / abs(E_GOAL - stepbuffer.Back().E_STEP_CNT);
	}
	else {
		OCR5A = abs(stepbuffer.Back().Y_SPEED * (((long)(abs(stepbuffer.Back().Y_STEP_CNT - Y_GOAL) * 100)) / 100)) / abs(E_GOAL - stepbuffer.Back().E_STEP_CNT);
	}

	//Serial.println("SPEED : " + String(OCR5A));

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
			X_GOAL = x;
			Y_GOAL = y;
			brm_i++;
		}
		else
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

			X_GOAL = x;
			Y_GOAL = y;
			brm_i++;
		}
		else
			brm_com = true;
	}
}


void set_step() {

	if (!stepbuffer.Empty()) {



		if (brm_com) {

			if (X_MOVE_COM && Y_MOVE_COM && E_MOVE_COM) {

				switch (stepbuffer.Back().G_CODE)
				{
				case 1:
					Set_Bresenham(X_GOAL, Y_GOAL, stepbuffer.Back().X_STEP_CNT, stepbuffer.Back().Y_STEP_CNT);


					if (stepbuffer.Back().E_STEP_CNT) {
						E_GOAL = stepbuffer.Back().E_STEP_CNT;
					}

					OCR1A = stepbuffer.Back().X_SPEED;
					OCR3A = stepbuffer.Back().Y_SPEED;

					X_MOVE_COM = false;
					Y_MOVE_COM = false;
					E_MOVE_COM = false;

					stepbuffer.Erase(0);
					break;

				case 0:
					Set_Bresenham(X_GOAL, Y_GOAL, stepbuffer.Back().X_STEP_CNT, stepbuffer.Back().Y_STEP_CNT);


					if (stepbuffer.Back().E_STEP_CNT) {
						E_GOAL = stepbuffer.Back().E_STEP_CNT;
					}

					OCR1A = stepbuffer.Back().X_SPEED;
					OCR3A = stepbuffer.Back().Y_SPEED;

					X_MOVE_COM = false;
					Y_MOVE_COM = false;
					E_MOVE_COM = false;

					stepbuffer.Erase(0);
					break;

				case 92:
					E_POS = stepbuffer.Back().E_STEP_CNT;
					stepbuffer.Erase(0);
					break;
				}

			}

		} else if (X_MOVE_COM && Y_MOVE_COM) {
			Calc_Bresenham();
		}
	}

}