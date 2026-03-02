// #include <Arduino.h>
// const int lm35Pin = A0;

// class outTemp{
//     private:
//         float voltage;
//         float tempc;
//         int adcValue;
//         int pin_m;
//     public:
//         outTemp(int pin): pin_m(pin){}
//         float getOutTemp(){
//             int adcValue = analogRead(lm35Pin);
//             float voltage = adcValue * (5.0 / 1023.0);  
//             float tempc = voltage * 100.0;  
//             return tempc; 


//         }
        
// };
// // /*
// //   This code reads the temperature and humidity values from a DHT11 sensor 
// //   connected to pin 2 and prints them to the serial monitor. 
// //   It also calculates and prints the heat index value in both Celsius and Fahrenheit.
  
// //   Board: Arduino Uno R4 (or R3)
// //   Component: Temperature and humidity module(DHT11)
// //   Library: https://github.com/adafruit/DHT-sensor-library  (DHT sensor library by Adafruit)
// // */

// // #include <DHT.h>

// // #define DHTPIN 2       // Define the pin used to connect the sensor
// // #define DHTTYPE DHT11  // Define the sensor type

// //   // Create a DHT object
// class internal_sensor{
//     private:
//         float temp;
//         float humidity;
//         uint8_t pin;
//         uint8_t type;
//         DHT dht;
//         float f = dht.readTemperature(true);


//     public:
//         internal_sensor( uint8_t dht_pin, uint8_t DHT_TYPE): 
//         pin(dht_pin),type(DHT_TYPE),
//         dht(dht_pin, DHT_TYPE) {}



//         void init(){
//                 dht.begin();

//             }
//         float getTemp(){
//             temp = dht.readTemperature();  
//             return temp;
//         }
//         float getHumdity(){
//             humidity = dht.readHumidity();
//             return humidity;
//         }

// };
// internal_sensor ht(DHTPIN,DHTTYPE);
// void setup() {
//   // Initialize the serial communication
//   Serial.begin(9600);
//   Serial.println(F("DHT11 test!"));
//   ht.init();

// }

// void loop() {
//   delay(2000);
//   Serial.println(ht.getTemp());
//   Serial.println(ht.getHumdity());

// }