```cpp
#include <Wire.h>
#include <LiquidCrystal_I2C.h>

const int pinTrig = 9;
const int pinEcho = 10;
const int pinBuzzer = 8;
const int pinLedMerah = 6;
const int pinLedHijau = 5;
const int pinRelay = 7;
const int pinLDR = A0;

int batasJarak = 40;
unsigned long durasiTunggu = 10000;
int batasGelap = 300;

unsigned long waktuMulaiDeteksi = 0;
bool sedangMenghitung = false;
unsigned long waktuMasukAman = 0;
bool modeAmanAktif = false;

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEcho, INPUT);
  pinMode(pinBuzzer, OUTPUT);
  pinMode(pinLedMerah, OUTPUT);
  pinMode(pinLedHijau, OUTPUT);
  pinMode(pinRelay, OUTPUT);
  pinMode(pinLDR, INPUT);

  Serial.begin(9600);

  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0);
  lcd.print("SYSTEM READY...");
  delay(1000);
  lcd.clear();
}

void loop() {
  long duration;
  int jarak;

  digitalWrite(pinTrig, LOW);
  delayMicroseconds(2);
  digitalWrite(pinTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinTrig, LOW);

  duration = pulseIn(pinEcho, HIGH);
  jarak = duration * 0.034 / 2;
  if (jarak == 0) jarak = 200;

  int nilaiCahaya = analogRead(pinLDR);

  Serial.print("Cahaya: ");
  Serial.print(nilaiCahaya);

  if (nilaiCahaya > batasGelap) {
    digitalWrite(pinRelay, HIGH);
    Serial.println(" -> GELAP (Lampu ON)");
  } else {
    digitalWrite(pinRelay, LOW);
    Serial.println(" -> TERANG (Lampu OFF)");
  }

  if (jarak < batasJarak) {
    modeAmanAktif = false;

    if (!sedangMenghitung) {
      waktuMulaiDeteksi = millis();
      sedangMenghitung = true;
    }

    unsigned long selisihWaktu = millis() - waktuMulaiDeteksi;

    if (selisihWaktu >= durasiTunggu) {
      digitalWrite(pinLedHijau, LOW);

      digitalWrite(pinLedMerah, HIGH);
      tone(pinBuzzer, 2000);
      delay(80);
      digitalWrite(pinLedMerah, LOW);
      noTone(pinBuzzer);
      delay(80);

      lcd.setCursor(0, 0);
      lcd.print("!! BAHAYA !!    ");
      lcd.setCursor(0, 1);
      lcd.print("MOHON MUNDUR... ");
    } else {
      digitalWrite(pinLedMerah, LOW);
      digitalWrite(pinLedHijau, LOW);
      noTone(pinBuzzer);

      lcd.setCursor(0, 0);
      lcd.print("Mendeteksi...   ");

      int sisaWaktu = (durasiTunggu - selisihWaktu) / 1000;
      lcd.setCursor(0, 1);
      lcd.print("Alarm dlm: ");
      lcd.print(sisaWaktu + 1);
      lcd.print("s    ");
    }
  } else {
    sedangMenghitung = false;
    digitalWrite(pinLedMerah, LOW);
    noTone(pinBuzzer);

    if (!modeAmanAktif) {
      waktuMasukAman = millis();
      modeAmanAktif = true;
    }

    if (millis() - waktuMasukAman < 3000) {
      digitalWrite(pinLedHijau, HIGH);
    } else {
      digitalWrite(pinLedHijau, LOW);
    }

    lcd.setCursor(0, 0);
    lcd.print("JARAK AMAN: ");
    lcd.print(jarak);
    lcd.print("cm  ");

    lcd.setCursor(0, 1);
    if (nilaiCahaya > batasGelap) {
      lcd.print("LMP:ON (GELAP)  ");
    } else {
      lcd.print("LMP:OFF (TERANG)");
    }
  }
}
```
