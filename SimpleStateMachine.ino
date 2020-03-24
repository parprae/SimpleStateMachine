/*
weekly assignment 6

push button 4 times to turn on the light

*/

const int pinButton = A0;
const int ledExternal = 12;
const int ledInternal = 13; 

int buttonPushCounter = 0;
int stateButton = 0;
int previous = 0;

void setup() {
  pinMode(pinButton, INPUT);
  pinMode(ledExternal, OUTPUT);
  pinMode(ledInternal, OUTPUT);
  Serial.begin(9600);
}


void loop() {
  stateButton = digitalRead(pinButton);

  // compare the states
  if (stateButton != previous) {
    // if the state has changed, increment the counter
    if (stateButton == HIGH) {
      buttonPushCounter++;
      Serial.println("on");
        digitalWrite(ledInternal, HIGH);
      Serial.print("number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      Serial.println("off");
        digitalWrite(ledInternal, LOW);
    }
    delay(50);
  }
  // for the next loop
  previous = stateButton;

// when the remainder is 0 then the light turns on
  if (buttonPushCounter % 4 == 0) {
    digitalWrite(ledExternal, HIGH);
  } else {
    digitalWrite(ledExternal, LOW);
  }

}
