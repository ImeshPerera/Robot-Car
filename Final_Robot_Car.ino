#include <Servo.h>
Servo s = Servo();
#include <Ultrasonic.h>
Ultrasonic u = Ultrasonic(11, 10); // triger,echo

void setup() {
 
  pinMode(A1, OUTPUT); //ENB
  pinMode(6, OUTPUT); //in4
  pinMode(7, OUTPUT); //in3

  pinMode(13, OUTPUT); //in2
  pinMode(12, OUTPUT); //in1
  pinMode(A0, OUTPUT); //ENA

  pinMode(2, OUTPUT); //180 LEFT LED
  pinMode(3, OUTPUT); //front LED
  pinMode(4, OUTPUT); //0 RIGHT LED
  pinMode(5, OUTPUT); //middle LED
  pinMode(9, OUTPUT); //back LED

  Serial.begin(9600);
  s.attach(8); //Servo motor
}

void loop() {
  
  int x = Serial.read(); //read blutooth signals always and store as x
  int d = u.read();      //read distance signals always and store as d

  if (x == '1' & d > 30) {
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //7,13,HIGH forward OK
    digitalWrite(7, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH); //front lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
  } //x==1 forward is ended

  if (x == '2') {
    s.write(90);
    delay(500);
    digitalWrite(6, HIGH);  //6,12,HIGH backward OK
    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);  //back lights on
  } //x==2 backward is ended

  if (x == '3' & d > 30) {
    s.write(180);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(6, LOW);    //7F 12B (right side motor),HIGH OK
    digitalWrite(7, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //L lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
  }  //x==3 turn left is ended

  if (x == '4'& d > 30) {
    s.write(0);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(6, HIGH);   //13F 6B (left side motor),HIGH OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //R lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
  }  //x==4 turn right is ended

  if (x == '5'& d > 30) {
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //7,13,HIGH OK
    digitalWrite(7, HIGH);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(A0, 140);
    analogWrite(A1, 140);
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH); //front lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(400);
    digitalWrite(6, LOW);   //7,13,STOP OK
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW); //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==5 FORWERD STOP is ended

  if (x == '6') {
    s.write(90);
    delay(500);
    digitalWrite(6, HIGH);   //6,12,HIGH OK
    digitalWrite(7, LOW);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(A0, 140);
    analogWrite(A1, 140);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);  //back lights on
    delay(400);
    digitalWrite(6, LOW);   //6,12,STOP OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==6 backward stop is ended

  if (x == '7'& d > 30) {
    s.write(180);
    delay(500);
    digitalWrite(6, LOW);   //7,12 HIGH OK
    digitalWrite(7, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(A0, 150);
    analogWrite(A1, 150);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(25);
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //7,12 STOP OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==7 left stop is ended

  if (x == '8'& d > 30) {
    s.write(0);
    delay(500);
    digitalWrite(6, HIGH);   //6,13,HIGH OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(A0, 150);
    analogWrite(A1, 150);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(25);
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //6,13 STOP OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==8 right stop is ended

  if (x == 'E'& d > 30) {
    s.write(180);
    digitalWrite(2, HIGH);
    delay(500);
    digitalWrite(6, LOW);   //7,12 HIGH OK
    digitalWrite(7, HIGH);
    digitalWrite(12, HIGH);
    digitalWrite(13, LOW);
    analogWrite(A0, 140);
    analogWrite(A1, 140);
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(380);
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //7,STOP OK
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==7 left stop is ended

  if (x == 'F'& d > 30) {
    s.write(0);
    digitalWrite(4, HIGH);
    delay(500);
    digitalWrite(6, HIGH);   //6,13,HIGH OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, HIGH);
    analogWrite(A0, 140);
    analogWrite(A1, 140);
    digitalWrite(2, LOW );
    digitalWrite(3, LOW);  
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(380);
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //6,13 STOP OK
    digitalWrite(7, LOW);
    digitalWrite(13, LOW);
    digitalWrite(12, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MIDDLE lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
  }  //x==7 left stop is ended

  if (x == '0') { 
    s.write(90);
    delay(500);
    digitalWrite(6, LOW);   //STOP OK
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);
    digitalWrite(13, LOW);
    analogWrite(A0, 200);
    analogWrite(A1, 200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
  }
  if (x == '9') {   //THE SHOW

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    digitalWrite(4, LOW);  //FRONT/MID lights on
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(90);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);
    digitalWrite(4, HIGH);  //RIGHT lights on
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(60);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MID lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(30);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(0);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MID lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(30);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(60);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //MID/FRONT lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(90);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(120);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MID lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(150);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(180);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //MID lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(150);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  // lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(120);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //MID/FRONT lights on
    digitalWrite(4, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    s.write(90);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT/RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(50);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    s.write(90);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT/RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(130);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    s.write(90);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT/RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(40);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    s.write(90);
    delay(250);

    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);  //LEFT/RIGHT lights on
    digitalWrite(4, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    s.write(140);
    delay(250);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    s.write(90);
    delay(250);

  }  //x==0 stop is ended

  if (d < 30) {
    digitalWrite(6, LOW);     
    digitalWrite(7, LOW);
    digitalWrite(12, LOW);   //7,12,HIGH forward OK
    digitalWrite(13, LOW);
    analogWrite(A0, 125);
    analogWrite(A1, 125);
    
    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    delay(200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5,HIGH);
    digitalWrite(9, LOW);
    delay(200);
    digitalWrite(2, LOW);
    digitalWrite(3, LOW);  //FRONT/BACK lights on
    digitalWrite(4, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    delay(200);
    
  }  //d<15 stop is ended
}
