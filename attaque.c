#include <stdio.h>
#include <stdbool.h>
#include <math.h>

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
} Explorer;

// Fonction pour calculer la distance entre deux points
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

// Fonction pour identifier les vaisseaux ennemis à proximité de l'explorateur
void identifyEnemyShips(Explorer *explorer, Ship *ships, int num_ships) {
    for (int i = 0; i < num_ships; i++) {
        // Vérifier si le vaisseau est ennemi et à moins de 5 000 km de l'explorateur
        if (ships[i].is_enemy && distance(explorer->position_x, explorer->position_y, ships[i].position_x, ships[i].position_y) <= 5000) {
            printf("Enemy ship %d detected by explorer %d\n", ships[i].id, explorer->id);
        }
    }
}

// Fonction pour déployer stratégiquement les attaquants vers les vaisseaux ennemis identifiés
void deployAttackers(Ship *enemy_ships, int num_enemy_ships, Ship *attackers, int num_attackers) {
    // Exemple : déployer les attaquants vers les vaisseaux ennemis les plus proches
    for (int i = 0; i < num_attackers; i++) {
        int closest_enemy_index = -1;
        double min_distance = INFINITY;

        for (int j = 0; j < num_enemy_ships; j++) {
            double dist = distance(attackers[i].position_x, attackers[i].position_y, enemy_ships[j].position_x, enemy_ships[j].position_y);
            if (dist < min_distance) {
                min_distance = dist;
                closest_enemy_index = j;
            }
        }

        if (closest_enemy_index != -1) {
            printf("Attacker %d deployed towards enemy ship %d\n", attackers[i].id, enemy_ships[closest_enemy_index].id);
            // Supposons que le vaisseau attaquant se déplace vers le vaisseau ennemi le plus proche
            attackers[i].position_x = enemy_ships[closest_enemy_index].position_x;
            attackers[i].position_y = enemy_ships[closest_enemy_index].position_y;
        }
    }
}

int main() {
    // Exemple d'explorateur et de vaisseaux ennemis
    Explorer explorer = {1, 1000, 1000};
    Ship enemy_ships[] = {{1, 1500, 1500, true}, {2, 2000, 2000, true}};
    int num_enemy_ships = sizeof(enemy_ships) / sizeof(enemy_ships[0]);

    // Exemple de déploiement d'attaquants
    Ship attackers[] = {{1, 500, 500, false}, {2, 800, 800, false}};
    int num_attackers = sizeof(attackers) / sizeof(attackers[0]);

    // Identification des vaisseaux ennemis par l'explorateur
    identifyEnemyShips(&explorer, enemy_ships, num_enemy_ships);

    // Déploiement stratégique des attaquants
    deployAttackers(enemy_ships, num_enemy_ships, attackers, num_attackers);

    return 0;
}
