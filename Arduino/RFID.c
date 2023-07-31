#include <SPI.h>
#include <MFRC522.h>

#define RST_PIN 9
#define SS_PIN 10

MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup() {
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println(); 
  pinMode(7,OUTPUT);
}

void loop() {
  digitalWrite(7,LOW);
  if(! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  Serial.print("UID tag :");
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }
  digitalWrite(7,HIGH);
  delay(1000);
  Serial.println();
  
}