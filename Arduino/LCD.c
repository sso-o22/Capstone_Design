#include <LiquidCrystal.h>
#include <SoftwareSerial.h> 
#include <SPI.h>            //rfid
#include <MFRC522.h>        //rfid
LiquidCrystal lcd(2,3,4,6,7,8);
#define RST_PIN 5
#define SS_PIN 53

MFRC522 mfrc522(SS_PIN, RST_PIN);
const int ext_rfid=9;
int ext_rfid_value=0;
int last_count_fsr=0;
int fsr[4]={0,0,0,0};
int count=0;
int last_count=0;
int recent_count=0;
int count_fsr=0;


void setup() {
  pinMode(ext_rfid,INPUT);
  pinMode(10,INPUT);
  pinMode(11,INPUT);
  pinMode(12,INPUT);
  pinMode(13,INPUT);
  pinMode(48,INPUT);
  Serial.begin(9600);
  lcd.begin(16,2);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("Approximate your card to the reader...");
  Serial.println();
  lcd.setCursor(0,0);
  lcd.print(" empty seat:   ");
}

void ent_rfid()
{
  last_count=0;
  if(! mfrc522.PICC_IsNewCardPresent())
  {
    return;
  }
  if( ! mfrc522.PICC_ReadCardSerial())
  {
    return;
  }
  /*
  recent_count=1;
  if(last_count!=recent_count)
  {
    last_count=1;
    if(recent_count==1) count++;
  }*/
  /*
  Serial.print("UID tag :");
  for (byte i = 0; i < mfrc522.uid.size; i++)
  {
    Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    Serial.print(mfrc522.uid.uidByte[i], HEX);
  }*/
  count++;
 // Serial.println();
  delay(1000);
}

void loop() {

  count_fsr=0;

  fsr[0] = digitalRead(10); if(fsr[0]==1){delay(1); count_fsr++;}
  fsr[1] = digitalRead(11); if(fsr[1]==1){delay(1); count_fsr++;}
  fsr[2] = digitalRead(12); if(fsr[2]==1){delay(1); count_fsr++;}
  fsr[3] = digitalRead(13); if(fsr[3]==1){delay(1); count_fsr++;}
  int xx = digitalRead(48);

  lcd.setCursor(0,0);
  lcd.print(" empty seat:   ");
  
  if( xx == 1)
  {
    lcd.setCursor(13,0);
    lcd.print(6);
  }
  else if( xx == 0)
  {
  lcd.setCursor(13,0);
  lcd.print(10-count_fsr);
  }

  ent_rfid();
  ext_rfid_value=digitalRead(ext_rfid);
  if(ext_rfid_value==1)
  {
    count--;
    delay(1000);
    if(count<0) count=0;    //0보다 작은 값은 0으로
  }
  ent_rfid();
  if(count>=12)
  {
    lcd.setCursor(6,1);
    lcd.print("full  ");
  }
    
  else if(count>=8)
  {
    lcd.setCursor(6,1);
    lcd.print("normal");
  }
  else
  {
    lcd.setCursor(6,1);
    lcd.print("free  ");
  }
  lcd.setCursor(12,1);
  lcd.print("     ");
  lcd.setCursor(13,1);
  lcd.print(count);
  Serial.print(fsr[0]);Serial.print("  ");
  Serial.print(fsr[1]);Serial.print("  ");
  Serial.print(fsr[2]);Serial.print("  ");
  Serial.println(fsr[3]);
}