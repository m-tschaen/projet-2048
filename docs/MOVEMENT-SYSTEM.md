# Movement System

## Purpose

This document explains how movements and tile fusions work in the 2048 game.

The related code is located in:

```text
PROJET2048/main.c
```

The system manages:

- tile movement;
- tile fusion;
- score updates;
- detection of valid movements.

## How It Works

The game uses four movement directions:

- `Z` → Up
- `S` → Down
- `Q` → Left
- `D` → Right

For each direction, the program follows the same logic:

```text
Move
→ Merge
→ Move again
```

For example, when moving left:

```c
deplacerGauche(grille);
fusionnerGauche(grille, &score);
deplacerGauche(grille);
```

The first movement groups the tiles together.

The fusion combines identical adjacent tiles.

The second movement removes the empty spaces created by the fusion.

## Example

Initial row:

```text
2 | 0 | 2 | 4
```

After moving left:

```text
2 | 2 | 4 | 0
```

After fusion:

```text
4 | 0 | 4 | 0
```

Final result:

```text
4 | 4 | 0 | 0
```

The score increases by `4`.

## Grid Change Detection

Before each movement, the current grid is copied with:

```c
copierGrille(grille, ancienneGrille);
```

After the movement, the program checks whether the grid changed with:

```c
grillesDifferentes(grille, ancienneGrille);
```

A new random tile is only added if the grid has changed.

This prevents a new tile from appearing after an impossible movement.

## Files and Functions to Modify

The movement system is located in:

```text
PROJET2048/main.c
```

The main functions are:

```text
deplacerGauche
fusionnerGauche
deplacerDroite
fusionnerDroite
deplacerHaut
fusionnerHaut
deplacerBas
fusionnerBas
```

The grid size is defined with:

```c
#define TAILLE 4
```

## Verification

The system can be verified with simple tests:

- moving a tile into an empty space;
- merging two identical tiles;
- checking that the score increases after a fusion;
- checking that no new tile appears after an impossible movement;
- checking that a new tile appears after a valid movement.

## Common Problems

If tiles do not merge correctly, verify that the movement follows this order:

```text
Move
→ Merge
→ Move again
```

If a new tile appears after an impossible movement, verify that the grid is compared with the previous grid before generating a new tile.

If the score does not increase, verify that the fusion function correctly updates the score.

## Limitations

The current system has the following limitations:

- the grid is fixed to 4x4;
- new random tiles always have the value `2`;
- movement logic is separated into different functions for each direction;
- the project does not contain automated tests.

## References

```text
README.md
docs/adr/0001-movement-and-fusion.md
```