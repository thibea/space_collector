#include <stdio.h>
#include <stdbool.h>

// Structure pour représenter une planète
typedef struct {
    int id;
    int position_x;
    int position_y;
    bool is_collected;
} Planet;

// Structure pour représenter un collecteur
typedef struct {
    int id;
    int position_x;
    int position_y;
} Collector;

// Fonction pour déplacer un collecteur vers une position donnée
void moveCollector(Collector *collector, int target_x, int target_y, int speed) {
    // Calculer la direction et la distance
    int dx = target_x - collector->position_x;
    int dy = target_y - collector->position_y;
    double distance = sqrt(dx*dx + dy*dy);
    
    // Calculer les composantes de la vitesse
    double vx = dx / distance * speed;
    double vy = dy / distance * speed;
    
    // Mettre à jour la position du collecteur
    collector->position_x += (int)vx;
    collector->position_y += (int)vy;
}

// Fonction pour simuler la collecte des planètes
void collectPlanets(Collector *collectors, int num_collectors, Planet *planets, int num_planets) {
    for (int i = 0; i < num_collectors; i++) {
        for (int j = 0; j < num_planets; j++) {
            // Vérifier si le collecteur est à moins de 200 km de la planète non collectée
            if (!planets[j].is_collected && distance(collectors[i].position_x, collectors[i].position_y, planets[j].position_x, planets[j].position_y) < 200) {
                // Collecter la planète
                planets[j].is_collected = true;
                printf("Collector %d collected planet %d\n", collectors[i].id, planets[j].id);
            }
        }
    }
}

int main() {
    // Exemple de collecteurs et de planètes
    Collector collectors[] = {{1, 1000, 1000}, {2, 1500, 1500}};
    int num_collectors = sizeof(collectors) / sizeof(collectors[0]);

    Planet planets[] = {{1, 200, 200, false}, {2, 500, 500, false}};
    int num_planets = sizeof(planets) / sizeof(planets[0]);

    // Simulation du jeu
    while (true) {
        // Déplacement des collecteurs vers les planètes ciblées
        for (int i = 0; i < num_collectors; i++) {
            moveCollector(&collectors[i], planets[i].position_x, planets[i].position_y, 1000);
        }

        // Collecte des planètes
        collectPlanets(collectors, num_collectors, planets, num_planets);
        
        // Autres actions...

        // Pause pour simuler le temps de jeu
        // sleep(1);
    }

    return 0;
}
