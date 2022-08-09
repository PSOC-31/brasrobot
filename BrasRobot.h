
#ifndef __BrasRobot__
#define __BrasRobot__

#include <Servo.h>


#define pinbouton A0


class BrasRobot
{
private:
int pincoude=3;
int pinpince=5;
int pinpoignet=6;
int pinepaule1=9;
int pinepaule2=10;
int pinbase=11;


Servo spince;
Servo spoignet;
Servo scoude;
Servo sepaule1;
Servo sepaule2;
Servo sbase;

int apince=90;
int apoignet=90;
int acoude=90;
int aepaule=90;
int abase=90;



bool isBlack=false;
void init();

void updatePos();
int inv(int);
int ralenti;
public:

//@bras - initialisation
//@bloc texte=nouveau bras png=arm.png
BrasRobot();

//@bloc texte=activer les moteurs png=on.png
void activerMoteurs();
//@bloc texte=desactiver les moteurs png=off.png
void desactiverMoteurs();

void initPosition();

void finTravail();

void setRalenti(int );

//@bras - Articulations
//Articulations
//@bloc texte=angle de la base png=anglebase.png
void setAngleBase(int angle);
//@bloc texte=angle des épaules png=angleepaule.png
void setAngleEpaule(int angle);
//@bloc texte=angle du coude png=anglecoude.png
void setAngleCoude(int angle);
//@bloc texte=angle du poignet png=anglepoignet.png
void setAnglePoignet(int angle);
//@bloc texte=angle de la pince png=anglepince.png
void setAnglePince(int angle);
//@bloc texte=tous les angles png=tous.png
void setAnglesBECP(int base, int epaules, int coude, int poignet);




//@mouvements basiques
//@bloc texte=lever le bras png=lever.png
void lever();
//@bloc texte=baisser le bras png=baisser.png
void baisser();
//@bloc texte=tourner à gauche png=tournegauche.png
void rotationGauche();
//@bloc texte=tourner à droite png=tournedroite.png
void rotationDroite();
//@bloc texte=recenter le robot png=tournemilieu.png
void rotationMilieu();

//@pince

//@bloc texte=ouvrir la pince png=pinceouverte.png
void ouvrirPince();
//@bloc texte=fermer la pince png=pincefermee.png
void fermerPince();
//@bloc texte=lever la pince png=pincehaut.png
void inclinerHaut();
//@bloc texte=baisser l apince png=pincebas.png
void inclinerBas();
//@bloc texte=pince à l'horizontal png=pinceplat.png
void horizontal();



};


#endif