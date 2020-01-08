// defines pins numbers
const int trigPin = 9;
const int echoPin = 10;
const int buzzer = 11;
const int ledPin = 13;

// defines distance 
const int high=20;
const int mid=10;
const int low=5;
const int minSpot=0;
 
// defines variables
long duration;
int distance;
int safetyDistance;

void setup() {
pinMode(trigPin, OUTPUT); // Sets the trigPin as an Output
pinMode(echoPin, INPUT); // Sets the echoPin as an Input
pinMode(buzzer, OUTPUT);
pinMode(ledPin, OUTPUT);
Serial.begin(9600); // Starts the serial communication
}
  
void loop() {
//// Clears the trigPin
digitalWrite(trigPin, LOW);
delayMicroseconds(2);

// Sets the trigPin on HIGH state for 10 micro seconds
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
 
// Reads the echoPin, returns the sound wave travel time in microseconds
duration = pulseIn(echoPin, HIGH);
 
// Calculating the distance
distance = duration*0.034/2;
  
 Serial.print(distance);      // To show the distance of the obstacle on the serial monitor.
 Serial.println(" CM");
 delay(500);

safetyDistance = distance;
if (mid < safetyDistance && safetyDistance <= high){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(200);
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  delay(200);
}
if (low < safetyDistance && safetyDistance <= mid){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
  delay(80);
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  delay(80);
}
if (minSpot < safetyDistance && safetyDistance <= low){
  digitalWrite(buzzer, HIGH);
  digitalWrite(ledPin, HIGH);
}
else if ( safetyDistance > high){
  digitalWrite(buzzer, LOW);
  digitalWrite(ledPin, LOW);
  }
}
