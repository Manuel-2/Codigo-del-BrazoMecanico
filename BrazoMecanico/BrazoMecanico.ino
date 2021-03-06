//codigo controlador de brazo mecanico | by Manuel Peñaloza

#include <Servo.h>

Servo servo1; // Servo de base pin 3     ||  limites:    0-minimo   | 180-maximo
Servo servo2; //Servo de hombro  pin 6   ||  limites:    30-minimo  | 100-maximo
Servo servo3; //Servo de codo  pin 10    ||  limites:    60-minimo  | 180-maximo
Servo servo4; //servo de pinza pin 11    ||  limites:    110-minimo | 155-maximo

//posiciones iniciales
int angulo1 = 110;
int angulo2 = 90;
int angulo3 = 90;
int angulo4 = 110;

//valores para manejar la pinza
int abierto = 110;
int cerrado = 155;

void setup() {
  //inisialisacion de los servos
  servo1.attach(3) ;  // Conectar servo1 al pin 3
  servo2.attach(6) ;  // Conectar servo2 al pin 6
  servo3.attach(10) ;  // Conectar servo3 al pin 10
  servo4.attach(11) ;   // Conectar servo4 al pin 11

  //posisciones iniciales
  servo1.write(0);
  servo2.write(angulo2);
  servo3.write(angulo3);
  servo4.write(angulo4-5);

  //rutina
  delay(1000);
  move(servo1,0,65);
  delay(1000);
  move(servo3,angulo3,130);
  delay(1000);
  servo4.write(cerrado);
  delay(1000);
  move(servo2,angulo2,20);
  delay(1000);
  move(servo3,130,180);
  delay(1000);
  move(servo1,65,170);
  delay(1000);
  servo4.write(abierto);
  move(servo1,170,65);
  
  
  
  

}

void loop() {
  //rutina de calibracion
  
}

void move(Servo servo,int posI,int posF)
{
  int jumps = 5;
  int wait = 50;
  
  if(posF>posI)
  {
    for(int i = posI ; i <= posF ; i+=jumps)
    {
      servo.write(i);
      delay(wait);
    }
  }
  else if(posI>posF)
  {
    for(int i = posI ; i >= posF ; i-=jumps)
    {
      servo.write(i);
      delay(wait);
    }
  }
  
}
