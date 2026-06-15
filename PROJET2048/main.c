#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAILLE 4  /* Taille de la grille (4x4) */

/* --- Prototypes des fonctions --- */
void afficherGrille(int grille[TAILLE][TAILLE], int score);
void initialiserGrille(int grille[TAILLE][TAILLE]);
void ajouterNombreAleatoire(int grille[TAILLE][TAILLE]);
int verifierVictoire(int grille[TAILLE][TAILLE]);
int verifierDefaite(int grille[TAILLE][TAILLE]);
void copierGrille(int source[TAILLE][TAILLE], int copie[TAILLE][TAILLE]);
int grillesDifferentes(int grille1[TAILLE][TAILLE], int grille2[TAILLE][TAILLE]);

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
    int ancienneGrille[TAILLE][TAILLE]; /* Sauvegarde avant chaque mouvement pour détecter un changement */
    char choix;
    char recommencer;
    int gagne;
    int perdu;
    int score;

    srand(time(NULL)); /* Initialisation du générateur aléatoire */

    printf("+--------------------------------------+\n");
    printf("|                 2048                 |\n");
    printf("+--------------------------------------+\n\n");
    printf("Chaque mouvement compte. Atteignez 2048 !\n\n");

    /* --- Boucle principale : permet de rejouer une partie --- */
    do
    {
        choix = ' ';
        gagne = 0;
        perdu = 0;
        score = 0;

        /* Initialisation de la grille et placement de deux tuiles de départ */
        initialiserGrille(grille);
        ajouterNombreAleatoire(grille);
        ajouterNombreAleatoire(grille);

        /* --- Boucle de jeu : tourne jusqu'à victoire, défaite ou abandon --- */
        do
        {
            afficherGrille(grille, score);
            copierGrille(grille, ancienneGrille); /* Sauvegarde l'état avant le mouvement */

            printf("+---------------------------+\n");
            printf("| [Z] Haut    [S] Bas       |\n");
            printf("| [Q] Gauche  [D] Droite    |\n");
            printf("| [X] Quitter               |\n");
            printf("+---------------------------+\n\n");
            printf("Votre choix : ");

            scanf(" %c", &choix);

            /* Application du mouvement selon la direction choisie :
               déplacement puis fusion puis déplacement pour combler les trous */
            if (choix == 'q')
            {
                deplacerGauche(grille);
                fusionnerGauche(grille, &score);
                deplacerGauche(grille);
            }
            else if (choix == 'd')
            {
                deplacerDroite(grille);
                fusionnerDroite(grille, &score);
                deplacerDroite(grille);
            }
            else if (choix == 'z')
            {
                deplacerHaut(grille);
                fusionnerHaut(grille, &score);
                deplacerHaut(grille);
            }
            else if (choix == 's')
            {
                deplacerBas(grille);
                fusionnerBas(grille, &score);
                deplacerBas(grille);
            }
            else if (choix != 'x')
            {
                printf("Direction inconnue.\n");
            }

            /* On ajoute une tuile aléatoire uniquement si la grille a changé */
            if ((choix == 'q' || choix == 'd' || choix == 'z' || choix == 's') &&
                grillesDifferentes(grille, ancienneGrille))
            {
                ajouterNombreAleatoire(grille);
            }

            gagne = verifierVictoire(grille);
            perdu = verifierDefaite(grille);

        } while (choix != 'x' && gagne == 0 && perdu == 0);

        afficherGrille(grille, score);

        /* Affichage du résultat de fin de partie */
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

        printf("\nVoulez-vous recommencer ? (o/n) : ");
        scanf(" %c", &recommencer);

    } while (recommencer == 'o' || recommencer == 'O');

    return 0;
}

/* Remplit toute la grille avec des zéros */
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

/* Place un 2 dans une case vide choisie aléatoirement */
void ajouterNombreAleatoire(int grille[TAILLE][TAILLE])
{
    int ligne, colonne;

    /* Recherche aléatoire d'une case vide (peut boucler longtemps si la grille est presque pleine) */
    do
    {
        ligne = rand() % TAILLE;
        colonne = rand() % TAILLE;
    }
    while (grille[ligne][colonne] != 0);

    grille[ligne][colonne] = 2;
}

/* Copie case par case la grille source dans copie */
void copierGrille(int source[TAILLE][TAILLE], int copie[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            copie[i][j] = source[i][j];
        }
    }
}

/* Retourne 1 si les deux grilles diffèrent, 0 si elles sont identiques */
int grillesDifferentes(int grille1[TAILLE][TAILLE], int grille2[TAILLE][TAILLE])
{
    int i, j;

    for (i = 0; i < TAILLE; i++)
    {
        for (j = 0; j < TAILLE; j++)
        {
            if (grille1[i][j] != grille2[i][j])
            {
                return 1;
            }
        }
    }

    return 0;
}

/* Retourne 1 si une case contient 2048 */
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

/* Retourne 1 si aucun mouvement n'est possible (grille pleine et aucune fusion adjacente) */
int verifierDefaite(int grille[TAILLE][TAILLE])
{
    int i, j;

    /* S'il existe une case vide, le jeu peut continuer */
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

    /* Vérification des fusions possibles en ligne */
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

    /* Vérification des fusions possibles en colonne */
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

/* Affiche la grille et le score courant */
void afficherGrille(int grille[TAILLE][TAILLE], int score)
{
    int i, j;

    printf("\nScore : %d\n\n", score);

    for (i = 0; i < TAILLE; i++)
    {
        printf("+------+------+------+------+\n");

        for (j = 0; j < TAILLE; j++)
        {
            printf("| %4d ", grille[i][j]);
        }

        printf("|\n");
    }

    printf("+------+------+------+------+\n\n");
}

/* Décale toutes les tuiles vers la gauche (comble les cases vides) */
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

/* Fusionne les tuiles égales adjacentes vers la gauche et met à jour le score */
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

/* Décale toutes les tuiles vers la droite */
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

/* Fusionne les tuiles égales adjacentes vers la droite et met à jour le score */
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

/* Décale toutes les tuiles vers le haut */
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

/* Fusionne les tuiles égales adjacentes vers le haut et met à jour le score */
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

/* Décale toutes les tuiles vers le bas */
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

/* Fusionne les tuiles égales adjacentes vers le bas et met à jour le score */
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
