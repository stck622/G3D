
#include "uart.h"
#include "endstop.h"
#include "heater.h"
#include "termister.h"
#include "stepmotor.h"

int gcode[][2] = { //x,y
	{0,50},
	{50,0},
{0,-50},
{-50,0},

};

void setup() {
	Serial.begin(9600);
	heater_init();
	endstop_init();
	step_init();
	auto_home('a');
	Serial.println("ok");
	//step_move((gcode[0][0]), (gcode[0][1]), 0, 0);
}

bool flag = false;
int i = 0;

// the loop function runs over and over again until power down or reset
void loop() { //30 ~ 50



	if (flag && (X_MOVE_COM && Y_MOVE_COM)) {
		step_move((gcode[i][0]), (gcode[i][1]), 0, 0);
		Serial.println("1");
		i++;
		if (i == 4) {
			i = 0;
		}
	}

	if (Serial.available()) {
		Serial.read();
		flag = !flag;
	}

}
