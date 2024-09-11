#include "include/main.h"

//LCD setup
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);
 
//LED setup
LedControl led(DataPin,CLK,CS,1);

//kinematic vectors
ivec2 velocity;
ivec2 position;

int JoyX;
int JoyY;


void positionCalculations(ivec2 velocity) {
  position.x =+ (velocity.x+position.x);
  position.y =+ velocity.y+position.y;
}
void setup() {
  led.shutdown(0,false);
  led.setIntensity(0,8);
  led.clearDisplay(0);
  pinMode(yPin, INPUT);
  pinMode(xPin, INPUT);
  pinMode(SwitchPin, INPUT);
  lcd.begin(16, 2);
  lcd.print("Joystick:");
}

void loop() {
     lcd.setCursor(0,0);
      
      lcd.print("Coordinates");
      JoyY = analogRead(yPin)-496; //offset to center 0,0
      JoyX = analogRead(xPin)- 507; //offset to center 0,0
      velocity.x = JoyX/400;
      velocity.y = JoyY/480;
      
      lcd.setCursor(0,1);
      lcd.print("X: ");
      lcd.print(position.x);
      lcd.setCursor(8,1);
      lcd.print("Y: ");
      lcd.print(position.y);
      positionCalculations(velocity);

      led.setLed(0,(-1)*position.x,position.y,true);


      delay(100);
      led.clearDisplay(0);
      lcd.clear();
}


