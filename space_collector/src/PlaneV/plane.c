
#include <string.h>

#include "Plane/Plane.h"

/**********Function permet de deplacer les vaiseau****/
/**********
 * En parametre MOVE :
 *
 * ship_id : 1, 2, 3, 4, 5 : attaquants; 6, 7 : explorateurs; 8, 9 : collectionneurs
 *
 * {angle} : 0 à 360
 *
 * {speed} : 1 000 kms/s max for collectors; 2 000 kms/s max for explorers; 3 000 kms/s max for attackers;
 *
 */
/*void movePlane(int Id, int angle, int speed)
{

    char movecmd[16];
    movecmd[0] ='M';
    movecmd[1] ='O';
    movecmd[2] ='V';
    movecmd[3] ='E';
    movecmd[4] =' ';

    movecmd[0] ='R';
    movecmd[1] ='A';
    movecmd[2] ='D';
    movecmd[3] ='A';
    movecmd[4] ='R';
    movecmd[5] =' ';

    itoa(6, &movecmd[6], 10);
    //movecmd[7] =' ';

    itoa(6, &movecmd[8], 10);
    itoa(9, &movecmd[9], 10);
    movecmd[9] =' ';

    itoa(6, &movecmd[11], 10);
    itoa(0, &movecmd[12], 10);
    itoa(0, &movecmd[13], 10);

    puts(movecmd);
}*/

/***********Les extense de struc*************/
PlaneV p1;
PlaneV p2;
PlaneV p3;
PlaneV p4;
PlaneV p5;
PlaneV p6;
PlaneV p7;
PlaneV p8;
PlaneV p9;

/*extern PlanetteP pp0;
extern PlanetteP pp1;
extern PlanetteP pp2;
extern PlanetteP pp4;*/
/*******************fin des extense de struc*******/

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

void copierTxt(char *AddVariable, char const *chaine)
{
    strcpy(AddVariable, chaine);
}

void formatageData(char DataServer[], char *recBuffer)
{
    int longData = strlen(DataServer);
    char seperat[] = ",";
    char *p = strtok(DataServer, seperat);
    for (int i = 0; i < strlen(p); i++)
    {
        //*recBuffer = p[i];
        strcpy(&recBuffer, "MOVE MOC MOC");
        i++;
    }
}

/**
void parse_enemy_info(char *str, Enemi *e)
{
    char *token;

    // Utilisation de strtok pour découper la chaîne en tokens
    token = strtok(str, ",");
    if (token == NULL)
    {
        // fprintf(str, "Erreur: Impossible de récupérer la position X\n");
        return;
    }
    e->position_x = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        // fprintf(stderr, "Erreur: Impossible de récupérer la position Y\n");
        return;
    }
    e->position_y = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        // fprintf(stderr, "Erreur: Impossible de récupérer la santé\n");
        return;
    }
    e->health = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL)
    {
        // fprintf(stderr, "Erreur: Impossible de récupérer le dégât\n");
        return;
    }
    e->damage = atoi(token);
}*/

/*
void parse_enemy_info(char *str, Enemi *e) {
    char *token;

    // Utilisation de strtok pour découper la chaîne en tokens
    token = strtok(str, " ");
    if (token == NULL) {
        fprintf(stderr, "Erreur: Impossible de récupérer la position X\n");
        return;
    }
    e->position_x = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        fprintf(stderr, "Erreur: Impossible de récupérer la position Y\n");
        return;
    }
    e->position_y = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        //fprintf(stderr, "Erreur: Impossible de récupérer la santé\n");
        return;
    }
    e->health = atoi(token);

    token = strtok(NULL, " ");
    if (token == NULL) {
        //fprintf(stderr, "Erreur: Impossible de récupérer le dégât\n");
        return;
    }
    e->damage = atoi(token);
}
void movePlane(PlaneV *plane) {
    char movecmd[16];
    snprintf(movecmd, sizeof(movecmd), "MOVE %c %d %d  ", itoa(plane->Id_Plane, 1, 10), itoa(plane->angle,90 , 10), itoa(plane->speed,900 , 10));
    puts(movecmd);
}
Id_Plane;
    int angle;
    int speed;
    */
