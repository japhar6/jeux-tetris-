#include "PieceTetris.h"
#include "GameGrid.h"
#include "GameLogic.h"
#include <iostream>
#include <chrono>
#include <thread>
#include <conio.h>
#include <cstdlib>

int main() {
    GrilleJeu grille;
    PieceTetris piece;
    initialiserGrille(grille);
    initialiserPiece(piece, TypePiece::I);

    bool jeuEnCours = true;
    auto derniereDescente = std::chrono::steady_clock::now();
    const auto intervalleDescente = std::chrono::milliseconds(500);

    while (jeuEnCours) {

        if (_kbhit()) {
            char input = _getch();
            gererEntree(input, piece, grille);
        }

        auto maintenant = std::chrono::steady_clock::now();
        if (maintenant - derniereDescente >= intervalleDescente) {
            deplacerPiece(grille, piece, 0, 1);
            derniereDescente = maintenant; // réinitialise le temps de la dernièredescente


            system("CLS");
            afficherGrilleAvecPiece(grille, piece);
        }

        std::this_thread::sleep_for(std::chrono::milliseconds(50));
    }

    return 0;
}
