#include "main.h"

// void movePlane(int Id, int angle, int speed);

/**les Vaisseau ******/
// typedef struct Plane;
typedef struct Plane
{
    signed char cmd[5];
    int Id_Plane;
    int angle;
    int speed;
} PlaneV;

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

typedef struct Planette
{
    int Id_Planette;
    int posX;
    int posY;
    int Id_Ship;
    int saved;
} PlanetteP;

void afficher(PlaneV *plane);
void copierTxt(char *AddVariable, char const *chaine);