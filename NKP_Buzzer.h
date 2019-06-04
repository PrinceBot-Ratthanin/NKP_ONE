#define _buzzer 12
void beep(){
	pinMode(_buzzer,OUTPUT);
	digitalWrite(_buzzer,HIGH);
	delay(500);
	digitalWrite(_buzzer,LOW);
	delay(500);
}