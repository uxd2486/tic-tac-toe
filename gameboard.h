//
// gameboard.h : declarations for gameboard.c
//
// Author : Utkarsh Dayal
//

#ifndef TIC_TAC_TOE_GAMEBOARD_H
#define TIC_TAC_TOE_GAMEBOARD_H

//Function declarations

//
// initialise_board() - creates the gameboard as a 2-D array of characters and
//                      returns it. Initially, it will be populated with the
//                      '-' character
//
// return - the gameboard
//
char **initialise_board();

//
// print_board() - prints the current state of the board to stdin
//
void print_board(char **gameboard);

//
// mark_board() - changes the board at the location specified by row and col
//                to the symbol given by mark.
//                row and col must be greater than or equal to 0
//                mark must be either 'x' or 'o'
//
// mark - the mark to be made on the board('x' or 'o')
// row - int that specifies the row for the mark to be made
// col - int that specifies the column for the mark to be made
//
// return - the gameboard, after making the change
//
char **mark_board(char mark, int row, int col);

//
// free_board() - frees the memory where the gameboard is stored
//
void free_board(char **gameboard);

#endif //TIC_TAC_TOE_GAMEBOARD_H
