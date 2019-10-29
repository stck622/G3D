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
			Z_STEP_CNT = Z_MM * 400;
			E_STEP_CNT = E_MM * 110;

			if (FEEDRATE != -1) {
				DEF_SPEED = ((1000.0 * 1000.0) / ((FEEDRATE / 60.0) * 100.0));
			}

			X_SPEED = DEF_SPEED * multi_speed;
			Y_SPEED = DEF_SPEED * multi_speed;
			Z_SPEED = DEF_SPEED * multi_speed;
			E_SPEED = DEF_SPEED;

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

volatile long dx, dy, dz, l, m, n, x_inc, y_inc, z_inc, err_1, err_2, dx2, dy2, dz2;
volatile long point[3];

volatile long brm_i;
volatile bool brm_com = true;

void Set_Bresenham(long x1, long y1, long z1, const long x2, const long y2, const long z2) {

	point[0] = x1;
	point[1] = y1;
	point[2] = z1;
	dx = x2 - x1;
	dy = y2 - y1;
	dz = z2 - z1;
	x_inc = (dx < 0) ? -1 : 1;
	l = abs(dx);
	y_inc = (dy < 0) ? -1 : 1;
	m = abs(dy);
	z_inc = (dz < 0) ? -1 : 1;
	n = abs(dz);
	dx2 = l << 1;
	dy2 = m << 1;
	dz2 = n << 1;

	if ((l >= m) && (l >= n)) {
		err_1 = dy2 - l;
		err_2 = dz2 - l;
	}
	else if ((m >= l) && (m >= n)) {
		err_1 = dx2 - m;
		err_2 = dz2 - m;
	}
	else {
		err_1 = dy2 - n;
		err_2 = dx2 - n;
	}

	brm_i = 0;
	brm_com = false;
}



void Calc_Bresenham()
{


	if ((l >= m) && (l >= n)) {
		if (brm_i < l) {
			if (err_1 > 0) {
				point[1] += y_inc;
				err_1 -= dx2;
			}
			if (err_2 > 0) {
				point[2] += z_inc;
				err_2 -= dx2;
			}
			err_1 += dy2;
			err_2 += dz2;
			point[0] += x_inc;
		}
		else {
			brm_com = true;
		}
	}
	else if ((m >= l) && (m >= n)) {
		if (brm_i < m) {
			if (err_1 > 0) {
				point[0] += x_inc;
				err_1 -= dy2;
			}
			if (err_2 > 0) {
				point[2] += z_inc;
				err_2 -= dy2;
			}
			err_1 += dx2;
			err_2 += dz2;
			point[1] += y_inc;
		}
		else {
			brm_com = true;
		}
	}
	else {
		if (brm_i < n) {
			if (err_1 > 0) {
				point[1] += y_inc;
				err_1 -= dz2;
			}
			if (err_2 > 0) {
				point[0] += x_inc;
				err_2 -= dz2;
			}
			err_1 += dy2;
			err_2 += dx2;
			point[2] += z_inc;

		}
		else {
			brm_com = true;
		}
	}

	brm_i++;

	X_GOAL = point[0];
	Y_GOAL = point[1];
	E_GOAL = point[2];

	X_MOVE_COM = false;
	Y_MOVE_COM = false;
	E_MOVE_COM = false;

}


void set_step() {

	if (!stepbuffer.Empty()) {



		if (brm_com) {

			if (X_MOVE_COM && Y_MOVE_COM && E_MOVE_COM && Z_MOVE_COM) {

				int c = stepbuffer.Back().G_CODE;

				if (c == 1 || c == 0) {

					Serial.println(stepbuffer.Back().head);
					//라인수 출력

					long x_Step = stepbuffer.Back().X_STEP_CNT;
					long y_Step = stepbuffer.Back().Y_STEP_CNT;
					long z_Step = stepbuffer.Back().Z_STEP_CNT;
					long e_Step = stepbuffer.Back().E_STEP_CNT;
					//버퍼 X Y Z E 카운트 받기

					/* 각 방향 포함 여부 조사 */
					if (x_Step == -100) {
						x_Step = X_GOAL;
					}

					if (y_Step == -100) {
						y_Step = Y_GOAL;
					}

					if (z_Step == -400) {
						z_Step = Z_GOAL;
					}

					if (e_Step == -110) {
						e_Step = E_GOAL;
					}

					OCR1A = stepbuffer.Back().X_SPEED;
					OCR3A = stepbuffer.Back().Y_SPEED;
					OCR5A = stepbuffer.Back().E_SPEED;
					//OCR4A = stepbuffer.Back().Z_SPEED;
					OCR4A = 2000;
					// X,Y,Z 속도 설정

					Set_Bresenham(X_GOAL, Y_GOAL, E_GOAL, x_Step, y_Step, e_Step);
					if (z_Step != Z_GOAL) {
						Serial.println("up");
						Serial.println(z_Step);
					}
					Z_GOAL = z_Step;

					X_MOVE_COM = false;
					Y_MOVE_COM = false;
					Z_MOVE_COM = false;
					E_MOVE_COM = false;

					stepbuffer.Erase(0);
					//버퍼 초기화

					E_GOAL = e_Step;
					//익스트루더 카운트 설정
				}

				if (c == 92) {
					E_POS = stepbuffer.Back().E_STEP_CNT;
					E_GOAL = stepbuffer.Back().E_STEP_CNT;
					stepbuffer.Erase(0);
					//일단 익스트루더만 해두자
				}

			}

		}
		else if (X_MOVE_COM && Y_MOVE_COM) {
			Calc_Bresenham();
			//연산
		}
	}

}