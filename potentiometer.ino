#include <LiquidCrystal_I2C.h>



LiquidCrystal_I2C lcd(0x3F, 16, 2);
int potPin = A2;
int led = 9;
int dial = 0;
int bright = 0 ;
int val = 0; 
void setup()
{
	lcd.begin(16,2);
	lcd.init();
	lcd.backlight();
	lcd.setCursor(0,0);
	lcd.print("BRIGHTNESS:");
	pinMode(potPin, INPUT);
	pinMode(led, OUTPUT);
	Serial.begin(9600);
}	

void loop()
{
	val = analogRead(potPin);
	val = map(val, 0, 1023, 0, 255);
	analogWrite(led, val);
	val = map(val, 0, 255, 11, 0);
	lcd.setCursor(0,1);
	lcd.print(val);
	lcd.print("      ");
	
}