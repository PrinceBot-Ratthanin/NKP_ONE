int * _sensorPins = nullptr;
int  _NumofSensor = 0;
int * _min_sensor_values = nullptr;
int * _max_sensor_values = nullptr;
int _lastPosition = 0;
int _Sensitive  = 300;
void setSensorPins(const int * _pins, int _NumofSensor_)
{
  _NumofSensor = _NumofSensor_;
  _sensorPins = (int *)realloc(_sensorPins, sizeof(int) * _NumofSensor_);
  _min_sensor_values = (int *)realloc(_min_sensor_values, sizeof(int) * _NumofSensor_);
  _max_sensor_values = (int *)realloc(_max_sensor_values, sizeof(int) * _NumofSensor_);
  for (uint8_t i = 0; i < _NumofSensor_; i++)
  {
    _sensorPins[i] = _pins[i];
    _min_sensor_values[i] = 4095;
    _max_sensor_values[i] = 0;
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
void setSensitive(const uint16_t  _SensorSensitive)
{
    _Sensitive = _SensorSensitive;
}
void setCalibrate(){

  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    if(analogRead(_sensorPins[i]) > _max_sensor_values[i] || _max_sensor_values[i] > 1023 ){
      _max_sensor_values[i]  = analogRead(_sensorPins[i]);
      if(_max_sensor_values[i] > 4095 )_max_sensor_values[i] = 4095;
    }
  }
  for (uint8_t i = 0; i < _NumofSensor; i++)
  {
    if(analogRead(_sensorPins[i]) < _min_sensor_values[i] || _min_sensor_values[i] == 0){
      _min_sensor_values[i] = analogRead(_sensorPins[i]);
      if(_min_sensor_values[i] < 0) _min_sensor_values[i] = 0;
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
    if (value > _Sensitive) {
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
