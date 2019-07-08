/*
 * **************** UNIVERSIDAD TÉCNICA DEL NORTE*******************
 * ------------------ SISTEMAS MICROPROCESADOS ---------------------
 * Nombre: Diego Guamá
 * Carrera: Ingeniería en Electrónica y Redes de Comunicación
 * Actividad: Realizar un programa de seguridad domótica que permita encender las luces de un domicilio 
 * de 5 habitaciones de forma aleatoria solo en horario nocturno. 
 * El sistema se activa al ingresar una contraseña por comunicación serial
 */
#include <MsTimer2.h>
#include <TimerOne.h>
int horero, minutero, segundero;
int i = 0;
int cont = 6;
String pswd;
boolean validar;
int alarma = 0;
int pin;
void setup() {
  Serial.begin(9600);
  MsTimer2::set(500, reloj);
  Timer1.initialize(2000000);
  Timer1.stop();
  Timer1.attachInterrupt(luces);
  Serial.println("BIENVENIDO INGRESE PASSWORD PARA ACTIVAR SISTEMA");
  delay(500);
  for ( pin = 2; pin <= cont; pin++) { //Pines de dormitorios representados con leds
    pinMode (pin, OUTPUT);
  }
  randomSeed(analogRead(0));
}

void loop() {
  if (Serial.available() > 0) {
    pswd = Serial.readString(); //StringUntil(/n)  es para enter en real
    if (pswd.length() != 7) {
      Serial.println("PASSWORD INVALIDA");
      delay(500);
    }
    else {
      validar = pswd.equals("CIERCOM");
      if (validar == true) {
        Serial.println("PASSWORD VALIDO");
        delay(500);
        Serial.println("SISTEMA ACTIVADO");
        delay(500);
        alarma = 1;
        MsTimer2::start();
        Timer1.start();

      }
      else {
        Serial.println("PASSWORD INVALIDA");
        delay(500);
      }
    }
  }
}
void reloj() {
  if (segundero < 60) {
    Serial.print(horero);
    Serial.print(':');
    Serial.print(minutero);
    Serial.print(':');
    Serial.println(segundero);
    segundero++;

  }
  else {
    segundero = 0;
    if (minutero < 60) {
      minutero++;

    }
    else {
      minutero = 0;
      if (horero < 24) {
        horero++;
      }
      else {
        horero = 0;
      }
    }
  }
}
void luces() {
  if (alarma == 1) {
    if (minutero > 0 && minutero < 2 ) {    // haciendo de cuenta que a esta hora es por la noche
      Serial.println("Luces on");           //y el sistema se enciende en ese intervalo de tiempo(noche) para simulación
      for ( pin = 2; pin <= cont; pin++) {
        int rnd = random(0, 2);
        digitalWrite (pin, rnd);
        delay (500);
      }
    } else {
      for ( pin = 2; pin <= cont; pin++) {
        digitalWrite (pin, 0);
        delay (500);
      }
    }
  }
}
