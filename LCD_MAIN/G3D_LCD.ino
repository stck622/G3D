#include <G3D_LCD.h>

G3DLCD geniLCD;
void setup() {
	geniLCD.LCDinit();
}

void loop() {

	geniLCD.maincur = millis();
	if(geniLCD.maincur-geniLCD.mainper>1) {
		geniLCD.mainper=geniLCD.maincur;
		geniLCD.GetRotateSwitch(digitalRead(6),digitalRead(7));
		geniLCD.GetSelectSwitch(geniLCD.Arrow_Point,geniLCD.Menu_Point,digitalRead(3));
	}
	geniLCD.ChangeLCD();
}
