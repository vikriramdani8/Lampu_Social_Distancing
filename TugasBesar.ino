const int trigPin = 9;
const int echoPin = 10;
boolean check = false;
long duration;
int distance;
int relayPin = 7;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT); 
  pinMode(relayPin, OUTPUT);
  Serial.begin(9600);
}
void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance= duration*0.034/2;

  if(distance < 30) {
    check = !check;
    Serial.print("Check: ");
    Serial.println(check);
  }

  if(check == 1){
    digitalWrite(relayPin, LOW);
  } else {
    digitalWrite(relayPin, HIGH);
  }

  delay(1000);
}
