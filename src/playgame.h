//
// playgame.h : Declarations for playgame.h
//
// Author : Utkarsh Dayal
//

#ifndef TICTACTOE_PLAYGAME_H
#define TICTACTOE_PLAYGAME_H

#define PLAYER_ONE 'x'
#define PLAYER_TWO 'o'

//
// start() - this function basically has the entire gameplay loop. The gameplay loop consists of printing the
//           gameboard, then asking the current player for input, processing the input and if required, changing
//           turns to the next player.
//
void start();

#endif //TICTACTOE_PLAYGAME_H