#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>

int gameMode = 0, rows = 0, columns = 0, wincon = 0;

void scan_setting();
void game_of_lines();
void print_arena(int (*arena)[rows][columns]);
void reset_arena(int (*arena)[columns][rows]);
int scan_move(int (*arena)[rows][columns]);
void update_arena(int player, int *moveColumn, int *moveRows, int(*board)[rows][columns]);
int ai_move();
int check_horizontal(int moveColumn, int moveRows, int player, int (*board)[rows][columns]);
int check_vertical(int player,int moveColumn, int (*board)[rows][columns]);
int check_diagonal(int player, int moveColumn, int moveRows, int (*board)[rows][columns]);
int check_diagonal2(int player, int moveColumn, int moveRows, int (*board)[rows][columns]);
int winnerMessage(int player);