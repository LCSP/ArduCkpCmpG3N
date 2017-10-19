
#define pinPot A0
#define pinCKP 13
#define pinCMP 12
int ValPot;
const int ArrayLen = 1;
int S2000CKP[5] = {1,1,5,0,0};
int S2000CMP[5] = {0,0,5,1,1};
String ECUS[ArrayLen] = {"S2000"};
String EcuSel;
String GetEcuCKP;
String GetEcuCMP;
boolean State = false;

void setup() {
Serial.begin(9600);

pinMode(pinCKP, OUTPUT);
pinMode(pinCMP, OUTPUT);

Menu();

}

void loop() {
ValPot = analogRead(pinPot);
if(Serial.available()){
  String ST = Serial.readString();
  if(ST == "Stop" or "stop"){
    State == false;
    Menu();
  }
}
while(State == true){
Serial.println(GetEcuCKP[2]);
Serial.println(GetEcuCMP[2]);
delay(1000);
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


