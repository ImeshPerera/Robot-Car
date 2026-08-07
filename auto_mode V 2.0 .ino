                                       // auto mode by imesh
#include <Servo.h>
Servo s = Servo();
#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(10, 9); // triger,echo
void setup() {
  // put your setup code here, to run once:
  pinMode(5, OUTPUT); //ENB
  pinMode(6, OUTPUT); //in4
  pinMode(7, OUTPUT); //in3

  pinMode(13, OUTPUT); //in2
  pinMode(12, OUTPUT); //in1
  pinMode(11, OUTPUT); //ENA

  pinMode(2, OUTPUT); //180 LEFT LED
  pinMode(3, OUTPUT); //front LED
  pinMode(4, OUTPUT); //0 RIGHT LED
  pinMode(A0, OUTPUT); //middle LED
  analogWrite(A0, 120);
  pinMode(A1, OUTPUT); //back LED
  analogWrite(A1, 120);

  Serial.begin(9600);
  s.attach(8); //Servo motor
}

void loop() {
  // put your main code here, to run repeatedly:
if (x == 'G') { //auto mode
    int d = u.read();      //read distance signals always and store as d
    if (d > 30) {
      s.write(90);
      digitalWrite(3, HIGH);
      delay(500);
      digitalWrite(6, LOW);   //7,13,HIGH OK
      digitalWrite(7, HIGH);
      digitalWrite(12, LOW);
      digitalWrite(13, HIGH);
      analogWrite(5, 140);
      analogWrite(11, 140);
      digitalWrite(2, LOW );
      digitalWrite(3, LOW);
      digitalWrite(4, HIGH);
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
    }
    if (d < 30) {
      digitalWrite(6, LOW);
      digitalWrite(7, LOW);
      digitalWrite(12, LOW);   //7,12,stop OK
      digitalWrite(13, LOW);
      analogWrite(5, 125);
      analogWrite(11, 125);
      digitalWrite(6, HIGH);
      digitalWrite(7, LOW);
      digitalWrite(12, HIGH);   //6,12,BACK OK
      digitalWrite(13, LOW);
      analogWrite(5, 125);
      analogWrite(11, 125);
      delay(300);

      digitalWrite(2, LOW);
      digitalWrite(3, LOW);  //FRONT lights on
      digitalWrite(4, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(A1, LOW);
      delay(200);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);  //MID lights on
      digitalWrite(4, LOW);
      digitalWrite(A0, HIGH);
      digitalWrite(A1, LOW);
      delay(200);
      digitalWrite(2, LOW);
      digitalWrite(3, LOW);  //BACK lights on
      digitalWrite(4, LOW);
      digitalWrite(A0, LOW);
      digitalWrite(A1, HIGH);
      delay(200);
      s.write(0);
      digitalWrite(4, HIGH);
      delay(500);

      int d = u.read();      //read distance signals and store as d
      if (d > 30) {

        digitalWrite(6, HIGH);   //6,13,HIGH FOR TURN OK
        digitalWrite(7, LOW);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        analogWrite(5, 140);
        analogWrite(11, 140);
        digitalWrite(2, LOW );
        digitalWrite(3, LOW);
        digitalWrite(4, HIGH);
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        delay(200);
        s.write(90);
        digitalWrite(3, HIGH);
        delay(500);
        digitalWrite(6, LOW);   //7,13,HIGH OK
        digitalWrite(7, HIGH);
        digitalWrite(12, LOW);
        digitalWrite(13, HIGH);
        analogWrite(5, 140);
        analogWrite(11, 140);
        digitalWrite(2, LOW );
        digitalWrite(3, HIGH);
        digitalWrite(4, LOW);
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
      }
      if (d < 30) {
        digitalWrite(6, LOW);
        digitalWrite(7, LOW);
        digitalWrite(12, LOW);   //7,12,stop OK
        digitalWrite(13, LOW);
        analogWrite(5, 125);
        analogWrite(11, 125);

        digitalWrite(2, LOW);
        digitalWrite(3, HIGH);  //FRONT lights on
        digitalWrite(4, LOW);
        digitalWrite(A0, LOW);
        digitalWrite(A1, LOW);
        delay(200);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);  //MID lights on
        digitalWrite(4, LOW);
        digitalWrite(A0, HIGH);
        digitalWrite(A1, LOW);
        delay(200);
        digitalWrite(2, LOW);
        digitalWrite(3, LOW);  //BACK lights on
        digitalWrite(4, LOW);
        digitalWrite(A0, LOW);
        digitalWrite(A1, HIGH);
        delay(200);
        s.write(180);
        digitalWrite(2, HIGH);
        delay(500);

        int d = u.read();      //read distance signals and store as d
        if (d > 30) {

          digitalWrite(6, LOW);   //7,12,HIGH FOR TURN OK
          digitalWrite(7, HIGH);
          digitalWrite(12, HIGH);
          digitalWrite(13, LOW);
          analogWrite(5, 140);
          analogWrite(11, 140);
          digitalWrite(2, HIGH);
          digitalWrite(3, LOW);
          digitalWrite(4, LOW);
          digitalWrite(A0, LOW);
          digitalWrite(A1, LOW);
          delay(200);
          s.write(90);
          digitalWrite(3, HIGH);
          delay(500);

          digitalWrite(6, LOW);   //7,13,HIGH OK
          digitalWrite(7, HIGH);
          digitalWrite(12, LOW);
          digitalWrite(13, HIGH);
          analogWrite(5, 140);
          analogWrite(11, 140);
          digitalWrite(2, LOW );
          digitalWrite(3, HIGH);
          digitalWrite(4, LOW);
          digitalWrite(A0, LOW);
          digitalWrite(A1, LOW);
        }
      } //d<30 2nd
    } //d<30 1st
  }  //x==G AUTO MODE is ended
}
