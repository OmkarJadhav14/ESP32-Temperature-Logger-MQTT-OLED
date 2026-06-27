# ESP32-Temperature-Logger-MQTT-OLED
ESP32-based IoT temperature monitoring system using ESP-IDF, FreeRTOS, DS18B20, SSD1306 OLED, Wi-Fi, and MQTT for real-time local and remote temperature monitoring.

# ESP32 IoT Temperature Logger with OLED Display and MQTT

An IoT-based temperature monitoring system built using the ESP32 microcontroller and the ESP-IDF framework.

The project reads ambient temperature from a DS18B20 digital temperature sensor, displays the temperature locally on a 0.96-inch SSD1306 OLED display, and publishes the readings to an MQTT broker over Wi-Fi for remote monitoring.

The project demonstrates practical embedded software development concepts including FreeRTOS multitasking, OneWire communication, I2C interfacing, Wi-Fi networking, MQTT messaging, and modular firmware design.

---

# Project Highlights

- Developed using ESP-IDF (v6.x)
- FreeRTOS task-based application
- DS18B20 digital temperature sensor
- SSD1306 OLED display (I2C)
- Wi-Fi connectivity
- MQTT communication
- Real-time local and remote temperature monitoring
- Modular and scalable project structure

---

# Features

- Reads temperature using DS18B20
- Displays temperature on SSD1306 OLED
- Connects automatically to Wi-Fi
- Publishes temperature over MQTT
- Serial debugging logs
- FreeRTOS based application
- Modular ESP-IDF project structure
- Easy to configure

---

# Hardware Used

|          Component         |   Quantity  |
|----------------------------|-------------|
| ESP32 DevKit V1            |      1      |
| DS18B20 Temperature Sensor |      1      |
| SSD1306 0.96" OLED Display |      1      |
| 4.7kΩ Pull-up Resistor     |      1      |
| Breadboard                 |      1      |
| Jumper Wires               | As Required |

---

# Software Used

- ESP-IDF v6.0.1
- Espressif IDE
- ESP-IDF Extension
- MQTT Client
- Git

---

# System Architecture

```
                   DS18B20
                      │
                OneWire Driver
                      │
               ┌─────────────┐
               │    ESP32    │
               └──────┬──────┘
                      │
        ┌─────────────┴─────────────┐
        │                           │
      I2C Bus                    Wi-Fi
        │                           │
    SSD1306 OLED                MQTT Broker
    Display                         │
                                    │
                               MQTT Client
```

---

# Working Principle

1. ESP32 boots.
2. Initializes NVS.
3. Initializes the OLED display.
4. Initializes the DS18B20 sensor.
5. Connects to the configured Wi-Fi network.
6. Connects to the MQTT broker.
7. Reads the temperature from the DS18B20 sensor.
8. Displays the temperature on the OLED display.
9. Publishes the temperature to the configured MQTT topic.
10. Repeats every 3 seconds.

---


# Configuration

Before building the project, configure the following parameters in the source code:

- Wi-Fi SSID
- Wi-Fi Password
- MQTT Broker Address
- MQTT Port
- MQTT Topic

---

# Images

## Hardware Setup

<img width="1280" height="960" alt="hardware" src="https://github.com/user-attachments/assets/a6639c8c-9103-4b38-854a-193a6ecb55e2" />

---
## OLED Output

<img width="1366" height="1360" alt="OLED" src="https://github.com/user-attachments/assets/3cf58261-93e0-43a7-a956-30a284481a85" />

---

## Serial Monitor

<img width="457" height="224" alt="serial output" src="https://github.com/user-attachments/assets/492dd9d6-855f-4e19-92c9-2418d615abaa" />

---

## MQTT Client

<img width="720" height="1600" alt="MQTT Dashboard" src="https://github.com/user-attachments/assets/570124c6-d2a2-44c4-96f3-a86692997836" />

---

# Future Improvements

- Data logging to SD Card
- NTP time synchronization
- OTA firmware updates
- Web dashboard
- ThingSpeak integration
- Firebase integration
- HTTPS communication
- Blynk dashboard
- Multiple sensor support
- Deep Sleep mode for low power applications

---

# Skills Demonstrated

- Embedded C Programming
- ESP-IDF Framework
- FreeRTOS
- Wi-Fi Networking
- MQTT Protocol
- OneWire Communication
- I2C Communication
- OLED Display Interfacing
- Embedded Debugging
- IoT Application Development
- Real-Time Embedded Systems
- Modular Firmware Development

---

# Learning Outcomes

Through this project, I gained practical experience in:

- Developing applications using ESP-IDF
- Creating FreeRTOS task-based firmware
- Interfacing digital sensors using OneWire
- Driving OLED displays using I2C
- Implementing Wi-Fi connectivity
- Publishing sensor data using MQTT
- Designing modular embedded software
- Debugging and testing embedded applications

---

# Author

**Omkar Jadhav**


