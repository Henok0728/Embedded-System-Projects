# 🔌 4-Bit Digital Voltage Generator

A **4-bit Digital-to-Analog Converter (DAC)** built using an **Arduino Nano**, an **R-2R resistor ladder**, and a **20×4 I2C LCD**. The system generates **16 discrete analog voltage levels (0–15)** from digital inputs and displays the selected binary value, decimal value, and output voltage in real time.

---

## 🎥 Demo

<p align="center">
 <img src="https://raw.githubusercontent.com/Henok0728/Embedded-System-Projects/main/4Bit%20DC%20Signal%20Generator/images/converter.gif" width="700" alt="4-Bit Digital Voltage Generator Demo">
</p>

---

## ✨ Features

- Generates **16 discrete analog voltage levels**
- Implements a **4-bit R-2R resistor ladder DAC**
- Push-button interface for incrementing and decrementing the output value
- Real-time display on a **20×4 I2C LCD**
- Displays:
  - Binary value
  - Decimal value
  - Analog output voltage
- Simple, low-cost hardware design
- Easily expandable to higher DAC resolutions (8-bit, 10-bit, etc.)

---

## 🛠 Hardware Used

- Arduino Nano
- 20×4 I2C LCD
- R-2R resistor ladder
- Push buttons
- 10 kΩ and 20 kΩ resistors
- Breadboard
- Jumper wires
- USB cable / 5 V power supply

---

## ⚙️ How It Works

The Arduino outputs a **4-bit binary number** through four digital output pins connected to an **R-2R resistor ladder**. The resistor ladder converts the digital signal into a proportional analog voltage.

Two push buttons allow the user to:

- Increase the digital value
- Decrease the digital value

The LCD continuously displays:

- Binary output
- Decimal value
- Approximate analog output voltage

---

## 📂 Main Project Structure

```text
.
├── .pio/build/
│ 
├── include/
│   
├── images/
│   ├── converter.gif
│ 
├── src/
│   └── main.cpp
├── README.md
├── .gitignore
├── 4Bit DC Signal Generator/src/Embedded-System-Projects.code-workspace
```

---

## 🚀 Getting Started

1. Clone the repository.

```bash
git clone git clone https://github.com/Henok0728/Embedded-System-Projects.git
```

2. Open the project in the Arduino IDE.
3. Install the required libraries.
4. Upload the sketch to the Arduino Nano.
5. Assemble the hardware according to the circuit diagram.
6. Power the circuit and begin generating output voltages.

## 📈 Future Improvements

- 8-bit or higher-resolution DAC
- Rotary encoder user interface
- Adjustable reference voltage
- Buffered op-amp output stage
- Serial interface for PC control
- Waveform generation (sine, square, triangle)

---

## 👤 Author

**Henok**

If you found this project useful, consider giving it a ⭐ on GitHub!
