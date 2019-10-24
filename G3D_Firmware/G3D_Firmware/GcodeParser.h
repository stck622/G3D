
#pragma once

File myFile;

void sd_init() {

	pinMode(53, OUTPUT);

	if (!SD.begin(4)) {
		Serial.println("initialization failed!");
		return;
	}

	Serial.println("initialization done.");

}

void sd_open_file(char* name) {

	myFile = SD.open(name, FILE_READ);

}

String sd_get_line() {
	header++;
	return (myFile.readStringUntil('\n'));
}

void sd_close() {
	myFile.close();
}

double get_value(String str, String pos) {
	int i = str.indexOf(pos);
	if (i == -1) return -1;
	while ((i < str.length()) && str[i] != ' ')i++;
	return (str.substring(str.indexOf(pos) + 1, i)).toDouble();
}

void gcode_parse() {

	String str = sd_get_line();

	if (((get_value(str, "G")) == 0) || ((get_value(str, "G")) == 1) || ((get_value(str, "G")) == 92)) {

		double
			x_mm = get_value(str, "X"),
			y_mm = get_value(str, "Y"),
			z_mm = get_value(str, "Z"),
			e_mm = get_value(str, "E"),
			feedrate = get_value(str, "F");

		StepBuffer tmp;

		tmp.Set_StepBuffer(get_value(str, "G"), (x_mm), (y_mm), z_mm, e_mm, feedrate, header);

		stepbuffer.PushBack(tmp);

	}
	else {
		Serial.println(str);
	}



}