/*
 * Funcionamiento:
 * Se esta loopeando constantemente la cantidad de dientes totales menos
 * la cantidad de dientes faltantes, mientras con un delay (que su valor viene
 * del potenciometro) se regulan las rpm.
 */

#define pinSig 13 //Definicion del Pin

int DientesTotales = 5;//Variables dientes totales
int DientesFaltantes = 2;//Variables dientes faltantes
int DelTime = 0;//Valor Potenciometro

void setup() {
	pinMode(pinSig, OUTPUT);//Configuracion pin
	
}

void loop() {
	DelTime = analogRead(A0);//Leer Valor potenciometro
	if(DelTime < 5){
		DelTime = DelTime + 5;//Se pone un limite para que la señal no se haga muy chica
	}
	DoWork();//Se llama al void DoWork()
} 

void DoWork(){	
	
	for(int i=1;i<=DientesTotales - DientesFaltantes; i++){//for para dientes totales - dientes faltantes
		digitalWrite(pinSig, HIGH);
		delay(DelTime);//Delay para controlar RPM
		digitalWrite(pinSig, LOW);
		delay(DelTime);//Delay para controlar RPM
	}
	
	for(int i=1;i<=DientesFaltantes; i++){//for para dientes faltantes
		digitalWrite(pinSig, LOW);
		delay(DelTime);//Delay para controlar RPM
	}
}

