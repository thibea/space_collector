#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure pour stocker les informations de la commande MOVE
typedef struct {
    int ship_id;
    int angle;
    int speed;
} MoveCommand;

// Fonction pour traiter la commande MOVE
MoveCommand processMoveCommand(const char *command) {
    MoveCommand move;

    // Utilisation de sscanf pour extraire les valeurs des paramètres
    sscanf(command, "MOVE %d %d %d", &move.ship_id, &move.angle, &move.speed);

    return move;
}

int main() {
    // Exemple de commande MOVE
    const char *command = "MOVE 3 45 2000";

    // Traitement de la commande MOVE
    MoveCommand move = processMoveCommand(command);

    // Affichage des informations extraites
    printf("Ship ID: %d\n", move.ship_id);
    printf("Angle: %d\n", move.angle);
    printf("Speed: %d\n", move.speed);

    return 0;
}
