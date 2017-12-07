/*

*/

int finalport = 13;
int timing = 1700;

// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
         pinMode(4, OUTPUT);

    pinMode(5, OUTPUT);
      pinMode(6, OUTPUT);

    pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);

    pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);

//    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
//    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
//        digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)


}

// the loop function runs over and over again forever
void loop() {

    digitalWrite(4, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(4, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);     

  


    digitalWrite(6, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);

    digitalWrite(5, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);     

    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second

  
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);  


    digitalWrite(10, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(10, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second


    digitalWrite(11, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(11, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second

    digitalWrite(12, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(12, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second

    digitalWrite(13, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(13, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
}
