
boolean count = true;
void CKPCMP(byte Sig[], int PinCKP, int PinCMP, int Retr, boolean Estados){
byte l = 0;
byte c = 5;
byte j;
for(int h; j<=9; j++){
while(count){
  for(int i; l <= 4;i++){
    GEN(l, Sig, PinCKP, Retr, 1);
    l++;
    SerialLoop(Estados);
    //Serial.println("lol");
    break;
  }
}

while(!count){
   for(int i; c <= 9;i++){
    GEN(c, Sig, PinCMP, Retr, 0);
    c++;
    SerialLoop(Estados);
    //Serial.println("lol2");
    break;
  }
}


 
}

byte GEN(byte Esp, byte Sign[], int PinO, int Retra, byte Wh){
  if(Sign[Esp] == 1){
    digitalWrite(PinO, HIGH);
    Serial.println("ALTO");
    delay(Retra);
    digitalWrite(PinO, LOW);
  }else{
    digitalWrite(PinO, LOW);
    Serial.println("bajo");
    delay(Retra);
    }
   if(Wh == 1){
    count = false;
   }else{
    count = true;
   }
}

