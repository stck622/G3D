#include "Status.h"
#include "StepMotor.h"
#include "sample_gcode.h"

void setup() {

	step_init();
	step_lock('a',true);
	Serial.begin(9600);

	for (int i = 1; i < 30; i ++) {
		StepBuffer tmp;
		tmp.Set_StepBuffer((xy_pos[i][0] - xy_pos[i - 1][0]), (xy_pos[i][1] - xy_pos[i - 1][1]), 0, 0,1125);
		stepbuffer.PushBack(tmp);
	}

	Serial.println("run");
	TIMSK1 = 0x02;

}

void loop() {

	
  
}
