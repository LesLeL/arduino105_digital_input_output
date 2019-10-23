/*
 * Based on StateChangeDetection example from
 * Arduino's Examples>Digital
 */ 

//Input/output pin definitions
#define button1 D5
#define button2 D6
#define button3 D7
#define led1    D1
#define led2    D2
#define led3    D3

int button1PushCounter = 0; //Counter for the number of button presses
int button1PreviousState = 0; //Button state from previous loop() function iteration

int button2PushCounter = 0;
int button2PreviousState = 0;

int button3PushCounter = 0;
int button3PreviousState = 0;

void setup() {
  Serial.begin(9600);
  pinMode(button1, INPUT_PULLUP); //Buttons are using INPUT_PULLUP mode
  pinMode(button2, INPUT_PULLUP); //to avoid using additional resistors.
  pinMode(button3, INPUT_PULLUP);
  // Initialize output pins for LEDs
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop() {
  checkButtonState(button1, button1PushCounter, button1PreviousState, led1);
  checkButtonState(button2, button2PushCounter, button2PreviousState, led2);
  checkButtonState(button3, button3PushCounter, button3PreviousState, led3);
}

/*
 * Reads state of button connected to given buttonPin,
 * toggling the state of output represented by ledPin.
 * 
 * buttonPushCounter and buttonPreviousState are passed by reference
 * to modify values of global variables, which are then read on
 * next loop() function iteration.
 * 
 */
void checkButtonState(int buttonPin, 
        int &buttonPushCounter, 
        int &buttonPreviousState, 
        int ledPin) {
  //Read the input pin of button        
  int buttonState = digitalRead(buttonPin);

  //Compares current button state with 
  //its state from previous loop() function iteration
  if (buttonState != buttonPreviousState) {
    //If the state has changed, do action based on button's state:
    if (buttonState == LOW) {
      //If current state is LOW, the button went from off to on
      //increment buttonPushCounter variable and print debug message.
      buttonPushCounter++;
      Serial.println("on");
      Serial.print("Number of button pushes: ");
      Serial.println(buttonPushCounter);
    } else {
      //If current state is HIGH, the button went from on to off:
      Serial.println("off");
    }
    //Use 50ms delay as software way to prevent bouncing effect.
    delay(50);
  }
  
  //Save current state of the button 
  //for next iteration of loop() function.
  //This allows to change output state based on input state change
  //and not only based on current state of the button.
  buttonPreviousState = buttonState;

  //Turns on/off LED on each button press event. 
  //As long as button is presed the state of the output
  //should not change
 
  if (buttonPushCounter % 2 == 0) {
    digitalWrite(ledPin, LOW);
  } else {
    digitalWrite(ledPin, HIGH);
  }
}
