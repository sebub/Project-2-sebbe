#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "global.h"
#include "WinCheck.h"

/***
 *Containing main loop of the game and allocates memory for a 2d array
 */
void game_of_lines();

/***
 *Scans following game settings:
 * Gamemode 1 for singleplayer 2 for multiplayer. Number of rows and columns and number for connections to win.
 * these values are stored in global variables in the file global.c(er det her bad practice? Er der en bedre måde at
 * håndtere dem på så man ikke skal tage dem med ind i samtlige funktioner i programet?)
 *
 */
void scan_setting();

/***
 *
 * @param board Array allocated in function game_of_lines
 *
 * Sets every element in the array to 0.
 */
void reset_board(int (*board)[rows][columns]);

/**
 *
 * @param board Array allocated in function game_of_lines
 *
 * Prints the passed array, prints x for player 1 and o for player 2 or AI.
 */
void print_board(int (*board)[rows][columns]);

/**
 *
 * @param board Array allocated in function game_of_lines
 *
 *Loops until winner is found or game is a tie
 *Calls the functions 'scan_move' and 'checkwinner'
 * for each player each loop and ends the game if
 * winner is found or game is a tie.
 */
void update_board(int (*board)[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveColumn Passed to int 'moveColumn' initialized in 'update_board'
 * @param moveRows Passed to int 'moveRows' initialized in 'update_board'
 * @param board Array allocated in function game_of_lines
 *
 * Asks current player to choose column and changes array accordingly
 */
void scan_move(int player, int *moveColumn, int *moveRows, int(*board)[rows][columns]);

int ai_move();

