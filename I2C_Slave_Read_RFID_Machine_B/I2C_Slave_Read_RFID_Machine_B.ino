// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

int x = 0;
String Tag = "";
boolean readflag = false;

#define GOFOR 4
#define GOBACK 5

#define LA 7
#define LB 8
#define LC 9
#define LD 10

#define LE 11
#define LF 12
#define LG 13
#define LH 6

void setup() {


  //Start ALL OFF

  pinMode(GOFOR, OUTPUT);
  pinMode(GOBACK, OUTPUT);

  pinMode(LA, OUTPUT);
  pinMode(LB, OUTPUT);
  pinMode(LC, OUTPUT);
  pinMode(LD, OUTPUT);

  pinMode(LE, OUTPUT);
  pinMode(LF, OUTPUT);
  pinMode(LG, OUTPUT);
  pinMode(LH, OUTPUT);

  digitalWrite(GOFOR, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(GOBACK, HIGH);   // turn the LED on (HIGH is the voltage level)


  digitalWrite(LA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LB, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LC, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LD, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LE, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LF, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LG, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LH, HIGH);   // turn the LED on (HIGH is the voltage level)


  // Start the I2C Bus as Slave on address 9
  Wire.begin(9);
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);

  Serial.begin(115200);

}

void receiveEvent(int bytes) {
  if (readflag) {
    Tag = "";
    readflag = false;
  }
  x = Wire.read();    // read one character from the I2C
  Serial.println(x);
  Tag.concat(x);


}

void loop() {

  readflag = true;
  Serial.println(Tag);

  if (x == 0) { // Some kind of default action
    Serial.println("got an 0");

    digitalWrite(LA, LOW);
    delay(200);
    digitalWrite(LA, HIGH);
    delay(200);


  }


evaluateTag();

  //If value received is 3 blink LED for 400 ms
  if (x == 3) {
    digitalWrite(LA, LOW);
    delay(1000);
    digitalWrite(LA, HIGH);
    delay(1000);
  }
  delay(100);
}


//Simple example function to look at the tag and see if the tag that was read is any that we recognize
//If it is one we recognize, do some sort of specific movement
void evaluateTag(){
  
  if (Tag ==  "2260021134141145179616794") {
    Serial.println("got a cool tag");

    digitalWrite(LA, LOW);
    delay(200);
    digitalWrite(LA, HIGH);
    delay(200);

  }
  if (Tag == "226002113414055178016884") {
    Serial.println("Diagnostic Tag");

    digitalWrite(GOFOR, LOW);    // turn the LED off by making the voltage LOW

    digitalWrite(LA, LOW);    // turn the LED off by making the voltage LOW

    digitalWrite(LB, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LC, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LD, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LE, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LF, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LG, LOW);    // turn the LED off by making the voltage LOW
    digitalWrite(LH, LOW);    // turn the LED off by making the voltage LOW

    Serial.println("Running Pattern");

    delay(4000);                       // wait for a second
    digitalWrite(GOFOR, HIGH);    // turn the LED off by making the voltage LOW

    digitalWrite(LA, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LB, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LC, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LD, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LE, HIGH);    // turn the LED off by making the voltage LOW
    digitalWrite(LF, HIGH);    // turn the LED off by making the voltage LOW
    digitalWrite(LG, HIGH);    // turn the LED off by making the voltage LOW
    digitalWrite(LH, HIGH);    // turn the LED off by making the voltage LOW

    delay(100);




    Tag = "";
  }


  if (Tag == "2260021134141137179616793") {
    Serial.println("got a boring tag!");

    digitalWrite(LA, LOW);
    delay(2000);
    digitalWrite(LA, HIGH);
    delay(200);

  }
}

