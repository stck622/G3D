#include <SD.h>
#include "Status.h"
#include "StepMotor.h"
#include "GcodeParser.h"

int head = 1;

void setup() {

	step_init();


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

	for (head = 0; head < 20; head++) {
		gcode_parse();
	}

	Serial.println("run");


	//TIMSK1 = 0x02;

}

void loop() {

	if ((stepbuffer.Size() < 30)) {
		gcode_parse();
	}

	if (analogRead(TEMP_0_PIN) > 50) {
		digitalWrite(HEATER_0_PIN,HIGH);
	}
	else if (analogRead(TEMP_0_PIN) < 40) {
		digitalWrite(HEATER_0_PIN, LOW);
	}

	Serial.println(analogRead(TEMP_0_PIN));

}
