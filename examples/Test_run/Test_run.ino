#include <popx2.h>
#include "NKP_TCSensor.h"


uint8_t numSensor = 4;
float Kp = 0.7  ;
float Ki = 0;
float Kd = 0;

// การปรับ PID นั้น เริ่มจากการปรับที่ KP ก่อน แล้วให้ KI KD ตัวอื่น ๆให้เป็น 0 ให้หมด
// เมื่อหุ่นยนต์ของเรา วิ่งกลับมาจุดกลึงกลางแล้วก็ปรับ KD เพิ่มมากชึ้นทำให้การสวิงนั้นต่ำลง
// พร้อมกับลดค่า KP ลงเพิ่มเติม
// ทำไมถึงไม่พูดถึง KI ก็เพราะว่า ตามหลักแล้ว KI ที่จะใช้คือน้อยมาก ๆเลย ผมเลยไม่ขอยกขึ้นมานะครับ
// หรือถ้าปรับ KI ไม่ดีจะทำให้เกิดการ ทำให้ระบบมันระเบิด เอาภาษาง่าย ๆแล้วมันก็จะไม่จับเส้ยนะจ่ะ
uint16_t setpoint;
float present_position;
float errors = 0;
float output = 0;
float integral ;
float derivative ;
float previous_error ;




void setup() {
  OK();
  Serial.begin(115200);
  setSensorPins((const int[]){25, 26, 27 , 28}, numSensor);
  // setSensorMax((const int[]){2400, 4001,4002,3500});
  // setSensorMin((const int[]){300, 301, 302, 303});
  Serial.print(sizeof(_max_sensor_values));
  for(int i = 0;i<5000;i++){
    setCalibrate();
    delay(1);
  }
  for (uint8_t i = 0; i < numSensor; i++)
  {
    Serial.print(ReadSensorMinValue(i));
    Serial.print(' ');
  }
  Serial.println();
  for (uint8_t i = 0; i < numSensor; i++)
  {
    Serial.print(ReadSensorMaxValue(i));
    Serial.print(' ');
  }
  beep();
  

}

void loop() {
  
  //Serial.print("  readline");  
  //Serial.println(readline());
  /*int speed_max = 30;
  present_position = readline() / (numSensor - 1) * 10 ;
  setpoint = 50.0;
  errors = setpoint - present_position;
  integral = integral + errors ;
  derivative = (errors - previous_error) ;
  output = Kp * errors + Ki * integral + Kd * derivative;
  previous_error = errors;
  if(output > 100 )output = 100;
  else if(output < -100)output = -100;
  motor(1, speed_max - output);
  motor(2, speed_max + output);
  delay(1);*/
  

}
