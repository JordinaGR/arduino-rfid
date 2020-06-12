#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 53
#define RST_PIN 49
#define red 7
#define green 6
#define blue 5
#define bot 9

Servo myservo;
MFRC522 mfrc522(SS_PIN, RST_PIN);

void setup(){
  Serial.begin(9600);
  SPI.begin();
  mfrc522.PCD_Init();
  Serial.println("RFID reading UID");
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(bot, INPUT);
  myservo.attach(3);
  myservo.write(0);
}
void loop(){
    if(mfrc522.PICC_IsNewCardPresent()){
    if(mfrc522.PICC_ReadCardSerial()){
      Serial.print("Tag UID:");
      /*for (byte i = 0; i<mfrc522.uid.size; i++){
        Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
        Serial.print(mfrc522.uid.uidByte[i], HEX);
        }*/
        Serial.println();
        mfrc522.PICC_HaltA();
      
      }
      if(mfrc522.uid.uidByte[0] == 186){
        if(mfrc522.uid.uidByte[1] == 0) {
          if(mfrc522.uid.uidByte[2] == 207) {
            if(mfrc522.uid.uidByte[3] == 129) {
                digitalWrite(red, HIGH);
                delay(2000);
                digitalWrite(red, LOW);
                delay(1000);
              }
            }
          }
        } 
        if(mfrc522.uid.uidByte[0] == 185) {
          if(mfrc522.uid.uidByte[1] == 111) {
            if(mfrc522.uid.uidByte[2] == 228) {
              if(mfrc522.uid.uidByte[3] == 178){
                digitalWrite(green, HIGH);
                delay(1000);
                myservo.write(180);
                digitalWrite(blue, HIGH);
                delay(5000);
                myservo.write(0);
                digitalWrite(blue, LOW);
                delay(1000);
                digitalWrite(green, LOW);
                delay(1000);
              }
            }
          }
        }
        }
      if(digitalRead(bot) == HIGH){
        digitalWrite(green, HIGH);
        delay(1000);
        myservo.write(180);
        digitalWrite(blue, HIGH);
        delay(5000);
        myservo.write(0);
        digitalWrite(blue, LOW);
        delay(1000);
        digitalWrite(green, LOW);
        delay(1000);
      }
}
