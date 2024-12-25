#include <Arduino.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// put function declarations here:
int myFunction(int, int);
Adafruit_SSD1306 display(128,64,&Wire);




// '', 128x64px
const unsigned char epd_bitmap_ [] PROGMEM = {
	0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xfc, 0x70, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x51, 0x77, 0x77, 0x71, 0x71, 0x10, 0x17, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xe0, 0x03, 0xe6, 0xa1, 0x00, 0x02, 0x07, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x44, 0x55, 0x55, 0x55, 0x14, 0x05, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xe8, 0x2a, 0x8a, 0xa8, 0xaa, 0x00, 0x3f, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xe2, 0x22, 0x22, 0x22, 0x22, 0x9b, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xfa, 0x2a, 0x82, 0xaa, 0xaa, 0xbf, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x77, 0x55, 0x51, 0x55, 0x55, 0x55, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xbb, 0xf3, 0x22, 0x22, 0x00, 0x22, 0x0f, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x45, 0x54, 0x01, 0x55, 0x55, 0x55, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xfa, 0xa9, 0x86, 0xaa, 0x62, 0xaf, 0xff, 0x7f, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x75, 0x55, 0x55, 0x55, 0x77, 0x55, 0x55, 0x37, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xf8, 0x3f, 0xbe, 0x23, 0xbf, 0xbb, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xfc, 0x06, 0x9f, 0x7f, 0xa3, 0xee, 0xbf, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x71, 0x11, 0x57, 0x77, 0x77, 0x17, 0x55, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xd8, 0x00, 0x7a, 0x6f, 0xff, 0x3f, 0xff, 0xf7, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x54, 0x44, 0x54, 0x01, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xfe, 0xfe, 0x01, 0xf7, 0xfa, 0x8f, 0xef, 0xff, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xfd, 0xfb, 0x7f, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x51, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xfe, 0xff, 0xef, 0xff, 0xe7, 0xfe, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x75, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x17, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xbf, 0xbe, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbd, 0xfd, 0xfe, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xfe, 0x00, 0xbb, 0xfe, 0xa3, 0xfb, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf7, 0xad, 0xbe, 0xf9, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x77, 0x75, 0x57, 0x55, 0x15, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xf6, 0x3a, 0xff, 0xfa, 0x3f, 0xff, 0x3f, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0x3f, 0xff, 0x9e, 0xfc, 0xaf, 0xff, 0xdf, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x77, 0x75, 0x75, 0x55, 0x51, 0x55, 0x57, 0x77, 0x71, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xfa, 0x02, 0x2f, 0xff, 0xff, 0x7f, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x54, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xea, 0x3b, 0xfd, 0xfe, 0xaa, 0xbf, 0xff, 0xff, 0xf7, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x77, 0x55, 0x55, 0x55, 0x75, 0x15, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xfe, 0x22, 0xbb, 0xbf, 0xfd, 0xa2, 0x2a, 0xff, 0xff, 0xf7, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xfa, 0xaf, 0xfb, 0xff, 0xff, 0xfe, 0xaa, 0xbf, 0xfe, 0xf3, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x75, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0x57, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xf2, 0x7f, 0xff, 0xff, 0xff, 0xfe, 0x22, 0x2f, 0x7f, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x54, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xf1, 0xff, 0xfb, 0xfe, 0xff, 0xfd, 0xaa, 0xaf, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x75, 0x55, 0x55, 0x55, 0x55, 0x51, 0x55, 0x57, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xfa, 0x2a, 0x27, 0xef, 0xd8, 0x22, 0x02, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xaa, 0xaa, 0xab, 0xca, 0xaa, 0xaa, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x75, 0x77, 0x75, 0x55, 0x55, 0x55, 0x55, 0x55, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xf0, 0x22, 0x22, 0xe2, 0x22, 0x22, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x45, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xff, 0xea, 0x3f, 0xfe, 0x2f, 0xef, 0xfa, 0xaf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x77, 0x77, 0x77, 0x77, 0x73, 0x57, 0x55, 0x37, 0x55, 0x75, 0x57, 0x77, 0x77, 0x77, 0x77, 0x77, 
	0xff, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xbf, 0xff, 0xff, 0xff, 0xff, 0xff, 
	0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 0x55, 
	0xff, 0xff, 0xff, 0xef, 0xf7, 0xff, 0xfe, 0xff, 0xff, 0xff, 0xef, 0xff, 0xff, 0xff, 0xff, 0xff
};


void setup() {
  // put your setup code here, to run once:
  Wire.begin(14,12);
  display.begin(SSD1306_SWITCHCAPVCC,0x3c);
  display.clearDisplay();
  display.setTextColor(WHITE);
  display.setTextSize(3);
  display.setCursor(0,0);
  display.print("Hej\nNina");
  display.display();
}

void loop() {
  // put your main code here, to run repeatedly:

}

// put function definitions here:
int myFunction(int x, int y) {
  return x + y;
}