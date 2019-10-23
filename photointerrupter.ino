const byte ledPin = 13;  
const byte interruptPin = 2; 
int photoPin = 2;
volatile byte state = LOW; 

void setup()
{
	Serial.begin(9600);
	pinMode(ledPin, OUTPUT);
	pinMode(photoPin, INPUT_PULLUP);
	attachInterrupt(digitalPinToInterrupt(interruptPin), blink, RISING); //(pin, function, mode) turns led on
}

void loop()
{
	digitalWrite(ledPin, state);  
}

void blink()
{
	state = !state;
}

