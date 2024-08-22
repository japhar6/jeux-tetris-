#include "GameGrid.h"
#include <iostream>


void initialiserGrille(GrilleJeu& grille) {
    for (int x = 0; x < LARGEUR_GRILLE; ++x) {
        for (int y = 0; y < HAUTEUR_GRILLE; ++y) {
            grille.grille[x][y] = false;
        }
    }
}



