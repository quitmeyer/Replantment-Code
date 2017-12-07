/*
For machine A, make sure connections are good!
*/



#define GOFOR 4
#define GOBACK 5

#define LA 6
#define LB 7
#define LC 8
#define LD 9

#define LE 10
#define LF 11
#define LG 12
#define LH 13

int PIRpin=A0;

int fauxVIN=A1;
int fauxGND=A2;

int timing = 5000;


boolean motion=false;
// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);

    pinMode(fauxGND, OUTPUT);
  pinMode(fauxVIN, OUTPUT);
  pinMode(PIRpin, INPUT);


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

    digitalWrite(fauxVIN, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(fauxGND, LOW);   // turn the LED on (HIGH is the voltage level)

}

// the loop function runs over and over again forever
void loop() {

  Serial.println(digitalRead(PIRpin));
if(digitalRead(PIRpin)==HIGH){
  Serial.println("Motion Detected");
runAll();

}


}

void runAll(){

 

        digitalWrite(LA, LOW);    // turn the LED off by making the voltage LOW

        digitalWrite(LB, LOW);    // turn the LED off by making the voltage LOW

                digitalWrite(GOFOR, LOW);    // turn the LED off by making the voltage LOW

    digitalWrite(LC, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LD, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LE, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LF, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LG, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LH, LOW);    // turn the LED off by making the voltage LOW


delay(timing);                 // wait for a second
     digitalWrite(LA, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LB, HIGH);    // turn the LED off by making the voltage HIGH
                digitalWrite(GOFOR, HIGH);    // turn the LED off by making the voltage HIGH
    digitalWrite(LC, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LD, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LE, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LF, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LG, HIGH);    // turn the LED off by making the voltage HIGH
        digitalWrite(LH, HIGH);    // turn the LED off by making the voltage HIGH
delay(1000);                 // wait for a second
}

