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