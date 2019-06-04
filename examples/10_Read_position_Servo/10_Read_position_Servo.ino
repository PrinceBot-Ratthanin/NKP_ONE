#include <NKP_ONE.h>
int degreeServo1 = 90;
int degreeServo2 = 90;
int degreeServo3 = 90;
int degreeServo4 = 90;
int Cursor = 0;
void setup() {
  NKP_ONE();
}
void loop() {
  set_oled_clear();
  set_oled_S(5,0,"Servo1=");set_oled_S(75,0,degreeServo1);  
  set_oled_S(5,8,"Servo2=");set_oled_S(75,8,degreeServo2); 
  set_oled_S(5,16,"Servo3=");set_oled_S(75,16,degreeServo3); 
  set_oled_S(5,24,"Servo4=");set_oled_S(75,24,degreeServo4);                           
  

  if(sw1() == 0){
    Cursor++;
    delay(200);
    if(Cursor > 3)Cursor = 0;
  }
  if(Cursor == 0){
    degreeServo1 = Knob()/22.5;;
    servo(1,degreeServo1);
    display.drawLine(0, 8, 120, 8, WHITE);set_oled_show(); 
  }
  else if(Cursor == 1){
    degreeServo2 = Knob()/22.5;;
    servo(2,degreeServo2);
    display.drawLine(0, 8*2, 120, 8*2, WHITE);set_oled_show();  
  }
  else if(Cursor == 2){
    degreeServo3 = Knob()/22.5;
    servo(3,degreeServo3);
    display.drawLine(0, 8*3, 120, 8*3, WHITE);set_oled_show();  
  }
  else if(Cursor == 3){
    degreeServo4 = Knob()/22.5;;
    servo(4,degreeServo4);
    display.drawLine(0, 8*4, 120, 23, WHITE);set_oled_show();   
  }
}
