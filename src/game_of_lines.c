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
    while(1) {
        printf("Enter 1 for singleplayer, enter 2 for multiplayer");
        fflush(stdin);
        scanf("%d", gameMode);
        if((*gameMode == 1)||(*gameMode == 2))
            break;
    }
    while(1) {
        printf("Enter size of map");
        printf("Columns:");
        fflush(stdin);
        scanf("%d",Columns);
        if(Columns>0)
            break;
    }

    while(1) {
        printf("Rows:");
        fflush(stdin);
        scanf("%d",Rows);
        if(Rows>0)
            break;
}

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
    for (int i = 0; i < columns; ++i) {
        printf("|%d| ",i);
    }
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if((*board)[i][j] == 1)
                printf("|x| ");
            else if((*board)[i][j]== 2 || (*board)[i][j]== 3){
                printf("|o| ");
            }
            else
                printf("|_| ");
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

        update_arena(1, move, rows, columns, board);
        update_arena(3, move, rows, columns, board);
        print_arena(rows, columns, board);



    }
    if(mode == 2) {

        update_arena(1, move, rows, columns, board);
        print_arena(rows, columns, board);

        update_arena(2, move, rows, columns, board);
        print_arena(rows, columns, board);
    }
}

void update_arena(int player, int move,int columns, int rows, int(*board)[rows][columns]){
    int i = 0;
    while(1) {
        if (player != 3)
            printf("Player %d choose column between 0 and %d \n", player, columns - 1);
        fflush(stdin);
        if(player == 3)
            move = ai_move(columns-1);
        else
            scanf("%d", &move);
        if((move > columns) || (move < 0)) {
            printf("Please choose valid column");}
        else {
            if ((*board)[0][move-1] != 0) {
                if (player != 3)
                    printf("Row full please choose another one\n");
            }
            else break;
        }
    }
    while(i <= rows) {
        if((*board)[rows-i-1][move-1]==0) {
            (*board)[rows - i - 1][move-1] = player;
            break;
        }
        i++;
    }
}

void check_if_valid(int move,int columns, int rows, int(*board)[rows][columns]){

}

int ai_move(int columns){
    return (rand()%columns);
}

bool winnerfound(){
    true;
}