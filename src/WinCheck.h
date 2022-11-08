#ifndef PROJECT2_WINCHECK_H
#define PROJECT2_WINCHECK_H
#endif //PROJECT2_WINCHECK_H
#include "global.h"

/**
 *
 * @param player Current player
 * @param moveRows row of last move made by player or AI
 * @param moveColumns column last move made by player or AI
 * @param board array allocated in game_of_lines
 * @return returns the value of player if one of the called functions returns 1 else returns -1
 */
int checkWinner(int player, int moveRows, int moveColumns, int (*board)[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveRows row of last move made by player or AI
 * @param board array allocated in game_of_lines
 * @return returns 1 if number of connected pieces in moveRows with the value of player is equal to 'wincon'
 */
int check_horizontal(int player, int moveRows, int (*board)[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveColumn column of last move made by player or AI
 * @param board array allocated in game_of_lines
 * @return returns 1 if number of connected pieces with the value of current player is equal to 'wincon'
 */
int check_vertical(int player,int moveColumn, int (*board)[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveRows row of last move made by player or AI
 * @param moveColumn column of last move made by player or AI
 * @param board array allocated in game_of_lines
 * @return returns 1 if the called functions 'diagonal_left' or 'diagonal_right' returns the value of 'wincon'
 */
int check_diagonal(int player, int moveRows, int moveColumns, int (*board)[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveRows row of last move made by player or AI
 * @param moveColumn column of last move made by player or AI
 * @param tempboard array allocated in game_of_lines
 * @return return number of connected pieces in the main diagonal
 */
int diagonal_main(int player, int moveRows, int moveColumns, int tempboard[rows][columns]);

/**
 *
 * @param player Current player
 * @param moveRows row of last move made by player or AI
 * @param moveColumn column of last move made by player or AI
 * @param tempboard array allocated in game_of_lines
 * @return return number of connected pieces in the anti diagonal
 */
int diagonal_anti(int player, int moveRows, int moveColumns, int tempboard[rows][columns]);