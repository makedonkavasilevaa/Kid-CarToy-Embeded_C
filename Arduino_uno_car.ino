#define R_S 4  // ir sensor Right
#define L_S 2  // ir sensor Left
#define redLED_right 6  // Red Right LED for simulation
#define redLED_left 5  // Red Left LED for simulation
#define greenLED 7  // Green LED for simulation


void setup() {
  pinMode(R_S, INPUT);
  pinMode(L_S, INPUT);
  pinMode(redLED_right, OUTPUT);
  pinMode(redLED_left, OUTPUT);
  pinMode(greenLED, OUTPUT);
}


void loop() {
  if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 0)) {
    // Both sensors are on a white surface
    digitalWrite(redLED_right, HIGH);
    digitalWrite(redLED_left, HIGH);
    digitalWrite(greenLED, LOW);
  } else if ((digitalRead(R_S) == 0) && (digitalRead(L_S) == 1)){
    //The right sensor is on white surface
    digitalWrite(redLED_right, HIGH);
    digitalWrite(redLED_left, LOW);
    digitalWrite(greenLED, LOW);
  } else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 0)){
    //The left sensor is on white surface
    digitalWrite(redLED_right, LOW);
    digitalWrite(redLED_left, HIGH);
    digitalWrite(greenLED, LOW);
  }else if ((digitalRead(R_S) == 1) && (digitalRead(L_S) == 1)){
    // Both sensors are on a black surface
    digitalWrite(redLED_right, LOW);
    digitalWrite(redLED_left, LOW);
    digitalWrite(greenLED, HIGH);
  } else {
    digitalWrite(redLED_right, LOW);
    digitalWrite(redLED_left, LOW);
    digitalWrite(greenLED, LOW);
  }
}