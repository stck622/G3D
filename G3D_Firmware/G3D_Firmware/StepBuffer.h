#pragma once

class StepBuffer
{

public:

	long X_STEP_CNT;
	long X_SPEED;

	long Y_STEP_CNT;
	long Y_SPEED;

	long Z_STEP_CNT;
	long Z_SPEED;

	long E_STEP_CNT;
	long E_SPEED;

	int G_CODE;
	unsigned long head;
	long feedrate;

	void Set_StepBuffer(int code, double X_MM, double Y_MM, double Z_MM, double  E_MM, int FEEDRATE, unsigned long head) {

		G_CODE = code;
		this->head = head;

		switch (code) {

		case 0:
		case 1:

			X_STEP_CNT = X_MM * 100;
			Y_STEP_CNT = Y_MM * 100;
			Z_STEP_CNT = Z_MM * 100;
			E_STEP_CNT = E_MM * 100;

			if (FEEDRATE != -1) {
				DEF_SPEED = ((1000.0 * 1000.0) / ((FEEDRATE / 60.0) * 100.0));
			}

			X_SPEED = DEF_SPEED * multi_speed;
			Y_SPEED = DEF_SPEED * multi_speed;
			Z_SPEED = DEF_SPEED * multi_speed;
			E_SPEED = DEF_SPEED * multi_speed;

			feedrate = DEF_SPEED * multi_speed;

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

				int c = stepbuffer.Back().G_CODE;

				if (c == 1 || c == 0) {

					Serial.println(stepbuffer.Back().head);
					//���μ� ���

					long x_Step = stepbuffer.Back().X_STEP_CNT;
					long y_Step = stepbuffer.Back().Y_STEP_CNT;
					long z_Step = stepbuffer.Back().Z_STEP_CNT;
					long e_Step = stepbuffer.Back().E_STEP_CNT;
					//���� X Y Z E ī��Ʈ �ޱ�

					/* �� ���� ���� ���� ���� */
					if (x_Step == -100) {
						x_Step = X_GOAL;
					}

					if (y_Step == -100) {
						y_Step = Y_GOAL;
					}

					if (z_Step == -100) {
						z_Step = Z_GOAL;
					}

					if (e_Step == -100) {
						e_Step = E_GOAL;
					}

					switch (stepbuffer.Back().head) {
					case 6:
						Serial.println(X_STEP);
					}

					Set_Bresenham(X_GOAL, Y_GOAL, x_Step, y_Step);
					//�극���� �ʱ�ȭ

					if (dx >= dy) {
						OCR5A = abs(stepbuffer.Back().X_SPEED * (((long)(abs(stepbuffer.Back().X_STEP_CNT - X_GOAL) * 100)) / 100)) / abs(E_GOAL - stepbuffer.Back().E_STEP_CNT);
					}
					else {
						OCR5A = abs(stepbuffer.Back().Y_SPEED * (((long)(abs(stepbuffer.Back().Y_STEP_CNT - Y_GOAL) * 100)) / 100)) / abs(E_GOAL - stepbuffer.Back().E_STEP_CNT);
					}
					//E �ӵ� ����

					if ((x_Step == X_GOAL) && (y_Step == Y_GOAL)) {
						Serial.println("!!");
						OCR5A = stepbuffer.Back().feedrate;
					} 
					// G�ڵ忡 X,Y �� ������ �� E �ӵ� �缳��

					//E �ӵ� ����

					OCR1A = stepbuffer.Back().X_SPEED;
					OCR3A = stepbuffer.Back().Y_SPEED;
					OCR4A = stepbuffer.Back().Z_SPEED;
					// X,Y,Z �ӵ� ����

					X_MOVE_COM = false;
					Y_MOVE_COM = false;
					Z_MOVE_COM = false;
					E_MOVE_COM = false;

					stepbuffer.Erase(0);
					//���� �ʱ�ȭ

					E_GOAL = e_Step;
					//�ͽ�Ʈ��� ī��Ʈ ����
				}

				if (c == 92) {
					E_POS = stepbuffer.Back().E_STEP_CNT;
					E_GOAL = stepbuffer.Back().E_STEP_CNT;
					stepbuffer.Erase(0);
					//�ϴ� �ͽ�Ʈ����� �ص���
				}

			}

		}
		else if (X_MOVE_COM && Y_MOVE_COM) {
			Calc_Bresenham();
			//����
		}
	}

}