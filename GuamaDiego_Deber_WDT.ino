/*
 * ************* UNIVERSIDAD TÉCNICA DEL NORTE******************
 * -------------- SISTEMAS MICROPROCESADOS-------------------
 * NOMBRE: DIEGO GUAMÀ
 * TAREA: Realizar un programa que reinicie el sistema al tener la hora 00:10:50. Cuando vuelva a funcionar, deberá empezar con la hora 00:11:10. Es proceso se observa en una LCD
 */
#include <EEPROM.h>
#include<avr/wdt.h>
#include <MsTimer2.h>
#include <LiquidCrystal.h>
LiquidCrystal lcd(13, 12, 11, 10, 9, 8);
int segundero = 10;
int minutero = 11;
int horero;
int segundero2;
int minutero2;
void setup()
{
  //      EEPROM.write(0, 0);
  //      EEPROM.write(1, 0);
  //      EEPROM.write(2, 0);
  Serial.begin(9600);
  MsTimer2::set(100, reloj);
  MsTimer2::start();
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO");
  delay(500);
  lcd.clear();
}

void loop()
{

}

void reloj() {

  if (EEPROM.read(0) == 0) { // Posición para que la hora del reloj a la que empieza

    horero;
    if (segundero2 < 60) {
      segundero2++;
      lcd.setCursor(0, 0);
      lcd.print("RELOJ");
      lcd.setCursor(0, 1);
      lcd.print(horero);
      lcd.setCursor(3, 1);
      lcd.print(':');
      lcd.setCursor(4, 1);
      lcd.print(minutero2);
      lcd.setCursor(6, 1);
      lcd.print(':');
      lcd.setCursor(7, 1);
      lcd.println(segundero2);
    }
    else {
      segundero2 = 0;
      if (minutero2 < 60) {
        minutero2++;
      }
      else {
        minutero2 = 0;
        if (horero < 12) {
          horero++;
        }
        else {
          horero = 0;
        }
      }
    }
    if (minutero2 == 10) {
      EEPROM.update(1, 1); // Se actualiza la posición para usarla en WDT 
      if (segundero2 == 50 && EEPROM.read(1) == 1) { 
        EEPROM.update(2, 1); // Se actualiza la posición para usarla en WDT 
        if (EEPROM.read(1) == 1 && EEPROM.read(2) == 1) {
          EEPROM.update(0, 1); // Se utiliza para el reinicio del sistema y que empiece con la siguiente secuencia
          wdt_enable(WDTO_1S);
        }
      }
    }

  } else if (EEPROM.read(0) == 1)  { // Posición para que la hora del reloj a la que empieza

    if (segundero < 60) {

      segundero++;
      lcd.setCursor(0, 0);
      lcd.print("RELOJ");
      lcd.setCursor(0, 1);
      lcd.print(horero);
      lcd.setCursor(3, 1);
      lcd.print(':');
      lcd.setCursor(4, 1);
      lcd.print(minutero);
      lcd.setCursor(6, 1);
      lcd.print(':');
      lcd.setCursor(7, 1);
      lcd.println(segundero);
    }
    else {
      segundero = 0;
      if (minutero < 60) {
        minutero++;
      }
      else {
        minutero = 0;
        if (horero < 12) {
          horero++;
        }
        else {
          horero = 0;
        }
      }
    }
    if (minutero == 59) {
      EEPROM.update(1, 0);
      if (segundero == 0 && EEPROM.read(1) == 0) {
        EEPROM.update(2, 0);
        if (EEPROM.read(1) == 0 && EEPROM.read(2) == 0) {
          EEPROM.update(0, 0);  // Se utiliza para el reinicio del sistema y que empiece con la siguiente secuencia
          wdt_enable(WDTO_500MS);
        }
      }
    }

  }
}

