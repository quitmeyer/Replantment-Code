/*
For machine A, make sure connections are good!
*/



#define GOFOR 4
#define GOBACK 5

#define LA A0
#define LB A1
#define LC 6
#define LD 7

#define LE 8
#define LF 11
#define LG 12
#define LH 13


int timing = 700;

// the setup function runs once when you press reset or power the board
void setup() {


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

}

// the loop function runs over and over again forever
void loop() {

        digitalWrite(LA, LOW);
delay(timing);                 // wait for a second
  digitalWrite(LA, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(500);     

  


        digitalWrite(LB, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(LB, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);

        digitalWrite(GOFOR, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(GOFOR, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timing);     

    digitalWrite(LC, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(LC, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  
  digitalWrite(LD, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
  digitalWrite(LD, HIGH);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second

  
  digitalWrite(GOBACK, LOW);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
digitalWrite(GOBACK, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(timing);  


    digitalWrite(LE, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(LE, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second


    digitalWrite(LF, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(LF, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second

    digitalWrite(LG, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(LG, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second

    digitalWrite(LH, LOW);   // turn the LED on (HIGH is the voltage level)
delay(timing);                 // wait for a second
  digitalWrite(LH, HIGH);    // turn the LED off by making the voltage LOW
delay(timing);                 // wait for a second
}
