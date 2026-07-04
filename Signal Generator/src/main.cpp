#include <Arduino.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x38, 20, 4);

const int D9 = 9;
const int D10 = 10;
const int D11 = 11;
const int D12 = 12;

const int UP = 2;
const int DOWN = 3;

int counter = 0;
int direction = 1; // 1 for up, -1 for down
void up_counter();
void down_counter();
void DC_MODE();
void Triangle_MODE();
void lcd_display();
void writeDAC(int value);   
void setup() {
    pinMode(UP, INPUT_PULLUP);
    pinMode(DOWN, INPUT_PULLUP);

    pinMode(D9, OUTPUT);
    pinMode(D10, OUTPUT);
    pinMode(D11, OUTPUT);
    pinMode(D12, OUTPUT);
    lcd.init();
    lcd.backlight();
}

void loop() {

    Triangle_MODE();
}

void up_counter() {
    if (counter < 15)
        counter++;
}

void down_counter() {
    if (counter > 0)
        counter--;
}
void lcd_display() {
    lcd.setCursor(0, 0);
    lcd.print("4Bit DC Signal Generator");
    lcd.setCursor(0, 1);
    int temp = counter;
    double out_voltage = (double)(temp * 5.0) / 15.0;
    lcd.print("Voltage: ");
    lcd.print(out_voltage, 2);
    lcd.print(" V");
}
void DC_MODE() {
    if (digitalRead(UP) == LOW) {
        up_counter();
        delay(200);       // debounce
    }

    if (digitalRead(DOWN) == LOW) {
        down_counter();
        delay(200);       // debounce
    }

    digitalWrite(D9, counter & 0x01);
    digitalWrite(D10, (counter >> 1) & 0x01);
    digitalWrite(D11, (counter >> 2) & 0x01);
    digitalWrite(D12, (counter >> 3) & 0x01);
}
void writeDAC(int value) {
    digitalWrite(D9, value & 0x01);
    digitalWrite(D10, (value >> 1) & 0x01);
    digitalWrite(D11, (value >> 2) & 0x01);
    digitalWrite(D12, (value >> 3) & 0x01);
}
void Triangle_MODE() {
    counter += direction;

    if (counter >= 15) direction = -1;
    if (counter <= 0)  direction = 1;

    writeDAC(counter);

    delayMicroseconds(100);  // controls frequency
}
void Square_MODE() {
    counter += direction;

    if (counter >= 15) direction = -1;
    if (counter <= 0)  direction = 1;

    writeDAC(counter);

    delayMicroseconds(100);  // controls frequency
}
void Sine_MODE() {
    
}