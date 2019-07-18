/*
 * **************** UNIVERSIDAD TÉCNICA DEL NORTE*******************
   ------------------ SISTEMAS MICROPROCESADOS ---------------------
   Nombre: Diego Guamá
   Carrera: Ingeniería en Electrónica y Redes de Comunicación
   Actividad: Realizar un sistema reloj con alarma almacenada en la EEPROM.
*/
#include <MsTimer2.h>
#include <EEPROM.h>
#include <LiquidCrystal.h>
//LCD para verificar el reloj del sistema
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
String hing;
String ming;
int Hing;
int Ming;
int segundero; 
int minutero;
int horero;
int act = 0;
int on = 0;
void setup() {
  //Se da los valores de una posicion de la memoria EEPROM del arduino a cada componente del reloj en este caso:
  //Segundos, minutos y horas, Horas de comparacion y minutos de comparacion para 
  //verificar los datos ingresados por comunicacion serial
  segundero = EEPROM.read(0);
  minutero = EEPROM.read(1);
  horero = EEPROM.read(2);
  Hing = EEPROM.read(3);
  Ming = EEPROM.read(4);
  Serial.begin(9600);
  MsTimer2::set(500, reloj);
  MsTimer2::start();
  pinMode(7, OUTPUT);
  pinMode(6, OUTPUT);
  attachInterrupt(0, seleccion, LOW);
  attachInterrupt(1, alarma, LOW);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO");
}
void loop() {
  if (on == 1) {
    if (Serial.available() > 0) {
      hing = Serial.readString();
      Hing = hing.toInt();
      EEPROM.update(3, Hing);
    }
  }
  if (on == 0) {
    if (Serial.available() > 0) {
      ming = Serial.readString();
      Ming = ming.toInt();
      EEPROM.update(4, Ming);
    }
  }
  if (act == 1) {
    //Se compara si los datos ingresados de horas y minutos para activar la alarma son iguales con los
    //del reloj del sistema al ser iguales la alarma se enciende, caso contrario esta se apaga
    if ((horero == Hing) && (minutero == Ming)) {
      digitalWrite (7, HIGH);
      digitalWrite (6, HIGH);
      delay (500);
    } else {
      digitalWrite (7, LOW);
      digitalWrite (6, LOW);
      delay (500);
    }
  }
  if (act == 0) {
    digitalWrite (7, LOW);
    digitalWrite (6, LOW);
    delay (500);
  }
}
void seleccion() {
  on = 1 - on;
  if (on == 1) {
    //Ingreso de horas y minutos a activar la alarma
    Serial.println("Ingrese Hora a encender la alarma");

  } else if (on == 0) {
    Serial.println("Ingrese minutos a encender la alarma");
  }
}
void alarma() {
  act = 1 - act;
  if (act == 1) {
    Serial.println("La alarma ha sido activada");
  } else {
    if (act == 0) {
      Serial.println("La alarma ha sido apagada");
    }
  }
}
void reloj() {
  if (segundero < 60) {
    segundero++;
    tiempo();
    EEPROM.write(0, segundero);// Se almacenan los nuevos valores de los segundos en la posicion designada
  }
  else {
    segundero = 0;
    if (minutero < 60) {
      minutero++;
      tiempo();
      EEPROM.write(1, minutero);// Se almacenan los nuevos valores de los minutos en la posicion designada
    }
    else {
      minutero = 0;
      if (horero < 1) {
        horero++;
        tiempo();
        EEPROM.write(2, horero); // Se almacenan los nuevos valores de las horass en la posicion designada
      }
      else {
        horero = 0;
        tiempo();
      }
    }
  }
}
void tiempo() {
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
}
