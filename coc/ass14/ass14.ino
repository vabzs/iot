// Define pin numbers for LEDs
const int redPin = 2;
const int yellowPin = 1;
const int greenPin = 0;

// Define durations for each light in milliseconds
const int redDuration = 5000;   // 5 seconds
const int yellowDuration = 2000; // 2 seconds
const int greenDuration = 5000; // 5 seconds

void setup() {
  // Set LED pins as outputs
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop() {
  // Red light on, yellow and green off
  digitalWrite(redPin, HIGH);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, LOW);
  delay(redDuration); // Keep red light on for 5 seconds

  // Yellow light on, red and green off
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, HIGH);
  digitalWrite(greenPin, LOW);
  delay(yellowDuration); // Keep yellow light on for 2 seconds

  // Green light on, red and yellow off
  digitalWrite(redPin, LOW);
  digitalWrite(yellowPin, LOW);
  digitalWrite(greenPin, HIGH);
  delay(greenDuration); // Keep green light on for 5 seconds
}
