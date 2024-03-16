#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Fonction pour traiter la commande RADAR
int processRadarCommand(const char *command) {
    int ship_id;

    // Utilisation de sscanf pour extraire la valeur de l'identifiant du vaisseau
    sscanf(command, "RADAR %d", &ship_id);

    return ship_id;
}

int main() {
    // Exemple de commande RADAR
    const char *command = "RADAR 7";

    // Traitement de la commande RADAR
    int ship_id = processRadarCommand(command);

    // Affichage de l'identifiant du vaisseau concerné
    printf("Ship ID: %d\n", ship_id);

    return 0;
}
