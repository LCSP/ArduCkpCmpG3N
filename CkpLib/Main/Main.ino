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
#define pinCMP 12//Definicion pin CMP
int ValPot; //Variable para potenciometro
const int ArrayLen = 1; //Variable tamaño array
int S2000CKP[5] = {1,1,5,0,0}; //Pulsos CKP
int S2000CMP[5] = {0,0,5,1,1}; //Pulsos CMP
String ECUS[ArrayLen] = {"S2000"}; //Lista de Ecus
String EcuSel; //Variable de Ecu Seleccionada por el User
String GetEcuCKP; //Intento de geteoEcu
String GetEcuCMP;//Intento de geteoEcu
boolean State = false; //Controlador Loop

void setup() {
Serial.begin(9600); //Inicializacion del Serial

pinMode(pinCKP, OUTPUT); //Configuracion de pinCKP
pinMode(pinCMP, OUTPUT); //Configuracion de pinCKP

Menu(); //Llamado al void menu para pedir info al user

}

void loop() {
ValPot = analogRead(pinPot); //Lectura del valor del potenciometro
if(Serial.available()){
  String ST = Serial.readString();//Lectura para parar el loop
  if(ST == "Stop" or "stop"){
    State == false;
    Menu();
  }
}
while(State == true){
Serial.println(GetEcuCKP[2]);//Intento de generacion con array a base de variable TODO
Serial.println(GetEcuCMP[2]);//Intento de generacion con array a base de variable TODO
delay(1000);//delay para pruebas
}


}

void Menu(){
  Serial.println("Elija ECU:(Escribir Numero) ");
  for(int i; i <= ArrayLen - 1; i++){
      Serial.println(String(i) + ")" + ECUS[i]);
   }
  while(!Serial.available()){}
  EcuSel = Serial.readString();
  Serial.println("Ejecutando: " + ECUS[EcuSel.toInt()]);
  Serial.println("Para detener enviar Stop");
  GetEcuCKP = SYS(EcuSel, 1);
  GetEcuCMP = SYS(EcuSel, 2);
  State = true;
}


