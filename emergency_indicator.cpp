
#define BLYNK_TEMPLATE_ID "TMPL3pVXfHhUC"
#define BLYNK_TEMPLATE_NAME "Wifi Traffic Control"
#define BLYNK_AUTH_TOKEN "BOQygMTAu2BK61mrE3vHUVXXKP8fzcwE"
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
//#include <BlynkSimpleStream.h>
#define BLYNK_PRINT Serial
#include <SoftwareSerial.h>

char auth[] = BLYNK_AUTH_TOKEN;
char ssid[] = "Pooja";  // Enter your WIFI name
char pass[] = "pooja9880";  // Enter your WIFI password

SoftwareSerial mySerial(D4, D3);  // D4 of ESP = TX of Arduino, D3 of ESP = RX of Arduino

void setup() {
  pinMode(D3, INPUT);
  pinMode(D4, OUTPUT);
  
  mySerial.begin(9600);  // Start serial communication with Arduino
  Blynk.begin(auth, ssid, pass, "blynk.cloud", 80);  // Connect to Blynk server
}

void loop() {
  Blynk.run();  // Run Blynk
}

BLYNK_WRITE(V0) {
  // Handle virtual button V0 press in Blynk app
  int buttonValue = param.asInt();

  if (buttonValue == HIGH) {
    // V0 button is pressed in the Blynk app
    mySerial.write('0');  // Send '0' to Arduino
  }
}

BLYNK_WRITE(V1) {
  // Handle virtual button V1 press in Blynk app
  int buttonValue = param.asInt();

  if (buttonValue == HIGH) {
    // V1 button is pressed in the Blynk app
    mySerial.write('1');  // Send '1' to Arduino
  }
}

BLYNK_WRITE(V2) {
  // Handle virtual button V2 press in Blynk app
  int buttonValue = param.asInt();

  if (buttonValue == HIGH) {
    // V2 button is pressed in the Blynk app
    mySerial.write('2');  // Send '2' to Arduino
  }
}

BLYNK_WRITE(V3) {
  // Handle virtual button V3 press in Blynk app
  int buttonValue = param.asInt();

  if (buttonValue == HIGH) {
    // V3 button is pressed in the Blynk app
    mySerial.write('3');  // Send '3' to Arduino
  }
}

