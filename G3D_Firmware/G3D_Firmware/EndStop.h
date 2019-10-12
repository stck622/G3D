#pragma once

#include "Arduino.h"
#include "PinMap.h"

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
		return digitalRead(X_MIN_PIN);
	case 'y':
		return digitalRead(Y_MIN_PIN);
	case 'z':
		return digitalRead(Z_MIN_PIN);
	default:
		return -1;
	}
}