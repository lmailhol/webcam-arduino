#include <Servo.h>

Servo myservo;
Servo myservo2;

int servoSpeed = 95; //vitesse de rotation du servomoteur continue
int servoSpeed2 = 95; //vitesse de rotation du servomoteur continue
String readSerial, servo1, servo2;

void setup() {
  Serial.begin(115200);
  myservo.attach(8);
  myservo2.attach(9);
  pinMode(8, OUTPUT); //broche en sortie
  pinMode(9, OUTPUT); //broche en sortie
  myservo.write(servoSpeed); //position initiale
  myservo2.write(servoSpeed2); //position initiale
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
    servo1 = readSerial.substring(0, 3); //get the first two characters
    servo2 = readSerial.substring(3, 6); //get the next two characters     
    Serial.println("Servomoteur 1 : "); 
    Serial.println(servo1);
    Serial.println("Servomoteur 2 : ");
    Serial.println(servo2);
    
    char carray1[6]; //magic needed to convert string to a number 
    servo1.toCharArray(carray1, sizeof(carray1));
    servoSpeed = atoi(carray1); 
      
    char carray2[6];
    servo2.toCharArray(carray2, sizeof(carray2));
    servoSpeed2 = atoi(carray2); 
    //lancement de la fonction servoTurn
    myservo.write(servoSpeed);
    myservo2.write(servoSpeed2);
    //remise a zero de la valeur de recuperation
    //servo1 = "";
    //servo2 = "";
    readSerial = "";
  }
}
