#include "RF24.h"
#include <Servo.h>
Servo servoS1;
Servo servoS2; 
Servo servoS3; 
int Eapera = 0;
int Vuelta = 0;
RF24 myRadio (48, 49); 
//--------- >>>>>>>> Paquete >>>>>>>>>
struct package{
  int Joys1X=0;
  int Joys1Y=0;
  int Joys2X=0;
  //int Joys2Y=0;
  int CHN22A=0;
  int CHN23A=0;
  int CHN24A=0;
  int CHN25A=0;
  int CHN26A=0;
  int CHN27A=0;
  int CHN28A=0;
  int CHN29A=0;
};
typedef struct package Package;
Package data;
//--------- <<<<<<<< Paquete <<<<<<<<<
void setup() 
{
  Eapera = 0;
  Vuelta = 0;
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  servoS1.attach(2); 
  servoS2.attach(3);  
  servoS3.attach(4);
  pinMode(22, INPUT);
  pinMode(23, INPUT);
  pinMode(24, INPUT);
  pinMode(25, INPUT);
  pinMode(26, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);
  pinMode(29, INPUT);

  pinMode(30, OUTPUT);
  pinMode(31, OUTPUT);
  pinMode(32, OUTPUT);
  pinMode(33, OUTPUT);
  pinMode(34, OUTPUT);
  pinMode(35, OUTPUT);
  pinMode(36, OUTPUT);
  pinMode(37, OUTPUT);
  pinMode(38, OUTPUT);
  pinMode(39, OUTPUT);
  pinMode(40, OUTPUT);
  pinMode(41, OUTPUT);
  pinMode(42, OUTPUT);
  pinMode(43, OUTPUT);
  pinMode(44, OUTPUT);
  pinMode(45, OUTPUT);
  
  myRadio.begin(); 
  myRadio.setChannel(115); 
  myRadio.setPALevel(RF24_PA_MAX);
  myRadio.setDataRate( RF24_250KBPS ) ; 
  myRadio.openWritingPipe(1);
  myRadio.openReadingPipe(1, 1);
  myRadio.startListening();
  delay(100);
}
void loop()  
{
{
  //>>>>  -------------------------- Recibe >>>>>>>>
Eapera=0;
delay(100);
  if ( myRadio.available()) 
  {
    Vuelta=0;    
        while (myRadio.available())
          {
            myRadio.read( &data, sizeof(data) );
          }
    int val2X = map(data.Joys1X, 0, 1023, 900, 2200);
    int val1X = map(data.Joys2X, 0, 1023, 2200, 900);
    int val1Y = map(data.Joys1Y, 0, 1023, 0, 180);
    servoS1.write(val1X);
    servoS2.write(val2X);
    servoS3.write(val1Y);
    digitalWrite(30, data.CHN22A);
    digitalWrite(31, data.CHN23A);
    digitalWrite(32, data.CHN24A);
    digitalWrite(33, data.CHN25A);
    digitalWrite(34, data.CHN26A);
    digitalWrite(35, data.CHN27A);
    digitalWrite(36, data.CHN28A);
    digitalWrite(37, data.CHN29A);           
  }  
  else
  {
   Vuelta++;  
      if (Vuelta > 5)
      {
       servoS1.write(0);                  
       servoS2.write(0);       
      }
   }   
}
//<<<<  -------------------------- Recibe <<<<<<<<<
  
//>>>> --------------------------- Send >>>>>>>>>
  //delay(100);
  myRadio.stopListening();
  //=================== Send >>>>
   if (digitalRead(22) == HIGH){if (data.CHN22A == 1){data.CHN22A = 0;}else{data.CHN22A = 1;}Eapera=1;}
   if (digitalRead(23) == HIGH){if (data.CHN23A == 1){data.CHN23A = 0;}else{data.CHN23A = 1;}Eapera=1;}
   if (digitalRead(24) == HIGH){if (data.CHN24A == 1){data.CHN24A = 0;}else{data.CHN24A = 1;}Eapera=1;}
   if (digitalRead(25) == HIGH){if (data.CHN25A == 1){data.CHN25A = 0;}else{data.CHN25A = 1;}Eapera=1;}
   if (digitalRead(26) == HIGH){if (data.CHN26A == 1){data.CHN26A = 0;}else{data.CHN26A = 1;}Eapera=1;}
   if (digitalRead(27) == HIGH){if (data.CHN27A == 1){data.CHN27A = 0;}else{data.CHN27A = 1;}Eapera=1;}
   if (digitalRead(28) == HIGH){if (data.CHN28A == 1){data.CHN28A = 0;}else{data.CHN28A = 1;}Eapera=1;}
   if (digitalRead(29) == HIGH){if (data.CHN29A == 1){data.CHN29A = 0;}else{data.CHN29A = 1;}Eapera=1;}

           data.Joys1X = analogRead(15);
           data.Joys1Y = analogRead(14);
           data.Joys2X = analogRead(12); 
           
           digitalWrite(30, data.CHN22A);
           digitalWrite(31, data.CHN23A);
           digitalWrite(32, data.CHN24A);
           digitalWrite(33, data.CHN25A);
           digitalWrite(34, data.CHN26A);
           digitalWrite(35, data.CHN27A);
           digitalWrite(36, data.CHN28A);
           digitalWrite(37, data.CHN29A);

           digitalWrite(45, data.CHN22A);
           digitalWrite(44, data.CHN23A);
           digitalWrite(43, data.CHN24A);
           digitalWrite(42, data.CHN25A);
           digitalWrite(41, data.CHN26A);
           digitalWrite(40, data.CHN27A);
           digitalWrite(39, data.CHN28A);
           digitalWrite(38, data.CHN29A);
  //=================== Send <<<<
  myRadio.write(&data, sizeof(data)); 
  myRadio.startListening();
if (Eapera==1){delay(200);}
//<<<<  -------------------------- Send <<<<<<<<<
}
