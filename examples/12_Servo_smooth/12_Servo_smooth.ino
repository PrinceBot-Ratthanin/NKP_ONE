#include <NKP_ONE.h>    //ประกาศคำสั่งภายในบอร์ด NKP[ONE]
int pos_open = 10;
int pos_close = 70;
int pos_up = 160;
int pos_down = 50; 
int delay_servo1 = 5;
int delay_servo2 = 10;
void gripper_open(){     
//  servo(1,10);          //ให้ Servo ฃ่องที่ 1 หมุนไปตำแหน่งที่ 10 องศา
//  delay(300);           //หน่วงเวลาเป็นเวลา 0.3 วินาที 
  for(int pos_servo1 = pos_close ; pos_servo1 > pos_open ; pos_servo1--){
    servo(1,pos_servo1);
    delay(delay_servo1);
  }
}
void gripper_close(){
//  servo(1,70);          //ให้ Servo ฃ่องที่ 1 หมุนไปตำแหน่งที่ 70 องศา
//  delay(300);           //หน่วงเวลาเป็นเวลา 0.3 วินาที
  for(int pos_servo1 = pos_open ; pos_servo1 < pos_close ; pos_servo1++){
    servo(1,pos_servo1);
    delay(delay_servo1);
  }

}
void gripper_up(){
//  servo(2,160);       //ให้ Servo ฃ่องที่ 2 หมุนไปตำแหน่งที่ 160 องศา
//  delay(300);         //หน่วงเวลาเป็นเวลา 0.3 วินาที

  for(int pos_servo2 = pos_down ; pos_servo2 < pos_up ; pos_servo2++){
    servo(2,pos_servo2);
    delay(delay_servo2);
  }
}
void gripper_down(){
//  servo(2,50);        //ให้ Servo ฃ่องที่ 2 หมุนไปตำแหน่งที่ 50 องศา
//  delay(300);         //หน่วงเวลาเป็นเวลา 0.3 วินาที

  for(int pos_servo2 = pos_up ; pos_servo2 > pos_down ; pos_servo2--){
    servo(2,pos_servo2);
    delay(delay_servo2);
  }
}
void setup() {
  NKP_ONE();        //เรียกใฃ้คำสั่งภายในบอร์ด NKP[ONE]
}
void loop() {
  gripper_open();
  gripper_down();
  gripper_close();
  gripper_up();
  gripper_down();
  gripper_open();
  gripper_up();
}
