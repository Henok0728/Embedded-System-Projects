#include <SPI.h>
#include <MFRC522.h>

class rfid {
  private:
    MFRC522 rf;

  public:
    rfid(byte SS_PIN, byte RST_PIN) : rf(SS_PIN, RST_PIN) {}

    void init() {
      SPI.begin();
      rf.PCD_Init();
    }

    String getUid() {
      if (!rf.PICC_IsNewCardPresent()) return "";
      if (!rf.PICC_ReadCardSerial()) return "";

      String uid = "";
      for (byte i = 0; i < rf.uid.size; i++) {
        if (rf.uid.uidByte[i] < 0x10) uid += "0";
        uid += String(rf.uid.uidByte[i], HEX);
      }
      uid.toUpperCase();

      rf.PICC_HaltA();
      rf.PCD_StopCrypto1();

      return uid;
    }

    bool authenticate(String uid) {
      String allowed[] = {"D5498005", "A0D7BB32"};
      int size = sizeof(allowed) / sizeof(allowed[0]);

      for (int i = 0; i < size; i++) {
        if (allowed[i].equals(uid)) {
          return true;
        }
      }
      return false;
    }

    void sendToJava(String uid) {
      Serial.println("RFID_SCAN:" + uid);
    }
    void implementation(){
       String uid = getUid();
  if (uid != "") {
        Serial.println("UID: " + uid);

        if (authenticate(uid)) {
          Serial.println("AUTHORIZED");
        } else {
          Serial.println("DENIED");
        }

        sendToJava(uid);
        delay(2000);
      }
    }
};

#define SS_PIN 10
#define RST_PIN 9

rfid RFID(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  RFID.init();
  Serial.println("SCAN RFID CARD...");
}

void loop() {
   RFID.implementation();
}
