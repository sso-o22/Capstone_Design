#include <SoftwareSerial.h>    

SoftwareSerial BTSerial(9, 10);  
int FSRsen0 = A0;
int FSRsen1 = A1;
int FSRsen2 = A2;
int FSRsen3 = A3;

int value[4];
int sensor0 = 0b0000;
int sensor1 = 0;
int sensor2 = 0;
int sensor3 = 0;
int sensor4 = 0;

int x =0;

int count=0;

void setup()
{
  Serial.begin(9600);
  pinMode(5,INPUT);
  pinMode(6,INPUT);
  pinMode(7,INPUT);
  pinMode(8,INPUT);
  pinMode(11,OUTPUT);
  pinMode(12,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(2,OUTPUT);
  BTSerial.begin(9600); 

}

void loop()
{

  value[0] = analogRead(FSRsen0);
  value[1] = analogRead(FSRsen1);
  value[2] = analogRead(FSRsen2);
  value[3] = analogRead(FSRsen3);

  Serial.print(value[0]); Serial.print("  ");
  Serial.print(value[1]); Serial.print("  ");
  Serial.print(value[2]); Serial.print("  ");
  Serial.println(value[3]);

  if(BTSerial.available())                     
  Serial.write(BTSerial.read());    
  
  int sens[4] = {0,0,0,0};
  long total_sens=0;
  for(int i=0;i<4;i++){sens[i]=0;}
  
  if(value[0]>7) 
  { 
    sens[0]=1;
    digitalWrite(3,HIGH);
  }
  else 
  { 
    sens[0]=0;
    digitalWrite(3,LOW);
  }
  if(value[1] >7)
  {
    sens[1]=2;
    digitalWrite(4,HIGH);
  }
  else 
  {
    sens[1] = 0;
    digitalWrite(4,LOW);
  }
  if(value[2]>7) 
  {
    sens[2]=4;
    digitalWrite(11,HIGH);
  }
  else 
  {
    sens[2] = 0;
    digitalWrite(11,LOW);
  }
  if(value[3]>7) 
  {
    sens[3]=8;
    digitalWrite(12,HIGH);
  }
  else 
  {
    sens[3] = 0;
    digitalWrite(12,LOW);
  }

  if(sens[0] == 1 && sens[1] == 2 && sens[2] == 4 && sens[3] == 8)
  {
    digitalWrite(2,HIGH);
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(11,LOW);
    digitalWrite(12,LOW);
  }
  else digitalWrite(2,LOW);

  if(digitalRead(6) == HIGH)
  x = 1;  
  else if(digitalRead(7) == HIGH)
  x = 2;
  else if(digitalRead(8) == HIGH)
  x = 4;
  else
  x = 0;
  
  total_sens=sens[0]+sens[1]+sens[2]+sens[3];
  
  if( x == 0 ){
  if(total_sens == 0 && x == 0)
  BTSerial.write("A");
  else if(total_sens == 1)
  BTSerial.write("B");
  else if(total_sens == 2)
  BTSerial.write("C");
  else if(total_sens == 3)
  BTSerial.write("D");
  else if(total_sens == 4)
  BTSerial.write("E");
  else if(total_sens == 5)
  BTSerial.write("F");
  else if(total_sens == 6)
  BTSerial.write("G");
  else if(total_sens == 7)
  BTSerial.write("H");
  else if(total_sens == 8)
  BTSerial.write("I");
  else if(total_sens == 9)
  BTSerial.write("J");
  else if(total_sens == 10)
  BTSerial.write("K");
  else if(total_sens == 11)
  BTSerial.write("L");
  else if(total_sens == 12)
  BTSerial.write("M");
  else if(total_sens == 13)
  BTSerial.write("N");
  else if(total_sens == 14)
  BTSerial.write("O");
  else if(total_sens == 15)
  BTSerial.write("P");
  }
  else if( x == 1){
  if(total_sens == 0)
  BTSerial.write("AQ");
  else if(total_sens == 1)
  BTSerial.write("BQ");
  else if(total_sens == 2)
  BTSerial.write("CQ");
  else if(total_sens == 3)
  BTSerial.write("DQ");
  else if(total_sens == 4)
  BTSerial.write("EQ");
  else if(total_sens == 5)
  BTSerial.write("FQ");
  else if(total_sens == 6)
  BTSerial.write("GQ");
  else if(total_sens == 7)
  BTSerial.write("HQ");
  else if(total_sens == 8)
  BTSerial.write("IQ");
  else if(total_sens == 9)
  BTSerial.write("JQ");
  else if(total_sens == 10)
  BTSerial.write("KQ");
  else if(total_sens == 11)
  BTSerial.write("LQ");
  else if(total_sens == 12)
  BTSerial.write("MQ");
  else if(total_sens == 13)
  BTSerial.write("NQ");
  else if(total_sens == 14)
  BTSerial.write("OQ");
  else if(total_sens == 15)
  BTSerial.write("PQ");
  }
  else if( x  == 2){
  if(total_sens == 0)
  BTSerial.write("AR");
  else if(total_sens == 1)
  BTSerial.write("BR");
  else if(total_sens == 2)
  BTSerial.write("CR");
  else if(total_sens == 3)
  BTSerial.write("DR");
  else if(total_sens == 4)
  BTSerial.write("ER");
  else if(total_sens == 5)
  BTSerial.write("FR");
  else if(total_sens == 6)
  BTSerial.write("GR");
  else if(total_sens == 7)
  BTSerial.write("HR");
  else if(total_sens == 8)
  BTSerial.write("IR");
  else if(total_sens == 9)
  BTSerial.write("JR");
  else if(total_sens == 10)
  BTSerial.write("KR");
  else if(total_sens == 11)
  BTSerial.write("LR");
  else if(total_sens == 12)
  BTSerial.write("MR");
  else if(total_sens == 13)
  BTSerial.write("NR");
  else if(total_sens == 14)
  BTSerial.write("OR");
  else if(total_sens == 15)
  BTSerial.write("PR");
  }
  else if( x == 4){
  if(total_sens == 0)
  BTSerial.write("AS");
  else if(total_sens == 1)
  BTSerial.write("BS");
  else if(total_sens == 2)
  BTSerial.write("CS");
  else if(total_sens == 3)
  BTSerial.write("DS");
  else if(total_sens == 4)
  BTSerial.write("ES");
  else if(total_sens == 5)
  BTSerial.write("FS");
  else if(total_sens == 6)
  BTSerial.write("GS");
  else if(total_sens == 7)
  BTSerial.write("HS");
  else if(total_sens == 8)
  BTSerial.write("IS");
  else if(total_sens == 9)
  BTSerial.write("JS");
  else if(total_sens == 10)
  BTSerial.write("KS");
  else if(total_sens == 11)
  BTSerial.write("LS");
  else if(total_sens == 12)
  BTSerial.write("MS");
  else if(total_sens == 13)
  BTSerial.write("NS");
  else if(total_sens == 14)
  BTSerial.write("OS");
  else if(total_sens == 15)
  BTSerial.write("PS");
  }
  delay(500);
}