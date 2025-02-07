#include <Arduino.h>
#include <oleddraw.h>

unsigned int DELETEbtn = 19; //2
unsigned int CONFIRMbtn = 5; // 5
unsigned int UPbtn = 4; //4
unsigned int DOWNbtn = 2; //0
unsigned int picturemode = 18; //13

oleddraw* screen = nullptr;

void setup()
{
	Serial.begin(115200);

	pinMode(CONFIRMbtn, INPUT_PULLUP);
	pinMode(DELETEbtn, INPUT_PULLUP);
	pinMode(UPbtn, INPUT_PULLUP);
	pinMode(DOWNbtn, INPUT_PULLUP);
	pinMode(picturemode, INPUT_PULLUP);
	screen = new oleddraw(14,12);
	Serial.println("> Setup succesfull waiting for loop");
	
	delay(800);
}

unsigned int curimg = 0;

void loop(){

	if (!digitalRead(picturemode))
	{
		screen->showimagefromdb((4 > curimg) ? 0 : curimg);
		curimg++;
		delay(150);
	}

	if (!digitalRead(CONFIRMbtn))
	{
		screen->confirm();
		delay(150);
	}
	if (!digitalRead(DELETEbtn))
	{
		screen->deletestuf();
		delay(150);
	}
	if (!digitalRead(UPbtn))
	{
		screen->up();
		delay(150);
	}
	if (!digitalRead(DOWNbtn))
	{
		screen->down();
		delay(150);
	}
}