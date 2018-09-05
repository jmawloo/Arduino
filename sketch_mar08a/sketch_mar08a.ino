const int led1 = 3; //YELLOW
const int led2 = 4; //RED
const int led3 = 5; //GREEN

void setup() {
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(led1,HIGH);
  digitalWrite(led1,HIGH);
  digitalWrite(led1,HIGH);

  digitalWrite(led1,LOW);
  digitalWrite(led1,LOW);
  digitalWrite(led1,LOW);
}
