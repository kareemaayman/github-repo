void setup() {
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read and print any data received from the master
  while (Serial.available()) {
    char data = Serial.read();
    Serial.print(data); // Print the data to the Serial Monitor
  }
  delay(1000); // Adjust delay for stability
  // Send a message to the master
  const char *message = "i am slave 2";
  Serial.write(message); // Send the message
  Serial.write('\n'); // Send a newline character to indicate the end of the message

  delay(1000); // Delay to prevent flooding the master with messages
}
