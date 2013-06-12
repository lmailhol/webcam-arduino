/*
Le code ci-dessous fonctionne dans un environnement processing dès lors que la carte arduino (UNO) est reliée
à l'ordinateur par l'intermédiaire d'un port USB.
=================================================================
*/


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
    if (keyCode == UP) { //"UP" et "DOWN" pour controler la rotation sur z
      valeur = "87902"; //on envoie une valeur de vitesse au servomoteur tandis qu'on stoppe le reste
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == DOWN) {
      valeur = "93902";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == RIGHT) { //"RIGHT" et "LEFT" pour controler la rotation sur x
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
  
  if (key == 'p') { //"p" et "m" pour controler le deplacement sur y 
      valeur = "90900";
      println(valeur);
      SerialPort.write(valeur);
  }
  if (key == 'm') {
      valeur = "90901";
      println(valeur);
      SerialPort.write(valeur);
  }
  
  if (key == 'a') { //"a" pour tout stopper
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
  }
}

/*void keyReleased() { //essai pour s'affranchis de la touche "a" pour tout couper"
  if (key == CODED) {
    if (keyCode == UP) {
      background(0);
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
      delay(100);
    }
    else if (keyCode == DOWN) {
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == RIGHT) {
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
    }
    else if (keyCode == LEFT) {
      valeur = "90902";
      println(valeur);
      SerialPort.write(valeur);
    }
  }
} */
