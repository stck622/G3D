#pragma once

#include "Arduino.h"
#include "PinMap.h"

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
		return digitalRead(X_MIN_PIN);
	case 'y':
		return digitalRead(Y_MIN_PIN);
	case 'z':
		return digitalRead(Z_MIN_PIN);
	default:
		return -1;
	}
}