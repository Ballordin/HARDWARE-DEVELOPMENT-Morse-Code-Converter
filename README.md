Temperature to Morse Code Encoder

A professional embedded systems project developed for the Laboratory of Hardware Development (UTeSP - Sistemas Eletrónicos e Computadores). This device monitors ambient temperature using a PT100 sensor and encodes the data into Morse Code, delivered via audio (Buzzer) and visual (LED) signals.

🚀 Project Overview

The system features two primary modes of operation, controlled via a TTL serial interface:
Mode 1 (Standard): Real-time temperature monitoring and encoding.
Mode 2 (Manual): Interruption of sensor reading to encode user-provided strings/characters received via UART.

Key Features & Commands
  - Microcontroller: ATmega328P (Running at 8MHz).
  - Baud Rate: 9600 bps (standard) / 115200 bps (high speed).
  - Interactive Commands:
      - '!' : Toggle output between LED and Buzzer.
      - '#' : Toggle between Temperature mode and Manual String mode.
      - '+' / '-' : Increment or decrement the Buzzer tone frequency (PWM).
  - Physical Interface: Two buttons to adjust the Morse transmission speed (BPS).

🛠 Hardware Design (Altium Designer)

The hardware focuses on signal integrity and cost-optimization.
  - Signal Conditioning: PT100 RTD integrated into a Wheatstone bridge for precise analog-to-digital conversion.
  - Buzzer: MP-ABI-050-RC (Low-power, 30mA), driven directly by the MCU.
  - Power & Protection: * Integrated USB-to-TTL conversion for power and data.
      - PTC Resettable fuse and decoupling capacitors (10µF and 100nF) for ADC stability and noise filtering.
      - Strategic use of SMD components for high-frequency performance and reliability.

💻 Firmware (Embedded C)

The software follows a modular architecture for better maintainability:
  - UART Driver: Custom asynchronous communication handler for serial commands.
  - GPIO & Morse Engine: Optimized dictionary for alphanumeric translation into timed Dot (200ms) and Dash (600ms) sequences.
  - PWM Control: Used for dynamic frequency adjustment of the audio output.
  - Interrupt Handling: Real-time UART RX processing to ensure no characters are lost during transmission.

📂 Repository Structure


  - /firmware: C source code, header files, and Atmel Studio project files.
  - /hardware: Altium Designer schematics, PCB layout, and manufacturing Gerbers.
  - /docs: Technical reports, market studies, and project planning.

👥 Author
  - Tiago Oliveira (25547)

Institution: IPCA - Escola Técnica Superior Profissional (2023/2024)

---------------------------------------------------------------------------------
Developed as part of the Laboratory of Hardware Development Course.
---------------------------------------------------------------------------------
