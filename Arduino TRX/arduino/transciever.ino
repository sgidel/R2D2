#include "RF24.h"
#include <Servo.h>
#include <stdint.h>

Servo servoS1;
Servo servoS2;
Servo servoS3;
int EStopCount = 0;
RF24 myRadio (48, 49);
//--------- >>>>>>>> Paquete >>>>>>>>>
struct package{
  int Joys1X=0;
  int Joys1Y=0;
  int Joys2X=0;
  int Joys2Y=0;

  int CHN22=0;
  int CHN23=0;
  int CHN24=0;
  int CHN25=0;
  int CHN26=0;
  int CHN27=0;
  int CHN28=0;
  int CHN29=0;
};
typedef struct package Package;
Package data;
//--------- <<<<<<<< Paquete <<<<<<<<<
void setup()
{
  pinMode(2, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(6, OUTPUT);
  servoS1.attach(2);
  servoS2.attach(4);
  servoS3.attach(6);
  pinMode(22, OUTPUT);
  pinMode(23, OUTPUT);
  pinMode(24, OUTPUT);
  pinMode(25, OUTPUT);
  pinMode(26, OUTPUT);
  pinMode(27, OUTPUT);
  pinMode(28, OUTPUT);
  pinMode(29, OUTPUT);

  pinMode(30, INPUT);
  pinMode(31, INPUT);
  pinMode(32, INPUT);
  pinMode(30, INPUT);
  pinMode(30, INPUT);
  pinMode(30, INPUT);
  pinMode(30, INPUT);
  pinMode(30, INPUT);

  myRadio.begin();
  myRadio.setChannel(115);
  myRadio.setPALevel(RF24_PA_MAX);     //<< RF24_PA_MIN,/ RF24_PA_LOW,/ RF24_PA_HIGH,/ RF24_PA_MAX,  <<ojO
  myRadio.setDataRate( RF24_250KBPS ); //<< RF24_1MBPS,/ RF24_2MBPS,/ RF24_250KBPS  <<ojO
  myRadio.openWritingPipe(1);
  myRadio.openReadingPipe(1, 1);
  myRadio.startListening();
  delay(100);
}
void loop()
{//>>>>  -------------------------- Recibe >>>>>>>>

myRadio.startListening();
delay(300);
if (myRadio.available())
  {
   while (myRadio.available())
      {
        myRadio.read( &data, sizeof(data) );
      }
      EStopCount=0;
      servoS1.write(map(data.Joys1Y, 0, 1023, 0, 180));
      servoS2.write(map(data.Joys2Y, 0, 1023, 180, 0));
      //servoS1.write(map(data.Joys1Y, 0, 1023, 900, 2200));
      //servoS2.write(map(data.Joys2Y, 0, 1023, 2200, 900));
      servoS3.write(map(data.Joys1X, 0, 1023, 0, 180));
      if (data.CHN22 == 1){digitalWrite(22, HIGH);}else{digitalWrite(22, LOW);}
      if (data.CHN23 == 1){digitalWrite(23, HIGH);}else{digitalWrite(23, LOW);}
      if (data.CHN24 == 1){digitalWrite(24, HIGH);}else{digitalWrite(24, LOW);}
      if (data.CHN25 == 1){digitalWrite(25, HIGH);}else{digitalWrite(25, LOW);}
      if (data.CHN26 == 1){digitalWrite(26, HIGH);}else{digitalWrite(26, LOW);}
      if (data.CHN27 == 1){digitalWrite(27, HIGH);}else{digitalWrite(27, LOW);}
      if (data.CHN28 == 1){digitalWrite(28, HIGH);}else{digitalWrite(28, LOW);}
      if (data.CHN29 == 1){digitalWrite(29, HIGH);}else{digitalWrite(29, LOW);}
    }
  else
    {
   EStopCount++;
      if (EStopCount > 5)
      {
       servoS1.write(0);
       servoS2.write(0);
       //servoS1.write(1500);
       //servoS2.write(1500);
       servoS3.write(0);
      }
   }
  myRadio.stopListening();
//<<<<  -------------------------- Recibe <<<<<<<<<
//>>>> --------------------------- Send >>>>>>>>>

  //=================== Send >>>>
  data.Joys1Y = analogRead(11);
  data.Joys2Y = analogRead(13);
  data.Joys1X = analogRead(10);
 if (digitalRead(30) == HIGH){if (data.CHN22 == 1){digitalWrite(22, LOW);data.CHN22 = 0;}else{digitalWrite(22, HIGH);data.CHN22 = 1;}delay(400);}
 if (digitalRead(31) == HIGH){if (data.CHN23 == 1){digitalWrite(23, LOW);data.CHN23 = 0;}else{digitalWrite(23, HIGH);data.CHN23 = 1;}delay(400);}
 if (digitalRead(32) == HIGH){if (data.CHN24 == 1){digitalWrite(24, LOW);data.CHN24 = 0;}else{digitalWrite(24, HIGH);data.CHN24 = 1;}delay(400);}
 if (digitalRead(33) == HIGH){if (data.CHN25 == 1){digitalWrite(25, LOW);data.CHN25 = 0;}else{digitalWrite(25, HIGH);data.CHN25 = 1;}delay(400);}
 if (digitalRead(34) == HIGH){if (data.CHN26 == 1){digitalWrite(26, LOW);data.CHN26 = 0;}else{digitalWrite(26, HIGH);data.CHN26 = 1;}delay(400);}
 if (digitalRead(35) == HIGH){if (data.CHN27 == 1){digitalWrite(27, LOW);data.CHN27 = 0;}else{digitalWrite(27, HIGH);data.CHN27 = 1;}delay(400);}
 if (digitalRead(36) == HIGH){if (data.CHN28 == 1){digitalWrite(28, LOW);data.CHN28 = 0;}else{digitalWrite(28, HIGH);data.CHN28 = 1;}delay(400);}
 if (digitalRead(37) == HIGH){if (data.CHN29 == 1){digitalWrite(29, LOW);data.CHN29 = 0;}else{digitalWrite(29, HIGH);data.CHN29 = 1;}delay(400);}

myRadio.write(&data, sizeof(data));
//=================== Send <<<<
}
