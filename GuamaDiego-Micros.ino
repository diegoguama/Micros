
/*
 -----***UNIVERSIDAD TÉCNICA DEL NORTE***------
                FICA/CIERCOM
                DIEGO GUAMÁ
         SISTEMAS MICROPROCESADOS 
 */
int i;
int j;
int leds[8]={6,7,8,9,10,11,12,13};
void setup() {
  // put your setup code here, to run once:
for (;i<8;i++){
pinMode(leds[i],OUTPUT);
}
i=0;
randomSeed(analogRead(0));
}
void loop() {
  // put your main code here, to run repeatedly:
  //1.- Encender leds pares
   for(;i<8;i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(500);
    digitalWrite(leds[i],LOW);
    i++;
  }
  //2.- Encender leds impares
     for(i=1;i<8;i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(500);
    digitalWrite(leds[i],LOW);
    i++;
  }
i=0;
  //3.- Encender leds y apagar ascendente y descandente
  for(i=0;i<8;i++)
  {
    digitalWrite(leds[i],HIGH);
    delay(300);
    digitalWrite(leds[i],LOW);
  }
   for(i=6;i>=0;i--)
  {
    digitalWrite(leds[i],HIGH);
    delay(300);
    digitalWrite(leds[i],LOW);
  }
  //4.- Encendido ascendente y apagado descendente
  for(i=0;i<=8;i++){
  digitalWrite(leds[i],HIGH);
  delay(300);
  }
  for(i=7;i>=0;i--){
  digitalWrite(leds[i],LOW);
  delay(300);
  }
  //5.- Encender los leds de afuera hacia adentro y apagar de adentro hacia afuera
  for(i=0;i<5;i++){
    for(j=7;j>3;j--){
  digitalWrite(leds[i],HIGH);
  delay(50);
  digitalWrite(leds[j],HIGH);
  delay(500);
    }
  }
  for(i=4;i<9;i++){
    for(j=3;j>=0;j--){
  digitalWrite(leds[i],LOW);
  delay(500);
  digitalWrite(leds[j],LOW);
  delay(100);
  i=0;
}
  }
  }
