//
// gameboard.c : contains functionality for creating, printing, changing and deleting the
//               gameboard used for tic tac toe
//
// Author : Utkarsh Dayal
//
#include <stdio.h>
#include <stdlib.h>

#include "gameboard.h"

//Private functions

//
// print_horizontal_lines() - only used to print out the gameboard in a neat, readable format
//                            prints out the following:
//                                      _ _ _
//
//                            followed by a newline character
void print_horizontal_lines(){
    for (int i = 0; i < 6; i++){ //6 was chosen just so that the output looked nice
        printf("- ");
    }
    printf("\n");
}

//Functions(extensive documentation in gameboard.h)

//
// Creates the gameboard
//
char **initialise_board(){
    char **board = calloc(9, sizeof(char) ); //the board is 3x3, hence 9 members
    for (int i = 0; i < 3; i++){
        board[i] = calloc(3, sizeof(char));
    }
    return  board;
}

void print_board(char **gameboard){
    for (int i = 0; i < 3 ; i++){
        for (int j = 0; j < 3; j++) {
            printf(" %c ", gameboard[i][j]);
            if (j == 2){
                printf("\n");
                if (i != 2) {
                    print_horizontal_lines();
                }
            } else{
                printf("|");
            }
        }
    }
}


