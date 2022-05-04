/*
programme commandant une roue à énergie cinétique a l'aide d'un servo moteur pour le challenge course en cours.
Une application sur smartphone envoi via une liaison bluetooth un signal sur un octet ici une valeur allant de 0 à 3 
La roue en position basse permet d'empecher celle-ci d'etre au contact de la piste c'est la valeur par défaut 
La roue en position normale entre en contact avec la piste et entraine la voiture
le pillotage des leds permets de prouver une communication entre l'application android et la carte arduino en cas de défaillance du moteur
l'application android a été conçu a l'aide de appinventor https://appinventor.mit.edu/
*/


#include <Servo.h>
  Servo monServo;
  int angle;
  int btsignal;
  int val;
  byte valeurX;
void setup() {
  monServo.attach(2,350,2450);
  Serial.begin(9600); 
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() { // code qui se repete
 // partie reception de donnees du moteur
val = analogRead(A0); // lecture de la valeur envoyer par le moteur
val = val/5 ;// division par 5 pour que la valeur soit inferieur à 255
valeurX = val;// troncature de la valeur de val a un octet
 delay(100);
 Serial.write (valeurX);
 
 //partie reception de donnes de l'application.
 if (Serial.available() > 0) {
 btsignal=Serial.read(); 
 /*lecture des valeurs recu sur les portsseries par le module bluetooth */
   if(btsignal == 0){// si le signal vaut 0 la roue est mise en position basse
    angle-110; // roue basse
    monServo.write(angle);// envoi de la demande au servo moteur
   }
   else if(btsignal == 1) { // sinon si le signal vaut 1 la roue en position normale 
       angle =122;// roue en position nomale
      monServo.write(angle);// envoi de la demande au servo moteur
   }
   else if(btsignal == 2) {// sinon si le signal vaut 2 allumer la led integre a la carte 
 digitalWrite(LED_BUILTIN, HIGH);// commande allumer la led
   }
   else if(btsignal == 3) {// sinon si le signal vaut 3 eteindre la led integre a la carte 
 digitalWrite(LED_BUILTIN, LOW);// commande allumer la led
   }
}
}
