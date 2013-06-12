/*
Le code ci-contre fonctionne avec deux servomoteurs a rotation continue, un moteur a courant continu, le tout grace
a une carte Arduino Uno. Pour autant, je ne saurais que vous conseiller d'adapter le programme a des servomoteurs
"normaux" fonctionnants avec des valeurs d'angle.
=================================================================
*/

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
    servo1 = readSerial.substring(0, 2); //recuperation des deux premiers caracteres (servo1)
    servo2 = readSerial.substring(2, 4); //recuperation des deux suivants (servo2)     
    motor = readSerial.substring(4, 5); //recuperation du dernier (moteur a courant continu)
    Serial.println("Servomoteur 1 : "); //affichage dans la console pour verifier visuellement
    Serial.println(servo1);
    Serial.println("Servomoteur 2 : ");
    Serial.println(servo2);
    Serial.println("Motor Courant Continu : ");
    Serial.println(motor);
    
    //convertion en int de chaques chaines (possibilite d'utiliser toInt(), aussi, manifestement)
    
      char carray1[5]; 
      servo1.toCharArray(carray1, sizeof(carray1));
      servoSpeed = atoi(carray1); 
      
      char carray2[5];
      servo2.toCharArray(carray2, sizeof(carray2));
      servoSpeed2 = atoi(carray2); 
    
      char carray3[5];
      motor.toCharArray(carray3, sizeof(carray3));
      motorDirection = atoi(carray3); 
    
   
    myservo.attach(8); //on attache les servomoteurs
    myservo2.attach(9);
    myservo.write(servoSpeed); //on envoie la valeur de vitesse
    myservo2.write(servoSpeed2);
    
    analogWrite(SPEED, motorSpeed); //controle du moteur a courant continu
    
    if(motorDirection == 0) { //si la direction est de 0 on fait tourner dans un sens, sinon dans l'autre
      digitalWrite(DIRECTION,HIGH); 
    } else if(motorDirection == 1) {
      digitalWrite(DIRECTION,LOW);
    } else if(motorDirection == 2) {
      analogWrite(SPEED, 0);
    }
    
    /*bout de programme test afin de couper completement les servomoteurs à rotation continue que nous utilisons et
    qui sont très embettants sur ce point (malheureusement, il s'agissait d'une contrainte du cahier des charges).
    Le but était de detacher le servomoteur une fois qu'il n'etait plus en court d'usage. Mais il n'était alors
    pas bloqué et retombait lourdement sous le poid du systeme*/

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
