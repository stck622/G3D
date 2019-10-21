#include <SD.h>
#include "util.h"
#include "Status.h"
#include "StepUtill.h"
#include "StepMotor.h"
#include "GcodeParser.h"

int head = 1;

void setup() {

	step_init();
	endstop_init();

	pinMode(FAN_PIN, OUTPUT);

	digitalWrite(FAN_PIN,HIGH);

	step_lock('a', true);
	Serial.begin(9600);
	sd_init();


	sd_open_file("sample.txt");

	Serial.println("read");

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

	for (head = 0; head < 20; head++) {
		gcode_parse();
	}

}

void loop() {

	if (Serial.available()) {
		switch (Serial.read())
		{
		case 'a':
			X_GOAL = 100*100;
			Y_GOAL = 100*100;
			break;
		case 'b':
			X_GOAL = 0;
			Y_GOAL = 0;
			break;
		default:
			break;
		}
	}

	if ((stepbuffer.Size() < 30)) {
		gcode_parse();
	}

}
