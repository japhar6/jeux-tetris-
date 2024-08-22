#include "Piecetetris.h"
#include "GameGrid.h"
#include "GameLogic.h"
#include <cstdlib>
#include <ctime>

//piecesamy hafa
TypePiece obtenirTypePieceAleatoire() {
    std::srand(static_cast<unsigned>(std::time(0)));
    int type = std::rand() % 7;
    return static_cast<TypePiece>(type);
}

void initialiserPiece(PieceTetris& piece, TypePiece type) {

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            piece.forme[i][j] = false;
        }
    }

    piece.x = 0;
    piece.y = 0;

    switch (type) {
        case TypePiece::I:
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            piece.forme[1][2] = true;
            piece.forme[1][3] = true;
            break;
        case TypePiece::O:
            piece.forme[0][0] = true;
            piece.forme[0][1] = true;
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            break;
        case TypePiece::T:
            piece.forme[0][1] = true;
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            piece.forme[1][2] = true;
            break;
        case TypePiece::S:
            piece.forme[0][1] = true;
            piece.forme[0][2] = true;
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            break;
        case TypePiece::Z:
            piece.forme[0][0] = true;
            piece.forme[0][1] = true;
            piece.forme[1][1] = true;
            piece.forme[1][2] = true;
            break;
        case TypePiece::L:
            piece.forme[0][0] = true;
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            piece.forme[1][2] = true;
            break;
        case TypePiece::J:
            piece.forme[0][2] = true;
            piece.forme[1][0] = true;
            piece.forme[1][1] = true;
            piece.forme[1][2] = true;
            break;
    }
}

void rotationPiece(PieceTetris& piece, GrilleJeu& grille) {

    bool temp[4][4];


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            temp[i][j] = piece.forme[3-j][i];
        }
    }


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            int nouvelleX = piece.x + i;
            int nouvelleY = piece.y + j;
            if (temp[i][j] && (nouvelleX < 0 || nouvelleX >= LARGEUR_GRILLE || nouvelleY < 0 || nouvelleY >= HAUTEUR_GRILLE || grille.grille[nouvelleX][nouvelleY])) {
                return;
            }
        }
    }


    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            piece.forme[i][j] = temp[i][j];
        }
    }
}

