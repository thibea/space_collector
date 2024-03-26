#include "main.h"

// void movePlane(int Id, int angle, int speed);

void copierTxt(char *AddVariable, char const *chaine);                // Permet d'effectuer des copie des chaine
void decoupeDataRadarLigne(char DataServer[], char *retourLigneInfo); // Permet de decouper les donnees renvoyer par les radar en ligne,
void decoupeInfosRadar(char *delimiter, char *Lettre);                // Permet de decouper les chaine pour les stocker dans struct DataTocken
void afficheInfoDataTocken();                                         // Afficher les information stockés dans le tableau de structures DataTocken
void coordonneePlanetteRecu();                                        // Permet de placer les information de planette stock dans le structure DataTocken
