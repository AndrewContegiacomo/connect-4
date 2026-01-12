#include "../include/connect-4.h"

//Initialize board with all EMPTY spaces
void initBoard(int board[ROWS][COLS]){

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = EMPTY;
        }
    }
    printf("Board is ready to play!\n");
}

//Print Board with coordinates on top 
//P1 = x
//P2 = o
void printBoard(int board[ROWS][COLS]) {
    
    printf(" 0 1 2 3 4 5 6\n"); 
    printf("---------------\n");

    for(int i = 0; i < ROWS; i++) {
        printf("|"); 

        for(int j = 0; j < COLS; j++) {
            if(board[i][j] == P1) {
                printf("x|");            
            }else if(board[i][j] == P2) {
                printf("o|");
            }else {
                printf(" |");
            }
        }
        printf("\n");
    }
    printf("---------------\n");
}

//Insert Token in the Board
int insertToken(int board[ROWS][COLS], int column, int player){

    //Check validity of the column in input
    if (column < 0 || column >= COLS) {
        return -1;
    }
    
    //Starting check from last row of the column 
    for(int i = ROWS - 1; i != -1; i--){
        if(board[i][column] == EMPTY){
            board[i][column] = player;
            return i;
        }
    }
    return -1;
}

//Helper function to count n token of the same player in any direction
//dr & dc used to indicate where we have to move vertically and horizontally
//r & c indicate the input token in the turn that we check
int countDirection(int board[ROWS][COLS], int r, int c, int dr, int dc, int player) {

    int count = 1;
    int startRow = r;
    int startColumn = c;
    r +=  dr;
    c += dc;

    //Firstly check limit cases in while
    while(r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player){
        count++;
        r += dr;
        c += dc;
    }

    //Change direction with * -1  
    dr = dr * -1;
    dc = dc * -1;
    r = startRow + dr;
    c = startColumn + dc;

    while(r >= 0 && r < ROWS && c >= 0 && c < COLS && board[r][c] == player){
        count++;
        r += dr;
        c += dc;
    }
        if(count >= 4) return 1;

    return 0;
}

int checkWin(int board[ROWS][COLS], int r, int c, int player) {

    // Check Horizontally (-)
    if (countDirection(board, r, c, 0, 1, player)) return 1;

    // Check Vertically (|)
    if (countDirection(board, r, c, 1, 0, player)) return 1;

    // Check Diagonal (\)
    if (countDirection(board, r, c, 1, 1, player)) return 1;

    // Check Diagonal (/)
    if (countDirection(board, r, c, 1, -1, player)) return 1;

    // No win found
    return 0;
}

//Save game board in filename with currentTurn to restart the match in the same condition
void saveGame(int board[ROWS][COLS], int currentTurn, int movesCount,  const char *filename){

    FILE *fp = fopen(filename, "w");
    
    //Check open
    if (fp == NULL) {
        printf("Error opening files.\n");
        return;
    }

    // Scrive DUE numeri sulla prima riga
    fprintf(fp, "%d %d\n", currentTurn, movesCount);

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            fprintf(fp, "%d ", board[i][j]);
        }
        fprintf(fp, "\n");
 }

    // Close files to release locks
    fclose(fp);

    printf("Game saved successfully in: %s\n", filename);
}

// We use pointers to send these values back to the main function
int loadGame(int board[ROWS][COLS], int *currentTurn, int *movesCount, const char *filename) {
    
    FILE *fp = fopen(filename, "r");

    // Check if file exists
    if (fp == NULL) {
        printf("Error: Save file not found.\n");
        return 0; // Return 0 to indicate failure
    }

    // We use & because fscanf needs the memory address
    if (fscanf(fp, "%d %d", currentTurn, movesCount) != 2) {
        fclose(fp);
        return 0;
    }

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            // Read each cell directly into the board
            if (fscanf(fp, "%d", &board[i][j]) != 1) {
                fclose(fp);
                return 0;
            }
        }
    }

    fclose(fp);
    printf("Game loaded successfully!\n");
    return 1;
}
