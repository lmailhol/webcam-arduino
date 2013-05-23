import processing.serial.*;

Serial SerialPort;

int valeur = 0; //valeur envoyée

void setup(){
  size(100,100);
  background(255);
  println(Serial.list());
  SerialPort = new Serial(this, Serial.list()[0], 9600);
  delay(100);
  SerialPort.write(0);
  delay(100);
}

void draw() {
  
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      background(0);
      valeur = 20;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      background(0);
      valeur = 140;
      SerialPort.write(valeur);
      delay(100);
    }
  } 
}

void keyReleased() {
  if (key == CODED) {
    if (keyCode == UP) {
      background(255);
      valeur = 95;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      background(255);
      valeur = 95;
      SerialPort.write(valeur);
      delay(100);
    }
  } 
}
