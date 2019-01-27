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
    char **board = calloc(BOARD_LENGTH*BOARD_LENGTH, sizeof(char) );
    for (int i = 0; i < BOARD_LENGTH; i++){
        board[i] = calloc(BOARD_LENGTH, sizeof(char));
    }
    return  board;
}

//
// print_board() - prints the current state of the board
//
void print_board(char **gameboard){
    for (int i = 0; i < BOARD_LENGTH ; i++){
        for (int j = 0; j < BOARD_LENGTH; j++) {
            printf(" %c ", gameboard[i][j]);
            if (j == BOARD_LENGTH-1){ //to make sure this only happens at the end of the line
                printf("\n");
                if (i != BOARD_LENGTH-1) { //to make sure this doesn't happen after the last row
                    print_horizontal_lines();
                }
            } else{
                printf("|");
            }
        }
    }
}

//
// Frees all memory associated with the board
//
void free_board(char **board){
    for (int i = 0; i < BOARD_LENGTH; i++){
        free(board[i]);
    }
    free(board);
}


