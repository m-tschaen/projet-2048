#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 4

void afficherGrille(int grille[TAILLE][TAILLE], int score);
void initialiserGrille(int grille[TAILLE][TAILLE]);
void ajouterNombreAleatoire(int grille[TAILLE][TAILLE]);
int verifierVictoire(int grille[TAILLE][TAILLE]);
int verifierDefaite(int grille[TAILLE][TAILLE]);

void deplacerGauche(int grille[TAILLE][TAILLE]);
void fusionnerGauche(int grille[TAILLE][TAILLE], int *score);

void deplacerDroite(int grille[TAILLE][TAILLE]);
void fusionnerDroite(int grille[TAILLE][TAILLE], int *score);

void deplacerHaut(int grille[TAILLE][TAILLE]);
void fusionnerHaut(int grille[TAILLE][TAILLE], int *score);

void deplacerBas(int grille[TAILLE][TAILLE]);
void fusionnerBas(int grille[TAILLE][TAILLE], int *score);

int main()
{
    int grille[TAILLE][TAILLE];
    char choix;
    int gagne = 0;
    int perdu = 0;
    int score = 0;

    srand(time(NULL));

    initialiserGrille(grille);
    ajouterNombreAleatoire(grille);
    ajouterNombreAleatoire(grille);

    do
    {
        afficherGrille(grille, score);

        printf("Choisis une direction :\n");
        printf("z = haut, s = bas, q = gauche, d = droite\n");
        printf("x = quitter\n");
        printf("Ton choix : ");

        scanf(" %c", &choix);

        if (choix == 'q')
        {
            deplacerGauche(grille);
            fusionnerGauche(grille, &score);
            deplacerGauche(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix == 'd')
        {
            deplacerDroite(grille);
            fusionnerDroite(grille, &score);
            deplacerDroite(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix == 'z')
        {
            deplacerHaut(grille);
            fusionnerHaut(grille, &score);
            deplacerHaut(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix == 's')
        {
            deplacerBas(grille);
            fusionnerBas(grille, &score);
            deplacerBas(grille);
            ajouterNombreAleatoire(grille);
        }
        else if (choix != 'x')
        {
            printf("Direction inconnue.\n");
        }

        gagne = verifierVictoire(grille);
        perdu = verifierDefaite(grille);

    } while (choix != 'x' && gagne == 0 && perdu == 0);

    afficherGrille(grille, score);

    if (gagne == 1)
    {
        printf("Bravo, vous avez atteint 2048 !\n");
    }
    else if (perdu == 1)
    {
        printf("Vous avez perdu, aucun mouvement possible.\n");
    }
    else
    {
        printf("Fin du jeu.\n");
    }

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
    int ligne, colonne;

    do
    {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;
    }
    while (grille[ligne][colonne] != 0);

    grille[ligne][colonne] = 2;
}

int verifierVictoire(int grille[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 2048)
            {
                return 1;
            }
        }
    }

    return 0;
}

int verifierDefaite(int grille[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (grille[i][j] == 0)
            {
                return 0;
            }
        }
    }

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            if (grille[i][j] == grille[i][j + 1])
            {
                return 0;
            }
        }
    }

    for (j = 0; j < TAILLE; j++)
    {
        for (i = 0; i < TAILLE - 1; i++)
        {
            if (grille[i][j] == grille[i + 1][j])
            {
                return 0;
            }
        }
    }

    return 1;
}

void afficherGrille(int grille[TAILLE][TAILLE], int score)
{
    int i, j;

    printf("\n===== 2048 =====\n");
    printf("Score : %d\n\n", score);

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

void fusionnerGauche(int grille[TAILLE][TAILLE], int *score)
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE - 1; j++)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j + 1])
            {
                grille[i][j] *= 2;
                *score += grille[i][j];
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

void fusionnerDroite(int grille[TAILLE][TAILLE], int *score)
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = TAILLE - 1; j > 0; j--)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i][j - 1])
            {
                grille[i][j] *= 2;
                *score += grille[i][j];
                grille[i][j - 1] = 0;
            }
        }
    }
}

void deplacerHaut(int grille[TAILLE][TAILLE])
{
    int i, j, k;

    for (j = 0; j < TAILLE; j++)
    {
        for (i = 1; i < TAILLE; i++)
        {
            if (grille[i][j] != 0)
            {
                k = i;

                while (k > 0 && grille[k - 1][j] == 0)
                {
                    grille[k - 1][j] = grille[k][j];
                    grille[k][j] = 0;
                    k--;
                }
            }
        }
    }
}

void fusionnerHaut(int grille[TAILLE][TAILLE], int *score)
{
    int i, j;

    for (j = 0; j < TAILLE; j++)
    {
        for (i = 0; i < TAILLE - 1; i++)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i + 1][j])
            {
                grille[i][j] *= 2;
                *score += grille[i][j];
                grille[i + 1][j] = 0;
            }
        }
    }
}

void deplacerBas(int grille[TAILLE][TAILLE])
{
    int i, j, k;

    for (j = 0; j < TAILLE; j++)
    {
        for (i = TAILLE - 2; i >= 0; i--)
        {
            if (grille[i][j] != 0)
            {
                k = i;

                while (k < TAILLE - 1 && grille[k + 1][j] == 0)
                {
                    grille[k + 1][j] = grille[k][j];
                    grille[k][j] = 0;
                    k++;
                }
            }
        }
    }
}

void fusionnerBas(int grille[TAILLE][TAILLE], int *score)
{
    int i, j;

    for (j = 0; j < TAILLE; j++)
    {
        for (i = TAILLE - 1; i > 0; i--)
        {
            if (grille[i][j] != 0 && grille[i][j] == grille[i - 1][j])
            {
                grille[i][j] *= 2;
                *score += grille[i][j];
                grille[i - 1][j] = 0;
            }
        }
    }
}
