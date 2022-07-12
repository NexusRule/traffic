/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/fxxsj/OneDrive/Desktop/traffic/src/traffic.ino"
/*
 * Project traffic
 * Description:
 * Author:
 * Date:
 */
// #include "MQTT.h"
void letset();
void setup();
void loop();
#line 8 "c:/Users/fxxsj/OneDrive/Desktop/traffic/src/traffic.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

void ledset();
// void callback(char *topic, byte *payload, unsigned int length);

enum States
{
  north,
  east,
  northOn,
  eastOn
};
States currentState = northOn;
// MQTT client("lab.thewcl.com", 1883, callback);
bool bnorth = false;
bool beast = false;

// void callback(char *topic, byte *payload, unsigned int length)
// {
//   char p[length + 1];
//   memcpy(p, payload, length);
//   p[length] = NULL;
//   Serial.printf("%s", p);
//   Serial.println();

//   if (String(topic).equals("7"))
//   {
//     Serial.println(p);
//   }
// }

void letset()
{
  digitalWrite(D2, LOW);
  digitalWrite(D3, LOW);
  digitalWrite(D4, LOW);
  digitalWrite(D5, LOW);
  digitalWrite(D6, LOW);
  digitalWrite(D7, LOW);
}

// setup() runs once, when the device is first turned on.
void setup()
{
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);

  // client.subscribe("7");
  // client.subscribe("8");

  pinMode(A0, INPUT);
  pinMode(A1, INPUT);
  pinMode(D2, OUTPUT);
  pinMode(D3, OUTPUT);
  pinMode(D4, OUTPUT);
  pinMode(D5, OUTPUT);
  pinMode(D6, OUTPUT);
  pinMode(D7, OUTPUT);
}

// loop() runs over and over again, as quickly as it can execute.
void loop()
{
  // The core of your code will likely live here.
  // if (client.isConnected())
  // {
  //   client.loop();
  // }
  // else
  // {
  //   client.connect(System.deviceID());
  //   client.subscribe("7");
  //   client.subscribe("8");
  // }

  beast = digitalRead(A0);
  bnorth = digitalRead(A1);

  if (beast == 0)
  {
    currentState = east;
  }
  else if (bnorth == 0)
  {
    currentState = north;
  }

  switch (currentState)
  {
  case north:
    digitalWrite(D4, HIGH);
    digitalWrite(D7, HIGH);
    delay(800);
    letset();
    digitalWrite(D7, HIGH);
    digitalWrite(D4, HIGH);
    delay(2000);
    digitalWrite(D4, LOW);
    digitalWrite(D3, HIGH);
    delay(5000);
    digitalWrite(D3, LOW);
    digitalWrite(D2, HIGH);
    currentState = northOn;
    break;

  case east:
    digitalWrite(D7, HIGH);
    digitalWrite(D4, HIGH);
    delay(800);
    letset();
    digitalWrite(D4, HIGH);
    digitalWrite(D7, HIGH);
    delay(2000);
    digitalWrite(D7, LOW);
    digitalWrite(D6, HIGH);
    delay(5000);
    digitalWrite(D6, LOW);
    digitalWrite(D5, HIGH);
    currentState = eastOn;
    break;

  case northOn:
    letset();
    digitalWrite(D2, HIGH);
    digitalWrite(D7, HIGH);
    break;

  case eastOn:
    letset();
    digitalWrite(D5, HIGH);
    digitalWrite(D4, HIGH);
    break;
  }
}
