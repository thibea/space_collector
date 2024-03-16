#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les informations de la commande FIRE
typedef struct {
    int ship_id;
    int angle;
} FireCommand;

// Fonction pour traiter la commande FIRE
FireCommand processFireCommand(const char *command) {
    FireCommand fire;

    // Utilisation de sscanf pour extraire les valeurs des paramètres
    sscanf(command, "FIRE %d %d", &fire.ship_id, &fire.angle);

    return fire;
}

int main() {
    // Exemple de commande FIRE
    const char *command = "FIRE 5 90";

    // Traitement de la commande FIRE
    FireCommand fire = processFireCommand(command);

    // Affichage des informations extraites
    printf("Ship ID: %d\n", fire.ship_id);
    printf("Angle: %d\n", fire.angle);

    return 0;
}
