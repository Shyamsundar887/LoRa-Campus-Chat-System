
#include <SPI.h>
#include <LoRa.h>

// LoRa pin connections
#define SS    15    // D8
#define RST   16    // D0
#define DIO0  4     // D2

String message = "";

void setup() {
  Serial.begin(9600);

  // Configure LoRa pins
  LoRa.setPins(SS, RST, DIO0);

  // Initialize LoRa at 433 MHz
  if (!LoRa.begin(433E6)) {
    Serial.println("LoRa initialization failed!");
    while (1);
  }

  // LoRa configuration
  LoRa.setSpreadingFactor(7);
  LoRa.setSignalBandwidth(125E3);
  LoRa.setTxPower(17);

  Serial.println("LoRa Chat Started!");
  Serial.println("Type a message and press Enter.");
}

void loop() {

  // Read message from Serial Monitor
  while (Serial.available()) {
    char ch = Serial.read();

    if (ch == '\n') {
      message.trim();

      if (message.length() > 0) {
        // Transmit message
        LoRa.beginPacket();
        LoRa.print(message);
        LoRa.endPacket();

        Serial.print("You: ");
        Serial.println(message);

        message = "";
      }
    }
    else if (ch != '\r') {
      message += ch;
    }
  }

  // Check for incoming LoRa packets
  int packetSize = LoRa.parsePacket();

  if (packetSize) {
    String receivedMessage = "";

    while (LoRa.available()) {
      receivedMessage += (char)LoRa.read();
    }

    Serial.print("Received: ");
    Serial.println(receivedMessage);
  }
}
