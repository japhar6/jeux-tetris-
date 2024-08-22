# Tetris en C++

Ce projet est une implémentation du jeu classique Tetris en C++ utilisant une grille de jeu en console. Ce fichier `README.md` explique comment exécuter le programme et comment jouer au jeu.

## Prérequis

Avant de pouvoir exécuter le programme, assurez-vous d'avoir les éléments suivants installés :

- [Un compilateur C++](https://gcc.gnu.org/) (comme GCC ou Clang).
- [Code::Blocks](http://www.codeblocks.org/) ou tout autre IDE ou éditeur de texte avec support pour C++.

## Compilation et Exécution

### Avec Code::Blocks

1. **Téléchargez et installez Code::Blocks** (si ce n'est pas déjà fait).
2. **Ouvrez le projet** :
   - Lancez Code::Blocks.
   - Cliquez sur `Fichier` -> `Ouvrir un projet`.
   - Sélectionnez le fichier `.cbp` du projet Tetris.
3. **Compilez le projet** :
   - Cliquez sur le bouton `Construire` (ou appuyez sur `F9`).
4. **Exécutez le programme** :
   - Cliquez sur le bouton `Exécuter` (ou appuyez sur `Ctrl+F9`).

### Avec la Ligne de Commande

1. **Ouvrez un terminal**.
2. **Accédez au répertoire du projet** où se trouvent les fichiers source.
3. **Compilez les fichiers** avec le compilateur. Par exemple, avec GCC :

   ```bash
   g++ -o tetris main.cpp PieceTetris.cpp GameGrid.cpp GameLogic.cpp



Comment Jouer
Commandes
Déplacer la pièce vers la gauche : q
Déplacer la pièce vers la droite : d
Descendre la pièce : s
Faire pivoter la pièce : w
Objectif du Jeu
Le but de Tetris est de remplir les lignes horizontales de la grille sans laisser d'espaces vides. Lorsque vous faites tomber des pièces, elles se déplacent vers le bas et peuvent se déplacer à gauche ou à droite. Vous pouvez faire pivoter les pièces pour les adapter aux espaces vides de la grille.

Fin du Jeu
Le jeu se termine lorsque de nouvelles pièces ne peuvent plus entrer dans la grille en raison de l'empilement des pièces déjà placées. Lorsque le jeu est terminé, le score final est affiché, et vous serez invité à quitter le programme.