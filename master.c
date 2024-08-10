#include <Wire.h>

void setup() {
  Wire.begin(); // Initialize I2C communication as master
  Serial.begin(9600); // Initialize serial communication
}

void loop() {
  // Read data from Slave 1
  Wire.requestFrom(7, 12); // Request 12 bytes from slave 1
  while (Wire.available()) {
    char data = Wire.read();
    Serial.write(data); // Print data to the Serial Monitor
  }
  Serial.write("\n");

  delay(1000);

  // Check if there's data from Slave 2
  while (Serial.available()) {
    char data2 = Serial.read(); // Read data from Serial (from Slave 2)
    Wire.beginTransmission(7);  // Begin transmission to Slave 1
    Wire.write(data2);          // Send the data to Slave 1
    Wire.endTransmission();     // End transmission
  }

  delay(1000); // Adjust delay for stability
}
