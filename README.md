Connect 4 (C Implementation)

Overview
This project is a modular C implementation of the classic strategy game Connect 4. It runs in the terminal and features a robust logic system using a 2D matrix to represent the game board. The game supports two local players, move validation with "gravity" logic, an optimized victory check algorithm, and file persistence (Save/Load).

Key Features
Grid System: Uses a standard 6x7 dimensional array.

Gravity Logic: Tokens are inserted into a column and automatically "fall" to the lowest available row (bottom-up validation).

Optimized Win Check: instead of scanning the entire board every frame, the algorithm checks only the immediate surroundings of the last placed token (Horizontal, Vertical, and both Diagonals).

Save & Load: Players can save their progress to a text file and resume later.

Input Validation: prevents writing to full columns or accessing out-of-bounds memory.

Project Structure
main.c: Handles the main game loop, user input, and turn management.

file.h: The header file containing constants (ROWS, COLS), function prototypes, and libraries.

file.c: Contains the implementation of the game logic (initialization, printing, checking logic, and file I/O).

Logic Details
1. Board Representation
The board is an integer matrix board[6][7]:

0 (EMPTY): Empty slot.

1 (P1): Player 1's token.

2 (P2): Player 2's token.

2. The Algorithm
Insertion: The program checks the column from the bottom row (5) upwards (0). The token is placed in the first found 0.

Victory Detection: Upon placing a token at [r][c], the system scans 4 axes centered on that specific coordinate. Boundary checks are performed strictly before accessing memory to prevent Segmentation Faults.
