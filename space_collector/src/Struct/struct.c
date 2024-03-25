
#include <string.h>
#include "StructH/struct.h"

PlaneV TabPlaneV[8];       // Tableau des vaiseau utilise pour envoyer les requet vers terminal serie
PlanetteP TabPlanette[10]; // Stockage les information sous forme de tableau

// Permet d'afficher les message dans le terminal serie en fonction des commandes
void afficher(PlaneV *plane)
{
    char CMD[16];
    if ((strcmp(plane->cmd, "RADAR")) == 0)
    {
        snprintf(CMD, sizeof(CMD), "%s %d ", plane->cmd, plane->Id_Plane);
    }
    else if ((strcmp(plane->cmd, "FIRE")) == 0)
    {
        snprintf(CMD, sizeof(CMD), "%s %d %d", plane->cmd, plane->Id_Plane, plane->angle);
    }
    else
    {
        snprintf(CMD, sizeof(CMD), "%s %d %d %d", plane->cmd, plane->Id_Plane, plane->angle, plane->speed);
    }

    puts(CMD);
}