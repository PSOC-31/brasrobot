/*
 code généré pour ARDUINO par UniBot!!! 
*/

// déclaration des librairies utilisées
#include <BrasRobot.h>

//declaration des variables
BrasRobot brasrobot;


//initialisation des données du programme
void setup(){
brasrobot.activerMoteurs();
brasrobot.initPosition();


}
//methode principale, le programme boucle dessus
void loop()
{
brasrobot.finTravail();
}
