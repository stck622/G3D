void setup() {
  Serial.begin(9600);
}

unsigned long cur_millis = 0;
unsigned long pre_millis = 0;
double renew_xy_pos[][4] = { 0, };
float x = 0, y = 0, e = 0;
int f = 0, g = 0, cnt = 0;

float x_float = 0, y_float = 0, e_float = 0;
char f_char[10], g_char[5], x_char[10], y_char[10], e_char[10];
int g_int, f_int, j = 0, k = 0;

float atf(char buff[]);
byte leng;


void loop() {
  char buf[10] = {0, };

  if (Serial.available()) {
    Serial.println("Receiving...");
    /*
        if (Serial.find("G") || Serial.find("X") || Serial.find("Y") || Serial.find("E") || Serial.find("F")) {

          leng = Serial.readBytesUntil('X', buf, 10);
          g = atoi(buf);

          leng = Serial.readBytesUntil('Y', buf, 10);
          x = atof(buf);

          leng = Serial.readBytesUntil('E', buf, 10);
          y = atof(buf);

          leng = Serial.readBytesUntil('F', buf, 10);
          e = atof(buf);

          leng = Serial.readBytesUntil('\0', buf, 10);
          if (atoi(buf) > 5)
            f = atoi(buf);
          else
            f = f;
    */

    //String gcode = Serial.readString();
    char gcode[100];
    Serial.println(Serial.read());
    //Serial.println(gcode);
    //Serial.println(leng);
    for (int i = 0; i < leng; i++) {

      if (gcode[i] == 'G') {
        j = i;
        while (gcode[j] != ' ') {
          j++;

          g_char[k] = gcode[j];
          k++;
        }
        k = 0;
      }
      if (gcode[i] == 'X') {
        j = i;
        while (gcode[j] != ' ')
        {
          j++;

          x_char[k] = gcode[j];
          k++;
        }
        k = 0;

      }
      if (gcode[i] == 'Y') {
        j = i;
        while (gcode[j] != ' ') {
          j++;

          y_char[k] = gcode[j];
          k++;
        }
        k = 0;
      }
      if (gcode[i] == 'E') {
        j = i;
        while (gcode[j] != ' ') {
          j++;

          e_char[k] = gcode[j];
          k++;
        }
        k = 0;
      }
      if (gcode[i] == 'F') {
        j = i;
        while (gcode[j] != '\0') {
          j++;

          f_char[k] = gcode[j];
          k++;
        }
        k = 0;
      }
    }

    g_int = atoi(g_char);
    x_float = atof(x_char);
    y_float = atof(y_char);
    e_float = atof(e_char);
    f_int = atoi(f_char);

    //cnt++;

    Serial.print("G = " + String(g_int) + ", X = " + String(x_float) + ", Y = " + String(y_float));
    Serial.println(", E = " + String(e_float) + ", F = " + String(f_int) + ", CNT = " + String(cnt));

    cnt++;
    j = 0; k = 0;
    //Serial.print("G = " + String(g) + ", X = " + String(x) + ", Y = " + String(y));
    //Serial.println(", E = " + String(e) + ", F = " + String(f) + ", CNT = " + String(cnt));
  }
}
