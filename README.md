# Arduino Weather Station

## Description

This Arduino Weather Station project showcases how to create a basic weather monitoring system using an Arduino Mega, a DHT22 temperature and humidity sensor, a DS3231 Real-Time Clock (RTC) module, and an LCD screen. The weather station displays the current temperature, humidity, and time, providing real-time weather updates.

## Components Used
- **Arduino Mega**: The main microcontroller board for the project.
- **DHT22 Temperature and Humidity Sensor**: Measures the ambient temperature and humidity.
- **DS3231 Real-Time Clock Module**: Keeps track of the current time and date.
- **LCD Screen (16x2 with I2C)**: Displays temperature, humidity, and time.
- **Breadboard and Jumper Wires**: For making circuit connections.
- **Potentiometer**: For adjusting the LCD contrast (if necessary).

## Features
- Real-time display of temperature (in Celsius) and humidity (in percentage).
- Real-time clock functionality displaying hours and minutes.
- Simple and intuitive user interface using an LCD screen.
- Easy-to-follow wiring and coding instructions.

## Getting Started

### Prerequisites
- Arduino IDE installed on your computer.
- Basic knowledge of Arduino programming and circuit building.

### Libraries Required
Make sure to install the following libraries via the Arduino IDE Library Manager:
- `DHT sensor library`
- `RTClib`
- `LiquidCrystal_I2C` (or the appropriate library for your specific screen)

### Circuit Diagram
1. **DHT22 Sensor:**
   - VCC to Arduino 5V
   - GND to Arduino GND
   - Data to Arduino digital pin 2 (with a 10kΩ pull-up resistor to VCC)
2. **DS3231 RTC Module:**
   - SDA to Arduino SDA (pin 20)
   - SCL to Arduino SCL (pin 21)
   - VCC to Arduino 5V
   - GND to Arduino GND
3. **LCD Screen (16x2 with I2C):**
   - SDA to Arduino SDA (pin 20)
   - SCL to Arduino SCL (pin 21)
   - VCC to Arduino 5V
   - GND to Arduino GND
