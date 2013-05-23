import processing.serial.*;

Serial SerialPort;

int valeur = 0; //valeur envoyée

void setup(){
  size(100,100);
  background(255);
  println(Serial.list());
  SerialPort = new Serial(this, Serial.list()[0], 115200);
  delay(100);
  delay(100);
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      background(0);
      valeur = 020000;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      background(0);
      valeur = 140000;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == RIGHT) {
      background(0);
      valeur = 000020;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == LEFT) {
      background(0);
      valeur = 000140;
      SerialPort.write(valeur);
      delay(100);
    }
  } 
}

void keyReleased() {
  if (key == CODED) {
    if (keyCode == UP) {
      background(255);
      valeur = 095000;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      background(255);
      valeur = 095000;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == RIGHT) {
      background(0);
      valeur = 000095;
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == LEFT) {
      background(0);
      valeur = 000095;
      SerialPort.write(valeur);
      delay(100);
    }
  } 
}
