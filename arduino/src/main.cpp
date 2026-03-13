#include <Arduino.h>

// --- Transmitter Code ---
const int LED_PIN = 13;    // Connect your bright LED here
const int BIT_PERIOD = 100; // Time in milliseconds for each bit
void sendByte(char c);
void setup() {
  pinMode(LED_PIN, OUTPUT);
  Serial.begin(9600);
  Serial.println("Transmitter Ready. Type a character to send:");
}
void loop() {
  if (Serial.available() > 0) {
    char data = Serial.read(); // Get character from Serial Monitor
    sendByte(data);
    Serial.print("Sent: ");
    Serial.println(data);
  }
}

void sendByte(char c) {
  // 1. START BIT (Signal the receiver to wake up)
  digitalWrite(LED_PIN, HIGH);
  delay(BIT_PERIOD);

  // 2. DATA BITS (Send 8 bits of the character)
  for (int i = 0; i < 8; i++) {
    bool bit = (c >> i) & 0x01; // Extract each bit (LSB first)
    digitalWrite(LED_PIN, bit ? HIGH : LOW);
    Serial.print(bit ? "1" : "0"); // Optional: Print the bit being sent
    delay(BIT_PERIOD);
  }

  // 3. STOP BIT (Signal the end of the character)
  digitalWrite(LED_PIN, LOW);
  delay(BIT_PERIOD);
  
  // Extra pause to ensure the receiver is ready for the next one
  delay(BIT_PERIOD); 
}