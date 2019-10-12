void setup() {
  Serial.begin(115200);
}

float x = 0, y = 0, e = 0;
unsigned long cur_millis = 0;
unsigned long pre_millis = 0;
double renew_xy_pos[][4] = { 0, };
int f = 0, cnt = 0;

byte leng;

float atf(char buff[]);

void loop() {
  char buf[10] = {0, };

  delay(1000);
  Serial.write("OK");
  if (Serial.available()) {
    if (Serial.find("X") || Serial.find("Y") || Serial.find("E") || Serial.find("F")) {

      leng = Serial.readBytesUntil('Y', buf, 10);
      x = atof(buf);

      leng = Serial.readBytesUntil('E', buf, 10);
      y = atof(buf);

      leng = Serial.readBytesUntil('F', buf, 10);
      e = atof(buf);

      leng = Serial.readBytesUntil('G', buf, 10);
      if (atoi(buf) > 5)
        f = atoi(buf);
      else
        f = f;

      cnt++;

      Serial.print("X = " + String(x) + ", Y = " + String(y) + ", E = " + String(e) + ", ");
      Serial.println("F = " + String(f) + ", CNT = " + String(cnt));


      //      renew_xy_pos[i][0] = x;
      //      renew_xy_pos[i][1] = y;
      //      renew_xy_pos[i][2] = e;
      //      renew_xy_pos[i][3] = f;
      //
      //      Serial.print("X = " + String(renew_xy_pos[i][0]) + ", " );
      //      Serial.print("Y = " + String(renew_xy_pos[i][1]) + ", " );
      //      Serial.print("E = " + String(renew_xy_pos[i][2]) + ", " );
      //      Serial.println(String(renew_xy_pos[i][3]));
      //      i++;
    }


  }
}

float atf(char buff[]) {
  int i = 0, j = 0, k = 0;
  float result = 0;
  float square = 1;

  for (i = 0; i < leng; i++) {
    if (buff[i] == '.') {

      k = i;
      for (j = i - 1; j >= 0; j--) {
        result += float(buff[j]);
      }

      for (j = 1; j < leng - i; j++) {
        k++;
        square *= 10;
        result += float(buff[k]) * (1 / square);
      }
    }
  }
  //Serial.println(String(result));
  return result;
}
