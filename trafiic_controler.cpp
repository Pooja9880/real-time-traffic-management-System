#include <SoftwareSerial.h>

#define ledgreenA1 4
#define ledyellowA2 3
#define ledredA3 2

#define ledgreenB1 7
#define ledyellowB2 6
#define ledredB3 5

#define ledgreenC1 10
#define ledyellowC2 9
#define ledredC3 8

#define ledgreenD1 13
#define ledyellowD2 12
#define ledredD3 11 

SoftwareSerial mySerial(A4,A5);  

int sensorValue = 0;
int a, b, c, d,amb=20000;
int k = 0;
int l = 0;
int m = 0;
int n = 0;

bool laneExecuted = false;
unsigned long previousTime = 0;
unsigned long delayTime = 0;
unsigned long yellowEndTime=0;
unsigned long currentTime=0;

void setup() 
{
  Serial.begin(9600);
  mySerial.begin(9600);  

  pinMode(ledgreenA1, OUTPUT);
  pinMode(ledyellowA2, OUTPUT);
  pinMode(ledredA3, OUTPUT);

  pinMode(ledgreenB1, OUTPUT);
  pinMode(ledyellowB2, OUTPUT);
  pinMode(ledredB3, OUTPUT);

  pinMode(ledgreenC1, OUTPUT);
  pinMode(ledyellowC2, OUTPUT);
  pinMode(ledredC3, OUTPUT);

  pinMode(ledgreenD1, OUTPUT);
  pinMode(ledyellowD2, OUTPUT);
  pinMode(ledredD3, OUTPUT);
}

void readSensor()
{
  a = analogRead(A0);
  b = analogRead(A1);
  c = analogRead(A2);
  d = analogRead(A3);

  if (a < 100)
   k = 15000;
   else 
   k = 10000;

  if (b < 100)
  l = 15000;
  else
  l = 10000;

  if (c < 100) 
   m = 15000;
   else 
   m = 10000;

  if (d < 100) 
   n = 15000;
   else 
    n =10000;

  Serial.print(a);
   Serial.print("\t");

  Serial.print(b);
  Serial.print("\t");

  Serial.print(c);
  Serial.print("\t");

  Serial.print(d);
  Serial.print("\t");
  Serial.println("\t");
}

void normal()
{
  unsigned long currentTime = millis();

  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledredA3, LOW);
    digitalWrite(ledredB3, HIGH);
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, HIGH);

    digitalWrite(ledyellowA2, LOW);
    digitalWrite(ledyellowB2, LOW);
    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledyellowD2, LOW);

    digitalWrite(ledgreenD1, LOW);
    digitalWrite(ledgreenB1, LOW);
    digitalWrite(ledgreenC1, LOW);
    digitalWrite(ledgreenA1, HIGH);

    previousTime = currentTime;
  }

  delayTime = k;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowA2, HIGH);
    digitalWrite(ledyellowB2, HIGH);
  }

  unsigned long yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowA2, LOW);
    digitalWrite(ledyellowB2, LOW);
    digitalWrite(ledredA3, HIGH);
    digitalWrite(ledredB3, LOW);
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, HIGH);
    digitalWrite(ledgreenA1, LOW);
    digitalWrite(ledgreenB1, HIGH);
  }

  delayTime += l;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowB2, HIGH);
    digitalWrite(ledyellowC2, HIGH);
  }

  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowB2, LOW);
    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledredA3, HIGH);
    digitalWrite(ledredB3, HIGH);
    digitalWrite(ledredC3, LOW);
    digitalWrite(ledredD3, HIGH);
    digitalWrite(ledgreenB1, LOW);
    digitalWrite(ledgreenC1, HIGH);
  }

  delayTime += m;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowC2, HIGH);
    digitalWrite(ledyellowD2, HIGH);
  }

  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledyellowD2, LOW);
    digitalWrite(ledredA3, HIGH);
    digitalWrite(ledredB3, HIGH);
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, LOW);
    digitalWrite(ledgreenC1, LOW);
    digitalWrite(ledgreenD1, HIGH);
  }

  delayTime += n+1000;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowD2, HIGH);
    digitalWrite(ledyellowA2, HIGH);
  }
//laneExecuted = true;
return;
}

void alane()
{
  digitalWrite(ledredA3, LOW);
  digitalWrite(ledredB3, HIGH);
  digitalWrite(ledredC3, HIGH);
  digitalWrite(ledredD3, HIGH);

  digitalWrite(ledyellowA2, LOW);
  digitalWrite(ledyellowB2, LOW);
  digitalWrite(ledyellowC2, LOW);
  digitalWrite(ledyellowD2, LOW);

  digitalWrite(ledgreenD1, LOW);
  digitalWrite(ledgreenB1, LOW);
  digitalWrite(ledgreenC1, LOW);
  digitalWrite(ledgreenA1, HIGH);
  
  delay(amb);
  
  digitalWrite(ledyellowA2, HIGH);
  digitalWrite(ledyellowB2, HIGH);
  delay(2000);

   currentTime = millis();
   delayTime = 0;
   yellowEndTime = previousTime + delayTime + 1000;

  // B LANE IS GREEN
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledredA3, HIGH);
    digitalWrite(ledredB3, LOW);

    digitalWrite(ledyellowA2, LOW);
    digitalWrite(ledyellowB2, LOW);

    digitalWrite(ledgreenA1, LOW);
    digitalWrite(ledgreenB1, HIGH);
     previousTime=currentTime ;
     
  }

  delayTime += l;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowB2, HIGH);
    digitalWrite(ledyellowC2, HIGH);
  }

  // C LANE IS GREEN
  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledredB3, HIGH);
    digitalWrite(ledredC3, LOW);

    digitalWrite(ledyellowB2, LOW);
    digitalWrite(ledyellowC2, LOW);

    digitalWrite(ledgreenB1, LOW);
    digitalWrite(ledgreenC1, HIGH);
  }

  delayTime += m;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowC2, HIGH);
    digitalWrite(ledyellowD2, HIGH);
  }

  // D LANE IS GREEN
  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, LOW);

    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledyellowD2, LOW);

    digitalWrite(ledgreenC1, LOW);
    digitalWrite(ledgreenD1, HIGH);
  }

  delayTime += n;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowD2, HIGH);
    digitalWrite(ledyellowA2, HIGH);
  }

  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowD2, LOW);
    digitalWrite(ledyellowA2, LOW);
  }
