#include <SD.h>
#include "util.h"
#include "Status.h"
#include "StepMotor.h"
#include "GcodeParser.h"
#include "thermistor.h"

thermistor therm1(TEMP_0_PIN, 70);

int head = 1;

void setup() {

	step_init();
	endstop_init();

	//pinMode(TEMP_0_PIN,INPUT);
	pinMode(HEATER_0_PIN,OUTPUT);
	pinMode(FAN_PIN, OUTPUT);

	digitalWrite(FAN_PIN,HIGH);
	digitalWrite(HEATER_0_PIN, HIGH);

	step_lock('a', true);
	sd_init();
	Serial.begin(9600);


	sd_open_file("sample.txt");

	//for (head = 1; head < 20; head++) {
	//	StepBuffer tmp;
	//	tmp.Set_StepBuffer((xy_pos[head][0] - xy_pos[head - 1][0]), (xy_pos[head][1] - xy_pos[head - 1][1]), 0, 0, xy_pos[head ][2]);
	//	stepbuffer.PushBack(tmp);
	//}
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

	Serial.println("run");
	double a = 62.30;
	int b = 1066;

	Serial.println(double_tlqkf(10.1254));
	Serial.println(a*b/5.04);

	//TIMSK1 = 0x02;


}

void loop() {

	if (Serial.available()) {
		switch (Serial.read())
		{
		case 'a':
			TIMSK1 = 0x02;
			break;
		default:
			break;
		}
	}

	int temp = therm1.analog2temp();

	if ((stepbuffer.Size() < 30)) {
		gcode_parse();
	}

	if (temp < 250) {
		digitalWrite(HEATER_0_PIN,HIGH);
	}
	else if (temp >= 240) {
		digitalWrite(HEATER_0_PIN, LOW);
	}

	//Serial.println(analogRead(HEATER_0_PIN));

}
