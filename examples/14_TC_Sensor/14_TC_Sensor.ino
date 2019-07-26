#include <NKP_ONE.h>

void setup() {
  Serial.begin(115200);
  setSensorPins((const uint8_t[]){A0, A1, A2 , A3}, 4);
  // setSensorMax((const uint16_t[]){2400, 4001,4002,3500});
  // setSensorMin((const uint16_t[]){300, 301, 302, 303});
  for(int i = 0;i<5000;i++){
    setCalibrate();
    delay(1);
  }
  for (uint8_t i = 0; i < 4; i++)
  {
    Serial.print(ReadSensorMinValue(i));
    Serial.print(' ');
  }
  Serial.println();
  for (uint8_t i = 0; i < 4; i++)
  {
    Serial.print(ReadSensorMaxValue(i));
    Serial.print(' ');
  }
  Serial.println();
  delay(1000);
  

}

void loop() {
  
  Serial.print("  readline");
  Serial.println(readline());
  delay(1);
  

}
