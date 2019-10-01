#ifndef LCDH_h
#define LCDH_h
#define RS 2
#define E 4
char data[10];
short win_point, sel_point;
int SCount, i_low, j_column, MenuValue, MenuLv, cursor_, state = 0;
unsigned long per, permil;
bool Scrollflag,ScrollX,rf;
int pinmap[4][20] =
{
  {0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93},
  {0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3},
  {0x94, 0x95, 0x96, 0x97, 0x98, 0x99, 0x9A, 0x9B, 0x9C, 0x9D, 0x9E, 0x9F, 0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7},
  {0xD4, 0xD5, 0xD6, 0xD7, 0xD8, 0xD9, 0xDA, 0xDB, 0xDC, 0xDD, 0xDE, 0xDF, 0xE0, 0xE1, 0xE2, 0xE3, 0xE4, 0xE5, 0xE6, 0xE7}
};

char* Menu[5][6] = { 
                     {"Temp:19C  bed:220C ",
                      "X  0  Y  0  Z00.00 ",
                      " SD81%    ---100%  ",
                      "GeniEarth v1 Ready " },
                      
                     {" X motor speed    |",
				              " Y motor speed    |",
				              " Z motor speed    |",
				              " Feedrate set     |",
				              " Heatbed temp     |",
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


void LCDsetting4(unsigned char sum, bool dataflag);
void LCDsetting8(unsigned char sum, bool dataflag);
void CheckSwitch(bool EN1, bool EN2);
void Moving_arrow(bool flag);
void Scroll_Window();
void LCDSTART_();
void Change_window(char** menus);

#endif
