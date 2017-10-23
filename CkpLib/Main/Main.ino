
/*
 * Funcinamientro PREVISTO:
 * Se pregunta al usuario que ecu usar (Se muestra una lista), una vez elegida
 * la ecu se comienza a ejecutar los altos y bajos segun el array asignado a esa
 * ecu (1 = HIGH, 0 = LOW).
 * 
 * Quedan hacer arreglos, no hay generacion todabia, se esta pensado usar un
 * Struct en la funcion SYS.
 * 
 */


#define pinPot A0//Definicion pin Potencimetro
#define pinCKP 13//Definicion pin CKP
#define pinCMP 8//Definicion pin CMP
int ValPot; //Variable para potenciometro
const int ArrayLen = 1; //Variable tamaño array
String ECUS[ArrayLen] = {"S2000"}; //Lista de Ecus
String EcuSel; //Variable de Ecu Seleccionada por el User
byte EcuSig[255];
boolean State = false; //Controlador Loop

void setup() {
Serial.begin(9600); //Inicializacion del Serial

pinMode(pinCKP, OUTPUT); //Configuracion de pinCKP
pinMode(pinCMP, OUTPUT); //Configuracion de pinCKP

Menu(); //Llamado al void menu para pedir info al user

}

void loop() {
ValPot = analogRead(pinPot); //Lectura del valor del potenciometro

while(State == true){
  CKPCMP(EcuSig, pinCKP, pinCMP, ValPot, State);
  

}
}

void Menu(){
  Serial.println("Elija ECU:(Escribir Numero) ");
  for(int i; i <= ArrayLen - 1; i++){
      Serial.println(String(i) + ")" + ECUS[i]);
   }
  while(!Serial.available()){}
  EcuSel = Serial.readString();
  GetSignal();
  Serial.println("Ejecutando: " + ECUS[EcuSel.toInt()]);
  Serial.println("Para detener enviar Stop");
  State = true;
}

void GetSignal(){
  getSig(EcuSig, EcuSel.toInt());
  Serial.println("Cargando... Aguarde unos instantes");
}

