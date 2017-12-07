/*
  Reading multiple RFID tags, simultaneously!
  By: Nathan Seidle @ SparkFun Electronics
  Date: October 3rd, 2016
  https://github.com/sparkfun/Simultaneous_RFID_Tag_Reader

  Single shot read - Ask the reader to tell us what tags it currently sees. And it beeps!

  If using the Simultaneous RFID Tag Reader (SRTR) shield, make sure the serial slide
  switch is in the 'SW-UART' position.
*/

#include <SoftwareSerial.h> //Used for transmitting to the device

SoftwareSerial softSerial(2, 3); //RX, TX

#include "SparkFun_UHF_RFID_Reader.h" //Library for controlling the M6E Nano module
RFID nano; //Create instance

#define BUZZER1 9
//#define BUZZER1 0 //For testing quietly
#define BUZZER2 10

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

int lastdigit = 0;




// Include the required Wire library for I2C
#include <Wire.h>

double i2cmessage = 0;

String Tag= "";
void setup()
{
    Wire.begin(); 

  Serial.begin(115200);

  pinMode(BUZZER1, OUTPUT);
  pinMode(BUZZER2, OUTPUT);

  digitalWrite(BUZZER2, LOW); //Pull half the buzzer to ground and drive the other half.



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



 // while (!Serial);
  Serial.println();
  Serial.println("Initializing...");

  if (setupNano(38400) == false) //Configure nano to run at 38400bps
  {
    Serial.println("Module failed to respond. Please check wiring.");
    while (1); //Freeze!
  }

  nano.setRegion(REGION_NORTHAMERICA); //Set to North America

  nano.setReadPower(2700); //5.00 dBm. Higher values may cause USB port to brown out
  //Max Read TX Power is 27.00 dBm and may cause temperature-limit throttling


//Give the startup OK signal
      tone(BUZZER1, 2093, 150); //C
  delay(150);
 tone(BUZZER1, 2637, 150); //E
  delay(15);
  tone(BUZZER1, 2349, 150); //D
  delay(15);

    tone(BUZZER2, 2349, 150); //D
  delay(15);
   tone(BUZZER2, 2637, 150); //E
  delay(300);

}


void loop()
{

  
//  Serial.println(F("Press a key to scan for a tag"));
//  while (!Serial.available()); //Wait for user to send a character
//  Serial.read(); //Throw away the user's character

  byte myEPC[12]; //Most EPCs are 12 bytes
  byte myEPClength;
  byte responseType = 0;

  while (responseType != RESPONSE_SUCCESS)//RESPONSE_IS_TAGFOUND)
  {
    myEPClength = sizeof(myEPC); //Length of EPC is modified each time .readTagEPC is called

    responseType = nano.readTagEPC(myEPC, myEPClength, 500); //Scan for a new tag up to 500ms
    Serial.println(F("Searching for tag"));
    delay(200);
    Serial.println("cooling...");
    
  }

//Alert sound we detected
  //Beep! Piano keys to frequencies: http://www.sengpielaudio.com/KeyboardAndFrequencies.gif
  tone(BUZZER1, 2093, 150); //C
  delay(150);
 tone(BUZZER1, 2637, 150); //E
  delay(15);
  tone(BUZZER1, 2349, 150); //D
  delay(15);
   tone(BUZZER1, 2637, 150); //E
  delay(15);
  tone(BUZZER1, 2349, 150); //D
  delay(15);
   tone(BUZZER1, 2637, 150); //E
  delay(15);
  tone(BUZZER1, 2349, 150); //D
  delay(15);
  tone(BUZZER1, 2637, 150); //E
  delay(150);


 tone(BUZZER2, 2093, 150); //C
  delay(150);
 tone(BUZZER2, 2637, 150); //E
  delay(15);
  tone(BUZZER2, 2349, 150); //D
  delay(15);
   tone(BUZZER2, 2637, 150); //E
  delay(300);


 //Display the Tag
  //Send to the other machine

Tag="";
  //Print EPC
  Serial.print(F(" epc["));


  for (byte x = 0 ; x < myEPClength ; x++)
  {
    if (myEPC[x] < 0x10) Serial.print(F("0"));
 //   Serial.print(myEPC[x], HEX);
        Serial.print(myEPC[x]);

    Serial.print(F(" "));
 Wire.beginTransmission(9); // transmit to device #9
  Wire.write(myEPC[x]);              // sends x 
   Wire.endTransmission();    // stop transmitting

   lastdigit= myEPC[x];

  }
  Serial.println(F("]"));
Serial.println(Tag.toInt());

   Serial.print("Last Digit =  ");
   Serial.println(lastdigit);

  



//Light Signal that it was detected
       digitalWrite(LA, LOW);    // turn the LED off by making the voltage LOW

 
       digitalWrite(LB, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LC, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LD, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LE, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LF, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LG, LOW);    // turn the LED off by making the voltage LOW
        digitalWrite(LH, LOW);    // turn the LED off by making the voltage LOW

                        digitalWrite(GOFOR, LOW);    // turn the LED off by making the voltage LOW

Serial.println("Running");

  delay(2000);                       // wait for a second
  digitalWrite(LA, HIGH);   // turn the LED on (HIGH is the voltage level)
    digitalWrite(LB, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LC, HIGH);   // turn the LED on (HIGH is the voltage level)
  digitalWrite(LD, HIGH);   // turn the LED on (HIGH is the voltage level)
       digitalWrite(LE, HIGH);    // turn the LED off by making the voltage LOW
       digitalWrite(LF, HIGH);    // turn the LED off by making the voltage LOW
       digitalWrite(LG, HIGH);    // turn the LED off by making the voltage LOW
       digitalWrite(LH, HIGH);    // turn the LED off by making the voltage LOW

                digitalWrite(GOFOR, HIGH);    // turn the LED off by making the voltage LOW

Serial.println("Stopping");

  delay(2000);                       // wait for a second


}

//Gracefully handles a reader that is already configured and already reading continuously
//Because Stream does not have a .begin() we have to do this outside the library
boolean setupNano(long baudRate)
{
  nano.begin(softSerial); //Tell the library to communicate over software serial port

  //Test to see if we are already connected to a module
  //This would be the case if the Arduino has been reprogrammed and the module has stayed powered
  softSerial.begin(baudRate); //For this test, assume module is already at our desired baud rate
  while(!softSerial); //Wait for port to open

  //About 200ms from power on the module will send its firmware version at 115200. We need to ignore this.
  while(softSerial.available()) softSerial.read();
  
  nano.getVersion();

  if (nano.msg[0] == ERROR_WRONG_OPCODE_RESPONSE)
  {
    //This happens if the baud rate is correct but the module is doing a ccontinuous read
    nano.stopReading();

    Serial.println(F("Module continuously reading. Asking it to stop..."));

    delay(1500);
  }
  else
  {
    //The module did not respond so assume it's just been powered on and communicating at 115200bps
    softSerial.begin(115200); //Start software serial at 115200

    nano.setBaud(baudRate); //Tell the module to go to the chosen baud rate. Ignore the response msg

    softSerial.begin(baudRate); //Start the software serial port, this time at user's chosen baud rate
  }

  //Test the connection
  nano.getVersion();
  if (nano.msg[0] != ALL_GOOD) return (false); //Something is not right

  //The M6E has these settings no matter what
  nano.setTagProtocol(); //Set protocol to GEN2

  nano.setAntennaPort(); //Set TX/RX antenna ports to 1

  return (true); //We are ready to rock
}

