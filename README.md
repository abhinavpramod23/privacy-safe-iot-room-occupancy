Privacy-safe room occupancy detection using ESP8266MOD, PIR sensor and MQTT cloud logging.
The system is designed using modular communication abstraction so the sensing MCU can be replaced with STM32 or ESP32 depending on deployment requirements.

# Project Overview
This project is a real-time IoT motion monitoring system using:
- ESP8266 (NodeMCU)
- PIR Motion Sensor
- MQTT Protocol
- Python Subscriber

The system detects motion using PIR sensor and sends data to cloud MQTT broker, which is received by Python client in real time.

# Architecture
PIR Sensor → ESP8266 → WiFi → MQTT Broker → Python Subscriber → Terminal Output (ultrasonic can be used for displaying accurate distance)


# Hardware Used
- NodeMCU ESP8266
- PIR Motion Sensor (HC-SR501)
- Jumper Wires
- MIcro-USB Cable


# Software Used
- Arduino IDE
- Python 3.10.11(since it already had paho-mqtt installed- can use other versions}
- VS Code
- MQTT Broker (test.mosquitto.org)


# MQTT Details
Broker: test.mosquitto.org  
Port: 1883  
Topic: hotel/room101/motion  


# Features
- Real-time motion detection
- Cloud data transmission via MQTT
- Python live monitoring subscriber
- Auto reconnect MQTT logic
- Unique client ID handling


# How To Run

## ESP8266
Upload Arduino code using Arduino IDE.

## Python Subscriber
Install dependencies:

