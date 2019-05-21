/*
 * -------------------UNIVERSIDAD TÉCNICA DEL NORTE-----------------
 * NOMBRE: DIEGO GUAMÁ
 * MATERIA: SISTEMAS MICROPROCESADOS
 * DEBER CAD Y COMUNICACIÓN SERIAL - VALIDACIÓN DE CÉDULA ECUATORIANA
 */

String cedula;
String pares;
String digito_region;
String ultimo_digito;
String numero1;
String numero3;
String numero5;
String numero7;
String numero9;
int digito_u;
int impares;
int par;
int n1;
int n3;
int n5;
int n7;
int n9;
int suma_total;
int digito1;
int decena;
int digito_validador;
void setup() {
  Serial.begin(9600);
}

void loop() {

  if (Serial.available() > 0) {
    cedula = '045014239-3'; // Ingreso de cédula con guión
    cedula = Serial.readString();

    if (cedula.length() == 11) {
      digito_region = cedula.substring(0, 2); // Se extrae el dígito e la región a la que pertenece la cédula

      if ( digito_region.toInt() >= 1 && digito_region.toInt() <= 24 )
      {
        ultimo_digito = cedula.substring(cedula.indexOf("-") + 1, cedula.length()); // Se extrae el último dígito de la cédula
        digito_u = ultimo_digito.toInt();
        pares = (cedula.substring(1, 2)).toInt() + (cedula.substring(3, 4)).toInt() + (cedula.substring(5, 6)).toInt() + (cedula.substring(7, 8)).toInt();  // Se extrae los números pares de la cédula
        par = pares.toInt();// se convierten a int para realizar operaciones
        numero1 = cedula.substring(0, 1);
        n1 = numero1.toInt();
        n1 = (n1 * 2);
        if ( n1 > 9 ) {
          n1 = (n1 - 9);
        }

        numero3 = cedula.substring(2, 3);
        n3 = numero3.toInt();
        n3 = (n3 * 2);
        if ( n3 > 9 ) {
          n3 = (n3 - 9);
        }

        numero5 = cedula.substring(4, 5);
        n5 = numero5.toInt();
        n5 = (n5 * 2);
        if ( n5 > 9 ) {
          n5 = (n5 - 9);
        }

        numero7 = cedula.substring(6, 7);
        n7 = numero7.toInt();
        n7 = (n7 * 2);
        if ( n7 > 9 ) {
          n7 = (n7 - 9);
        }

        numero9 = cedula.substring(8, 9);
        n9 = numero9.toInt();
        n9 = (n9 * 2);
        if ( n9 > 9 ) {
          n9 = (n9 - 9);
        }

        impares = n1 + n3 + n5 + n7 + n9;
        suma_total = (par + impares);
        String primer_digito_suma = String(suma_total).substring(0, 1);
        digito1 = primer_digito_suma.toInt();
        decena = ((digito1) + 1) * 10;
        digito_validador = decena - suma_total;
        if (digito_validador == 10) {
          digito_validador = 0;
        }
        if (digito_validador == digito_u) {// validación de la cédula
          Serial.println (" La cédula: " + cedula + " es correcta ");
        } else {
          Serial.println (" La cédula: " + cedula + " es incorrecta ");
        }
      } else {
        Serial.println (" Esta cédula no pertenece a ninguna región ");
      }
    } else {
      Serial.println (" Esta cédula tiene menos de 10 Dígitos ");
    }
  }
}
