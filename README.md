# Project Title
Bluetooth-Based FOTA System for ATmega128 Temperature Controller
![Bluetooth-Based FOTA System](images/full.png)

## Project Description:
This project implements a Firmware Over-The-Air (FOTA) update system for an Automatic Temperature Controller using Bluetooth communication between an Android app and an ATmega128 microcontroller.

The system reads temperature values and compares them with a user-defined reference:
1. If actual temperature < reference, it activates the heater.
2. If actual temperature > reference, it activates the cooler.
![Bluetooth-Based FOTA System](images/project.png)
## Technologies Used
### Hardware:
1. ATmega128
2. HC-05 Bluetooth Module
3. Temperature sensor (LM35)
4. LCD + Keypad for interface

### Software:
