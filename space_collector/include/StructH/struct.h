#include "main.h"

#define MAX_Plane 8
#define MAX_Planette 10
#define MAX_RetourRadar 10
#define MAX_TOKENS 20

// Structure pour les vaiseaux permet d'envoyer les commandevers le serveur
typedef struct Plane
{
    signed char cmd[5];
    int Id_Plane;
    int angle;
    int speed;
} PlaneV;

// P1 = TabPlaneV[0]; P2 = TabPlaneV[1]; P3 = TabPlaneV[2]; P4 = TabPlaneV[3]; P5 = TabPlaneV[4]
// P6 = TabPlaneV[5]; P7 = TabPlaneV[6]; P8 = TabPlaneV[7]; P9 = TabPlaneV[8];
extern PlaneV TabPlaneV[MAX_Plane];

// Structre permet de stocke les information des planettes à recuperer
typedef struct Planette
{
    char p[2];
    int Id_Planette;
    int posX;
    int posY;
    int Id_Ship;
    int saved;
} PlanetteP;

// Stockage les information de planette sous forme de tableau
extern PlanetteP TabPlanette[MAX_Planette];

// Structure permet de stocker tous les infos de radar en ligne
typedef struct InfosRadar
{
    char infos[25];

} RetourInfoRadar;

// Stockage tous les information de radar en ligne
extern RetourInfoRadar TabStockageInfoRadar[MAX_RetourRadar];

// Permet de stock tous les donnees decouper dans la fonction "decoupeInfosRadar"
typedef struct DataTocken
{
    char token[30];

} DecoupeToken;

// Stockage des data decouper dans la fonction ""
extern DecoupeToken TabDecoupeToken[MAX_TOKENS];

void afficher(PlaneV *plane);                           // Permet d'envoyer les commande vers les serveur via terminal serie
void affichageInfoStructure(RetourInfoRadar *ReadInfo); // Permet d'afficher tous les information stocke dans structre "InfosRadar"