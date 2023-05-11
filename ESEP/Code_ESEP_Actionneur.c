//Fonction fermer trappe servomoteur

void fermer_trappe_servomoteur(int angle_ferme) {
    initialiser_servomoteur();  // Initialise le servomoteur
    
    int position_actuelle = lire_position_servomoteur();  // Lit la position actuelle du servomoteur
    
    if (position_actuelle > angle_ferme) {
        bouger_servomoteur(angle_ferme);  // Deplace le servomoteur vers la position "fermee"
    }
}



/* Fonction position_trappe_servomoteur
#include <Servo.h>

Servo servo;  // Cree une instance de l'objet Servo

const int pinServo = 9;  // Broche a laquelle est connecte le servomoteur

void setup() {
  servo.attach(pinServo);  // Attache le servomoteur a la broche appropriee
}
void position_trappe_servomoteur(int angle) 
  servo.write(angle);  // Positionne le servomoteur a l'angle specifie
}*/

//Fonction pour demarrer le ventilo
const int pinVentilateur = 9;  // Broche a laquelle est connecte le ventilateur
unsigned long tempsDebutVentilateur;  // Variable pour stocker le temps de debut

void setup() {
  pinMode(pinVentilateur, OUTPUT);  // Configure la broche du ventilateur en sortie
}

void demarrer_ventilateur(int delai) {
  digitalWrite(pinVentilateur, HIGH);  // Active le ventilateur
  tempsDebutVentilateur = millis();  // Enregistre le temps de debut
  
  if (millis() - tempsDebutVentilateur > delai) {
    arreter_ventilateur(); // Desactive le ventilateur 
  }
  else {
     demarrer_ventilateur(delai);
     }
  
}


//Fonction pour arreter le ventilo puis fermer la trappe
const int pinMoteur = 9;   // Broche a laquelle est connecte le moteur du ventilateur
const int angleFermeture = 90;  // Angle de fermeture de la trappe

void setup() {
  pinMode(pinMoteur, OUTPUT);  // Configure la broche du moteur en sortie
}

void arreter_ventilateur() {
  digitalWrite(pinMoteur, LOW);  // Desactive le moteur du ventilateur
  fermer_trappe_servomoteur(angleFermeture);  // Appelle la fonction pour fermer la trappe
}


//Fonction ouvrir trappe
#include <Servo.h>

Servo servoTrappe;  // Creation d'une instance de la classe Servo pour controler le servomoteur
const int pinServo = 9;  // Broche a laquelle est connecte le servomoteur

void setup() {
  servoTrappe.attach(pinServo);  // Attache le servomoteur a la broche specifiee
  servoTrappe.write(0);  // Positionne le servomoteur a l'angle de depart pour fermer la trappe
}

void ouvrir_trappe() {
  servoTrappe.write(90);  // Positionne le servomoteur a l'angle d'ouverture pour ouvrir la trappe
}

