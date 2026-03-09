Hardware Design
This folder contains all the hardware development files for the Morse Code Temperature Encoder, designed using Altium Designer.

Technical Specifications
The PCB was designed to be a standalone shield/board based on the ATmega328P microcontroller, focused on precision sensing and signal conditioning.

1. Signal Conditioning (PT100 Sensor)
To accurately measure ambient temperature, a PT100 (RTD) sensor was used. Since the resistance variation of a PT100 is very small, the following was implemented:
  - Wheatstone Bridge: Used to convert resistance changes into a measurable voltage differential.
  - ADC Stability: A 100nF decoupling capacitor was placed close to the microcontroller's analog input to filter high-frequency noise and stabilize readings.
2. Power & Protection
  - Integrated USB-to-TTL: The board includes a dedicated section for USB communication, providing both power ($5$V) and data interface.
  - Circuit Protection: A PTC Resettable Fuse (MiniSMDC050F) was added to protect the USB port and the microcontroller from overcurrent.
  - Filtering: A combination of $10$µF electrolytic and $100$nF ceramic capacitors ensures a clean power rail for the MCU.
3. Components & I/O
  - Buzzer: MP-ABI-050-RC electro-mechanical buzzer.
      - Design Note: Selected specifically for its low current draw ($30$mA), allowing it to be driven directly by the ATmega328P I/O pin (max $40$mA) without needing an external transistor.
  - Visual Output: High-brightness Red LED for Morse signaling and a Yellow LED for system status/debugging.
  - User Interface: Two tactile switches for real-time BPS (Bits Per Second) adjustment.

📂 Folder Content

  - /Altium_Project: Native .PrjPcb, .SchDoc, and .PcbDoc files.
  - /Schematics: PDF version of the full circuit schematic.
  - /Gerber: Manufacturing files (RS-274X) for PCB production.
  - /BOM: Bill of Materials with specific Farnell/Mouser part numbers.
  
🖼 Preview
