#include <stdio.h>
#include <stdlib.h>
#include "../include/connect-4.h" 

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
                initBoard(board);
                currentTurn = 1; // Set first playere
                movesCount = 0;  // reset movesCount
                printf("New Game Initialized!\n");
                
                //Game logic....

                break;

            case 2:
                char fileName[100]; 
                
                printf("Insert the name of the file you want play: ");                 
                scanf("%s", fileName); 
                
                if (loadGame(board, &currentTurn, &movesCount, fileName)) {
                    printf("Game loaded successfully! Player %d turn.\n", currentTurn);
                    
                    //Game logic...
                    .
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
