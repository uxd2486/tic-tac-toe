//
// gameboard.c : contains functionality for creating, printing, changing and deleting the
//               gameboard used for tic tac toe
//
// Author : Utkarsh Dayal
//
#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"

//Functions(extensive documentation in gameboard.h)

//
// Creates the gameboard
//
char **initialise_board(){
    char **board = calloc(9, sizeof(char) ); //the board is 3x3, hence 9 members
    return board;
}


