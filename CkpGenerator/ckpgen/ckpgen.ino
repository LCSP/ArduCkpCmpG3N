#include <TimerOne.h>

#define pinPulso 13

long Tiempo = 5000000;
long Dientes = 5;
long DieFaltantes = 3;
long BaseTime = 1000000;

void setup() {

Timer1.initialize(60000000); 
pinMode(pinPulso, OUTPUT);
//getDientes();
//delay(1000);
//getDieFaltantes();
//delay(1000);
//getTiempo();
//delay(1000);
doWork();
}

void loop() {
  
}

void getDientes(){
  Serial.begin(9600);
  Serial.println("Escriba el total de dientes:");
  while(Serial.available() == 0); 
  Dientes = Serial.parseInt();
  Serial.println( Dientes);
  
}

void getDieFaltantes(){
  Serial.end();
  Serial.begin(9600);
  Serial.println("Escriba los dientes faltantes:");
  while(Serial.available() == 0); 
  DieFaltantes = Serial.parseInt();
  Serial.println(DieFaltantes);
  
}

void getTiempo(){
  Serial.end();
  Serial.begin(9600);
  Serial.println("Escriba el total de segundos que desea que dure la señal:");
  while(Serial.available() == 0); 
  Tiempo = Serial.parseInt();
  Serial.println(Tiempo);
  Tiempo = Tiempo * BaseTime;
  delay(1000);
  Serial.println("Iniciando...");
  
  
}

void doWork(){
  Timer1.start();
  while(Timer1.read() < Tiempo){
    for (int i=0; i <= Dientes - 2; i++){
      //Serial.println(Tiempo);
     // Serial.println(Timer1.read());
      digitalWrite(pinPulso, HIGH);
      digitalWrite(pinPulso, LOW);
   }
    
   for (int i=0; i <= DieFaltantes; i++){
      digitalWrite(pinPulso, LOW);
   }
    
  }
  Timer1.stop();
  Serial.println("Finalizado");
}

