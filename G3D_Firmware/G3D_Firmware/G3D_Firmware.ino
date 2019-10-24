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
	pinMode(HEATER_0_PIN, OUTPUT);
	pinMode(TEMP_0_PIN,INPUT);
	digitalWrite(FAN_PIN,HIGH);

	step_lock('a', true);
	Serial.begin(9600);
	sd_init();


	sd_open_file("sample2.txt");

	Serial.println("read");

	while (!endstop_getStatus('x')) {
		digitalWrite(X_STEP_PIN, (X_STEP = !X_STEP));
		delayMicroseconds(100);
	}

	while (!endstop_getStatus('y')) {
		digitalWrite(Y_STEP_PIN, (Y_STEP = !Y_STEP));
		delayMicroseconds(100);
	}

	while (!endstop_getStatus('z')) {
		digitalWrite(E1_STEP_PIN, (Z_STEP = !Z_STEP));
		delayMicroseconds(100);
	}

	for (head = 0; head < 20; head++) {
		gcode_parse();
	}
	

}

void loop() {

	//Serial.println(analogRead(TEMP_0_PIN));
	if (analogRead(TEMP_0_PIN) > 40) {
		digitalWrite(HEATER_0_PIN,HIGH);
	}
	else if (analogRead(TEMP_0_PIN) < 30) {
		digitalWrite(HEATER_0_PIN, LOW);
	}

	if (Serial.available()) {
		switch (Serial.read())
		{
		case 'a':
			OCR5A = 8000;
			TIMSK5 = 0x02;
			E_GOAL = 100 * 10;
			break;
		case 'b':

			TIMSK1 = 0x02;
			TIMSK3 = 0x02;
			TIMSK5 = 0x02;

			break;
		default:
			break;
		}
	}

	if ((stepbuffer.Size() < 10)) {
		gcode_parse();
	}

}
