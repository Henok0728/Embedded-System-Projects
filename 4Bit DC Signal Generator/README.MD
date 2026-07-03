# 🔌 4-Bit Digital Voltage Generator

A **4-bit Digital-to-Analog Converter (DAC)** built using an **Arduino Nano**, an **R-2R resistor ladder**, and a **20×4 I2C LCD**. This project generates **16 discrete analog voltage levels (0–15V)** with a user-friendly push-button interface.

---

## 🎥 Demo

<p align="center">
  <img src="images/converter.gif" width="700" alt="4-Bit Digital Voltage Generator Demo">
</p>

---

## ✨ Features

- 4-bit Digital-to-Analog Converter (DAC)
- 16 discrete analog voltage levels
- R-2R resistor ladder implementation
- Push-button interface for increasing and decreasing the output value
- Real-time voltage display on a 20×4 I2C LCD
- Displays:
  - Binary value
  - Decimal value
  - Output voltage
- Built with inexpensive and readily available components
- Easily expandable to 8-bit or higher DAC resolution

---

## 🛠 Hardware Used

- Arduino Nano
- 20×4 I2C LCD (I2C Interface)
- R-2R resistor ladder
- 2 × Push buttons
- 10 kΩ resistors
- 20 kΩ resistors
- Breadboard
- Jumper wires
- USB cable / 5 V power supply

---

## ⚙️ How It Works

The Arduino Nano outputs a 4-bit binary value through four digital output pins connected to an R-2R resistor ladder. The resistor ladder converts the digital value into a proportional analog voltage.

Two push buttons are used to:

- Increase the digital value
- Decrease the digital value

The LCD continuously displays:

- Binary output
- Decimal value
- Approximate analog output voltage

---

## 📂 Project Structure

```text
4Bit DC Signal Generator/
│
├── images/
│   └── converter.gif
│
├── include/
│
├── src/
│   └── main.cpp
│
├── platformio.ini
├── README.MD
└── .gitignore
```

---

## 🚀 Getting Started

### 1. Clone the repository

```bash
git clone https://github.com/Henok0728/Embedded-System-Projects.git
```

### 2. Open the project

Open the **4Bit DC Signal Generator** folder using **Visual Studio Code** with the **PlatformIO** extension installed.

### 3. Build and Upload

- Connect the Arduino Nano.
- Click **Build** in PlatformIO.
- Click **Upload** to flash the firmware.

### 4. Assemble the Hardware

Connect the Arduino, R-2R resistor ladder, push buttons, and LCD according to your circuit.

### 5. Run the Project

Power the Arduino. Use the push buttons to change the digital value and observe the corresponding analog voltage on the output and LCD.

---

## 📈 Future Improvements

- 8-bit DAC implementation
- Rotary encoder interface
- Adjustable reference voltage
- Buffered op-amp output stage
- Serial control from a PC
- Waveform generation (sine, square, and triangle)
- PCB design

---

## 📚 What I Learned

This project helped me gain practical experience with:

- Digital-to-Analog Conversion (DAC)
- R-2R resistor ladder design
- Arduino digital I/O
- LCD interfacing over I2C
- Embedded programming using PlatformIO
- Basic analog electronics

---

## 👤 Author

**Henok**

Electrical & Computer Engineering Student

GitHub: https://github.com/Henok0728

---

## ⭐ Support

If you found this project useful, please consider giving the repository a ⭐ on GitHub. It helps others discover the project and motivates future development.

---

## 📄 License

This project is licensed under the MIT License.