laneExecuted = true;
  return;
}

void blane()
{
digitalWrite(ledredA3, HIGH);
digitalWrite(ledredB3, LOW);
digitalWrite(ledredC3, HIGH);
digitalWrite(ledredD3, HIGH);

digitalWrite(ledyellowA2,LOW);
digitalWrite(ledyellowB2,LOW);
digitalWrite(ledyellowC2,LOW);
digitalWrite(ledyellowD2,LOW);

digitalWrite(ledgreenA1,LOW);
digitalWrite(ledgreenB1,HIGH);
digitalWrite(ledgreenC1,LOW);
digitalWrite(ledgreenD1,LOW); 

delay(amb);
digitalWrite(ledyellowB2, HIGH);
digitalWrite(ledyellowC2, HIGH);
delay(2000);

currentTime=millis();
delayTime=0;
//C LANE IS GREEN
  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {

    digitalWrite(ledredB3, HIGH);
    digitalWrite(ledredC3, LOW);

    digitalWrite(ledyellowB2, LOW);
    digitalWrite(ledyellowC2, LOW);

    digitalWrite(ledgreenB1, LOW);
    digitalWrite(ledgreenC1, HIGH);
    previousTime=currentTime;
  }

  delayTime += m;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowC2, HIGH);
    digitalWrite(ledyellowD2, HIGH);
  }

//D LANE IS GREEN
  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, LOW);

    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledyellowD2, LOW);

    digitalWrite(ledgreenC1, LOW);
    digitalWrite(ledgreenD1, HIGH);
  }

  delayTime += n;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowD2, HIGH);
    digitalWrite(ledyellowA2, HIGH);
  }

  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowD2, LOW);
    digitalWrite(ledyellowA2, LOW);
  }
laneExecuted = true;
return;
}

void clane()
{
digitalWrite(ledredA3, HIGH);
digitalWrite(ledredB3, HIGH);
digitalWrite(ledredC3, LOW);
digitalWrite(ledredD3, HIGH);

digitalWrite(ledyellowA2, LOW);
digitalWrite(ledyellowB2, LOW);
digitalWrite(ledyellowD2, LOW);
digitalWrite(ledyellowC2, LOW);

digitalWrite(ledgreenA1, LOW);
digitalWrite(ledgreenB1, LOW);
digitalWrite(ledgreenC1, HIGH);
digitalWrite(ledgreenD1, LOW);

delay(amb);
digitalWrite(ledyellowC2, HIGH);
digitalWrite(ledyellowD2, HIGH);
delay(2000);

 unsigned long currentTime = millis();
  unsigned long delayTime = 0;
//D LANE IS GREEN
  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledredC3, HIGH);
    digitalWrite(ledredD3, LOW);

    digitalWrite(ledyellowC2, LOW);
    digitalWrite(ledyellowD2, LOW);

    digitalWrite(ledgreenC1, LOW);
    digitalWrite(ledgreenD1, HIGH);
    previousTime=currentTime;
  }

  delayTime += n;
  if (currentTime - previousTime >= delayTime)
  {
    digitalWrite(ledyellowD2, HIGH);
    digitalWrite(ledyellowA2, HIGH);
  }

  yellowEndTime = previousTime + delayTime + 1000;
  if (currentTime >= yellowEndTime)
  {
    digitalWrite(ledyellowD2, LOW);
    digitalWrite(ledyellowA2, LOW);
  }
  laneExecuted = true;
return;
}

void dlane()
{
digitalWrite(ledredA3, HIGH);
digitalWrite(ledredB3, HIGH);
digitalWrite(ledredC3, HIGH);
digitalWrite(ledredD3, LOW);

digitalWrite(ledyellowA2, LOW);
digitalWrite(ledyellowB2, LOW);
digitalWrite(ledyellowC2, LOW);
digitalWrite(ledyellowD2, LOW);

digitalWrite(ledgreenA1, LOW);
digitalWrite(ledgreenB1, LOW);
digitalWrite(ledgreenC1, LOW);
digitalWrite(ledgreenD1, HIGH);

delay(amb);
digitalWrite(ledyellowD2, HIGH);
digitalWrite(ledyellowA2, HIGH);
delay(2000);
laneExecuted = true;
return;
}

void loop()
{
  readSensor();
  if (mySerial.available())
  {
    char data = mySerial.read();  // read data from the NodeMCU
    if(data=='0')
    {
      alane();delay(10);
      
    }
    else if(data=='1')
    {
      blane();
      
    }
    else if(data=='2')
    {
      clane();
       
    }
    else if(data=='3')
    {
      dlane(); delay(10); 
    }
  }

  if(laneExecuted=true)
  {
    normal();
  }
}

