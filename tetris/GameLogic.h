#ifndef GAMELOGIC_H
#define GAMELOGIC_H

#include "GameGrid.h"
#include "Piecetetris.h"


bool verifierFinDeJeu(const GrilleJeu& grille, const PieceTetris& piece);
void gererEntree(char input, PieceTetris& piece, GrilleJeu& grille);
bool peutDeplacer(const GrilleJeu& grille, const PieceTetris& piece, int dx, int dy);
void deplacerPiece(GrilleJeu& grille, PieceTetris& piece, int dx, int dy);
void effacerLignes(GrilleJeu& grille);
void afficherGrilleAvecPiece(const GrilleJeu& grille, const PieceTetris& piece);
void ajouterPieceAlaGrille(GrilleJeu& grille, const PieceTetris& piece);
PieceTetris genererNouvellePiece();

#endif
