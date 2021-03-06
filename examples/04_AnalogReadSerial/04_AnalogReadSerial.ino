#include <NKP_ONE.h>   //เรียกใช้ชุดคำสั่งทั้งหมด
void setup() {
  Serial.begin(115200); //กำหนดการเชื่อมต่อกับคอมพิวเตอร์ด้วยความเร็ว  115200 byte / วินาที
  NKP_ONE();     //ประกาศใช้ชุดคำสั่ง
  IO15();       //รอจนกว่าจะกด SW1 เพื่อทำงาน

}
void loop() {
  Serial.print("Analog0 = ");  //แสดงผลคำว่า Analog0 = ไปหนังหน้าจอคอมพิวเตอร์
  Serial.print("\t");          //เว้นระยะห่าง เหมือนกด tab 
  Serial.print(analog(A0));    //แสดงผลค่าที่อ่านได้จาก analog ช่องที่ A0  ไปหนังหน้าจอคอมพิวเตอร์
  Serial.print("\n");          //เริ่มต้นบรรทัดใหม่
  //หรือ
  Serial.println(" ... ");    //แสดงผลคำว่า " ... " ไปหนังหน้าจอคอมพิวเตอร์และขึ้นต้นบรรทัดใหม่
  delay(1);
}
