#include "playground.h"

char board[BOARDSIZE][BOARDSIZE];

void initBoard(void) {
    int i, j;
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++) {
            if (i == 0 && j == 0) {
                board[i][j] = '*';
            } else if (i == 0) {
                board[i][j] = '~';
            } else if (j == 0) {
                board[i][j] = '|';
            } else {
                board[i][j] = 'X';
            }
        }
    }
}

void printBorderWithNumbers(void){
    printf("\n");
    int i,j = 0;
    for(i = 0; i < BOARDSIZE; i++) {
        for(j = 0; j < BOARDSIZE; j++) {
            if ((i < BOARDSIZE && i > 0 ) && (j < BOARDSIZE && j > 0)) {
                printf(" ");
            } else if ((i == 0 && j > 0 && j < BOARDSIZE ||
                        j == 0 && i > 0 && i < BOARDSIZE)) {
                printf("%d", board[i][j]);
            }else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

void printBoardWithNumbers(void) {
    printf("\n");
    int i,j = 0;
    for(i = 0; i < BOARDSIZE; i++) {
        for(j = 0; j < BOARDSIZE; j++) {
            if (i == 0 && j > 0 && j < BOARDSIZE ||
                    j == 0 && i > 0 && i < BOARDSIZE) {
                printf("%d", board[i][j]);
            } else {
                printf("%c", board[i][j]);
            }
        }
        printf("\n");
    }
}

void printBoardFoundMarker(void) {
    printf("\n");
    int i, j = 0;
    for (i = 0; i < BOARDSIZE; i++) {
        for (j = 0; j < BOARDSIZE; j++) {
            if (i == 0 && j > 0 && j < BOARDSIZE ||
                    j == 0 && i > 0 && i < BOARDSIZE) {
                printf("%d", board[i][j]);
            } else if (board[i][j] == 'o') {
                printf("%c", board[i][j]);
            } else if (i == 0 && j == 0) {
                printf("%c", board[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}