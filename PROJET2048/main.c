#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 4

void afficherGrille(int grille[TAILLE][TAILLE]);
void initialiserGrille(int grille[TAILLE][TAILLE]);
void ajouterNombreAleatoire(int grille[TAILLE][TAILLE]);
void deplacerGauche(int grille[TAILLE][TAILLE]);
void fusionnerGauche(int grille[TAILLE][TAILLE]);
void deplacerDroite(int grille[TAILLE][TAILLE]);
void fusionnerDroite(int grille[TAILLE][TAILLE]);

int main()
{
    int grille[TAILLE][TAILLE];
    char choix;

    srand(time(NULL));

    initialiserGrille(grille);
    ajouterNombreAleatoire(grille);
    ajouterNombreAleatoire(grille);

    do
    {
        afficherGrille(grille);

        printf("Choisis une direction :\n");
        printf("z = haut, s = bas, q = gauche, d = droite\n");
        printf("x = quitter\n");
        printf("Ton choix : ");

        scanf(" %c", &choix);

        if (choix == 'q')
        {
            deplacerGauche(grille);
            fusionnerGauche(grille);
            deplacerGauche(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix == 'd')
        {
            deplacerDroite(grille);
            fusionnerDroite(grille);
            deplacerDroite(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix != 'x')
        {
            printf("Direction pas encore codee.\n");
        }

    } while (choix != 'x');

    printf("Fin du jeu.\n");

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

void deplacerGauche(int grille[TAILLE][TAILLE])
{
    int i, j, k;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 1; j < TAILLE; j++)
        {
            if (grille[i][j] != 0)
            {
                k = j;

                while (k > 0 && grille[i][k - 1] == 0)
                {
                    grille[i][k - 1] = grille[i][k];
                    grille[i][k] = 0;
                    k--;
                }
            }
        }
    }
}

void fusionnerGauche(int grille[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            if (grille[i][j] != 0 &&
                grille[i][j] == grille[i][j + 1])
            {
                grille[i][j] *= 2;
                grille[i][j + 1] = 0;
            }
        }
    }
}

void deplacerDroite(int grille[TAILLE][TAILLE])
{
    int i, j, k;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = TAILLE - 2; j >= 0; j--)
        {
            if (grille[i][j] != 0)
            {
                k = j;

                while (k < TAILLE - 1 && grille[i][k + 1] == 0)
                {
                    grille[i][k + 1] = grille[i][k];
                    grille[i][k] = 0;
                    k++;
                }
            }
        }
    }
}

void fusionnerDroite(int grille[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = TAILLE - 1; j > 0; j--)
        {
            if (grille[i][j] != 0 &&
                grille[i][j] == grille[i][j - 1])
            {
                grille[i][j] *= 2;
                grille[i][j - 1] = 0;
            }
        }
    }
}
