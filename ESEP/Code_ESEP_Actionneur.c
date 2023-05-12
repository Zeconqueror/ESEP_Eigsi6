

//Declaration des variables
#include <Servo.h>
 
Servo servo;  // Cree une instance de la classe Servo pour controler le servomoteur
const int pinServo = 3;  // Broche a laquelle est connecte le servomoteur
unsigned long tempsDebutVentilateur;  // Variable pour stocker le temps de debut
const int pinMoteur = 9;   // Broche a laquelle est connecte le moteur du ventilateur

//Fonction position_trappe_servomoteur
void position_trappe_servomoteur(int angle) {
   servo.attach(pinServo);  // Attache le servomoteur a la broche appropriee
  servo.write(angle);  // Positionne le servomoteur a l'angle specifie
}

//Fonction pour demarrer le ventilo

void demarrer_ventilateur(int delai) {
  pinMode(pinMoteur, OUTPUT);  // Configure la broche du ventilateur en sortie
  digitalWrite(pinMoteur, HIGH);  // Active le ventilateur
  tempsDebutVentilateur = millis();  // Enregistre le temps de debut
  
  while(millis() - tempsDebutVentilateur > delai) {
    arreter_ventilateur(); // Desactive le ventilateur 
  }
}

//Fonction pour arreter le ventilo
void arreter_ventilateur() {
  pinMode(pinMoteur, OUTPUT);  // Configure la broche du moteur en sortie
  digitalWrite(pinMoteur, LOW);  // Desactive le moteur du ventilateur
}


