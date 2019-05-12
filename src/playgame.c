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
        if (!check(board[i])){
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
    return '-';
}

char changePlayer(char *currentPlayer){
    switch (*currentPlayer){
        case 'x': return 'o';
        case 'o': return 'x';
        default: printf("Something went wrong.");
    }
}

void start(){
    char **board = initialise_board();
    char *player = malloc(sizeof(char));
    char *winner = malloc(sizeof(char));
    *winner = '-';
    *player = 'x';
    while (*winner == '-'){
        print_board(board);
        printf("Current player: %c\n",*player);
        printf("Please enter the row and column: ");
        int *row = malloc(sizeof(int));
        int *column = malloc(sizeof(int));
        char *input = calloc(3, sizeof(char));
        scanf("%s",input);
        int success = sscanf(input,"%d,%d",row,column);
        if (success == 2){
            printf("Turn successful!");
            *player = changePlayer(player);
            *winner = (char) isGameOver(board);
        } else {
            printf("Input was incorrect. Please try again.");
        }
    }
    printf("%s",winner);
    free(player);
    free_board(board);
}
