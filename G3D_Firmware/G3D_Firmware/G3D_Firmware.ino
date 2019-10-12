#include "Status.h"
#include "StepBuffer.h"

void setup() {

	Serial.begin(9600);

	StepBuffer a;
	StepBuffer b;

	a.X_STEP_CNT = 100;
	b.X_STEP_CNT = 200;

	stepbuffer.PushBack(a);
	stepbuffer.PushBack(b);

	stepbuffer.PopBack();
	Serial.println(stepbuffer.Front().X_STEP_CNT);

}

void loop() {

	
  
}
