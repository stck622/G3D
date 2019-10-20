#include "Status.h"
#include "StepMotor.h"

void bresenham(long _startX, long _startY, long _FinishX, long _FinishY)
{
	long x = _startX;
	long y = _startY;
	long W = _FinishX - _startX;
	long H = _FinishY - _startY;
	long F = 2 * H - W;
	long dF1 = 2 * H;
	long dF2 = 2 * (H - W);

	for (x = _startX; x <= _FinishX; ++x)
	{

		xy_move(y,x);

		while ((X_MOVE_COM && Y_MOVE_COM));

		if (F < 0)
		{
			F += dF1;
		} else {
			++y;
			F += dF2;
		}
			//Serial.println("wait");
			//Serial.println("X_COM : " + String(X_MOVE_COM));
			//Serial.println("Y_COM : " + String(Y_MOVE_COM));
		

	}
}


void xy_move(long x, long y) {
	//Serial.println("start");
	X_GOAL = (x  * 2);
	Y_GOAL = (y  * 2);
	Y_MOVE_COM = true;
	X_MOVE_COM = true;
	TIMSK1 = 0x02;
	TIMSK3 = 0x02;

}

void setup() {

	endstop_init();

	step_init();
	Serial.begin(9600);

	while (!endstop_getStatus('x')) {
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
		delayMicroseconds(400);
	}

	while (!endstop_getStatus('y')) {
		digitalWrite(Y_STEP_PIN, (Y_STEP = !Y_STEP));
		delayMicroseconds(400);
	}


	while (!endstop_getStatus('z')) {
		digitalWrite(E1_STEP_PIN, (Z_STEP = !Z_STEP));
		delayMicroseconds(400);
	}


	Serial.println("run");

	TIMSK1 = 0x02;
	TIMSK3 = 0x02;
	digitalWrite(X_DIR_PIN, HIGH);
	digitalWrite(Y_DIR_PIN, HIGH);
	bresenham(0, 0, 100*150 , 100 * 150);
	Serial.println("ok1");
	digitalWrite(X_DIR_PIN,LOW);
	digitalWrite(Y_DIR_PIN, LOW);
	bresenham( 100 * 150, 100 * 150,100*200,100*200);
	Serial.println("ok2");
}

void loop() {

	
  
}
