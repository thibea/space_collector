#include "main.h"

// void movePlane(int Id, int angle, int speed);

/**les Vaisseau *****--------********/
// typedef struct Plane;
typedef struct Plane
{
    signed char cmd[5];
    int Id_Plane;
    int angle;
    int speed;
} PlaneV;

extern PlaneV TabPlane[9];
extern PlaneV p1;
extern PlaneV p2;
extern PlaneV p3;
extern PlaneV p4;
extern PlaneV p5;
extern PlaneV p6;
extern PlaneV p7;
extern PlaneV p8;
extern PlaneV p9;
/******Finn*******/

/**les planettes *****--------********/
typedef struct Planette
{
    char p[2];
    int Id_Planette;
    int posX;
    int posY;
    int Id_Ship;
    int saved;
} PlanetteP;

extern PlanetteP TabPlanette[10];
/******Finn***************/

void afficher(PlaneV *plane);
void copierTxt(char *AddVariable, char const *chaine);
void formatageData(char DataServer[], char *recBuffer);