int val;
int tempPin = A0;         // Pin where the temperature sensor is connected
float tfmax = -1000;       // Initialize with a very low number
float tfmin = 1000;        // Initialize with a very high number

void setup() {
  Serial.begin(9600);
}

void loop() {
  // Read the analog value from the temperature sensor
  val = analogRead(tempPin);

  // Convert the analog reading to millivolts (assuming the sensor gives 500 mV for 50 degrees Celsius)
  float mv = (val / 1024.0) * 5000;

  // Convert millivolts to Celsius (assuming 10 mV per degree Celsius)
  float cel = mv / 10;

  // Convert Celsius to Fahrenheit
  float farh = (cel * 9.0) / 5.0 + 32.0;

  // Update the maximum and minimum Fahrenheit temperatures
  if (farh > tfmax) {
    tfmax = farh;
  }
  if (farh < tfmin) {
    tfmin = farh;
  }

  // Display the current temperature in Fahrenheit
  Serial.print("TEMPERATURE = ");
  Serial.print(farh);
  Serial.println(" °F");

  // Display the maximum temperature recorded
  Serial.print("Max Temp: ");
  Serial.print(tfmax);
  Serial.println(" °F");

  // Display the minimum temperature recorded
  Serial.print("Min Temp: ");
  Serial.print(tfmin);
  Serial.println(" °F");

  Serial.println();  // Print a blank line for spacing

  delay(2000);  // Wait for 2 seconds before taking the next reading
}
