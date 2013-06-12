#include <Servo.h>

#define SPEED 3
#define DIRECTION 12

Servo myservo;
Servo myservo2;

int servoSpeed; //vitesse de rotation du servomoteur continue
int servoSpeed2; //vitesse de rotation du servomoteur continue
String readSerial, servo1, servo2, motor;

int motorSpeed;
int motorDirection;

void setup() {
  Serial.begin(115200);
  pinMode(8, OUTPUT); //broche en sortie servo1
  pinMode(9, OUTPUT); //broche en sortie servo2
  
  pinMode(DIRECTION, OUTPUT); //broche direction
  pinMode(SPEED, OUTPUT); //broche vitesse
  
  motorSpeed = 125;  
}

void loop() {
  while (Serial.available()) {
    delay(1);  
    if (Serial.available() >0) {
      char c = Serial.read();  //gets one byte from serial buffer
      readSerial += c; //makes the string readSerial
    } 
  }
  if (readSerial.length() >0) {
    Serial.println("Chaine : "); 
    Serial.println(readSerial); //xxxxxx
    servo1 = readSerial.substring(0, 2); //get the first two characters
    servo2 = readSerial.substring(2, 4); //get the next two characters     
    motor = readSerial.substring(4, 5);
    Serial.println("Servomoteur 1 : "); 
    Serial.println(servo1);
    Serial.println("Servomoteur 2 : ");
    Serial.println(servo2);
    Serial.println("Motor Courant Continu : ");
    Serial.println(motor);
    
    char carray1[5]; //magic needed to convert string to a number 
    servo1.toCharArray(carray1, sizeof(carray1));
    servoSpeed = atoi(carray1); 
      
    char carray2[5];
    servo2.toCharArray(carray2, sizeof(carray2));
    servoSpeed2 = atoi(carray2); 
    
    char carray3[5];
    motor.toCharArray(carray3, sizeof(carray3));
    motorDirection = atoi(carray3); 
    
    myservo.attach(8);
    myservo2.attach(9);
    myservo.write(servoSpeed);
    myservo2.write(servoSpeed2);
    
    analogWrite(SPEED, motorSpeed);
    
    if(motorDirection == 0) {
      digitalWrite(DIRECTION,HIGH);
    } else if(motorDirection == 1) {
      digitalWrite(DIRECTION,LOW);
    } else if(motorDirection == 2) {
      analogWrite(SPEED, 0);
    }

    /*if (myservo.attached() && myservo2.attached()) {
      if (servoSpeed != 90 || servoSpeed2 != 90) {
        myservo.write(servoSpeed);
        myservo2.write(servoSpeed2);
      } else {
        //myservo.detach();
        //myservo2.detach();
        myservo.write(90);
        myservo2.write(90);
      }
    } else {
      if (servoSpeed != 90 || servoSpeed2 != 90) {  
        myservo.attach(8);
        myservo2.attach(9);
        myservo.write(servoSpeed);
        myservo2.write(servoSpeed2);
      }
    }*/
    //remise a zero de la valeur de recuperation
    //servo1 = "";
    //servo2 = "";
    readSerial = "";
  }
}
