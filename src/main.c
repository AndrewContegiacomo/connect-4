#include <stdio.h>
#include <stdlib.h>
#include "../include/connect-4.h" 

void loopGame(int board[ROWS][COLS], int currentTurn, int movesCount) {
    
    // Local variables needed for the loop
    int winChecker = 0;
    int row, col;

    // Loop Game
    do {
        int validMove = 0; // Flag to understand if we have a valid move

        // Input Loop, until col is valid and not full, -2 to save the game 
        while (!validMove) {
            printf("\nPlayer %d, insert column (0-6), -2 to Save & Exit, -3 to Exit: ", currentTurn);
            
            // Check type of col inserted
            if (scanf("%d", &col) != 1) {
                printf("Invalid input! Please enter a number.\n");
                while(getchar() != '\n'); // Clean buffer from Char
                continue; 
            }

            // Check if user want to save the game
            if (col == -2) {
                char saveName[100];
                printf("Enter filename for save (e.g., match.txt): ");
                scanf("%s", saveName);
                saveGame(board, currentTurn, movesCount, saveName);
                
                // Return to start Menu immediately
                return; 
            }
            
            //Exit without save
            if(col == -3){
                return;
            }

            // Try to insert token (insertToken handles out of bounds internally returning -1)
            row = insertToken(board, col, currentTurn); 
            
            if (row == -1) {
                printf("Column is full or doesn't exist! Try another one.\n");
            } else {
                validMove = 1; // Check if move is valid
            }
        }

        // Increment movesCount to check draw & printBoard updated
        movesCount++;
        printBoard(board);

        // Check Win
        if (checkWin(board, row, col, currentTurn)) {
            printf("\n!!! CONGRATULATIONS !!!\n");
            printf("Player %d WINS!\n\n", currentTurn);
            winChecker = 1; 
        } else if (movesCount >= ROWS * COLS) {
            printf("\nIt's a DRAW!\n\n");
            winChecker = 1; // Consider draw as a win to exit the loop
        } else {
            // If checkWin = 0, change player 1 -> 2 or 2 -> 1
            currentTurn = (currentTurn == 1) ? 2 : 1;
        }

    } while (winChecker == 0); // Continue only if there is no win or draw
}

int main() {
    int choice;
    int board[ROWS][COLS]; 
    
    int currentTurn;
    int movesCount; 

    // Main application loop
    do {
        // Display the menu options
        printf("\n=== Connect 4 Game ===\n");
        printf("1. New Game\n");
        printf("2. Load Game\n");
        printf("0. Exit\n");
        printf("Enter your choice: ");

        // Read user input
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number.\n");
            while(getchar() != '\n'); 
            continue;
        }

        switch (choice) {
            case 1:
                initBoard(board); 
                printf("New Game Initialized!\n");
                printBoard(board);
                
                //Start from player 1, moves 0
                loopGame(board, 1, 0); 
                break; 
            
            case 2:
                printf("Insert the name of the file you want play: ");   
                char fileName[100];
                scanf("%s", fileName); 
                
                if (loadGame(board, &currentTurn, &movesCount, fileName)) {
                    printf("Game loaded successfully! Player %d turn.\n", currentTurn);
                    printBoard(board);
                    
                    loopGame(board, currentTurn, movesCount);
                } else {
                    printf("Failed to load the game.\n");
                }
                break;

            case 0:
                printf("Exiting the application. Goodbye!\n");
                break;

            default:
                printf("Invalid choice! Please try again.\n");
        }

    } while (choice != 0);

    return 0;
}
