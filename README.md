# Temperature to Morse Code Encoder

A professional embedded systems project developed for the **Laboratory of Hardware Development** (UTeSP - Sistemas Eletrónicos e Computadores). This device monitors ambient temperature using a PT100 sensor and encodes the data into Morse Code, delivered via audio (Buzzer) and visual (LED) signals.

## 🚀 Project Overview
The system features two primary modes of operation, controlled via a TTL serial interface:
- **Mode 1 (Standard):** Real-time temperature monitoring and encoding.
- **Mode 2 (Manual):** Interruption of sensor reading to encode user-provided strings/characters received via UART into Morse Code.

### Key Requirements
- **Microcontroller:** ATmega328P.
- **Communication:** UART at 115200 bps.
- **User Interface:** Two physical buttons to increment/decrement signal BPS (bits per second).
- **Audio Control:** Configurable sound frequency via software commands.

## 🛠 Hardware Design (Altium Designer)
The hardware was designed with a focus on cost-optimization and electrical stability.
- [cite_start]**Sensor:** PT100 RTD integrated into a Wheatstone bridge for precise temperature measurement[cite: 551].
- **Indicators:** - Red LED (Morse output)
  - [cite_start]Yellow LED (Status/Debug)[cite: 524].
- [cite_start]**Sound:** MP-ABI-050-RC Electro-mechanical Buzzer (selected for its low current draw of 30mA, allowing direct connection to the MCU)[cite: 63].
- **Power & Protection:** - Integrated USB-to-TTL conversion for power and data.
  - [cite_start]Decoupling capacitors (10µF and 100nF) for ADC stability and high-frequency noise filtering[cite: 1082, 1083].
  - [cite_start]SMD components utilized for high-frequency performance and reliability[cite: 527].


## 💻 Firmware (Embedded C)
The software was developed using a modular approach in Embedded C, focusing on hardware abstraction and efficient interrupt handling.
- [cite_start]**UART Library:** Custom driver for asynchronous serial communication at 115200 bps[cite: 528].
- [cite_start]**ADC Driver:** Handles the conversion of analog signals from the PT100 bridge[cite: 305].
- [cite_start]**PWM Control:** Utilized for adjusting the frequency of the Morse "beeps" on the buzzer[cite: 331].
- [cite_start]**Morse Logic:** Algorithmic translation of alphanumeric characters into timed dot/dash sequences[cite: 235].

## 📂 Project Structure
- [cite_start]`G5_25547_25548.pdf`: Comprehensive final technical report[cite: 445].
- [cite_start]`Problem Statement`: Initial functional and non-functional requirements[cite: 536].
- [cite_start]`Analysis & Design`: Market study of components and theoretical foundations.

## 👥 Authors
- **Tiago Oliveira** (25547)
- **Rodrigo Pinto** (25548)
- [cite_start]**Institution:** IPCA - Escola Técnica Superior Profissional[cite: 444, 452, 453].

---
*Developed as part of the Laboratory of Hardware Development Course, 2023/2024.*
