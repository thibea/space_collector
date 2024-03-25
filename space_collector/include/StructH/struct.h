#include "main.h"

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
extern PlaneV TabPlaneV[8];

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

// Stockage les information sous forme de tableau
extern PlanetteP TabPlanette[10];

// Structure permet de stocker tous les infos de radar en ligne
typedef struct InfosRadar
{
    char infos[25];

} RetourInfoRadar;

void afficher(PlaneV *plane);