//Input/output pin definitions
#define button1 D5
#define button2 D6
#define button3 D7
#define led1    D1
#define led2    D2
#define led3    D3

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP); //Buttons are using INPUT_PULLUP mode
  pinMode(button2, INPUT_PULLUP); //to avoid using additional resistors.
  pinMode(button3, INPUT_PULLUP);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  toggleLed(button1, led1);
  toggleLed(button2, led2);
  toggleLed(button3, led3);
}

/*
 * Changes state of given output pin based on given input pin
 * e.g. LED diode is turned on as long as button is being pressed.
 */
void toggleLed(int buttonPin, int ledPin) {
  int buttonState = digitalRead(buttonPin);
  if (buttonState == LOW) {
    digitalWrite(ledPin, HIGH);
  } else {
    digitalWrite(ledPin, LOW);
  }
}
