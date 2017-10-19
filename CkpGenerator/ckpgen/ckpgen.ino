/*
 * Funcionamiento:
 * 
 * se lopea por la cantidad de tiempo indicada en la variable tiempo (Microsegundos)
 * la cantidad total de dientes (Dientes) menos los dientes faltantes (DieFaltantes)
 * 
 */



#include <TimerOne.h> //Inluir libreria TimerOne

#define pinPulso 13 //Definicion del pin de salida

long Tiempo = 5000000; //Variable de tiempo donde se ejecutara el loop
long Dientes = 5; //Dientes totales
long DieFaltantes = 3; //Dientes Faltantes
long BaseTime = 1000000; //Base de tiempo para calculos

void setup() {

Timer1.initialize(60000000);  //Inizialisacion del Timer1
pinMode(pinPulso, OUTPUT); //Configuracion del pin
//getDientes();
//delay(1000);
//getDieFaltantes();
//delay(1000);
//getTiempo();
//delay(1000);
doWork();//Ir al void doWork
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

