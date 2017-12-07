// Chapter 7 - Communications
// I2C Slave
// By Cornel Amariei for Packt Publishing

// Include the required Wire library for I2C
#include <Wire.h>

int LED = 13;
int x = 0;
String Tag="";
boolean readflag=false;
void setup() {
  // Define the LED pin as Output
  pinMode (LED, OUTPUT);
    pinMode (8, OUTPUT);

  // Start the I2C Bus as Slave on address 9
  Wire.begin(9); 
  // Attach a function to trigger when something is received.
  Wire.onReceive(receiveEvent);

    Serial.begin(115200);

}

void receiveEvent(int bytes) {
  if(readflag){
Tag="";
readflag=false;
  }
  x = Wire.read();    // read one character from the I2C
        Serial.println(x);
Tag.concat(x);


}

void loop() {

  readflag=true;
        Serial.println(Tag);

  //If value received is 0 blink LED for 200 ms
  if (x == 0) {
          Serial.println("got an 0");

    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);

    
  }

if(Tag==  "2260021134141145179616794"){
   Serial.println("got a cool tag");

    digitalWrite(LED, HIGH);
    delay(200);
    digitalWrite(LED, LOW);
    delay(200);

}
if(Tag== "226002113414055178016884"){
   Serial.println("Diagnostic Tag");

    digitalWrite(8, HIGH);
    delay(2000);
    digitalWrite(8, LOW);
    delay(200);

}


if(Tag== "2260021134141137179616793"){
   Serial.println("got a suckytag tag");

    digitalWrite(LED, HIGH);
    delay(2000);
    digitalWrite(LED, LOW);
    delay(200);

}

  //If value received is 3 blink LED for 400 ms
  if (x == 3) {
    digitalWrite(LED, HIGH);
    delay(1000);
    digitalWrite(LED, LOW);
    delay(1000);
  }
  delay(100);
}

