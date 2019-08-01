#include <TimerOne.h>

#include <avr/power.h>
#include <avr/sleep.h>
#include <avr/wdt.h>
#include <EEPROM.h>

int dato;
int valor;
String datos;
int led = 5;
int pulsador = 3;

void setup() {

  EEPROM.write(0, 0);
  EEPROM.write(1, 0);
  EEPROM.write(2, 0);
  Serial.begin(9600);
  pinMode(5, OUTPUT);
  pinMode(3, INPUT);
  Serial.print("BIENVENIDO");

}

void loop() {

  if (Serial.available() > 0)
  {
    datos = Serial.readString();
    dato = datos.toInt();
    if (EEPROM.read(1) == 0) {
      valor = (analogRead(0) * 5) / 1023;
      Serial.println(valor);
      lcd.setCursor(0, 1);
      lcd.print("DATO 1");
      set_sleep_mode(SLEEP_MODE_STANDBY);
      sleep_enable();
      Serial.println("Me dormi :|");
      delay(20);
      EEPROM.update(0, valor);
      lcd.print(EEPROM.read(0));
      EEPROM.write(1, 1);
      wdt_enable(WDTO_2S);
    }
    if (EEPROM.read(1) == 1) {
      valor = (dato * 5) / 1023;
      lcd.setCursor(0, 0);
      lcd.print("DATO 2");
      EEPROM.update(2, valor);
      lcd.print(EEPROM.read(2));
      if (EEPROM.read(2) < EEPROM.read(0)) {
        EEPROM.update(0, EEPROM.read(2));
      }
      digitalWrite(5, HIGH);
      Serial.println(valor);
      sleep_disable();
      Serial.println("Me desperte :|");
      delay(20);
      if (pulsador == HIGH) {
        EEPROM.write(1, 0);
        wdt_enable(WDTO_2S);
      }
    }
  }
}
