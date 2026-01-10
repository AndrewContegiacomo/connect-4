#ifndef FILE_H
#define FILE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h> 

// --- CONSTANTS ---
#define ROWS 6
#define COLS 7

#define EMPTY 0
#define P1 1 // Player 1
#define P2 2 // Player 2

// --- FUNCTION PROTOTYPES ---

// Initializes the matrix by setting all cells to EMPTY (0)
void initBoard(int board[ROWS][COLS]);

// Prints the current state of the board to the console
void printBoard(int board[ROWS][COLS]);

// Attempts to drop a token into the specified column.
int insertToken(int board[ROWS][COLS], int column, int player);

// Checks for a win condition specifically around the last placed token.
bool checkWin(int board[ROWS][COLS], int lastRow, int lastCol, int player);

// Saves the current board state and whose turn it is
void saveGame(int board[ROWS][COLS], int currentTurn, int drawChecker,  const char *filename);

// Loads the game. 
// Returns 1 if loading success.
// Returns 0 if loading failed.
int loadGame(int board[ROWS][COLS], int *currentTurn, int *drawChecker,  const char *filename);

#endif
