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

//endstop �ʱ�ȭ (min)
void endstop_init() {
	pinMode(X_MIN_PIN, INPUT_PULLUP);
	pinMode(Y_MIN_PIN, INPUT_PULLUP);
	pinMode(Z_MIN_PIN, INPUT_PULLUP);
}

//���ϴ� ���� endstop ���� �޾ƿ���.
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