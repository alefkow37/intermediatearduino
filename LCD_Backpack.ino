#include <Wire.h>
#include <LiquidCrystal_I2C.h>
unsigned long time;
LiquidCrystal_I2C lcd(0x3f, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display.
int switchpin = 10;
int buttonpin = 5;
int buttonstate = 0;
int switchstate = 0;
int press = 0;
int bp = 0;
void setup()
{
	Serial.begin(9600);
	lcd.begin(16, 2);
	lcd.init();
	lcd.backlight();
	lcd.print("Hello World");
	pinMode(buttonpin, INPUT);
	pinMode(switchpin, INPUT);
	delay(2000);
	lcd.setCursor(0, 0);
	lcd.print("Button Presses =");
}

void loop()
{
	digitalRead(buttonpin);
	digitalRead(switchpin);
	buttonstate = digitalRead(buttonpin);
	Serial.println(buttonstate);
	switchstate = digitalRead(switchpin);
	if (buttonstate == HIGH && bp == LOW)
	{
		press = press += 1;
		bp = HIGH;
	}
	// When the button is pressed and the switch is in the on position count up by 1 with each button press
	else
		if (buttonstate == HIGH && switchstate == LOW)
		{
			press = press -= 1;
		}
	// When the button is pressed and the switch is in the off position count down by 1 with each button press
	else
	{
	}
	if (buttonstate == LOW) {	
		bp = LOW;
	}
	lcd.setCursor(0, 1);
	// This tells it to start in the first column and second row (counting starts at 0)
	lcd.print(press);
	// Print how many times the button has been pressed
	lcd.print(" ");
	// Print a blank space in the place of a 0
	delay(250);
}
