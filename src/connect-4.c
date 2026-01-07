#include "connect-4.h"

void initBoard(int board[ROWS][COLS]){

    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            board[i][j] = EMPTY;
        }
    }
    printf("Board is ready to play!\n");
}

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

int insertToken(int board[ROWS][COLS], int column, int player){

    if (column < 0 || column >= COLS) {
        return -1;
    }

    for(int i = ROWS - 1; i != -1; i--){
        if(board[i][column] == EMPTY){
            board[i][column] = player;
            return i;
        }
    }
    return -1;
}


