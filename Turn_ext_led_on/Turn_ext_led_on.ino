int LED = 3; //Pin # for LED input
int trigPin = 13;
int echoPin = 12;

long duration;
int distance;

void setup() {
  Serial.begin(9600); // Starts serial communication so that values can be displayed.
  pinMode(LED, OUTPUT);
  pinMode(trigPin, OUTPUT); // Sends "pulse" for ultrasonic sensor to emit sound wave.
  pinMode(echoPin, INPUT); // Detects for the reflected sound wave produced once wave bounces off object.
}

void loop() {
 //Ensure trigPin is clear.
 digitalWrite(trigPin, LOW);
 delayMicroseconds(2);

 //Set trigPin on HIGH statefor 10 microsec
 digitalWrite(trigPin, HIGH);
 delayMicroseconds(10);
 digitalWrite(trigPin, LOW);

 // Read echoPin, return sound wave travel time in ms
 duration = pulseIn(echoPin, HIGH);

 // Calculate distance:
 distance = duration*0.034/2;

 // Prints distance on Serial Monitor.
 Serial.print("Distance: ");
 Serial.println(distance);
 delay(100);
 
 // Detects objects less than 1000 cm away 
 if(distance >= 1000)
   digitalWrite(LED, HIGH);
 else if (distance < 10) {
   digitalWrite(LED, LOW);
 }
 else {
   digitalWrite(LED, HIGH); 
   delay(distance*2); // Closer the object is the more frequent the blinks.
   digitalWrite(LED, LOW);
   delay(distance*2); 
 }   
}
