/*
 * ----------UNIVERSIDAD TÉCNICA DEL NORTE------
 * NOMBRE: DIEGO GUAMÁ
 * SISTEMAS MICROPROCESADOS
 * DEBER PUERTOS ENTRADA
 */
int operando1=5;
int operando2=4;
int suma=16;
int on=0;
int cont=0;
int sum=0;
int cont2=0;
int A=11;
int B=10;
int C=9;
int D=8;
int E=3;
int F=2;
int G=1;
int H=0;
int I=17;
int J=18;
int K=19;
int L=20;
int decenas;
int unidades;
int dec=13;
int uni=12;
int dec2=7;
int uni2=6;
int dec3=14;
int uni3=15;
void setup() {
pinMode(operando1,INPUT);
pinMode(operando2,INPUT);
pinMode(suma,INPUT);
pinMode(A,OUTPUT);
pinMode(B,OUTPUT);
pinMode(C,OUTPUT);
pinMode(D,OUTPUT);
pinMode(E,OUTPUT);
pinMode(F,OUTPUT);
pinMode(G,OUTPUT);
pinMode(H,OUTPUT);
pinMode(I,OUTPUT);
pinMode(J,OUTPUT);
pinMode(K,OUTPUT);
pinMode(L,OUTPUT);
pinMode(dec,OUTPUT);
pinMode(uni,OUTPUT);
pinMode(dec2,OUTPUT);
pinMode(uni2,OUTPUT);
pinMode(dec3,OUTPUT);
pinMode(uni3,OUTPUT);
}

void loop() {
//Funcionamiento de botón operando 1
 if(digitalRead(operando1)==LOW)
 {
 delay(300); 
 on=1-on;
  if(cont<25)
    cont++;
    else
     cont=0;
     }
 decenas=cont/10;
     unidades=cont-decenas*10;
     digitalWrite(dec,HIGH);
     digitalWrite(uni,LOW);
     contador(decenas);
     delay(50);
     digitalWrite(dec,LOW);
     digitalWrite(uni,HIGH);
     contador(unidades);
     delay(50);
//Funcionamiento de botón operando 2
 if(digitalRead(operando2)==LOW)
 {
 delay(300); 
 on=1-on;
  if(cont2<25)
    cont2++;
    else
     cont2=0;
     }
 decenas=cont2/10;
     unidades=cont2-decenas*10;
     digitalWrite(dec2,HIGH);
     digitalWrite(uni2,LOW);
     contador2(decenas);
     delay(50);
     digitalWrite(dec2,LOW);
     digitalWrite(uni2,HIGH);
     contador2(unidades);
     delay(50);
//Funcionamiento botón suma de operando 1 y operando 2
 if(digitalRead(suma)==LOW)
 {
 delay(300); 
 on=1-on;
sum=cont+cont2;
     }
     decenas=sum/10;
     unidades=sum-decenas*10;
     digitalWrite(dec3,HIGH);
     digitalWrite(uni3,LOW);
     sumador(decenas);
     delay(50);
     digitalWrite(dec3,LOW);
     digitalWrite(uni3,HIGH);
     sumador(unidades);
     delay(50);
}
void contador (int dato){
  switch(dato){
    case 0:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 1:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 2:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 3:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,LOW);
      digitalWrite(D,LOW);
    break;
    case 4:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 5:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 6:
      digitalWrite(A,LOW);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 7:
      digitalWrite(A,HIGH);
      digitalWrite(B,HIGH);
      digitalWrite(C,HIGH);
      digitalWrite(D,LOW);
    break;
    case 8:
      digitalWrite(A,LOW);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
    case 9:
      digitalWrite(A,HIGH);
      digitalWrite(B,LOW);
      digitalWrite(C,LOW);
      digitalWrite(D,HIGH);
    break;
    }
    
  }
  void contador2 (int dato){
  switch(dato){
    case 0:
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(H,LOW);
    break;
    case 1:
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(H,LOW);
    break;
    case 2:
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(H,LOW);
    break;
    case 3:
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,LOW);
      digitalWrite(H,LOW);
    break;
    case 4:
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(H,LOW);
    break;
    case 5:
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,HIGH);
      digitalWrite(H,LOW);
    break;
    case 6:
      digitalWrite(E,LOW);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(H,LOW);
    break;
    case 7:
      digitalWrite(E,HIGH);
      digitalWrite(F,HIGH);
      digitalWrite(G,HIGH);
      digitalWrite(H,LOW);
    break;
    case 8:
      digitalWrite(E,LOW);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(H,HIGH);
    break;
    case 9:
      digitalWrite(E,HIGH);
      digitalWrite(F,LOW);
      digitalWrite(G,LOW);
      digitalWrite(H,HIGH);
    break;
    }
    
  }
    void sumador (int dato){
  switch(dato){
    case 0:
      digitalWrite(I,LOW);
      digitalWrite(J,LOW);
      digitalWrite(K,LOW);
      digitalWrite(L,LOW);
    break;
    case 1:
      digitalWrite(I,HIGH);
      digitalWrite(J,LOW);
      digitalWrite(K,LOW);
      digitalWrite(L,LOW);
    break;
    case 2:
      digitalWrite(I,LOW);
      digitalWrite(J,HIGH);
      digitalWrite(K,LOW);
      digitalWrite(L,LOW);
    break;
    case 3:
      digitalWrite(I,HIGH);
      digitalWrite(J,HIGH);
      digitalWrite(K,LOW);
      digitalWrite(L,LOW);
    break;
    case 4:
      digitalWrite(I,LOW);
      digitalWrite(J,LOW);
      digitalWrite(K,HIGH);
      digitalWrite(L,LOW);
    break;
    case 5:
      digitalWrite(I,HIGH);
      digitalWrite(J,LOW);
      digitalWrite(K,HIGH);
      digitalWrite(L,LOW);
    break;
    case 6:
      digitalWrite(I,LOW);
      digitalWrite(J,HIGH);
      digitalWrite(K,HIGH);
      digitalWrite(L,LOW);
    break;
    case 7:
      digitalWrite(I,HIGH);
      digitalWrite(J,HIGH);
      digitalWrite(K,HIGH);
      digitalWrite(L,LOW);
    break;
    case 8:
      digitalWrite(I,LOW);
      digitalWrite(J,LOW);
      digitalWrite(K,LOW);
      digitalWrite(L,HIGH);
    break;
    case 9:
      digitalWrite(I,HIGH);
      digitalWrite(J,LOW);
      digitalWrite(K,LOW);
      digitalWrite(L,HIGH);
    break;
    }
    
  }
