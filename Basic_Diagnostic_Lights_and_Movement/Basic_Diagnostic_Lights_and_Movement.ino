/*
 Basic code to go through output ports on the arduino and turn them on and off. Connect your relays to ports 5-13 to test and see if they are working.
*/

int finalport = 13;


// the setup function runs once when you press reset or power the board
void setup() {
  // initialize digital pin LED_BUILTIN as an output.
    pinMode(5, OUTPUT);

     pinMode(6, OUTPUT);

   pinMode(7, OUTPUT);

  pinMode(8, OUTPUT);

    pinMode(9, OUTPUT);

  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);


    digitalWrite(5, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(6, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)


}

// the loop function runs over and over again forever
void loop() {

    digitalWrite(7, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(7, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second
  
  digitalWrite(8, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
  digitalWrite(8, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);                       // wait for a second

                         // wait for a second
  digitalWrite(9, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
digitalWrite(9, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);  

  
                     // wait for a second
  digitalWrite(10, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);   
  
    digitalWrite(10, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);    // wait for a second

            // wait for a second
  digitalWrite(11, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
 digitalWrite(11, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              


                        // wait for a second
  digitalWrite(12, LOW);    // turn the LED off by making the voltage LOW
  delay(1000); 
    digitalWrite(12, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000); // wait for a second

                  // wait for a second
  digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);                       // wait for a second
   digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);        
}
