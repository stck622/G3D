#include "G3D_LCD.h"











G3DLCD::G3DLCD(){}

void G3DLCD::LCDinit() {
	Serial.begin(9600);
  for (int i = 2; i < 14; i++) {
    pinMode(i, OUTPUT);
  }
  pinMode(3,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  digitalWrite(6,1);
  digitalWrite(7,1);
  digitalWrite(3,1);
	bit8Push(0x30,Setting);
	bit8Push(0x30,Setting);
	bit8Push(0x30,Setting);
	bit8Push(0x20,Setting);
	bit4Push(0x28,Setting);
	bit4Push(0x06,Setting);
	bit4Push(0x0C,Setting);
	bit4Push(0x80,Setting);
	bit4Push(0x01,Setting);
	
	delay(10);
	changeflag=true;

}

void G3DLCD::bit4Push(unsigned char data, bool modflag){
	int tmp = 0x80;
	for (int i = 0; i < 2; i++) {	
		//modflag - (data) / (setting) mod 
		if (modflag) digitalWrite(RS, HIGH);
		else 				 digitalWrite(RS, LOW);

		//13-10port push data
		for (int j = 13; j >= 10; j--) {
			if (data & tmp) digitalWrite(j, HIGH);
			else 					  digitalWrite(j, LOW);
			tmp >>= 1;
		}

		digitalWrite(E, HIGH);
		digitalWrite(E, LOW);
		digitalWrite(RS, HIGH);
		delayMicroseconds(50);
	}
}

void G3DLCD::bit8Push(unsigned char data, bool dataflag) {
	int tmp = 0x80;

	//modflag - (data) / (setting) mod 
	if (dataflag) digitalWrite(RS, HIGH);
	else 					digitalWrite(RS, LOW);

	//13-10port push data
	for (int j = 13; j >= 10; j--) {
		if (data & tmp) digitalWrite(j, HIGH);
		else 					  digitalWrite(j, LOW);
		tmp >>= 1;
	}

	digitalWrite(E, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(RS, HIGH);
	delayMicroseconds(50);
}

void G3DLCD::GetRotateSwitch(bool EN1, bool EN2){
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

void G3DLCD::GetSelectSwitch(int arrow_Point,int menu_Point,bool switchsum){
	if(!switchsum) {
      if(non) {
      	bit4Push(0x01, 0);
    		delay(10);
    		Zero_Point=0;
    		Arrow_Point=0;
        non=0;
        switch(menu_Point) {
          case 0:     SelectCase(1); break;
          case 1:
          switch(Select_Point) {
            case 0 :  SelectCase(2); break;
            case 1 :  SelectCase(3); break;
            case 2 :  SelectCase(4); break;
            case 3 : 
            case 4 : 
            case 5 :  SelectCase(0); break;
            default : break;
          }
          break;
          case 2:
          switch(Select_Point){
            case 0 :  
            case 1 :  
            case 2 :  SelectCase(1);  break;
            default : break;
          }
          break;
          case 3:
          switch(Select_Point) {
            case 0 :  
            case 1 :  
            case 2 :  SelectCase(1);  break;
            default : break;
          }
          break;
          case 4:
          switch(Select_Point) {
            case 0 :  
            case 1 :  
            case 2 : SelectCase(1); break;
            default : break;
          }
          break;
          default: break;
        }
      }

    }
    else non=1;
}

void G3DLCD::ChangeLCD() {
	unsigned long cur=micros();
	if(changeflag){
	  if(cur-per>100) { //micros()
	    per=cur;
			if(row==0 && col==0){ 			 	 //first setting
			 	if(Arrow_Point==0&&Menu_Point!=0){
			 		bit4Push(0x80, Setting);
			 	  bit4Push(0x3E, Data);
			 	}
			 	else bit4Push(0x81, Setting);
			}
	    bit4Push(*(*(*(Menus+Menu_Point) + col + Zero_Point) + row), Data); //writing data (19*4)
	    row++;
	    if(row%19==0) {
	    	row=0;
	    	bit4Push(pinmap[col+1][1], Setting);
	      col++;
	    }
	    scrollcount++;
	    if(scrollcount==76) {
	    	col=0;
	    	row=0;
	    	scrollcount=0;
	    	changeflag=false;

	    }
	  }
	}
}

void G3DLCD::Movingarrow(bool flag) {
  if(Menu_Point>0){
  	if (flag) {
  		Serial.println("down");
  		if (Zero_Point != 0 && Arrow_Point < 1 && !ScrollFlag) {
  			Zero_Point--;
        changeflag=true;
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
  		if (Zero_Point != 2 && Arrow_Point > 2 && !ScrollFlag) {
  			Zero_Point++;
        changeflag=true;
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

void G3DLCD::SelectCase(int menus){
	ScrollFlag = false; 
	changeflag=true;
	Menu_Point = menus;
	Select_Point=0;
}
