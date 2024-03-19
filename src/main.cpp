
#include <Arduino.h>    // nahrání knihoven
#include <Servo.h>
#include <ALKS.h>
#include "posunServa.h"


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