//
// playgame.c - contains the functionality to play the game
//
// Author : Utkarsh Dayal
//

#include <stdlib.h>
#include <stdio.h>
#include "gameboard.h"
#include "playgame.h"

//
// check() - checks if a row has all the same character. The character cannot be the default entry.
//
// row - the row that has to be checked
//
// return - 0 if the row is full, 1 if not
//
int check(const char *row){
    if (row[0] == row[1]){
        if (row[1] == row[2]){
            if (row[2] != DEFAULT_BOARD_ENTRY){
                return 0;
            }
        }
    }
    return 1;
}

//
// isGameOver() - Tells you whether the game is over or not by checking if a row, column or diagonal is
//                filled by the same character or not. If the game is over it returns 'x' or 'o'
//                depending on which player won. If the game is not over, it returns '-'.
//
// board - the gameboard that has to be checked
//
// return - '-' if game is not over, or 'x'/'o' depending on which player won
//
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

char changePlayer(const char *currentPlayer){
    switch (*currentPlayer){
        case PLAYER_ONE: return PLAYER_TWO;
        case PLAYER_TWO: return PLAYER_ONE;
        default: printf("Something went wrong.");
    }
}

//
// The main gameplay loop(more documentation in playgame.h)
//
void start(){
    char **board = initialise_board();
    //stores the current player
    char *player = malloc(sizeof(char));
    //stores the winner of the game
    char *winner = malloc(sizeof(char));
    *winner = DEFAULT_BOARD_ENTRY;
    *player = PLAYER_ONE;
    //row, column, input are just there to take and process user input
    int row, column;
    char *input = calloc(10, sizeof(char)); //10 is just a random number, the input should never actually be that long
    while (*winner == DEFAULT_BOARD_ENTRY){
        print_board(board);
        printf("Current player: %c\n",*player);
        printf("Please enter the row and column: ");
        fgets(input,10,stdin);
        int scanResult = sscanf(input,"%d,%d",&row,&column);
        //sscanf should convert 2 digits. If it doesn't, we have a problem.
        if (scanResult == 2){
            //we have to check if we were able to successfully mark the board or not
            int success = mark_board(*player,row,column,board);
            // success!
            if (success == 0){
                printf("Turn successful!\n");
                *player = changePlayer(player);
                *winner = (char) isGameOver(board);
            } else if (success == -1){ //the row or column was less than 0
                printf("Please enter row and column greater than or equal to 0\n");
            } else if (success == 1){ //the row or column was greater than or equal to 3
                printf("Please enter row and column less than 3.\n");
            } else { //the user tried to mark a place that was already marked
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
