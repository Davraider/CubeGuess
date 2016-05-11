#include <stdio.h>
#include <windows.h>
#include <conio.h>
#include "playground.h"
#include "calculation.h"

void prep(void) {
    hideMarker();
    checkCol();
    checkRow();
}

int main(void) {
    srand(GetTickCount());
    printf("Welcome to CubeGuess!\n----\n");
    //TODO other board sizes

    printf("Want to play?  (y/n)\n");
    int inPlay = getch();
    while (inPlay == 49 || inPlay == 121) {
        initBoard();
        prep();
        printBorderWithNumbers();

        play();
        printf("\nYou won!\nPlay again? (y/n)\n");
        inPlay = getch();
    }
    return 0;
}

