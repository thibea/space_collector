#include <stdio.h>
#include <stdbool.h>

// Structure pour représenter une planète
typedef struct {
    int id;
    int position_x;
    int position_y;
    bool is_collected;
} Planet;

// Structure pour représenter un vaisseau
typedef struct {
    int id;
    int position_x;
    int position_y;
    bool is_enemy;
} Ship;

// Structure pour représenter un explorateur
typedef struct {
    int id;
    int position_x;
    int position_y;
    bool is_damaged;
} Explorer;

// Fonction pour simuler la commande RADAR
void useRadar(Explorer *explorer, Planet *planets, int num_planets, Ship *ships, int num_ships) {
    // Simulation de l'utilisation du radar
    printf("Explorer %d is using RADAR...\n", explorer->id);

    // Analyse des données radar
    for (int i = 0; i < num_planets; i++) {
        // Repérer les planètes non collectées
        if (!planets[i].is_collected) {
            printf("Planet %d detected at (%d, %d)\n", planets[i].id, planets[i].position_x, planets[i].position_y);
        }
    }

    for (int i = 0; i < num_ships; i++) {
        // Repérer les vaisseaux ennemis
        if (ships[i].is_enemy) {
            printf("Enemy ship %d detected at (%d, %d)\n", ships[i].id, ships[i].position_x, ships[i].position_y);
        }
    }
}

// Fonction pour simuler la maintenance des explorateurs
void repairExplorer(Explorer *explorer) {
    // Simulation de la réparation de l'explorateur
    printf("Repairing Explorer %d...\n", explorer->id);
    explorer->is_damaged = false;
}

int main() {
    // Exemple d'explorateur
    Explorer explorer = {1, 1000, 1000, false};

    // Exemple de planètes et de vaisseaux ennemis
    Planet planets[] = {{1, 200, 200, false}, {2, 500, 500, true}};
    int num_planets = sizeof(planets) / sizeof(planets[0]);

    Ship ships[] = {{1, 1500, 1500, true}, {2, 2000, 2000, false}};
    int num_ships = sizeof(ships) / sizeof(ships[0]);

    // Utilisation régulière de la commande RADAR
    useRadar(&explorer, planets, num_planets, ships, num_ships);

    // Maintenance des explorateurs
    if (explorer.is_damaged) {
        repairExplorer(&explorer);
    }

    return 0;
}
