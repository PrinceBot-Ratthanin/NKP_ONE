#include <NKP_ONE.h>

void setup() {
  NKP_ONE();
  OTA_Open("PrinceBot","aaaaaaaa");   //ตั้ง Hostpot เป็นชื่อ PrinceBot  แล้วตั้ง รหัสผ่านเป็น aaaaaaaa  
  OTA_SW1();                          //รอจนกว่าจะกด SW1 เพื่อทำงาน 


}

void loop() {
  

}
