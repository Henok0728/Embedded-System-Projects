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

void up_counter();
void down_counter();
void lcd_display();
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
    lcd_display();
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
    lcd.print("Digtal voltage display");
    lcd.setCursor(0, 1);
    int temp = counter;
    double out_voltage = (double)(temp * 5.0) / 15.0 * 5.0;
    lcd.print("Voltage: ");
    lcd.print(out_voltage, 2);
    lcd.print(" V");
}