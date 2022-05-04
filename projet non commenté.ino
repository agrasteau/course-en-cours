#include <Servo.h>
  Servo monServo;
  int angle;
  int btsignal;
void setup() {
  monServo.attach(2,350,2450);
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  btsignal=Serial.read(); 
  angle =160;
  monServo.write(angle);
  delay (1000);
  angle =122;
  monServo.write(angle);
  delay (1000);
  
  
 if (Serial.available() > 0) {
    if(btsignal == 0){// si le signal vau t1 la demande est roue basse
      
     monServo.write(angle);
    angle=110; // roue basse 
    }
    else if(btsignal == 1) { // si le signal vaut 2 la demande est roue en position normale
         angle =122;
        monServo.write(angle);
        
    }
    else if(btsignal == 2) {// boutton 2 presser allumage led intégrer a la carte
      
   digitalWrite(LED_BUILTIN, HIGH);
    
    }
    
    else if(btsignal == 3) {// boutton 3 presser éteignage led intégrer a la carte
      
   digitalWrite(LED_BUILTIN, LOW);
    
    }

}
}
