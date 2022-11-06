#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include <math.h>
#include "global.h"
#include "WinCheck.h"

void scan_setting();
void game_of_lines();
void print_arena(int (*arena)[rows][columns]);
void reset_arena(int (*arena)[columns][rows]);
void scan_move(int (*arena)[rows][columns]);
void update_arena(int player, int *moveColumn, int *moveRows, int(*board)[rows][columns]);
int ai_move();

