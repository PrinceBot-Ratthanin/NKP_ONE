#include <NKP_ONE.h>    //ประกาศคำสั่งภายในบอร์ด NKP[ONE]
void gripper_open(){     
  servo(1,70);          //ให้ Servo ฃ่องที่ 1 หมุนไปตำแหน่งที่ 10 องศา
  delay(300);           //หน่วงเวลาเป็นเวลา 0.3 วินาที 
}
void gripper_close(){
  servo(1,10);          //ให้ Servo ฃ่องที่ 1 หมุนไปตำแหน่งที่ 70 องศา
  delay(300);           //หน่วงเวลาเป็นเวลา 0.3 วินาที
}
void gripper_up(){
  servo(2,160);       //ให้ Servo ฃ่องที่ 2 หมุนไปตำแหน่งที่ 160 องศา
  delay(300);         //หน่วงเวลาเป็นเวลา 0.3 วินาที
}
void gripper_down(){
  servo(2,50);        //ให้ Servo ฃ่องที่ 2 หมุนไปตำแหน่งที่ 50 องศา
  delay(300);         //หน่วงเวลาเป็นเวลา 0.3 วินาที
}
void setup() {
  NKP_ONE();        //เรียกใฃ้คำสั่งภายในบอร์ด NKP[ONE]
  gripper_up();
  gripper_close();
  while(sw1() == 1){set_oled(0,0,"PrinceBot");}
  set_oled(10,10,"Run");
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
