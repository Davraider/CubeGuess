#include "calculation.h"

extern char board[BOARDSIZE][BOARDSIZE];

int readNumber(void) {
    char inNumber[INPUTSIZE];
    char *prt;
    printf("Select row and column: \n");
    fgets(inNumber, sizeof(inNumber), stdin);

    readRow = strtol(inNumber, &prt, 10);
    readCol = strtol(prt, NULL, 10);

    if (readRow > 3 || readRow < 1 ||
        readCol < 1 || readCol > 3) {

        if (!strchr(inNumber, '\n')) {//if newline doesn't exist
            while (fgetc(stdin) != '\n');//discard until newline
        }//maybe flush buffer
        return 0;
    }
    return 1;
}

int getRand(void) {
    int magicNum = (rand() % 3) + 1;
    return magicNum;
}
void hideMarker(void) {
    int i, col, row;

    for (i = 0; i < 3; i++) {
        do {
            row = getRand();
            col = getRand();
        } while (board[row][col] == '#');
        board[row][col] = '#';
    }
}
void checkCol(void) {
    int i, j;
    char sum;
    for (i = 1; i < 4; i++) {
        sum = 0;
        for (j = 1; j < 4; j++) {
            if (board[j][i] == '#') {
                sum++;
            }
        }
        board[0][i] = sum;
    }
}
void checkRow(void) {
    int i, j;
    char sum;
    for(i = 1; i < 4; i++) {
        sum = 0;
        for (j = 0; j < 4; j++) {
            if (board[i][j] == '#') {
                sum++;
            }
        }
        board[i][0] = sum;
    }
}
void play(void) {
    int markerNum = 3;

    while (markerNum != 0) {
        int corrInput = readNumber();

        if (corrInput) {
            printf("Row: %lu\tCol: %lu\n", readRow, readCol);

            if (board[readRow][readCol] == '#') {
                board[readRow][readCol] = 'o';

                printBoardFoundMarker();
                markerNum--;
            }
        }
    }
}