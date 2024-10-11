#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"

int main() {
    char plateau[9] = { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' };
    int joueur = 1;

    printf("Bienvenue au jeu de morpion !\n");

    while (1) {
        system("clear");
        afficher_plateau(plateau);

        if (joueur)
	{
            jouer_joueur(plateau);
        } else
	{
            jouer_ordinateur(plateau);
        }


        if (verifier_victoire(plateau))
	{
            afficher_plateau(plateau);
            if (joueur)
	{
                printf("Félicitations ! Vous avez gagné !\n");
            } else {
                printf("L'ordinateur a gagné.\n");
            }
            break;
        }


        if (plateau_plein(plateau))
	{
            afficher_plateau(plateau);
            printf("Match nul !\n");
            break;
        }

        joueur = !joueur;
    }

    return 0;
}

