
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

