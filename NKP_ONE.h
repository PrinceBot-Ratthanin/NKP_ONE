#include "NKP_Servo_lib.h"    
#include "NKP_Oled_Lib.h"     
#include "NKP_Switch.h"       
#include "NKP_Knob.h"         
#include "NKP_Motor_drive.h"
#include "NKP_IO.h"
#include "NKP_Buzzer.h"
#define M1A 2
#define M1B 4
#define M2A 16
#define M2B 17

void NKP_ONE(){

  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  display.clearDisplay();
  pinMode(M1A,OUTPUT);
  pinMode(M1B,OUTPUT);
  pinMode(M2A,OUTPUT);
  pinMode(M2B,OUTPUT);
  ledcSetup(6, 5000, 8);
  ledcSetup(7, 5000, 8);
  ledcSetup(4, 5000, 8);
  ledcSetup(5, 5000, 8);
  ledcAttachPin(2, 6);
  ledcAttachPin(4, 7);
  ledcAttachPin(16, 4);
  ledcAttachPin(17, 5);
  display.setTextSize(1);
  display.setTextColor(WHITE);
}
void IO15(){
  while(sw1() == 1){
    set_oled(0,0,"press sw1 ");
    set_oled(0,8,"to start ");
  }
  set_oled_clear();
}