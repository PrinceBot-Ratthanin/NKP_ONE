
void motor_S(int pin, int Speeds) {
  int _SpeedsA;
  int _SpeedsB;
  if (pin == 1) {
    _SpeedsA = abs(Speeds);
    _SpeedsA = _SpeedsA * 2.55;
    if (_SpeedsA > 255)_SpeedsA = 255;
    else if (_SpeedsA < -255)_SpeedsA = -255;
    if (Speeds > 0) {
      ledcWrite(3, abs(_SpeedsA));
      ledcWrite(2, 0);
    }
    else if (Speeds <= 0) {
      ledcWrite(3, 0);
      ledcWrite(2, abs(_SpeedsA));
    }
  }
  else if (pin == 2) {
    _SpeedsB = abs(Speeds);
    
    _SpeedsB = _SpeedsB * 2.55;
    if (_SpeedsB > 255)_SpeedsB = 255;
    else if (_SpeedsB < -255)_SpeedsB = -255;
    if (Speeds > 0) {
      ledcWrite(5, abs(_SpeedsB));
      ledcWrite(4, 0);
    }
    else if (Speeds <= 0) {
      ledcWrite(5, 0);
      ledcWrite(4, abs(_SpeedsB));
    }
  }
}


void motor(int pin, int Speeds) {
  int _SpeedsA;
  int _SpeedsB;
  if (pin == 1) {
    _SpeedsA = abs(Speeds);
    _SpeedsA = _SpeedsA * 2.55;
    if (_SpeedsA > 255){_SpeedsA = 255;}
    else if (_SpeedsA < -255){_SpeedsA = -255;}
    if (Speeds > 0) {
      ledcWrite(6, 255 - abs(_SpeedsA));
      ledcWrite(7, 255);
    }
    else if (Speeds <= 0) {
      ledcWrite(6, 255);
      ledcWrite(7, 255 - abs(_SpeedsA));
    }
  }
  if (pin == 2) {
    _SpeedsB = abs(Speeds);
    
    _SpeedsB = _SpeedsB * 2.55;
    if (_SpeedsB > 255){_SpeedsB = 255;}
    else if (_SpeedsB < -255){_SpeedsB = -255;}
    if (Speeds > 0) {
      ledcWrite(4, 255 - abs(_SpeedsB));
      ledcWrite(5, 255);
    }
    else if (Speeds <= 0) {
      ledcWrite(4, 255);
      ledcWrite(5, 255 - abs(_SpeedsB));
    }
  }
}
void MT(int speeda, int speedb,int time_speed){ 
  motor(1,speeda);
  motor(2,speedb);
  delay(time_speed);
}
void ao(){
  motor(1,0);
  motor(2,0);
}
