#define M1A 2
#define M1B 4
#define M2A 16
#define M2B 17
void motor(int pin, int Speeds) {
  pinMode(M1A, OUTPUT);
  pinMode(M1B, OUTPUT);
  pinMode(M2A, OUTPUT);
  pinMode(M2B, OUTPUT);
  int _SpeedsA;
  int _SpeedsB;
  if (pin == 1) {
    _SpeedsA = abs(Speeds);
    if (Speeds > 100)_SpeedsA = 100;
    _SpeedsA = map(abs(_SpeedsA), 0, 100, 0, 255);
    if (Speeds > 0) {
      ledcWrite(2, abs(_SpeedsA));
      ledcWrite(3, 0);
    }
    else if (Speeds <= 0) {
      ledcWrite(2, 0);
      ledcWrite(3, abs(_SpeedsA));
    }
  }
  else if (pin == 2) {
    _SpeedsB = abs(Speeds);
    if (Speeds > 100)_SpeedsB = 100;
    _SpeedsB = map(abs(_SpeedsB), 0, 100, 0, 255);
    if (Speeds > 0) {
      ledcWrite(4, abs(_SpeedsB));
      ledcWrite(5, 0);
    }
    else if (Speeds <= 0) {
      ledcWrite(4, 0);
      ledcWrite(5, abs(_SpeedsB));
    }
  }
}
void motor_s(int pin, int Speeds) {
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(17, OUTPUT);
  int _SpeedsA;
  int _SpeedsB;
  if (pin == 1) {
    _SpeedsA = abs(Speeds);
    if (Speeds > 100)_SpeedsA = 100;
    _SpeedsA = map(abs(_SpeedsA), 0, 100, 255, 0);
    if (Speeds > 0) {
      ledcWrite(2, abs(_SpeedsA));
      ledcWrite(3, 255);
    }
    else if (Speeds <= 0) {
      ledcWrite(2, 255);
      ledcWrite(3, abs(_SpeedsA));
    }
  }
  else if (pin == 2) {
    _SpeedsB = abs(Speeds);
    if (Speeds > 100)_SpeedsB = 100;
    _SpeedsB = map(abs(_SpeedsB), 0, 100, 255, 0);
    if (Speeds > 0) {
      ledcWrite(4, abs(_SpeedsB));
      ledcWrite(5, 255);
    }
    else if (Speeds <= 0) {
      ledcWrite(4, 255);
      ledcWrite(5, abs(_SpeedsB));
    }
  }
}
