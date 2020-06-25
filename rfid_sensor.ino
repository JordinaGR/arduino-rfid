// make sure you have the libraries installed
#include <SPI.h>
#include <MFRC522.h>
#include <Servo.h>
#include <LiquidCrystal.h>

#define SS_PIN 53
#define RST_PIN 49
#define red 7
#define green 6
#define blue 5
#define bot 8     // this is the button

// create lcd object
const int rs = 45, en = 44, d4 = 43, d5 = 42, d6 = 41, d7 = 40;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

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
  myservo.attach(4);
  myservo.write(0);
  lcd.begin(16, 2);
  analogWrite(2,50);
}


void loop(){
  if(mfrc522.PICC_IsNewCardPresent()){
    if(mfrc522.PICC_ReadCardSerial()){
      Serial.print("Tag UID:");
      Serial.println();
      mfrc522.PICC_HaltA();
    }

    if(mfrc522.uid.uidByte[0] == 186){
      if(mfrc522.uid.uidByte[1] == 0) {
        if(mfrc522.uid.uidByte[2] == 207) {
          if(mfrc522.uid.uidByte[3] == 129) {
            lcd.clear();
            digitalWrite(red, HIGH);
            delay(100);
            lcd.print("wrong key!!!");
            lcd.setCursor(0,1);
            lcd.print("GET OUT OF HERE");
            delay(3000);
            digitalWrite(red, LOW);
            lcd.clear();
            delay(1000);
            lcd.setCursor(0,0);
            lcd.clear();
          }
        }
      }
    } 
    if(mfrc522.uid.uidByte[0] == 185) {
      if(mfrc522.uid.uidByte[1] == 111) {
        if(mfrc522.uid.uidByte[2] == 228) {
          if(mfrc522.uid.uidByte[3] == 178){
            lcd.clear();
            digitalWrite(green, HIGH);
            delay(100);
            lcd.clear();
            delay(100);
            lcd.setCursor(0,0);
            delay(100);
            lcd.print("Access granted");
            lcd.setCursor(4,1);
            delay(100);
            lcd.print("GET IN");
            delay(1000);
            digitalWrite(blue, HIGH);
            myservo.write(180);
            delay(5000);
            myservo.write(0);
            digitalWrite(blue, LOW);
            delay(1000);
            digitalWrite(green, LOW);
            delay(1000);
            lcd.clear();
          }
        }
      }
    }
  }
  if(digitalRead(bot) == HIGH){
    lcd.clear();
    digitalWrite(green, HIGH);
    lcd.setCursor(1,0);
    delay(100);
    lcd.print("close the door");
    delay(100);
    lcd.setCursor(4,1);
    lcd.print("SEE YOU!");
    delay(1000);
    myservo.write(180);
    digitalWrite(blue, HIGH);
    delay(5000);
    myservo.write(0);
    digitalWrite(blue, LOW);
    delay(1000);
    digitalWrite(green, LOW);
    delay(1000);
    lcd.clear();
  }
}
