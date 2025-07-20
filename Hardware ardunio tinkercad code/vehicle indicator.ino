
const int leftButtonPin = 2;
const int rightButtonPin = 3;
const int leftLEDPin = 9;
const int rightLEDPin = 10;

bool leftActive = false;
bool rightActive = false;
bool hazardActive = false;

unsigned long lastToggleTime = 0;
bool ledState = false;

unsigned long leftPressStart = 0;
unsigned long rightPressStart = 0;

void setup() {
  pinMode(leftButtonPin, INPUT_PULLUP);
  pinMode(rightButtonPin, INPUT_PULLUP);
  pinMode(leftLEDPin, OUTPUT);
  pinMode(rightLEDPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  unsigned long currentMillis = millis();

  bool leftButtonPressed = digitalRead(leftButtonPin) == LOW;
  bool rightButtonPressed = digitalRead(rightButtonPin) == LOW;

  // Detect press and hold for 1 second
  if (leftButtonPressed) {
    if (leftPressStart == 0) leftPressStart = currentMillis;
    if (currentMillis - leftPressStart > 1000) {
      handleLeftButtonPress();
      leftPressStart = 0;
      delay(300);  // Debounce
    }
  } else {
    leftPressStart = 0;
  }

  if (rightButtonPressed) {
    if (rightPressStart == 0) rightPressStart = currentMillis;
    if (currentMillis - rightPressStart > 1000) {
      handleRightButtonPress();
      rightPressStart = 0;
      delay(300);  // Debounce
    }
  } else {
    rightPressStart = 0;
  }

  // Blinking Logic
  if (currentMillis - lastToggleTime >= 300) {
    lastToggleTime = currentMillis;
    ledState = !ledState;

    if (hazardActive) {
      digitalWrite(leftLEDPin, ledState);
      digitalWrite(rightLEDPin, ledState);
    } else {
      digitalWrite(leftLEDPin, leftActive ? ledState : LOW);
      digitalWrite(rightLEDPin, rightActive ? ledState : LOW);
    }
  }
}

void handleLeftButtonPress() {
  if (hazardActive) {
    hazardActive = false;
    Serial.println("Hazard OFF");
  } else if (rightActive) {
    rightActive = false;
    leftActive = true;
    Serial.println("Right OFF, Left ON");
  } else if (leftActive) {
    leftActive = false;
    Serial.println("Left OFF");
  } else if (!leftActive && !rightActive) {
    leftActive = true;
    Serial.println("Left ON");
  }

  if (digitalRead(leftButtonPin) == LOW && digitalRead(rightButtonPin) == LOW) {
    hazardActive = true;
    leftActive = false;
    rightActive = false;
    Serial.println("Hazard ON");
  }
}

void handleRightButtonPress() {
  if (hazardActive) {
    hazardActive = false;
    Serial.println("Hazard OFF");
  } else if (leftActive) {
    leftActive = false;
    rightActive = true;
    Serial.println("Left OFF, Right ON");
  } else if (rightActive) {
    rightActive = false;
    Serial.println("Right OFF");
  } else if (!leftActive && !rightActive) {
    rightActive = true;
    Serial.println("Right ON");
  }

  if (digitalRead(leftButtonPin) == LOW && digitalRead(rightButtonPin) == LOW) {
    hazardActive = true;
    leftActive = false;
    rightActive = false;
    Serial.println("Hazard ON");
  }
}
