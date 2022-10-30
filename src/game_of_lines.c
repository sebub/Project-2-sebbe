#include <stdio.h>
#include <malloc.h>
#include <time.h>
#include <stdbool.h>
#include "game_of_lines.h"

int main(void)
{
    srand(time(NULL));
    int Mode, Columns, Rows, connectToWin;
    scan_setting(&Mode,&Columns,&Rows,&connectToWin);

    game_of_lines(Mode,Columns,Rows,connectToWin);

}
void scan_setting(int *gameMode, int *Columns, int *Rows, int *connetToWin){
    printf("Enter 1 for singleplayer, enter 2 for multiplayer");
    scanf("%d",gameMode);

    printf("Enter size of map");
    printf("Columns:");
    scanf("%d",Columns);

    printf("Rows:");
    scanf("%d",Rows);

    printf("Enter number of connections to win:");
    scanf("%d",connetToWin);

}

int game_of_lines(int gameMode, int columns, int rows, int connetToWin) {
    int (*arena)[rows][columns] = malloc(sizeof(int) * (columns * rows));
    int i=0;

    reset_arena(rows,columns,arena);
    print_arena(rows,columns,arena);

    while(winnerfound) {
        scan_move(gameMode, rows, columns, arena);
        printf("__________________________\n");
    }



}

void print_arena(int rows, int columns,int (*board)[rows][columns]){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if((*board)[i][j] == 2)
                printf("x ");
            else if((*board)[i][j]== 1){
                printf("o ");
            }
            else
                printf("_ ");
        }
        printf("\n");
    }
}

void reset_arena(int rows, int columns,int (*board)[rows][columns]){
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*board)[i][j] = 0;
        }
    }
}

void scan_move(int mode,int rows, int columns, int (*board)[rows][columns]){
    int move;
    if(mode == 1){
        printf("Player 1 choose column between 0 and %d ", columns - 1);
        scanf("%d", &move);

        update_arena(1, move, rows, columns, board);

        move = ai_move();
        printf("AI chose column %d\n", move);
        update_arena(2, move, rows, columns, board);
        print_arena(rows, columns, board);

    }
    if(mode == 2) {
        printf("Player 1 choose column between 0 and %d ", columns - 1);
        scanf("%d", &move);

        update_arena(1, move, rows, columns, board);
        print_arena(rows, columns, board);

        printf("Player 2 choose column between 0 and %d ", columns - 1);
        scanf("%d", &move);
        update_arena(2, move, rows, columns, board);
        print_arena(rows, columns, board);
    }
}

void update_arena(int player, int move,int columns, int rows, int(*board)[rows][columns]){
    for (int i = 0; i < rows; ++i) {
        if((*board)[rows-i-1][move]==0) {
            (*board)[rows - i - 1][move] = player;
            break;
        }
    }
}

int ai_move(){
    return rand()%4;
}

bool winnerfound(){
    true;
}