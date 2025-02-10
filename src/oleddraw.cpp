#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <images.h>
#include <oleddraw.h>

Adafruit_SSD1306 display(128, 64, &Wire);
String buff = "";
unsigned int charac = 65;
bool curdisplayed = false;

oleddraw::oleddraw(int sda, int scl) {
    Wire.begin(sda, scl);
	display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
	display.clearDisplay();
	display.setTextColor(WHITE);
	display.setTextSize(2);
	display.drawBitmap(0, 0, intro, 128, 64, WHITE);
	display.setCursor(0, 0);
	display.display();

}

oleddraw::~oleddraw(){
    
}

int oleddraw::uibackground(){
	display.clearDisplay();
	display.drawRect(0,0,128,64,SSD1306_WHITE);
	display.display();
	return 0;
}



int oleddraw::showimagefromdb(unsigned int curimg){

    switch (curimg){
    case 0:
        show();
        break;
    case 1:
        display.clearDisplay();
        display.drawBitmap(0, 0, epd_bitmap_1, 128, 64, WHITE);
        display.display();
        break;
    case 2:
        display.clearDisplay();
        display.drawBitmap(0, 0, epd_bitmap_2, 128, 64, WHITE);
        display.display();
        break;
    case 3:
        display.clearDisplay();
        display.drawBitmap(0, 0, epd_bitmap_3, 128, 64, WHITE);
        display.display();
        break;
    case 4:
        display.clearDisplay();
        display.drawBitmap(0, 0, epd_bitmap_4, 128, 64, WHITE);
        display.display();
        break;

    default:
        break;
    }
		
    
    return 0;
}


int oleddraw::deletestuf()
{
	display.clearDisplay();
	if (buff.length() > 0)
	{
		buff = buff.substring(0, buff.length() - 1);
	}
	display.setCursor(0, 0);
	display.print(buff);
	display.display();
	display.setCursor(0, 0);
	
	return 0;
}

int oleddraw::show()
{
	display.clearDisplay();
	display.setCursor(0, 0);
	display.print(buff);
	display.display();
	display.setCursor(0, 0);
	
	return 0;
}
int oleddraw::confirm()
{
	display.clearDisplay();
	buff += String(char(charac));
	display.print(buff);
	display.display();
	display.setCursor(0, 0);
	
	return 0;
}

int oleddraw::cursorflash(){
	
	if (!curdisplayed)
	{
		display.print(buff+"_");
		display.display();
		curdisplayed=true;
	}else{show();curdisplayed=false;}

	return 0;
}
int oleddraw::up()
{
	charac++;
	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextColor(WHITE);
	display.print(buff + String(char(charac)));
	display.display();
	display.setCursor(0, 0);
	
	return 0;
}
int oleddraw::down()
{
	charac--;
	display.clearDisplay();
	display.setCursor(0, 0);
	display.setTextColor(WHITE);
	display.print(buff + String(char(charac)));
	display.display();
	display.setCursor(0, 0);
	
	return 0;
}
