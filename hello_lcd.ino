#include <LiquidCrystal.h>
unsigned long time;
LiquidCrystal lcd(7, 8, 9, 10, 11, 12); // Those are the pins for RS, EN, DB4, DB5, DB6, DB7, respectively
void setup()
{
	lcd.begin(16,2); 
	//initialize LCD
	lcd.setCursor(0,0);
	lcd.print("Hello, World!");
}

void loop()
{
	lcd.setCursor(0,1);
	lcd.print(time/1000);
	time = millis();
}

