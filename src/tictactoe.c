//
// tictactoe.c : the main file with the gameplay loop for playing tic tac toe.
//
// Author : Utkarsh Dayal
//

#include <stdio.h>
#include "gameboard.h"

int main( int argc, char *argv[] ){
    char **board = initialise_board();
    for (int i = 0; i < 3 ; i++) {
        for (int j = 0; j < 3; j++) {
            mark_board('x',i,j,board);
        }
    }
    print_board(board);
    free_board(board);
}