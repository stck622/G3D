#include "endstop.h"
#include "heater.h"
#include "termister.h"
#include "stepmotor.h"

void setup() {
	Serial.begin(9600);
	heater_init();
	endstop_init();
	step_init();
	X_GOAL = 100000;
}

bool flag = true;

// the loop function runs over and over again until power down or reset
void loop() { //30 ~ 50




}
