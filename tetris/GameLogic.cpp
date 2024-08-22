#include "GameLogic.h"
#include <iostream>
#include "Piecetetris.h"
#include <cstdlib>

bool verifierFinDeJeu(const GrilleJeu& grille, const PieceTetris& piece) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.forme[i][j]) {
                int nouvelleX = piece.x + i;
                int nouvelleY = piece.y + j;
                if (nouvelleY < 0 || nouvelleY >= HAUTEUR_GRILLE || nouvelleX < 0 || nouvelleX >= LARGEUR_GRILLE || grille.grille[nouvelleX][nouvelleY]) {
                    return true;
                }
            }
        }
    }
    return false;
}

void gererEntree(char input, PieceTetris& piece, GrilleJeu& grille) {
    switch (input) {
        case 'q': // Gauche
            deplacerPiece(grille, piece, -1, 0);
            break;
        case 'd': // Droite
            deplacerPiece(grille, piece, 1, 0);
            break;
        case 's': // Bas
            deplacerPiece(grille, piece, 0, 1);
            break;
        case 'w': // Rotation
            rotationPiece(piece, grille);
            break;
    }
}

bool peutDeplacer(const GrilleJeu& grille, const PieceTetris& piece, int dx, int dy) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            if (piece.forme[i][j]) {
                int nouvelleX = piece.x + i + dx;
                int nouvelleY = piece.y + j + dy;
                if (nouvelleX < 0 || nouvelleX >= LARGEUR_GRILLE || nouvelleY < 0 || nouvelleY >= HAUTEUR_GRILLE || grille.grille[nouvelleX][nouvelleY]) {
                    return false;
                }
            }
        }
    }
    return true;
}

void deplacerPiece(GrilleJeu& grille, PieceTetris& piece, int dx, int dy) {
    if (peutDeplacer(grille, piece, dx, dy)) {
        piece.x += dx;
        piece.y += dy;
    } else if (dy > 0) {
        for (int i = 0; i < 4; ++i) {
            for (int j = 0; j < 4; ++j) {
                if (piece.forme[i][j]) {
                    grille.grille[piece.x + i][piece.y + j] = true;
                }
            }
        }
        effacerLignes(grille);


        PieceTetris nouvellePiece;
        TypePiece typeAleatoire = obtenirTypePieceAleatoire();
        initialiserPiece(nouvellePiece, typeAleatoire);
        if (verifierFinDeJeu(grille, nouvellePiece)) {
            std::cout << "Jeu Terminé !" << std::endl;
            std::exit(0);
        }
        piece = nouvellePiece;
    }
}


void effacerLignes(GrilleJeu& grille) {
    for (int y = 0; y < HAUTEUR_GRILLE; ++y) {
        bool ligneComplete = true;
        for (int x = 0; x < LARGEUR_GRILLE; ++x) {
            if (!grille.grille[x][y]) {
                ligneComplete = false;
                break;
            }
        }
        if (ligneComplete) {
            for (int yy = y; yy > 0; --yy) {
                for (int xx = 0; xx < LARGEUR_GRILLE; ++xx) {
                    grille.grille[xx][yy] = grille.grille[xx][yy - 1];
                }
            }
            for (int xx = 0; xx < LARGEUR_GRILLE; ++xx) {
                grille.grille[xx][0] = false;
            }
        }
    }
}void afficherGrilleAvecPiece(const GrilleJeu& grille, const PieceTetris& piece) {
    for (int y = 0; y < HAUTEUR_GRILLE; ++y) {
        for (int x = 0; x < LARGEUR_GRILLE; ++x) {
            if (grille.grille[x][y]) {
                std::cout << "#";
            } else {
                bool pieceAffichee = false;
                for (int i = 0; i < 4; ++i) {
                    for (int j = 0; j < 4; ++j) {
                        if (piece.forme[i][j] && piece.x + i == x && piece.y + j == y) {
                            std::cout << "@";
                            pieceAffichee = true;
                            break;
                        }
                    }
                    if (pieceAffichee) break;
                }
                if (!pieceAffichee) std::cout << ".";
            }
        }
        std::cout << std::endl;
    }
}
