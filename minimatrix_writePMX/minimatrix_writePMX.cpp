// Do not remove the include below
#include "minimatrix_writePMX.h"

#include <Wire.h>
#include <Adafruit_GFX.h>
#include "Adafruit_LEDBackpack.h"

Adafruit_8x16minimatrix matrix = Adafruit_8x16minimatrix();
Adafruit_8x16minimatrix matrix2 = Adafruit_8x16minimatrix();

//The setup function is called once at startup of the sketch
void setup() {
// Add your initialization code here

	Serial.begin(9600);
	Serial.println("16x8 LED Mini Matrix Test");

	matrix.begin(0x70);
	matrix2.begin(0x71);
}

// The loop function is called in an endless loop
void loop() {
	matrix.setTextSize(1);
	matrix2.setTextSize(1);

	matrix.setTextWrap(false); // we dont want text to wrap so it scrolls nicely
	matrix.setTextColor(LED_ON);

	matrix.setRotation(1);
	matrix2.setRotation(1);

	for (int x = 0; x >= -140; x--) {
		matrix.clear();
		matrix2.clear();

		matrix.setCursor(x, 0);
		matrix2.setCursor(x-20, 0);

		matrix.print( "          PMX  PM-ROBOTIX ");
		matrix2.print("          PMX  PM-ROBOTIX ");

		matrix.writeDisplay();
		matrix2.writeDisplay();

		delay(25);
	}

//Add your repeated code here
}
