void SerialLoop(boolean Estado){
  if(Serial.available()){
  String ST = Serial.readString();
  if(ST == "Stop" or "stop"){
    Estado == false;
    Menu();
  }
}
}

