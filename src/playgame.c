//
// Created by utkarsh on 5/10/19.
//

#include <stdlib.h>
#include <stdio.h>
#include "gameboard.h"
#include "playgame.h"

int check(char *row){
    if (row[0] == row[1]){
        if (row[1] == row[2]){
            if (row[2] != '-'){
                return 0;
            }
        }
    }
    return 1;
}

/**
 * Tells you whether the game is over or not by checking if a row, column or diagonal is
 * filled by the same character or not. If the game is over it returns 'x' or 'o'
 * depending on which player won
 *
 * @param board the gameboard which has to be checked
 *
 * @return 0 if game is not over, 'x' or 'o' if game is over
 */
int isGameOver(char **board){
    //check every row
    for (int i = 0; i < BOARD_LENGTH; i++){
        if (check(board[i])){
            return board[i][0];
        }
    }
    //check every column
    for (int j = 0; j < BOARD_LENGTH; j++){
        if (board[0][j] != '-'){
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]){
                return board[0][j];
            }
        }
    }
    //check the main diagonal(left to right)
    if (board[0][0] != '-'){
        if (board[0][0] == board[1][1] && board[2][2]){
            return board[0][0];
        }
    }
    //check the other diagonal(right to left)
    if (board[0][2] != '-'){
        if (board[0][2] == board[1][1] && board[2][0]){
            return board[0][2];
        }
    }
    return 0;
}

/**
 * Prints out who the winner of the game is.
 *
 * @param board the gameboard used to check who the winner is
 */
void printWinner(char **board){}

void start(){
    char **board = initialise_board();
    char *player = calloc(1,sizeof(char));
    char *winner = "-";
    while (*winner){
        printf("Suck it");
        *winner = (char) isGameOver(board);
    }
    printf(winner);
    printWinner(board);
    free(player);
    free_board(board);
}
