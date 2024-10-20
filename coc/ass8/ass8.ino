const int sensorPin = A1; // Pin where the DHT11 is connected

void setup() {
  Serial.begin(9600); // Initialize serial communication
  Serial.println("DHT11 Temperature Sensor Test");
}

void loop() {
  // Read the voltage from the DHT11
  int sensorValue = analogRead(sensorPin);
  
  // Convert the analog reading (0 - 1023) to voltage (0 - 5V)
  float voltage = sensorValue * (5.0 / 1023.0);
  
  // Convert voltage to temperature in Celsius (10 mV per degree)
  float temperatureC = voltage * 20; // DHT11 outputs 10 mV per degree Celsius

  // Print the temperature to the Serial Monitor
  Serial.print("Temperature: ");
  Serial.print(temperatureC);
  Serial.println(" °C");

  delay(2000); // Wait 2 seconds before the next reading
}
