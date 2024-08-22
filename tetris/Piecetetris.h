#ifndef PIECETETRIS_H
#define PIECETETRIS_H
#include "GameGrid.h"

enum class TypePiece {
    I, J, L, O, S, T, Z
};

struct PieceTetris {
    bool forme[4][4];
    int x, y;
};

void initialiserPiece(PieceTetris& piece, TypePiece type);
TypePiece obtenirTypePieceAleatoire();
void rotationPiece(PieceTetris& piece, GrilleJeu& grille);
#endif
