
#define A0 39
#define A1 34
#define A2 32
#define A3 35
#define A4 25
#define A5 33
#define A6 27
#define A7 26
#define A8 13
#define A9 14
int analog(int _pin){
	if(_pin == 0)_pin = A0;
	else if(_pin == 1)_pin = A1;
	else if(_pin == 2)_pin = A2;
	else if(_pin == 3)_pin = A3;
	else if(_pin == 4)_pin = A4;
	else if(_pin == 5)_pin = A5;
	else if(_pin == 6)_pin = A6;
	else if(_pin == 7)_pin = A7;
	else if(_pin == 8)_pin = A8;
	else if(_pin == 9)_pin = A9;
  return analogRead(_pin);
}
int in(int _pin){
  pinMode(_pin,INPUT);
  return digitalRead(_pin);
}
int in_pullup(int _pin){
  pinMode(_pin,INPUT_PULLUP);
  return digitalRead(_pin);
}
void out(int _pin,int _state){
  pinMode(_pin,OUTPUT);
  digitalWrite(_pin,_state);
}
float getdist(int _pin){
  float volts_distance = analog(_pin)*0.000805;  
  return  (12*pow(volts_distance, -1))-2.00;
}

