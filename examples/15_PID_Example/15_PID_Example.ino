#include <NKP_ONE.h>


uint16_t state_on_Line = 0;

uint8_t numSensor = 8;

void Run_fast(int delay_timer) {
  float Kp = 4 ;
  float Ki = 0;
  float Kd = 50;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  long timer =0;
  timer = millis();
  do {
    int speed_max = 85;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ((millis() - timer) < delay_timer);
}
void Run_slow(int delay_timer) {
  float Kp = 4 ;
  float Ki = 0;
  float Kd = 50;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  long timer = millis();
  do {
    int speed_max = 40;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while (millis() - timer < delay_timer);
}
void Run_until(){

  float Kp = 4 ;
  float Ki = 0;
  float Kd = 50;
  uint16_t setpoint;
  float present_position;
  float errors = 0;
  float output = 0;
  float integral ;
  float derivative ;
  float previous_error ;
  do {
    int speed_max = 50;
    present_position = readline() / ((numSensor - 1) * 10) ;
    setpoint = 50.0;
    errors = setpoint - present_position;
    integral = integral + errors ;
    derivative = (errors - previous_error) ;
    output = Kp * errors + Ki * integral + Kd * derivative;
    int max_output = 100;
    previous_error = errors;
    if (output > max_output )output = max_output;
    else if (output < -max_output)output = -max_output;
    motor(1, speed_max - output);
    motor(2, speed_max + output);
    delay(1);

  } while ((analogRead(_sensorPins[0]) > _min_sensor_values[0] + 300 || analogRead(_sensorPins[1]) > _min_sensor_values[1] + 300)  &&( analogRead(_sensorPins[6]) > _min_sensor_values[6] + 300 || analogRead(_sensorPins[7]) > _min_sensor_values[7] + 300));
  
}
void setup() {
  NKP_ONE();
  Serial.begin(115200);
  IO15();
  setSensorPins((const int[]) {A0, A1, A2 , A3, A4, A5, A6, A7}, numSensor);
  // setSensorMax((const uint16_t[]){2400, 4001,4002,3500});
  // setSensorMin((const uint16_t[]){300, 301, 302, 303});
  for (int i = 0; i < 3; i++) {
    for(int l = 0;l<300;l++){
      setCalibrate();
      delay(1);
      motor(1,30);
      motor(2,30);  
    }
    aot(100);
    for(int l = 0;l<300;l++){
      setCalibrate();
      delay(1);
      motor(1,-30);
      motor(2,-30);  
    }aot(100);
    
    for(int l = 0;l<200;l++){
      setCalibrate();
      delay(1);
      motor(1,-30);
      motor(2,-30);  
    }aot(100);
    for(int l = 0;l<300;l++){
      setCalibrate();
      delay(1);
      motor(1,30);
      motor(2,30);  
    }
    aot(100);
    
  }
  aot(100);
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
  IO15();


}

void loop() {



Run_slow(50000);
ao();
while(1);
}
