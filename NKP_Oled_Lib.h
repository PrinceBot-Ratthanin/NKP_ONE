#include <SPI.h>
#include <Wire.h>
//#include <Adafruit_GFX.h>
//#include <Adafruit_SSD1306.h>


#include "Adafruit_GFX1.h"
#include "Adafruit_SSD13061.h"

#define OLED_RESET 5
Adafruit_SSD1306 display(OLED_RESET);
void set_oled(int a,int b,char *da){
  
  display.setCursor(a,b);
 // display.clearDisplay();
  display.println(da);
  display.display();
  
}
void set_oled(int a,int b,int c){
  
  display.setCursor(a,b);
  //display.clearDisplay();
  display.println((String)c);
  display.display();
  
}
void set_oled_S(int a,int b,char *da){
  
  display.setCursor(a,b);
 // display.clearDisplay();
  display.println(da);
 // display.display();
  
}
void set_oled_S(int a,int b,int c){
  
  display.setCursor(a,b);
  //display.clearDisplay();
  display.println((String)c);
  //display.display();
  
}
void set_oled_clear(){
  display.clearDisplay();
}
void set_oled_show(){
  display.display();
}
