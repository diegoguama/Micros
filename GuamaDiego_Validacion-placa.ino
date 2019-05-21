/*
 * ------------------------------UNIVERSIDAD TÉCNICA DEL NORTE-----------------
 * NOMBRE: DIEGO GUAMÁ
 * MATERIA: SISTEMAS MICROPROCESADOS
 * DEBER COMUNICACIÓN SERIAL - VALIDACIÓN DE PLACAS VEHICULARES ECUADOR
 * 
  PLACAS ECUATORIANAS
  A – Azuay
  B – Bolívar
  U – Cañar
  C – Carchi
  X – Cotopaxi
  H – Chimborazo
  O – El Oro
  E – Esmeraldas
  W – Galápagos
  G – Guayas
  I – Imbabura
  L – Loja
  R – Los Ríos
  M – Manabí
  V – Morona Santiago
  N – Napo
  S – Pastaza
  P – Pichincha
  Q – Orellana
  K – Sucumbíos
  T – Tungurahua
  Z – Zamora Chinchipe
  Y – Santa Elena
  J – Santo Domingo de los Tsáchilas
*/
String letras;
String placa;
String numeros;
String letra1;
int  i;
char placac[8];
void setup() {
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    placa = 'ABC-1234';
    placa = Serial.readString();
    if (placa.length() == 8) {
      letras = placa.substring(0, placa.indexOf("-"));// Se obtienen los valores de antes del guión
      numeros = placa.substring(placa.indexOf("-") + 1, placa.length());// Se obtienen los valores de después del guión
      placa = letras + numeros;
      letra1 = letras.substring(0, 1);
      if (( letra1 == "A" || letra1 == "B" || letra1 == "U" || letra1 == "C" || letra1 == "X" || letras == "H" || letra1 == "O" || letra1 == "E" || letra1 == "W" || letra1 == "G" || letra1 == "I" || letra1 == "L" || letra1 == "R" || letra1 == "M" || letra1 == "V" || letra1 == "N" || letra1 == "S" || letra1 == "P" || letra1 == "Q" || letra1 == "K" || letra1 == "T" || letra1 == "Z" || letra1 == "Y" || letra1 == "J") )
      {
        placa.toCharArray(placac, 8);
        for (int i = 0; i < 3; i++) { // la validación para que en las posiciones existan solo letras
          if (placac[i] >= 'A' && placac[i] <= 'Z') {
            letras = true;
            for (int i = 4; i < 8; i++) { // la validación para que en las posiciones existan solo números
              if (placac[i] >= '0' && placac[i] <= '9' ) {

                if (placac[0] == 'A') {
                  Serial.println (" La placa: " + placa + " es de Azuay");
                }

                if (placac[0] == 'B') {
                  Serial.println (" La placa: " + placa + " es de Bolívar");
                }

                if (placac[0] == 'U') {
                  Serial.println (" La placa: " + placa + " es de Cañar");
                }

                if (placac[0] == 'C') {
                  Serial.println (" La placa: " + placa + " es de Carchi");
                }
                if (placac[0] == 'X') {
                  Serial.println (" La placa: " + placa + " es de Cotopaxi");
                }
                if (placac[0] == 'H') {
                  Serial.println (" La placa: " + placa + " es de Chimborazo");
                }
                if (placac[0] == 'O') {
                  Serial.println (" La placa: " + placa + " es de El Oro");
                }
                if (placac[0] == 'E') {
                  Serial.println (" La placa: " + placa + " es de Esmeraldas");
                }
                if (placac[0] == 'W') {
                  Serial.println (" La placa: " + placa + " es de Galápagos");
                }
                if (placac[0] == 'G') {
                  Serial.println (" La placa: " + placa + " es de Guayas");
                }
                if (placac[0] == 'I') {
                  Serial.println (" La placa: " + placa + " es de Imbabura");
                }

                if (placac[0] == 'L') {
                  Serial.println (" La placa: " + placa + " es de Loja");
                }
                if (placac[0] == 'R') {
                  Serial.println (" La placa: " + placa + " es de Los Ríos");
                }

                if (placac[0] == 'M') {
                  Serial.println (" La placa: " + placa + " es de Manabí");
                }

                if (placac[0] == 'V') {
                  Serial.println (" La placa: " + placa + " es de Morona Santiago");
                }

                if (placac[0] == 'N') {
                  Serial.println (" La placa: " + placa + " es de Napo");
                }

                if (placac[0] == 'S') {
                  Serial.println (" La placa: " + placa + " es de Pastaza");
                }

                if (placac[0] == 'P') {
                  Serial.println (" La placa: " + placa + " es de Pichincha");
                }

                if (placac[0] == 'Q') {
                  Serial.println (" La placa: " + placa + " es de Orellana");
                }

                if (placac[0] == 'K') {
                  Serial.println (" La placa: " + placa + " es de Sucumbíos");
                }

                if (placac[0] == 'T') {
                  Serial.println (" La placa: " + placa + " es de Tungurahua");
                }

                if (placac[0] == 'Z') {
                  Serial.println (" La placa: " + placa + " es de Zamora Chinchipe");
                }

                if (placac[0] == 'Y') {
                  Serial.println (" La placa: " + placa + " es de Santa Elena");
                }

                if (placac[0] == 'J') {
                  Serial.println (" La placa: " + placa + " es de Santo Domingo de los Tsáchilas");
                }
              }
            }
          }
        }

      }
      else Serial.println (" La placa no pertenece a ninguna región");

    }
    else
      Serial.println (" La placa es incorrecta, La placa no pertenece a ninguna región");

  }
  else
    Serial.println (" Dígitos incorrectos, la placa debe constar de letras y números");
}







