#include "G3D_LCD.h"

G3DLCD::G3DLCD() {}

void G3DLCD::LCDinit() {
	Serial.begin(9600);
	for (int i = 23; i < 30; i++) {
		pinMode(i, OUTPUT);
	}
	pinMode(16, OUTPUT);
	pinMode(17, OUTPUT);

	pinMode(37, OUTPUT);
	pinMode(31, INPUT);
	pinMode(33, INPUT);
	pinMode(35, INPUT);
	digitalWrite(31, 1);
	digitalWrite(33, 1);
	digitalWrite(35, 1);
	digitalWrite(37, 0);
	bit8Push(0x3, Setting);
	bit8Push(0x3, Setting);
	bit8Push(0x3, Setting);
	bit8Push(0x2, Setting);
	bit4Push(0x28, Setting);
	bit4Push(0x06, Setting);
	bit4Push(0x0C, Setting);
	bit4Push(0x80, Setting);
	bit4Push(0x01, Setting);

	delay(10);
	changeTrigger = true;
}

void G3DLCD::bit4Push(unsigned char data, bool modflag) {
	for (int j = 0; j < 2; j++) {
		digitalWrite(RS, modflag);

		for (int i = 0; i < 4; i++) {

			digitalWrite((23 + (2 * i)), (((0x10 >> j * 4) << i) & data));

		}

		digitalWrite(E, HIGH);
		digitalWrite(E, LOW);
		delayMicroseconds(50);

		digitalWrite(RS, HIGH);

		delayMicroseconds(100);
	}
}

void G3DLCD::bit8Push(unsigned char data, bool dataflag) {

	digitalWrite(RS, dataflag);

	for (int i = 0; i < 4; i++) {

		digitalWrite((23 + (2 * i)), ((0x1 << i) & data));

	}

	digitalWrite(E, HIGH);
	digitalWrite(E, LOW);
	delayMicroseconds(50);

	digitalWrite(RS, HIGH);

	delayMicroseconds(100);
}

void G3DLCD::OnRotateSwitch(bool EN1, bool EN2) {
	//state zero
	if (state == 0) {
		if (EN1 == 0) state = 1;
		if (EN2 == 0) state = 4;
	}

	//right state
	if (state == 1) {
		if (EN2 == 0) state = 2;
		if (EN1 == 1) state = 0;
	}
	if (state == 2) {
		if (EN1 == 1 && EN2 == 0) state = 3;
	}
	if (state == 3) {
		if (EN1 == 1 && EN2 == 1) {
			Movingarrow(0);
			state = 0;
		}
	}

	//left state
	if (state == 4) {
		if (EN1 == 0) state = 5;
		if (EN2 == 1) state = 0;
	}
	if (state == 5) {
		if (EN1 == 0 && EN2 == 1) state = 6;
	}
	if (state == 6) {
		if (EN1 == 1 && EN2 == 1) {
			Movingarrow(1);
			state = 0;
		}
	}
}

void G3DLCD::OnSelectSwitch(int arrow_Point, int menu_Point, bool switchsum) {

	if (!switchsum) {
		Serial.println("switch");
		if (non) {
			bit4Push(0x01, 0);
			delay(10);
			Zero_Point = 0;
			Arrow_Point = 0;
			non = 0;
			switch (menu_Point) {
			case 0:     SelectCase(1); break;
			case 1:
				switch (Select_Point) {
				case 0:  SelectCase(2); break;
				case 1:  SelectCase(3); break;
				case 2:  SelectCase(4); break;
				case 3:
				case 4:
				case 5:  SelectCase(0); break;
				default: break;
				}
				break;
			case 2:
				switch (Select_Point) {
				case 0:
				case 1:
				case 2:  SelectCase(1);  break;
				default: break;
				}
				break;
			case 3:
				switch (Select_Point) {
				case 0:
				case 1:
				case 2:  SelectCase(1);  break;
				default: break;
				}
				break;
			case 4:
				switch (Select_Point) {
				case 0:
				case 1:
				case 2: SelectCase(1); break;
				default: break;
				}
				break;
			default: break;
			}
		}

	}
	else non = 1;
}

