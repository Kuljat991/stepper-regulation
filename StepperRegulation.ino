#include <AccelStepper.h>

AccelStepper stepper1(AccelStepper::DRIVER, 9, 8); //pin 9 on pin step

#define  MAX_SPEED 200.
#define  MIN_SPEED 5.
#define SPEED_PIN A0

int analog_value;
int map_speed;
float current_speed = 0.0;

void setup() {
  stepper1.setMaxSpeed(MAX_SPEED);
  Serial.begin(9600);

}

void loop() {
  analog_value = analogRead(SPEED_PIN);
  map_speed = map (analog_value ,0 , 1023, 1, 100);
  current_speed = ((map_speed/100.) * (MAX_SPEED - MIN_SPEED)) + MIN_SPEED;
  stepper1.setSpeed(current_speed);
  stepper1.runSpeed();
  //Serial.print(map_speed);
  //Serial.print(', ');
  Serial.print(current_speed);
  Serial.print('\n');
}
