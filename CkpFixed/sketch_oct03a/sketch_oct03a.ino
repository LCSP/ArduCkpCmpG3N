#define pinSig 13

int DientesTotales = 5;
int DientesFaltantes = 2;
int DelTime = 0;

void setup() {
	pinMode(pinSig, OUTPUT);
	
}

void loop() {
	DelTime = analogRead(A0);
	if(DelTime < 5){
		DelTime = DelTime + 5;
	}
	DoWork();
} 

void DoWork(){	//Por Segundo 10 Ciclos, 1 clico por segundo
	
	for(int i=1;i<=DientesTotales - DientesFaltantes; i++){
		digitalWrite(pinSig, HIGH);
		delay(DelTime);
		digitalWrite(pinSig, LOW);
		delay(DelTime);
	}
	
	for(int i=1;i<=DientesFaltantes; i++){
		digitalWrite(pinSig, LOW);
		delay(DelTime);
	}
}

