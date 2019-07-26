#include <NKP_ONE.h>   //เรียกใช้ชุดคำสั่งทั้งหมด
void setup() {
  NKP_ONE();     //ประกาศใช้ชุดคำสั่ง
  IO15();       //รอจนกว่าจะกด SW1 เพื่อทำงาน

}

void loop() {
  motor(1,50);   //สั่งมอเตอร์ 1 เดินหน้า ทำงานด้วยความเร็ว 50 % ของแบตเตอร์รี่
  motor(2,100);   //สั่งมอเตอร์ 2 เดินหน้า ทำงานด้วยความเร็ว 100 % ของแบตเตอร์รี่
  delay(1000);    //หน่วงเวลา 1 วินาที
  motor(1,-100);  //สั่งมอเตอร์ 1 ถอยหลัง ทำงานด้วยความเร็ว 100 % ของแบตเตอร์รี่
  motor(2,-50);  //สั่งมอเตอร์ 2 ถอยหลัง ทำงานด้วยความเร็ว 50 % ของแบตเตอร์รี่
  delay(1000);   //หน่วงเวลา 1 วินาที 

  //หรือ

  motor(1,100);  
  motor(2,100);  
  delay(1000);

}
