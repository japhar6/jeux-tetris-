#ifndef GAMEGRID_H
#define GAMEGRID_H





const int LARGEUR_GRILLE = 10;
const int HAUTEUR_GRILLE = 20;

struct GrilleJeu {
    bool grille[LARGEUR_GRILLE][HAUTEUR_GRILLE];
};

void initialiserGrille(GrilleJeu& grille);
void afficherGrille(const GrilleJeu& grille);

#endif
