#include <SD.h>
#include "GcodeParser.h"
#include "Status.h"
#include "StepMotor.h"

int head = 1;

void setup() {

	step_init();

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
		double x_mm, y_mm, z_mm, e_mm, feedrate;
		StepBuffer tmp;
		gcode_parse(&x_mm, &y_mm, &z_mm, &e_mm, &feedrate);
		tmp.Set_StepBuffer((x_mm - sd_x_mm), (y_mm - sd_y_mm), 0, 0, feedrate);
		sd_x_mm = x_mm;
		sd_y_mm = y_mm;
		stepbuffer.PushBack(tmp);
	}


	TIMSK1 = 0x02;

}

void loop() {

	//if ((stepbuffer.Size() < 18) && (head != 480)) {
	//	StepBuffer tmp;
	//	tmp.Set_StepBuffer((xy_pos[head][0] - xy_pos[head - 1][0]), (xy_pos[head][1] - xy_pos[head - 1][1]), 0, 0, xy_pos[head][2]);
	//	stepbuffer.PushBack(tmp);
	//	head++;
	//}

	if ((stepbuffer.Size() < 30)) {
		double x_mm, y_mm, z_mm, e_mm, feedrate;
		StepBuffer tmp;
		gcode_parse(&x_mm, &y_mm, &z_mm, &e_mm, &feedrate);
		tmp.Set_StepBuffer((x_mm - sd_x_mm), (y_mm - sd_y_mm), 0, 0, feedrate);
		sd_x_mm = x_mm;
		sd_y_mm = y_mm;
		stepbuffer.PushBack(tmp);
		head++;
	}

}
