#include <SoftwareSerial.h>
int thr_hold = 200;
int laserPin = 10;
SoftwareSerial GSerial(2,3); 
void setup() {
  // put your setup code here, to run once:
  pinMode(laserPin, OUTPUT);
  Serial.begin(9600);
  GSerial.begin(400);
  pinMode(13 , OUTPUT);
  GSerial.print('&');
  }

void loop() {
  // put your main code here, to run repeatedly:
  int  val_read = analogRead(A0);
    digitalWrite(laserPin, HIGH);
 if (val_read < thr_hold) {


Serial.println(val_read);
digitalWrite(3 , LOW);
//GSerial.print("C");
delay(10);

}

else {

Serial.println(" ALARM ACTIVATED ");
GSerial.print("B");
digitalWrite(3 , HIGH);
delay(10);

}

delay(100);


}
