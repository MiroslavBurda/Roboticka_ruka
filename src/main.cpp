
#include <Arduino.h>    // nahrání knihpven
#include <Servo.h>
#include <ALKS.h>


static const int servo1Pin = S1;    //deklarace pinů
static const int servo2Pin = S2;
static const int servo3Pin = S3;
static const int servo4Pin = S4;

Servo servo1, servo2, servo3, servo4;   // deklarace serv

void PosunServa(int PocatecniUhel, int KoncovyUhel, int CisloServa) {
    if (KoncovyUhel > 90) {     // brání zadání servu úhel větší jak 90 stupňů a menší jak 0 stupňů
        KoncovyUhel = 90;
    }

    if (KoncovyUhel < 0) {
        KoncovyUhel = 0;
    }

    if (PocatecniUhel > 90) {
        PocatecniUhel = 90;
    }

    if (PocatecniUhel < 0) {
        PocatecniUhel = 0;
    }


    if (PocatecniUhel < KoncovyUhel) {      
        for(int posDegrees = PocatecniUhel; posDegrees <= KoncovyUhel; posDegrees++){   // po jednom stupni posune servo na koncový úhel
            switch(CisloServa) {       // Určuje, které servo je posunováno
                case 1:
                    servo1.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 2:
                    servo2.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 3:
                    servo3.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 4:
                    servo4.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                default: 
                    Serial.println("Chybné číslo serva!!");
                    break;
            }    
        Serial.println(posDegrees);          
        delay(50);           
        }
    // výsledek je, že se servo postupně posune z PocatecniUhel stupňů na KoncovyUhel stupňů
    }

    if (PocatecniUhel > KoncovyUhel) {      // To samé pro posun zpět
        for(int posDegrees = PocatecniUhel; posDegrees >= KoncovyUhel; posDegrees--) {     
            switch(CisloServa) {
                case 1:
                    servo1.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 2:
                    servo2.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 3:
                    servo3.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                case 4:
                    servo4.write(posDegrees);
                    Serial.print(CisloServa);
                    Serial.print(": ");
                    break;
                default: 
                    Serial.println("Chybné číslo serva!!");
                    break;
            }    

        Serial.println(posDegrees);
        delay(50);
        }
    }

}

void setup() {      // tato část programu se odehraje jednou
    Serial.begin(115200);            // nastavení frekvence, se kterou se bude ALKS bavit s počítačem
    servo1.attach(servo1Pin);        // nastavení který pin, patří ke kterému servu
    servo2.attach(servo2Pin);
    servo3.attach(servo3Pin);
    servo4.attach(servo4Pin);

    servo1.write(0);    // nastavení serv do nulové pozice
    delay(1000);
    servo2.write(0);
    delay(1000);
    servo3.write(0);
    delay(1000);
    servo4.write(0);
    delay(1000);

}

void loop(){    // až se odehraje setup, tak se tato část programu opakuje pořád dokola
   
    PosunServa(0, 40, 4);    // První hodnota říká počáteční úhel serva, Druhá říká koncový úhel serva, třetí říká číslo serva
    PosunServa(40, 0, 4);    // Posune servo s daným číslem z počátečího úhlu na koncový úhel
    //
     

}