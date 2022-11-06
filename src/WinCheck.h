#ifndef PROJECT2_WINCHECK_H
#define PROJECT2_WINCHECK_H
#endif //PROJECT2_WINCHECK_H
#include "global.h"

int check_horizontal(int moveRows, int player, int (*board)[rows][columns]);
int check_vertical(int player,int moveColumn, int (*board)[rows][columns]);
int checkWinner(int player, int moveRows, int moveColumns, int (*board)[rows][columns]);
int check_diagonal(int player, int moveRows, int moveColumns, int (*board)[rows][columns]);
int diagonal_left(int player, int moveRows, int moveColumns, int tempgird[rows][columns]);
int diagonal_right(int player, int moveRows, int moveColumns, int tempgird[rows][columns]);