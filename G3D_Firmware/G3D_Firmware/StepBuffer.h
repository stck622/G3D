#pragma once

//mm를 스텝 카운트로 변환
int mm_to_step(char pos, double mm) {
	return abs(mm * 100) + 0.5;
}


bool mm_to_dir(char pos, double mm) {

	switch (pos)
	{

	case 'x':
		return (mm < 0 ? !X_DIR_DEF : X_DIR_DEF);

	case 'y':
		return (mm < 0 ? !Y_DIR_DEF : Y_DIR_DEF);

	case 'z':
		return (mm < 0 ? !Z_DIR_DEF : Z_DIR_DEF);

	case 'e':
		return (mm < 0 ? !E_DIR_DEF : E_DIR_DEF);

	}

}

class StepBuffer
{

public:

	int X_STEP_CNT;
	bool X_DIR;
	int X_SPEED;

	int Y_STEP_CNT;
	bool Y_DIR;
	int Y_SPEED;

	int Z_STEP_CNT;
	bool Z_DIR;
	int Z_SPEED;

	int E_STEP_CNT;
	bool E_DIR;
	int E_SPEED;

	void Set_StepBuffer(double X_MM, double Y_MM, double Z_MM, double  E_MM, int FEEDRATE) {

		X_STEP_CNT = mm_to_step('x', X_MM);
		Y_STEP_CNT = mm_to_step('y', Y_MM);
		Z_STEP_CNT = mm_to_step('z', Z_MM);
		E_STEP_CNT = mm_to_step('e', E_MM);

		X_DIR = mm_to_dir('x', X_MM);
		Y_DIR = mm_to_dir('y', Y_MM);
		Z_DIR = mm_to_dir('z', Z_MM);
		E_DIR = mm_to_dir('e', E_MM);

		if (FEEDRATE > 1) {
			DEF_SPEED = ((1000.0 * 1000.0) / ((FEEDRATE / 60.0) * 100.0));
		}

		if ((X_MM != 0) && (Y_MM != 0)) {

			double angle = atan2(X_MM, Y_MM);

			X_SPEED = abs((cos(angle) * DEF_SPEED));
			Y_SPEED = abs((sin(angle) * DEF_SPEED));

			return;

		}

		X_SPEED = DEF_SPEED;
		Y_SPEED = DEF_SPEED;
		Z_SPEED = DEF_SPEED;
		E_SPEED = DEF_SPEED;

	}

};

#include "Vector.h"
static Vector<StepBuffer> stepbuffer;
