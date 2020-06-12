// make sure you have the libraries installed
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>

#define SS_PIN 53
#define RST_PIN 49
#define red 7
#define green 6
#define blue 5
#define bot 9     // this is the button

Servo myservo;    //create a servo object
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
      Serial.println();
      mfrc522.PICC_HaltA();
    }

    if(mfrc522.uid.uidByte[0] == 186){    //these numbers only work with my cards, these are the UID                                     
      if(mfrc522.uid.uidByte[1] == 0) {   //you have to write a program to get them
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
    if(mfrc522.uid.uidByte[0] == 185) {     //these numbers only work with my cards, these are the UID
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
