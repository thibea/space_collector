
#include <string.h>
#include "Plane/Plane.h"
#include "StructH/struct.h"

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

// Permet de decouper les donnees renvoyer par les radar en ligne, stocke dans une tableau de structure "InfosRadar"
void decoupeDataRadarLigne(char DataServer[], char *retourLigneInfo)
{
    char seperat[] = ",";
    char *chaineCoupe = strtok(DataServer, seperat);
    int IncmentNum = 0;

    // Tanque la chineCoupe n'est pas vide, ça boucle
    while (chaineCoupe != NULL)
    {
        memcpy(retourLigneInfo, chaineCoupe, strlen(chaineCoupe) + 1); // Copie les chaine de "chaineCoupe" dans le variable "retourLigneInfo"
        strcpy(TabStockageInfoRadar[IncmentNum].infos, chaineCoupe);

        // printf("*retourLigneInfo : %s \n", retourLigneInfo); // Test pour visualiser l'afiichage de resultat
        // printf("*chaineCoupe : %s\n", chaineCoupe);          // Test pour visualiser l'afiichage de resultat
        // printf("increNum :  %d \n", IncmentNum);             // Test pour visualiser l'afiichage de resultat

        IncmentNum++;
        chaineCoupe = strtok(NULL, seperat);
    }
}

// Permet de decouper les chaine pour les stocker dans struct DataTocken
void decoupeInfosRadar(char *delimiter, char *Lettre)
{
    int count = 0;

    for (int a = 0; a < MAX_RetourRadar; a++)
    {
        if (strchr(TabStockageInfoRadar[a].infos, Lettre) != NULL)
        {
            // Découper la chaîne en tokens
            char *ChaineToken = strtok(TabStockageInfoRadar[a].infos, delimiter);

            // Stocker chaque token dans le tableau de structures
            while (ChaineToken != NULL)
            {
                strcpy(TabDecoupeToken[count].token, ChaineToken);
                ChaineToken = strtok(NULL, delimiter);
                count++;
            }
        }
    }
}

// Afficher les information stockés dans le tableau de structures DataTocken
void afficheInfoDataTocken()
{
    printf("\n");
    for (int i = 0; i < MAX_TOKENS; i++)
    {
        printf("Tokens stockés[%d] : %s\n", i, TabDecoupeToken[i].token);
    }
}

// Permet de placer les information de planette stock dans le structure DataTocken
void coordonneePlanetteRecu()
{
    int i = 0;
    for (int j = 0; j < MAX_Plane; j++)
    {
        strcpy(TabPlanette[j].p, TabDecoupeToken[i].token);

        i = i + 1;
        TabPlanette[j].Id_Planette = atoi(TabDecoupeToken[i].token);

        i = i + 1;
        TabPlanette[j].posX = atoi(TabDecoupeToken[i].token);

        i = i + 1;
        TabPlanette[j].posY = atoi(TabDecoupeToken[i].token);

        i = i + 1;
        TabPlanette[j].Id_Ship = atoi(TabDecoupeToken[i].token);

        i = i + 1;
        TabPlanette[j].saved = atoi(TabDecoupeToken[i].token);

        i = i + 1;
    }
}