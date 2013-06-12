import processing.serial.*;

Serial SerialPort;

int y = 0;
String valeur;

void setup(){
  size(200,200);
  textSize(80);
  println("Bienvenue");
  SerialPort = new Serial(this, Serial.list()[0], 115200);
}

void draw() {
  background(204);
}

void keyPressed() {
  if (key == CODED) {
    if (keyCode == UP) {
      valeur = "87902";
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == DOWN) {
      valeur = "93902";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == RIGHT) {
      valeur = "90922";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == LEFT) {
      valeur = "90882";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
  }
  
  if (key == 'a') {
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
  }
  if (key == 'p') {
      valeur = "90900";
      println(valeur);
      SerialPort.write(valeur);
  }
  if (key == 'm') {
      valeur = "90901";
      println(valeur);
      SerialPort.write(valeur);
  }
}

/*void keyReleased() {
  if (key == CODED) {
    if (keyCode == UP) {
      background(0);
      valeur = "9090";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      valeur = "9090";
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == RIGHT) {
      valeur = "9090";
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == LEFT) {
      valeur = "9090";
      println(valeur);
      SerialPort.write(valeur);
    }
  }
} */
