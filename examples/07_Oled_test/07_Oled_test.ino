#include <NKP_ONE.h>   //เรียกใช้ชุดคำสั่งทั้งหมด
void setup() {
  NKP_ONE();     //ประกาศใช้ชุดคำสั่ง
  IO15();       //รอจนกว่าจะกด SW1 เพื่อทำงาน

  set_oled(0,0,"Hello world");  //แสดงผลคำว่า "Hello world" ขึ้นที่หน้าจอ คอลัมที่ 0  บรรทัด ที่ 0

}

void loop() {
 
}
