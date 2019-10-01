#include "LCDH.h"
void setup() {
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
  
  LCDSTART_();
  
  Scrollflag=true;
  LCDsetting4(pinmap[0][0], 0);
  sprintf(data,"%d",1234);
  Serial.println(data[0]);

}

void loop() {
  
  unsigned long curmil = millis();
  if(curmil-permil>1)
  {
    permil=curmil;
    bool EN1 = digitalRead(6);
    bool EN2 = digitalRead(7);
    CheckSwitch(EN1,EN2);
    bool it5 = digitalRead(3);
    if(!it5)
    {
      if(rf)
      {
        LCDsetting4(0x01, 0);
        delay(10);
        rf=0;
        switch(MenuLv)
        {
          case 0:    MenuLv = 1; ScrollX = false; Change_window(Menu[1]);   break;
          case 1:
          switch(sel_point)
          {
            case 0 : MenuLv = 2; ScrollX = true; Change_window(Menu[2]); break;
            case 1 : MenuLv = 3; ScrollX = true; Change_window(Menu[3]); break;
            case 2 : MenuLv = 4; ScrollX = true; Change_window(Menu[4]); break;
            case 3 : 
            case 4 : 
            case 5 : MenuLv = 0; Change_window(Menu[0]); break;
            default : break;
          }
          break;
          case 2:
          switch(sel_point)
          {
            case 0 :  
            case 1 :  
            case 2 : MenuLv = 1; ScrollX = false; Change_window(Menu[1]);   break;
            default : break;
          }
          break;
          case 3:
          switch(sel_point)
          {
            case 0 :  
            case 1 :  
            case 2 : MenuLv = 1; ScrollX = false; Change_window(Menu[1]);    break;
            default : break;
          }
          break;
          case 4:
          switch(sel_point)
          {
            case 0 :  
            case 1 :  
            case 2 : Change_window(Menu[1]); MenuLv = 1; ScrollX = false; break;
            default : break;
          }
          break;
          default: break;
        }
      }
    }
    else rf=1;
  }
  Scroll_Window();
}










void LCDsetting4(unsigned char sum, bool dataflag) {
	int tmp = 0x80;
	for (int i = 0; i < 2; i++)
	{
		if (dataflag) digitalWrite(RS, HIGH);
		else digitalWrite(RS, LOW);
		for (int j = 13; j >= 10; j--) {
			if (sum & tmp) digitalWrite(j, HIGH);
			else digitalWrite(j, LOW);
			tmp >>= 1;
		}
		digitalWrite(E, HIGH);
		digitalWrite(E, LOW);
		digitalWrite(RS, HIGH);
		delayMicroseconds(50);
	}
}

void LCDsetting8(unsigned char sum, bool dataflag) {
	int tmp = 0x80;
	if (dataflag) digitalWrite(RS, HIGH);
	else digitalWrite(RS, LOW);
	for (int j = 13; j >= 10; j--) {
		if (sum & tmp) digitalWrite(j, HIGH);
		else digitalWrite(j, LOW);
		tmp >>= 1;
	}
	digitalWrite(E, HIGH);
	digitalWrite(E, LOW);
	digitalWrite(RS, HIGH);
	delayMicroseconds(50);
}

void CheckSwitch(bool EN1, bool EN2)
{
	//state zero
	if (state == 0){
		if (EN1 == 0) state = 1;
		if (EN2 == 0) state = 4;
	}

	//right state
	if (state == 1){
		if (EN2 == 0) state = 2;
		if (EN1 == 1) state = 0;
	}
	if (state == 2){
		if (EN1 == 1 && EN2 == 0) state = 3;
	}
	if (state == 3){
		if (EN1 == 1 && EN2 == 1) {
			Moving_arrow(0);
			state = 0;
		}
	}

	//left state
	if (state == 4) {
		if (EN1 == 0) state = 5;
		if (EN2 == 1) state = 0;
	}
	if (state == 5){
		if (EN1 == 0 && EN2 == 1) state = 6;
	}
	if (state == 6){
		if (EN1 == 1 && EN2 == 1) {
			Moving_arrow(1);
			state = 0;
		}
	}
}

void Moving_arrow(bool flag) {
  if(MenuLv>0){
  	if (flag) {
  		if (win_point != 0 && cursor_ < 1 && !ScrollX) {
  			win_point--;
        //Scroll_Windowwindow(win_point);
        Scrollflag=true;
  			sel_point--;
  		}
  		else if (cursor_ != 0) {
  			cursor_--;
  			LCDsetting4(pinmap[cursor_ + 1][0], 0);
  			sel_point--;
  		}
  	}
  	else {
  		if (win_point != 2 && cursor_ > 2 && !ScrollX) {
  			win_point++;
        
      //Scroll_Windowwindow(win_point);
       Scrollflag=true;
  			sel_point++;
  		}
  		else if (cursor_ != 3) {
  			cursor_++;
        
  			LCDsetting4(pinmap[cursor_ - 1][0], 0);
  			sel_point++;
  		}
  	}
  	LCDsetting4(0x20, 1);
  	LCDsetting4(pinmap[cursor_][0], 0);
  	LCDsetting4(0x3E, 1);
  }
}

void Change_window(char** menus) {
  
  	for (int i = 0; i < 4; i++) {
  		LCDsetting4(pinmap[i][1], 0);
  		for (int j = 0; j < 19; j++) {
  			LCDsetting4(*(*(menus + i) + j), 1);
  			delayMicroseconds(50);
  		}
  	}
    win_point=0;
    sel_point=0;
    cursor_=0;
    LCDsetting4(pinmap[0][0], 0);
    if(MenuLv>0){
      LCDsetting4(0x3E, 1);
    }
}

void Scroll_Window()
{
  unsigned long cur=micros();
  if(Scrollflag) { 
    if(cur-per>100) {
        per=cur;
        if(i_low==0 && j_column==0) LCDsetting4(0x81, 0);  
        LCDsetting4(*(*(*(Menu+MenuLv) + i_low + win_point) + j_column), 1);
        j_column++;
        if(j_column%19==0) {
          j_column=0; 
          
          LCDsetting4(pinmap[i_low+1][1], 0);
          i_low++;
        }
        SCount++;
        if(SCount==76) 
        {
          j_column=0;
          i_low=0;
          SCount=0;
          Scrollflag=false;
        }
    }
  }
}
void LCDSTART_()
{
  LCDsetting8(0x30,0);
  LCDsetting8(0x30,0);
  LCDsetting8(0x30,0);
  LCDsetting8(0x20,0);
  LCDsetting4(0x28,0);
  LCDsetting4(0x06,0);
  LCDsetting4(0x0C,0);
  LCDsetting4(0x80,0);
  LCDsetting4(0x01,0);
  delay(10);
}
