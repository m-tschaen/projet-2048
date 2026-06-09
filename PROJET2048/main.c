#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 4

void afficherGrille(int grille[TAILLE][TAILLE]);
void initialiserGrille(int grille[TAILLE][TAILLE]);
void ajouterNombreAleatoire(int grille[TAILLE][TAILLE]);

int main()
{
    int grille[TAILLE][TAILLE];
    char choix;

    srand(time(NULL));

    initialiserGrille(grille);

    ajouterNombreAleatoire(grille);
    ajouterNombreAleatoire(grille);

    afficherGrille(grille);

    printf("Choisis une direction :\n");
    printf("z = haut, s = bas, q = gauche, d = droite\n");
    printf("Ton choix : ");
    scanf(" %c", &choix);

    printf("Tu as choisi : %c\n", choix);

    return 0;
}

void initialiserGrille(int grille[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            grille[i][j] = 0;
        }
    }
}

void ajouterNombreAleatoire(int grille[TAILLE][TAILLE])
{
    int ligne;
    int colonne;

    do
    {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;
    }
    while (grille[ligne][colonne] != 0);

    grille[ligne][colonne] = 2;
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
