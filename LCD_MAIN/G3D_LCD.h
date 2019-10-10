/*******************************

Last Modified Date : 10-04

*******************************/

#ifndef G3D_LCD_H
#define G3D_LCD_H

#include "Arduino.h"

#define Data 1
#define Setting 0
#define RS 2
#define E 4

class G3DLCD{
public:
  ~G3DLCD();
  G3DLCD();
  void bit4Push(unsigned char data, bool modflag); //Data transmission through 4 bits
  void bit8Push(unsigned char data, bool modflag); //Data transmission through 8 bits
  void OnRotateSwitch(bool EN1, bool EN2);
  void OnSelectSwitch(int Arrow_Point,int Menu_Point,bool switchsum);
  void Movingarrow(bool flag);
  void SelectCase(int menus);
  void ChangeLCD();
  void LCDinit();

  unsigned long maincur, mainper;

  unsigned long per; //using micros structure
  bool changeTrigger,ScrollFlag,non; //Writing lcd trigger
  int state; //rotate Switch statement
  int row,col,scrollcount; //writing lcd rows,cols
  int Zero_Point, Arrow_Point, Menu_Point, Select_Point; //using scroll point
private:

  int pinmap[4][20] = { 
    {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93},
    {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3},
    {0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7},
    {0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7}};
  //LCD PinMap
  char* Menus[5][6] = { 
                     {"Temp:19C  bed:220C ",
                      "X  0  Y  0  Z00.00 ",
                      " SD81%    ---100%  ",
                      "GeniEarth v1 Ready " },
                      
                     {" X motor speed    |",
                      " Y motor speed    |",
                      " Z motor speed    |",
                      " Heatbed temp     |",
                      " Feedrate set     |",
                      " Status           |"},
                      
                     {" X speed          |",
                      " X position       |",
                      " back             |",
                      " _________________| " },
                      
                     {" Y speed          |",
                      " Y position       |",
                      " back             |",
                      " _________________|" },
                      
                     {" Z speed          |",
                      " Z position       |",
                      " back             |",
                      " _________________|" }};
  //Menus
};

#endif /*G3D_LCD_H*/
