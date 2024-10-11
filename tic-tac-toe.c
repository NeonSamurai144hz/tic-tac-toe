#include <stdio.h>
#include <stdlib.h>
#include "tic-tac-toe.h"


void afficher_plateau(char *plateau)
{
    printf(" %c | %c | %c \n", plateau[0], plateau[1], plateau[2]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", plateau[3], plateau[4], plateau[5]);
    printf("---|---|---\n");
    printf(" %c | %c | %c \n", plateau[6], plateau[7], plateau[8]);
}


int verifier_victoire(char *plateau)
{

    for (int i = 0; i < 3; i++)
    {
        if (plateau[i * 3] == plateau[i * 3 + 1] && plateau[i * 3] == plateau[i * 3 + 2] && plateau[i * 3] != ' ')
            return 1;
        if (plateau[i] == plateau[i + 3] && plateau[i] == plateau[i + 6] && plateau[i] != ' ')
            return 1;
    }

    if (plateau[0] == plateau[4] && plateau[0] == plateau[8] && plateau[0] != ' ')
        return 1;
    if (plateau[2] == plateau[4] && plateau[2] == plateau[6] && plateau[2] != ' ')
        return 1;
    return 0;
}


int plateau_plein(char *plateau)
{
    for (int i = 0; i < 9; i++)
     {
        if (plateau[i] == ' ') {
            return 0;
        }
    }
    return 1;
}



void jouer_joueur(char *plateau)
{
    int ligne, colonne;
    do {
        printf("Entrez la ligne (0-2) : ");
        scanf("%d", &ligne);
        printf("Entrez la colonne (0-2) : ");
        scanf("%d", &colonne);
    } while (ligne < 0 || ligne > 2 || colonne < 0 || colonne > 2 || plateau[ligne * 3 + colonne] != ' ');
    plateau[ligne * 3 + colonne] = 'X';
}


void jouer_ordinateur(char *plateau)
{
    int position;
    do {
        position = rand() % 9;
    } while (plateau[position] != ' ');
    plateau[position] = 'O';
}

