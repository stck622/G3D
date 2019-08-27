// endstop.h

#include "PINMAP.h"

#ifndef _ENDSTOP_h
#define _ENDSTOP_h

#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif


#endif

//endstop 초기화 (min)
void endstop_init() {
	pinMode(X_MIN_PIN, INPUT_PULLUP);
	pinMode(Y_MIN_PIN, INPUT_PULLUP);
	pinMode(Z_MIN_PIN, INPUT_PULLUP);
}

//원하는 축의 endstop 상태 받아오기.
int endstop_getStatus(char pos) {
	switch (pos)
	{
	case 'x':
		return !digitalRead(X_MIN_PIN);
	case 'y':
		return !digitalRead(Y_MIN_PIN);
	case 'z':
		return !digitalRead(Z_MIN_PIN);
	default:
		return -1;
	}
}