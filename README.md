# LoRa-Campus-Chat-System
Two-way wireless chat using ESP8266 and SX1278 LoRa modules

# LoRa-Based Campus Chat System

## Project Overview
A wireless communication system that enables two users to exchange text messages using ESP8266 NodeMCU and SX1278 LoRa modules.

## Components Used
- ESP8266 NodeMCU – 2
- SX1278 LoRa Module (RA-02) – 2
- 433 MHz Antennas – 2
- USB cables
- Two computers

## Communication Details
- Frequency: 433 MHz
- Communication: Two-way point-to-point
- Protocol: LoRa
- Interface: SPI
- Serial Baud Rate: 9600

## Working Principle
The user enters a message through the Serial Monitor. The ESP8266 sends the message to the SX1278 module through SPI. The LoRa module transmits the data wirelessly to the other node, where it is received and displayed on the second computer's Serial Monitor.

## Arduino Library
LoRa by Sandeep Mistry

## Hardware Connections
| SX1278 | ESP8266 |
|---|---|
| VCC | 3.3V |
| GND | GND |
| SCK | D5 |
| MISO | D6 |
| MOSI | D7 |
| NSS | D8 |
| RESET | D0 |
| DIO0 | D2 |

## Future Improvements
- Add message acknowledgement.
- Support multiple communication nodes.
- Implement message encryption.
- Develop a graphical user interface.
