
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

// Permet de copier les chaine dans une autre variable
void copierTxt(char *AddVariable, char const *chaine)
{
    strcpy(AddVariable, chaine);
}

// Permet de decouper les donnees renvoyer par les radar en ligne, stocke dans une tableau de structure
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