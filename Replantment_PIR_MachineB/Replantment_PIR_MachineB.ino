/*
 * This Code runs on Machine B 
 * taking motion input
 * controlling the motors and lights on Machine B
 * and sending a control signal to Machine A
 * 
  For machine A, make sure connections are good! It connects to Machine A via its commPin on its i2C channels. 
  In this example they actually recieve simple (not i2C) control signals by just sending a voltage High or low
  Make sure Machine A and Machine B are BOTH CONNECTED TO SAME DC GROUND supply or communication will not work
*/


//These are the two options for our dry cleaner controls hacked from the pedals
#define GOFOR 4
#define GOBACK 5

//There are 8 Lights connected to our 8 relays which we can control individually
#define LA 6
#define LB 7
#define LC 8
#define LD 9

#define LE 10
#define LF 11
#define LG 12
#define LH 13

//This is our input which senses motion
int PIRpin = A0;

//This is our communication pin to talk to the slave.
int commPin = 20;

int fauxVIN = A1;
int fauxGND = A2;

int timing = 5000;

//For doing blinks without delays basically
int GOFORstate = LOW;
int GOBACKstate = LOW;

int LAstate = LOW;             // ledState used to set the LED
int LBstate = LOW;             // ledState used to set the LED
int LCstate = LOW;             // ledState used to set the LED
int LDstate = LOW;             // ledState used to set the LED
int LEstate = LOW;             // ledState used to set the LED
int LFstate = LOW;             // ledState used to set the LED
int LGstate = LOW;             // ledState used to set the LED
int LHstate = LOW;             // ledState used to set the LED

boolean motion = false;

//The machines don't have sensors on them to know exactly their current location, 
//but they do move QUITE RELIABLY
// We can do some basic dead reckoning of guessing what position 
//our machines are in by just keeping track of their position at all times.
//When we start, we set the machine at position 0, and then 
//we add or subtract the amount of time it spends moving one way or the other
double deadReckoning=0; 


// the setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(115200);

  pinMode(commPin, OUTPUT);


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


  digitalWrite(commPin, LOW);   // turn the LED on (HIGH is the voltage level)


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

//Test signal
  turnLightsON();

  delay(2000);
  allOff();

}

// the loop function runs over and over again forever
void loop() {
int motiondetection = digitalRead(PIRpin);
  Serial.println(motiondetection);
  digitalWrite(commPin, motiondetection); //Replicate whatever state gets read

  if (motiondetection == HIGH) {
  Serial.println("Motion Detected");
    //runAll();
    delay(900);
  //  runRandom();
    runRandomExtraLong();
//turnLightsON();
  }
  else{
    allOff();

  }


}

/*
 * Every time the machine moves we ADD a time value if it goes forward, and we SUBTRACT a time value if it goes backwards.
 * This gives our variable "deadReckoning" a measure of how many milliseconds it needs to run to go to its original position
 * 
 */
void calcPosition(){
  
}




void runRandomExtraLong() {
allRand();
  //Choose a direction //DO NOT GO BOTH DIRECTIONS AT SAME TIME, it hurts the machine! 
  if ( random(2) ){
  digitalWrite(GOBACK, LOW);   // turn the LED on (HIGH is the voltage level)
Serial.println("Going BACK");
  }
  else {
    digitalWrite(GOFOR, LOW);   // turn the LED on (HIGH is the voltage level)
Serial.println("Going Forward");

  }

///most of the time the machine will run for short bursts, but sometimes it will go extra long
if(random(10)==5){
  long runtime = random(30000, 99000);
Serial.print("Running LONG for:  " );
Serial.println(runtime);
delay(runtime);
}
else{
//run regular random
int runtime = random(5000, 14000);
Serial.print("Running for:  " );
Serial.println(runtime);
delay(runtime);

}
allOff();
  digitalWrite(commPin, 0); //Replicate whatever state gets read


//Give the audience some time to admire the glowing before trigger again based on RFID or motion detection
int waittime = random(5000,12000);
Serial.print("Chilling for:  " );
Serial.println(waittime);

delay(waittime);


}

void runRandom() {
  //turnLightsON();
allRand();
  //Choose a direction //DO NOT GO BOTH DIRECTIONS AT SAME TIME! 
  if ( random(2) ){
  digitalWrite(GOBACK, LOW);   // turn the LED on (HIGH is the voltage level)
Serial.println("Going BACK");
  }
  else {
    digitalWrite(GOFOR, LOW);   // turn the LED on (HIGH is the voltage level)
Serial.println("Going Forward");

  }


int runtime = random(5000, 14000);
Serial.print("Running for:  " );
Serial.println(runtime);
delay(runtime);

allOff();
  digitalWrite(commPin, 0); //Replicate whatever state gets read




//Serial.print("Running for:  " );
//Choose a random amount of time to move around
//  delay(Serial.println(random(5000, 14000)));
//  allOff();
//  delay(random(3000, 15000));

int waittime = random(5000,8000);
Serial.print("Chilling for:  " );
Serial.println(waittime);

  delay(waittime);


}
void allRand(){

Serial.println(random(2));
  
  digitalWrite(LA, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LB, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LC, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LD, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LE, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LF, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LG, random(2));   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LH, random(2));   // turn the LED on (HIGH is the voltage level)


}

void allState() {
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

void allOff() {
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


void turnLightsON() {

  digitalWrite(LA, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LB, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LC, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LD, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LE, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LF, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LG, LOW);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LH, LOW);   // turn the LED on (HIGH is the voltage level)


}

void turnLightsOff() {

  digitalWrite(LA, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LB, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LC, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LD, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LE, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LF, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LG, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LH, HIGH);   // turn the LED on (HIGH is the voltage level)


}

void turnMotorsOff() {
  digitalWrite(GOFOR, HIGH);   // turn the LED on (HIGH is the voltage level)

  digitalWrite(GOBACK, HIGH);   // turn the LED on (HIGH is the voltage level)

}

void runAll() {



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

