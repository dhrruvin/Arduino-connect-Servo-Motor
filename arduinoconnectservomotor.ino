#include <Servo.h>




Servo tap_servo;
#define mensorPin A0
int sensorpin = 0;                 // analog pin used to connect the moisture sensor
//int val = 0;                 // variable to store the values from sensor(initially zero)
int sensor_pin = 3;            // ir sesor
int tap_servo_pin =9;        // servo motor
int val;
int pos;
float sensorValue = 0;
void setup(){
  pinMode(sensor_pin,INPUT);
  tap_servo.attach(tap_servo_pin);
  Serial.begin(9600);
 
}

void loop(){
 
  val = analogRead(sensorpin);       // reads the value of the sharp sensor
  Serial.println(val);            // prints the value of the sensor to the serial monitor
  delay(100);      // wait for this much time before printing next value
  if (val > 300 && val < 950)
  {
    Serial.println(" Status: Servo motor rotate 90");
    for(pos = 0; pos <= 90; pos++){
    tap_servo.write(pos);
    delay(30);//moistur sesor iteral delay
  }}
  if (val > 0 && val < 300)
  {
    Serial.println(" Status: Servo motor rotate ");
   for(pos = 0; pos >= 90; pos--){
    tap_servo.write(pos);
    delay(15);//
  }
  }delay(400);//output of
  val = digitalRead(sensor_pin);
  for (int i = 0; i <= 100; i++)
  {
    sensorValue = sensorValue + analogRead(mensorPin);
    delay(1);
  }
  sensorValue = sensorValue/100.0;
  Serial.println(sensorValue);
  delay(100);


  if (val==0)
  {tap_servo.write(90);
  }
  if (val==1)
  {tap_servo.write(180);
    delay(100);
    }
   
}
