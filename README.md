# 2048 Game

This project is a console version of the 2048 game developed in C.

The objective is to move and merge tiles on a 4x4 grid until one of them reaches the value 2048.

## Features

The game includes:

- A 4x4 grid
- Random generation of tiles
- Movement in four directions
- Fusion of identical tiles
- Score calculation
- Victory detection
- Defeat detection
- Restart option
- Quit option

## Prerequisites

The project requires:

- A C compiler
- A terminal or console
- An IDE such as Code::Blocks can also be used

## Installation

The project can be downloaded or cloned from the GitHub repository.

The main source code is located in:

```text
PROJET2048/main.c
```

The program can then be compiled with a C compiler.

Example with GCC:

```bash
gcc PROJET2048/main.c -o 2048
```

## Configuration

No specific configuration is required.

The grid size is defined directly in the source code with:

```c
#define TAILLE 4
```

The game can therefore be launched without any external configuration file.

## Launch

After compilation, the program can be launched from the terminal.

Example:

```bash
./2048
```

## Controls

The following keys are used:

- `Z` : move up
- `S` : move down
- `Q` : move left
- `D` : move right
- `X` : quit the current game

Uppercase and lowercase letters are accepted.

## Game Rules

At the beginning of the game, two tiles with the value `2` are placed randomly on the grid.

After each valid move, a new tile with the value `2` is added to an empty position.

Two adjacent tiles with the same value can be merged.

When two tiles are merged, their values are added together and the new value is added to the score.

The player wins when one tile reaches the value `2048`.

The player loses when the grid is full and no horizontal or vertical fusion is possible.

## Project Architecture

```text
projet-2048/
├── PROJET2048/
│   ├── main.c
│   ├── PROJET2048.cbp
│   ├── PROJET2048.depend
│   ├── PROJET2048.layout
│   ├── bin/
│   └── obj/
└── README.md
```

The main source code is located in:

```text
PROJET2048/main.c
```

This file contains the game logic, including:

- grid initialization;
- random tile generation;
- grid display;
- movement management;
- tile fusion;
- score management;
- victory detection;
- defeat detection;
- restart management.

## Main Functions

The main functions of the project are:

- `initialiserGrille` : initializes the 4x4 grid with empty cells;
- `ajouterNombreAleatoire` : places a tile with the value `2` in a random empty cell;
- `afficherGrille` : displays the current grid and score;
- `copierGrille` : copies the current grid before a movement;
- `grillesDifferentes` : checks whether the grid changed after a movement;
- `verifierVictoire` : checks whether a tile has reached `2048`;
- `verifierDefaite` : checks whether no movement or fusion is possible.

The movement functions are:

- `deplacerGauche`
- `deplacerDroite`
- `deplacerHaut`
- `deplacerBas`

The fusion functions are:

- `fusionnerGauche`
- `fusionnerDroite`
- `fusionnerHaut`
- `fusionnerBas`

## Movement Logic

Each movement follows three steps:

1. Move the tiles toward the selected direction.
2. Merge identical adjacent tiles.
3. Move the tiles again to remove empty spaces created by the fusion.

For example, a movement to the left follows this sequence:

```text
Move left
→ Merge left
→ Move left again
```

A new tile is generated only if the grid has actually changed after the movement.

## Score

The score starts at `0`.

When two identical tiles are merged, the value of the new tile is added to the score.

Example:

```text
2 + 2 = 4
```

The score increases by `4`.

Another example:

```text
8 + 8 = 16
```

The score increases by `16`.

## Verification

The project can be checked with the following scenarios:

1. A new game displays a 4x4 grid.
2. Two initial tiles are generated.
3. The keys `Z`, `Q`, `S` and `D` move the tiles.
4. Two identical adjacent tiles can merge.
5. The score increases after a fusion.
6. A new tile appears only after a valid movement.
7. Reaching `2048` triggers the victory message.
8. A full grid with no possible fusion triggers the defeat message.
9. The `X` key quits the current game.
10. The player can restart after the end of a game.

## Limitations

The current version has several limitations:

- The game runs only in the console.
- The grid size is fixed to 4x4.
- New random tiles always have the value `2`.
- There is no graphical interface.
- There is no save system.
- The score is reset when a new game starts.

## Technical Decision

The main technical decision of the project is documented in:

```text
docs/adr/0001-movement-and-fusion.md
```

This document explains the choice to use separate movement and fusion functions for each direction.

## Technical Documentation

Detailed technical documentation about the movement and fusion system is available in:

```text
docs/MOVEMENT-SYSTEM.md
```

## Contribution

A contribution should follow this workflow:

1. Describe the problem or requested change in an issue.
2. Create a dedicated branch.
3. Make the required modification.
4. Test the change.
5. Create a clear commit.
6. Push the branch.
7. Open a Pull Request.
8. Review the changes.
9. Correct problems if necessary.
10. Merge after validation.

The documentation must also be updated if a change affects the game behavior, controls, architecture or technical decisions.

## Author

Morgane Tschaen