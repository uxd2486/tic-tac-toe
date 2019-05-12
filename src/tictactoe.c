//
// tictactoe.c : the main file with the gameplay loop for playing tic tac toe.
//
// Author : Utkarsh Dayal
//

#include <stdio.h>
#include "playgame.h"

int main( int argc, char *argv[] ){
    printf("Welcome to tic-tac-toe!\n");
    printf("How to play:\n");
    printf("When prompted, enter the row and column of the place where you wish to mark the board.\n");
    printf("The rows and columns start at 0, so the top left entry is 0,0 and the bottom right entry is 2,2.\n");
    printf("By default, the first player is always 'o'.\n");
    printf("Please press enter to start the game.\n");
    start();
}