#include "PINMAP.h"

#ifndef _TERMISTER_h
#define _TERMISTER_h
#if defined(ARDUINO) && ARDUINO >= 100
	#include "arduino.h"
#else
	#include "WProgram.h"
#endif
#endif

//���̽��� �� �޾ƿ���
int termister_getTemp() {
	return (analogRead(TEMP_0_PIN));
}