void setup() {
  // Start the Serial communication
  Serial.begin(9600);
  Serial.println("Enter a number to square:");
}

void loop() {
  // Check if data is available to read
  if (Serial.available() > 0) {
    // Read the input number from the Serial Monitor
    String input = Serial.readStringUntil('\n');
    
    // Convert the input to an integer (if input is a valid number)
    int number = input.toInt();

    // Check if the input is a valid number by comparing it with the input
    if (input.length() > 0 && input.toInt() != 0 || input == "0") {
      // Calculate the square of the number
      int squared = number * number;
      
      // Print the result
      Serial.print("The square of ");
      Serial.print(number);
      Serial.print(" is ");
      Serial.println(squared);
    } else {
      // If input is not a valid number, print an error message
      Serial.println("Invalid input, please enter a number.");
    }

    // Ask for another number
    Serial.println("Enter another number to square:");
  }
}
