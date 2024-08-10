#include <Wire.h>

void setup() {
  Wire.begin(7); // Initialize I2C communication with address 7
  Wire.onReceive(receive); // Set function to run when data is received
  Wire.onRequest(request); // Set function to run when data is requested
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  delay(1000); // Add a delay for stability
}

void receive(int numBytes) {
  while (Wire.available()) {
    char data = Wire.read(); // Read the incoming byte
    Serial.print(data); // Print the received data to the Serial Monitor
  }
}

void request() {
  Wire.write("i am slave 1"); // Send a message when requested
}
