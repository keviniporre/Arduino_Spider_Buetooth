//  --------                 --------
// |  D9    |               |  D7    |
// | joint9 |               | joint7 |
//  ----- --------     --------- -----
//       |  D8    |   |  D6    |
//       | joint8 |   | joint6 |
//        --------     --------
//       |  D2    |  |   D4    |
//       | joint2 |  |  joint4 |
//  ----- --------    --------- -----
// |  D3    |               |  D5    |
// | joint3 |               | joint5 |
//  --------                 --------
//                Front

// Incluir Libreria para Usar los Servo Motores
#include <Servo.h>

// Declaracion de los Motores Servo
Servo joint2;
Servo joint3;
Servo joint4;
Servo joint5;
Servo joint6;
Servo joint7;
Servo joint8;
Servo joint9;

// Declaracion de angulos iniciales de Servos
int home_joint2 = 120;
int home_joint3 = 15;
int home_joint4 = 60;
int home_joint5 = 165;
int home_joint6 = 100;
int home_joint7 = 15;
int home_joint8 = 70;
int home_joint9 = 165;

void idle(){
  delay(100);
}

void standhome(){
  joint2.write(home_joint2);
  joint3.write(home_joint3);
  joint4.write(home_joint4);
  joint5.write(home_joint5);
  joint6.write(home_joint6);
  joint7.write(home_joint7);
  joint8.write(home_joint8);
  joint9.write(home_joint9);
}

void sithome(){
    joint2.write(135);
    joint3.write(65);
    joint4.write(45);
    joint5.write(110);
    joint6.write(135);
    joint7.write(80);
    joint8.write(45);
    joint9.write(110);
}

void stand1(){
  sithome();
  joint2.write(170);
  delay(300);
  joint2.write(home_joint2);
  delay(300);
  joint4.write(10);
  delay(300);
  joint4.write(home_joint4);
  delay(300);
  joint6.write(170);
  delay(300);
  joint6.write(home_joint6);
  delay(300);
  joint8.write(10);
  delay(300);
  joint8.write(home_joint8);
  delay(300);
  
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
}

void stand2(){
  sithome();
  joint2.write(175);
  joint4.write(5);
  joint6.write(175);
  joint8.write(5);
  delay(600);
    
  joint2.write(home_joint2);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  joint8.write(home_joint8);
  delay(600);
  
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
}

void stand3()
{ 
  sithome();
  int i;
  int j = 90;
  int k = 90;
  joint2.write(home_joint2);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  joint8.write(home_joint8);
  for(i = 90; i < 165; i++)
  {
    joint5.write(i);
    j = j - 1;
    joint3.write(j);
    delay(20);
  }
  
  for(i = 115; i < 165; i++)
  {
    joint9.write(i);
    k = k - 1;
    joint7.write(k);
    delay(20);
  }
}

void downaction(unsigned int step){
  while (step-- > 0){
  sithome();
  delay(100);
  standhome();
  delay(100);
  }
}

void twist(){
  joint3.write(home_joint3);
  joint5.write(home_joint5);
  joint7.write(home_joint7);
  joint9.write(home_joint9);
  
  for(int right=90;right<170;right++){
      joint2.write(right);
      joint6.write(right);
      joint4.write(right-90);
      joint8.write(right-90);
      delay(10);
  }

   for(int right=170;right>90;right--){
      joint2.write(right);
      joint6.write(right);
      joint4.write(right-90);
      joint8.write(right-90);
      delay(10);
  }
}

void forward(unsigned int step){
  while (step-- > 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  }
}

void backward(unsigned int step){
  while (step-- > 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  }
}

void rightturn(unsigned int step){
  while (step-- > 0){
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  }
}

void leftturn(unsigned int step){
  while (step-- > 0){
  joint3.write(home_joint3+30);
  joint7.write(home_joint7+30);
  delay(100);
  joint2.write(home_joint2+30);
  joint8.write(home_joint8-30);
  joint4.write(home_joint4-30);
  joint6.write(home_joint6+30);
  delay(100);
  joint3.write(home_joint3);
  joint7.write(home_joint7);
  idle();
  
  joint5.write(home_joint5-30);
  joint9.write(home_joint9-30);
  delay(100);
  joint2.write(home_joint2);
  joint8.write(home_joint8);
  joint4.write(home_joint4);
  joint6.write(home_joint6);
  delay(100);
  joint5.write(home_joint5);
  joint9.write(home_joint9);
  idle();
  }
}

///////////////////////////////////////////////////////
//    VOID SETUP  AND VOID LOOP
///////////////////////////////////////////////////////
void setup() {
  // Asignar los pines de control a los Servo
  joint2.attach(2);
  joint3.attach(3);
  joint4.attach(4);
  joint5.attach(5);
  joint6.attach(6);
  joint7.attach(7);
  joint8.attach(8);
  joint9.attach(9);
  // Funcion que pone al robot en posicion inicial
  standhome();
  // Esperar un segundo
  delay(1000);
}

void loop() {
  

}
