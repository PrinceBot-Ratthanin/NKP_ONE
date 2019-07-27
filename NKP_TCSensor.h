uint8_t * _sensorPins = nullptr;
uint8_t  _NumofSensor = 0;
uint16_t * _min_sensor_values = nullptr;
uint16_t * _max_sensor_values = nullptr;
uint16_t _lastPosition = 0;
void setSensorPins(const uint8_t * _pins, uint8_t _NumofSensor_)
{
  _NumofSensor = _NumofSensor_;
  _sensorPins = (uint8_t *)realloc(_sensorPins, sizeof(uint8_t) * _NumofSensor_);
  _min_sensor_values = (uint16_t *)realloc(_min_sensor_values, sizeof(uint8_t) * _NumofSensor_);
  _max_sensor_values = (uint16_t *)realloc(_max_sensor_values, sizeof(uint8_t) * _NumofSensor_);
  for (uint8_t i = 0; i < _NumofSensor_; i++)
  {
    _sensorPins[i] = _pins[i];
  }
  
}
void setSensorMin(const uint16_t * _MinSensor)
{
  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    _min_sensor_values[i] = _MinSensor[i];
  }
}
void setSensorMax(const uint16_t * _MaxSensor)
{
  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    _max_sensor_values[i] = _MaxSensor[i];
  }
}
void setCalibrate(){

  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    if(analogRead(_sensorPins[i]) > _max_sensor_values[i] || _max_sensor_values[i] > 4095 ){
      _max_sensor_values[i] = analogRead(_sensorPins[i]);
    }
  }
  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    if(analogRead(_sensorPins[i]) < _min_sensor_values[i] || _min_sensor_values[i] == 0){
      _min_sensor_values[i] = analogRead(_sensorPins[i]);
    }
  }
    
}
int ReadSensorMinValue(uint8_t _Pin){
    return _min_sensor_values[_Pin];
}
int ReadSensorMaxValue(uint8_t _Pin){
    return _max_sensor_values[_Pin];
}
int readline()   
{                
  bool onLine = false;
  long avg = 0;
  long sum = 0;
  for (uint8_t i = 0; i < _NumofSensor; i++) 
  {
    long value = map(analogRead(_sensorPins[i]), _min_sensor_values[i], _max_sensor_values[i], 1000, 0);                                                                            // จากนั้นก็เก็บเข้าไปยังตัวแป value
    if (value > 200) {
      onLine = true;
    }
    if (value > 50)
    {
      avg += (long)value * (i * 1000);
      sum += value;                          
    }
  }
  if (!onLine)
  {
    if (_lastPosition < (_NumofSensor - 1) * 1000 / 2)
    {
      return 0;
    }
    else 
    {
      return (_NumofSensor - 1) * 1000;
    }
  }
  _lastPosition = avg / sum;
  return _lastPosition; 
}
//Cr. Pololu 
