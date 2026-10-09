# ADR 0001 - Movement and Fusion Strategy

## Status

Accepted

## Date

October 2026

## Context

The 2048 game requires the player to move tiles in four directions: left, right, up and down.

For each direction, the program must:

- move the tiles toward the selected direction;
- merge adjacent tiles with the same value;
- update the score when a fusion occurs;
- move the tiles again to remove the empty spaces created by the fusion.

The project therefore needs a clear way to organize the movement and fusion logic while keeping the code understandable.

## Considered Options

### Option 1 - Use one generic function for all directions

A single function could manage every movement by receiving the direction as a parameter.

Advantages:

- less duplicated code;
- fewer functions;
- centralized movement logic.

Disadvantages:

- more conditions would be required;
- horizontal and vertical movements use different indexes;
- the function would be more difficult to understand;
- debugging one specific direction would be harder.

### Option 2 - Use separate functions for each direction

Each direction can have its own movement and fusion functions.

The project uses:

- `deplacerGauche`
- `fusionnerGauche`
- `deplacerDroite`
- `fusionnerDroite`
- `deplacerHaut`
- `fusionnerHaut`
- `deplacerBas`
- `fusionnerBas`

Advantages:

- each function has a clear responsibility;
- the code is easier to read;
- each direction can be understood independently;
- problems are easier to locate and debug.

Disadvantages:

- some code is duplicated;
- the project contains more functions.

## Decision

The project uses separate movement and fusion functions for each direction.

For every valid movement, the program follows the same sequence:

```text
Move
→ Merge
→ Move again
```

For example, when the player moves left:

```c
deplacerGauche(grille);
fusionnerGauche(grille, &score);
deplacerGauche(grille);
```

The same principle is used for the other three directions.

## Justification

This solution was chosen because the project is relatively small and readability is more important than reducing every duplicated instruction.

Separating the directions makes the movement logic easier to understand and maintain.

It also makes it easier to identify which function is responsible for a problem if one direction does not behave correctly.

The second movement after the fusion is necessary because merging two tiles creates an empty cell that must be removed.

## Consequences

The positive consequences are:

- clearer movement logic;
- easier debugging;
- easier understanding of horizontal and vertical movements;
- independent functions for each direction.

The negative consequence is that similar logic is repeated between the different movement functions.

For the current size of the project, this duplication remains acceptable.

## Reconsideration

This decision should be reconsidered if:

- the project becomes significantly larger;
- the grid size becomes configurable;
- new movement rules are added;
- the duplicated code becomes difficult to maintain;
- the movement logic needs to be reused in another version of the game.

In that case, a generic movement function could replace the current direction-specific implementation.