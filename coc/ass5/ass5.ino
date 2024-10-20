int mychar = 0; // for incoming serial data

void setup() {
    Serial.begin(9600); // open serial port, set data rate to 9600 bps
    pinMode(7, OUTPUT); // red light
    pinMode(8, OUTPUT); // green light
    pinMode(5, OUTPUT); // yellow light
}

void loop() {
    // Check if there is serial data available
    if (Serial.available() > 0) {
        // Read the incoming byte
        mychar = Serial.read();
        
        // Print the received character for debugging
        Serial.print("I received: ");
        Serial.println((char)mychar);  // Cast to char to print the actual character
        
        // Control the lights based on the received character
        if (mychar == 'r') { // Red light
            digitalWrite(7, HIGH); // Turn on red light
            digitalWrite(8, LOW);  // Turn off green light
            digitalWrite(5, LOW);  // Turn off yellow light
        }
        else if (mychar == 'g') { // Green light
            digitalWrite(7, LOW);  // Turn off red light
            digitalWrite(8, HIGH); // Turn on green light
            digitalWrite(5, LOW);  // Turn off yellow light
        }
        else if (mychar == 'y') { // Yellow light
            digitalWrite(7, LOW);  // Turn off red light
            digitalWrite(8, LOW);  // Turn off green light
            digitalWrite(5, HIGH); // Turn on yellow light
        }
        else if (mychar == 'b') { // Blink green light
            for (int i = 0; i < 10; i++) { // Blink 10 times
                digitalWrite(8, HIGH); // Turn on green light
                delay(250); // Wait 250 milliseconds
                digitalWrite(8, LOW);  // Turn off green light
                delay(250); // Wait 250 milliseconds
            }
        }
    }
}
