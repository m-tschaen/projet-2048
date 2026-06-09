#include <stdio.h>
#include <stdlib.h>

#define TAILLE 4

void afficherGrille(int grille[TAILLE][TAILLE]);

int main()
{
    int grille[TAILLE][TAILLE] = {
        {0, 0, 0, 0},
        {0, 2, 0, 0},
        {0, 0, 2, 0},
        {0, 0, 0, 0}
    };

    afficherGrille(grille);

    return 0;
}

void afficherGrille(int grille[TAILLE][TAILLE])
{
    int i, j;

    printf("\n===== 2048 =====\n\n");

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            printf("| %4d ", grille[i][j]);
        }
        printf("|\n");
    }

    printf("\n");
}
