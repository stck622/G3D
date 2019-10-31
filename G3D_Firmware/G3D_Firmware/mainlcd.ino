#include "G3D_LCD.h"

G3DLCD geniLCD;
int second1;
int nozztemps = 0;
int bedtemps = 0;
void setup() {
	geniLCD.LCDinit();
}

void loop() {
	geniLCD.maincur = millis();
	if (geniLCD.maincur - geniLCD.mainper > 1) {
		geniLCD.mainper = geniLCD.maincur;
		geniLCD.OnRotateSwitch(digitalRead(31), digitalRead(33));
		geniLCD.OnSelectSwitch(geniLCD.Arrow_Point, geniLCD.Menu_Point, digitalRead(35));
		second1++;
		if (second1 == 500) {
			geniLCD.NozzPrint(nozztemps);
			geniLCD.BedPrint(bedtemps);
			second1 = 0;
			nozztemps++;
			bedtemps += 2;
		}
	}
	geniLCD.ChangeLCD();
}