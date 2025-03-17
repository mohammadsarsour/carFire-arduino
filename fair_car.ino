#include <Servo.h>
Servo myServo; 

#include <NewPing.h>
#define TRIG_PIN 10   
#define ECHO_PIN 11 
#define MAX_DISTANCE 200  
NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE);

const int water = 8 ;

const int leftWheel_1 = 5 ;
const int leftWheel_2 = 4 ;
const int rightWheel_1 = 3 ;
const int rightWheel_2 = 2 ;


const int flamSensor_1 = A0 ;
      int flamValue_1 = 0 ;
      
const int flamSensor_2 = A1 ;
      int flamValue_2 = 0 ;
      
const int flamSensor_3 = A2 ;
      int flamValue_3 = 0 ;


void setup() {
Serial.begin(9600);  
pinMode (water , OUTPUT);

pinMode (leftWheel_1 , OUTPUT);
pinMode (leftWheel_2 , OUTPUT);
pinMode (rightWheel_1 , OUTPUT);
pinMode (rightWheel_2 , OUTPUT);

myServo.attach(9);
}


void go_car (){
  digitalWrite (leftWheel_1 , HIGH);
  digitalWrite (leftWheel_2 , LOW);
  digitalWrite (rightWheel_1 , LOW);
  digitalWrite (rightWheel_2 , HIGH); 
}

void stop_car (){
  digitalWrite (leftWheel_1 , LOW);
  digitalWrite (leftWheel_2 , LOW);
  digitalWrite (rightWheel_1 , LOW);
  digitalWrite (rightWheel_2 , LOW); 
}

void rotation_car_right (){
  digitalWrite (leftWheel_1 , HIGH);
  digitalWrite (leftWheel_2 , LOW);
  digitalWrite (rightWheel_1 , HIGH);
  digitalWrite (rightWheel_2 , LOW); 
}
void rotation_car_left (){
  digitalWrite (leftWheel_1 , LOW);
  digitalWrite (leftWheel_2 , HIGH);
  digitalWrite (rightWheel_1 , LOW);
  digitalWrite (rightWheel_2 , HIGH); 
}


void loop() {  
digitalWrite (water , HIGH); 

unsigned int distance = sonar.ping_cm();
Serial.println(distance);

 
flamValue_1 = analogRead(flamSensor_1);
flamValue_2 = analogRead(flamSensor_2);
flamValue_3 = analogRead(flamSensor_3);

Serial.println("111111111");
Serial.println(flamValue_1);

Serial.println("22222222");
Serial.println(flamValue_2);

Serial.println("33333333");
Serial.println(flamValue_3);


if (flamValue_2 < 900) {
  go_car();
  }
  
  else if (flamValue_1 < 900) {
    rotation_car_left();
  }
 
  else if (flamValue_3 < 900) {
    rotation_car_right();
  }
  

  else {
    rotation_car_right();
  }
  
if (distance <= 10 && distance > 2) {
  stop_car();
    digitalWrite ( water , 0); 
  for (int pos = 0; pos <= 180; pos++) {
    myServo.write(pos); 
    delay(15);  
    delay(2000);  
  }

  // تحريك السيرفو من 180 إلى 0 درجة
  for (int pos = 180; pos >= 0; pos--) {
    myServo.write(pos);  
    delay(15);  
    delay(2000);     
  }


}

  delay(300);
}