void G3DLCD::NozzPrint(int Nozztemp) {
	char Nozzstring[3];
	sprintf(Nozzstring, "%d", Nozztemp);
	if (Nozzstring[1] == '\0') {
		bit4Push(pinmap[0][8], Setting);
		bit4Push(Nozzstring[0], Data);
	}
	else if (Nozzstring[2] == '\0') {
		bit4Push(pinmap[0][7], Setting);
		bit4Push(Nozzstring[0], Data);
		bit4Push(pinmap[0][8], Setting);
		bit4Push(Nozzstring[1], Data);
	}
	else {
		bit4Push(pinmap[0][6], Setting);
		bit4Push(Nozzstring[0], Data);
		bit4Push(pinmap[0][7], Setting);
		bit4Push(Nozzstring[1], Data);
		bit4Push(pinmap[0][8], Setting);
		bit4Push(Nozzstring[2], Data);
	}
}

void G3DLCD::BedPrint(int Bedtemp) {
	char Nozzstring[3];
	sprintf(Nozzstring, "%d", Bedtemp);
	if (Nozzstring[1] == '\0') {
		bit4Push(pinmap[0][17], Setting);
		bit4Push(Nozzstring[0], Data);
	}
	else if (Nozzstring[2] == '\0') {
		bit4Push(pinmap[0][16], Setting);
		bit4Push(Nozzstring[0], Data);
		bit4Push(pinmap[0][17], Setting);
		bit4Push(Nozzstring[1], Data);
	}
	else {
		bit4Push(pinmap[0][15], Setting);
		bit4Push(Nozzstring[0], Data);
		bit4Push(pinmap[0][16], Setting);
		bit4Push(Nozzstring[1], Data);
		bit4Push(pinmap[0][17], Setting);
		bit4Push(Nozzstring[2], Data);
	}
}

void G3DLCD::ChangeLCD() {
	unsigned long cur = micros();
	if (changeTrigger) {
		if (cur - per > 100) { //micros()
			per = cur;
			if (row == 0 && col == 0) { 			 	 //first setting
				if (Arrow_Point == 0 && Menu_Point != 0) {
					bit4Push(0x80, Setting);
					bit4Push(0x3E, Data);
				}
				else bit4Push(0x81, Setting);
			}
			bit4Push(*(*(*(Menus + Menu_Point) + col + Zero_Point) + row), Data); //writing data (19*4)
			row++;
			if (row % 19 == 0) {
				row = 0;
				bit4Push(pinmap[col + 1][1], Setting);
				col++;
			}
			scrollcount++;
			if (scrollcount == 76) {
				col = 0;
				row = 0;
				scrollcount = 0;
				changeTrigger = false;

			}
		}
	}
}

void G3DLCD::Movingarrow(bool flag) {
	Serial.println("changed");
	if (Menu_Point > 0) {
		if (flag) {
			Serial.println("down");
			if (Zero_Point != 0 && Arrow_Point < 1 && ScrollFlag) {
				Zero_Point--;
				changeTrigger = true;
				Select_Point--;
			}
			else if (Arrow_Point != 0) {
				Arrow_Point--;
				bit4Push(pinmap[Arrow_Point + 1][0], 0);
				Select_Point--;
			}
		}
		else {
			Serial.println("up");
			if (Zero_Point != 2 && Arrow_Point > 2 && ScrollFlag) {
				Zero_Point++;
				changeTrigger = true;
				Select_Point++;
			}
			else if (Arrow_Point != 3) {
				Arrow_Point++;
				bit4Push(pinmap[Arrow_Point - 1][0], 0);
				Select_Point++;
			}
		}
		bit4Push(0x20, 1);
		bit4Push(pinmap[Arrow_Point][0], 0);
		bit4Push(0x3E, 1);
	}
}

void G3DLCD::SelectCase(int menus) {
	if ((menus <= 4 && menus >= 2) || menus == 0) ScrollFlag = false;
	else ScrollFlag = true;
	changeTrigger = true;
	Menu_Point = menus;
	Select_Point = 0;
}



G3DLCD::~G3DLCD() {}
