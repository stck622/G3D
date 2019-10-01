// heater.h

#include "PINMAP.h"

#ifndef _HEATER_h
#define _HEATER_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

void heater_init() {
	pinMode(HEATER_0_PIN, OUTPUT);
	pinMode(4, OUTPUT);
}

void heater_run(bool run){
		digitalWrite(HEATER_0_PIN, run);
		digitalWrite(4, run);
}

