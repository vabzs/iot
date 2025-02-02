float temp;
float tempC = 0;
float tempF = 0;
int buzzer = 7;

void setup() {
  pinMode(A0, INPUT);
  pinMode(buzzer, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  temp = analogRead(A0);
  temp = ((temp * 5.0) / 1024);      // Convert analog value to voltage
  tempC = (temp - 0.5) * 100;        // Convert voltage to Celsius
  tempF = ((tempC * 9.0) / 5.0) + 32;  // Convert Celsius to Fahrenheit
  
  Serial.print("Temperature = ");
  Serial.print(tempC);
  Serial.print(" C , ");
  Serial.print(tempF);
  Serial.println(" F ");
  
  if (tempC < 18) {                    // Temperature less than 18°C
    noTone(buzzer);
    delay(1000);
  } else if (tempC >= 18 && tempC <= 22) {  // Temperature between 18°C and 22°C
    noTone(buzzer);
    delay(1000);
  } else if (tempC > 23) {             // Temperature greater than 23°C
    tone(buzzer, 1000);
    delay(200);
  }
}
