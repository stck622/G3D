
#include "uart.h"
#include "endstop.h"
#include "heater.h"
#include "termister.h"
#include "stepmotor.h"
#include "sample_gcode.h"

void setup() {
	Serial.begin(9600);
	heater_init();
	endstop_init();
	step_init();
	//auto_home('a');
	Serial.println("ok");
	                         
	DEF_SPEED = 800;

}

bool flag = false;
bool flag1 = true;
bool flag2 = false;
int i = 1;

// the loop function runs over and over again until power down or reset
void loop() { //30 ~ 50

	if (flag2)
		step_move('e', 10);

	if (flag && (X_MOVE_COM && Y_MOVE_COM)) {

		if (xy_pos[i][2] > 1) {
			DEF_SPEED = ((1000.0 * 1000.0) / ((xy_pos[i][2]/60.0) * 100.0));
			//Serial.println(DEF_SPEED);
		}


		//Serial.println(i);
		step_move((xy_pos[i][0] - xy_pos[i - 1][0]), (xy_pos[i][1] - xy_pos[i - 1][1]), 0, 0);

		i++;

		if (i == 480) {

			i = 1;
			flag = false;
		}
	}

	if (termister_getTemp() > 45) {
		heater_run(true);
	}
	else if (termister_getTemp() < 40) {
		heater_run(false);
	}

	//Serial.println(termister_getTemp());

	if (Serial.available()) {

		switch (Serial.read()) {

		case 'w':
			step_move(0, -10, 0, 0);
			break;
		case 'a':
			step_move(-10, 0, 0, 0);
			break;
		case 'd':
			step_move(10, 0, 0, 0);
			break;
		case 's':
			step_move(0, 10, 0, 0);
			break;

		case 'u':
			step_move(0, 0, 10, 0);
			break;
		case 'j':
			step_move(0, 0, -10, 0);
			break;

		case 'l':
			digitalWrite(4, (flag1 = !flag1));
			break;

		case 'f':
			step_move(0, 0, 0, 10);
			break;

		case 'g':
			step_move(0, 0, 0, -10);
			break;

		case 'k':
			flag2 = !flag2;
			break;

		case 'p':
			step_lock('a', true);
			break;


		default:
			flag = !flag;
			break;
		}
	}

}
