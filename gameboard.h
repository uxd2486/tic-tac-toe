//
// gameboard.h : declarations for gameboard.c
//
// Author : Utkarsh Dayal
//

#ifndef TIC_TAC_TOE_GAMEBOARD_H
#define TIC_TAC_TOE_GAMEBOARD_H

//Function declarations

char **initialise_board();

void print_board(char **gameboard);

char **mark_board(char mark, int row, int col);

void free_board(char **gameboard);

#endif //TIC_TAC_TOE_GAMEBOARD_H
