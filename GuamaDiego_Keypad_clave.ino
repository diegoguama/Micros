/*
 * ------------- UNIVERSIDAD TÈCNICA DEL NORTE-------------
 * NOMBRE: DIEGO GUAMÀ
 * MATERIA: SISTEMAS MICROPROCESADOS
 * ----------- VALIDAR CÉDULA CON KEYPAD Y LCD ----------
 */


#include <Keypad.h>                    //incluir la librería de teclado
#include <LiquidCrystal.h>
const byte Filas = 4;
const byte Cols = 4;
LiquidCrystal lcd (13, 12, 11, 10, 9, 8);
byte Pins_Filas[] = {A0, A1, A2, A3};     //Pines Arduino para las filas
byte Pins_Cols[] = { 5, 4, 3, 2};     // Pines Arduino para las columnas
char Teclas [ Filas ][ Cols ] =
{
  {'7', '8', '9', 'A'},
  {'4', '5', '6', 'B'},
  {'1', '2', '3', 'C'},
  {'*', '0', '#', 'D'}
};

char codigoSecreto[4] = {'1', '2', '3', '4'}; // clave por defecto
int posicion = 0;
int clave = 0;
int cursor = 5;
Keypad Teclado1 = Keypad(makeKeymap(Teclas), Pins_Filas, Pins_Cols, Filas, Cols);
char pulsacion = Teclado1.getKey(); // almacena el valor del keypad
void setup()
{
  Serial.begin(9600) ;

  lcd.begin (16, 2);
  lcd.setCursor(0, 0);
  lcd.print("BIENVENIDO");
  delay(500);
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("INGRESE CLAVE:");
  lcd.setCursor(cursor, 1);
}

void loop()
{
  //Validación de contraseña
  char pulsacion = Teclado1.getKey() ;
  if (pulsacion != 0)
  {
    if (pulsacion != '#' && pulsacion != '*' && clave == 0)
    {
      lcd.setCursor(cursor, 1);
      lcd.print(pulsacion);
      delay(300);
      lcd.setCursor(cursor, 1);
      lcd.print("*");
      delay(300);
      cursor++;
      if (pulsacion == codigoSecreto[posicion])
        posicion ++;
      if (posicion == 4)
      {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Clave correcta ");
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Bienvenido");
        delay(500);
        cursor = 5;   // lo volvemos a colocar al inicio
        posicion = 0;         // borramos clave introducida
        lcd.setCursor(5, 1);
        lcd.print(" ");       // borramos la clave de la pantalla
        lcd.setCursor(5, 1);
      }
      if (cursor > 8)     // comprobamos que no pase de la cuarta posicion
      {
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Clave incorrecta ");
        delay(500);
        lcd.clear();
        lcd.setCursor(0, 1);
        lcd.print("Pruebe otra");
        delay(500);
        cursor = 5;
        posicion = 0;
        lcd.setCursor(5, 1);
        lcd.print(" ");
        lcd.setCursor(5, 1);

      }
    }
  }
  // Limpiar LCD para nueva contraseña
  if (pulsacion == '*')
  {
    posicion = 0;
    cursor = 5;
    clave = 0;
    posicion = 0;
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("INGRESE CLAVE:");
    lcd.setCursor(5, 1);
    lcd.print(" ");
    lcd.setCursor(5, 1);
  }
}
