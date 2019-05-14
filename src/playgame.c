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
            if (row[2] != DEFAULT_BOARD_ENTRY){
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
        if (board[0][j] != DEFAULT_BOARD_ENTRY){
            if (board[0][j] == board[1][j] && board[1][j] == board[2][j]){
                return board[0][j];
            }
        }
    }
    //check the main diagonal(left to right)
    if (board[0][0] != DEFAULT_BOARD_ENTRY){
        if (board[0][0] == board[1][1] && board[2][2] == board[1][1]){
            return board[0][0];
        }
    }
    //check the other diagonal(right to left)
    if (board[0][2] != DEFAULT_BOARD_ENTRY){
        if (board[0][2] == board[1][1] && board[2][0] == board[1][1]){
            return board[0][2];
        }
    }
    return DEFAULT_BOARD_ENTRY;
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
    *winner = DEFAULT_BOARD_ENTRY;
    *player = 'x';
    int row, column;
    char *input = calloc(10, sizeof(char));
    while (*winner == DEFAULT_BOARD_ENTRY){
        print_board(board);
        printf("Current player: %c\n",*player);
        printf("Please enter the row and column: ");
        fgets(input,10,stdin);
        int scanResult = sscanf(input,"%d,%d",&row,&column);
        if (scanResult == 2){

            int success = mark_board(*player,row,column,board);
            if (success == 0){
                printf("Turn successful!\n");
                *player = changePlayer(player);
                *winner = (char) isGameOver(board);
            } else if (success == 1){
                printf("Please enter row and column less than 3.\n");
            } else {
                printf("You cannot mark a place that has already been marked.\n");
            }
        } else {
            printf("Input was incorrect. Please try again.\n");
        }
    }
    print_board(board);
    printf("Player %s has won the game!\n",winner);
    free(input);
    free(winner);
    free(player);
    free_board(board);
}
