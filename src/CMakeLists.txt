cmake_minimum_required(VERSION 3.13)
project(tictactoe C)

set(CMAKE_C_STANDARD 99)

add_executable(tictactoe tictactoe.c gameboard.c gameboard.h playgame.c playgame.h)