#include <Arduino.h>

// --- Receiver Code (Manchester) ---
const int SENSOR_PIN = A0;   // LDR connected to A0
const int THRESHOLD = 500;   // Adjust based on your room's light
const int BIT_PERIOD = 100;  // Must match the Transmitter!

void setup() {
  pinMode(SENSOR_PIN, INPUT);
  Serial.begin(9600);
  Serial.println("Receiver Ready. Waiting for light signal...");
}

void loop() {
  // 1. Wait for the START BIT (a transition from Dark to Light)
  if (analogRead(SENSOR_PIN) > THRESHOLD) {
    
    // Sync: Wait 1.5 bit periods to land in the middle of the first data bit
    delay(BIT_PERIOD * 1.5); 
    
    char receivedChar = 0;

    // 2. Sample 8 Data Bits
    for (int i = 0; i < 8; i++) {
      int lightLevel = analogRead(SENSOR_PIN);
      
      // In Manchester, we look at the state after the transition
      // If it's LOW now, it was a High-to-Low transition (Logic 1)
      // If it's HIGH now, it was a Low-to-High transition (Logic 0)
      if (lightLevel < THRESHOLD) {
        receivedChar |= (1 << i); // Set bit to 1
      } else {
        // Bit is 0, do nothing (it's already 0)
      }

      delay(BIT_PERIOD); // Move to the middle of the next bit
    }

    Serial.print("Received: ");
    Serial.println(receivedChar);
    
    // Wait for the line to go quiet before looking for the next Start Bit
    delay(BIT_PERIOD); 
  }
}