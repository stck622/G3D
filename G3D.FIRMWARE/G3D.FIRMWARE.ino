#include "endstop.h"
#include "heater.h"
#include "termister.h"
#include "stepmotor.h"

void setup() {
	Serial.begin(9600);
	heater_init();
	endstop_init();
	step_init();
}

// the loop function runs over and over again until power down or reset
void loop() { //30 ~ 50
	
	delay(500);
	step_lock('a',true);

}
