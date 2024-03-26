
#include <string.h>
#include "StructH/struct.h"

PlaneV TabPlaneV[MAX_Plane];                           // Tableau des vaiseau utilise pour envoyer les requet vers terminal serie
PlanetteP TabPlanette[MAX_Planette];                   // Stockage les information de planette sous forme de tableau
RetourInfoRadar TabStockageInfoRadar[MAX_RetourRadar]; // Stockage tous les information de radar en ligne
DecoupeToken TabDecoupeToken[MAX_TOKENS];              // Stockage des data decouper dans la fonction "decoupeInfosRadar"

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

// Permet d'afficher tous les information stocke dans structre "InfosRadar" pour un test visuel
void affichageInfoStructure(RetourInfoRadar *ReadInfo)
{
    for (int i = 0; i < MAX_RetourRadar; i++)
    {
        printf("Infos radar stocke [%d] : %s\n", i, ReadInfo[i].infos);
    }
}