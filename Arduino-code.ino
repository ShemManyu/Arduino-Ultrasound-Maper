#include <NewPing.h>

#define trigpin 5
#define echopin 6
#define max_distance 200

NewPing sonar(trigpin, echopin, max_distance);
int pos = 0;
int it = 10;

void setup() {
  Serial.begin(9600);
  pinMode(12, OUTPUT);
  digitalWrite(12,HIGH);
  pinMode(trigpin, OUTPUT);
  pinMode(echopin, INPUT);
  // put your setup code here, to run once:
  delay(3000);
}

void loop() {
  int duration, distance;

  int i = 0;
  int t = 0;
  int a = 0;

  for(i=0; i<180; i ++){
  unsigned int uS = sonar.ping();
    for(t = 0; t < it; t++){
      uS = sonar.ping();
      a = uS/US_ROUNDTRIP_CM + a;
      delay(30);
    }

    a = a /(it-1);
    t = 0;
  
    Serial.println(a);
  }
  digitalWrite(trigpin, HIGH);
  delay(10);
  digitalWrite(trigpin, LOW);
  duration = pulseIn(echopin, HIGH);
  distance = (duration/2)/29.1;
  Serial.print(distance);
  Serial.println("cm");//Prints distance in cm on screen
  delay(500);
  // put your main code here, to run repeatedly:

}
