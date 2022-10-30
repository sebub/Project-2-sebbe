#include <stdio.h>
#include <malloc.h>
#include "game_of_lines.h"

int main(void)
{
    int Mode, Columns, Rows, connectToWin;
    scan_setting(&Mode,&Columns,&Rows,&connectToWin);

    game_of_lines(Mode,Columns,Rows,connectToWin);
    while(1);
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
    printf("__________________________\n");
    while(1){
        scan_move(gameMode,rows,columns,arena);
        print_arena(rows,columns,arena);
        i++;
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
    if(mode == 2)
    printf("Player choose column between 0 and %d ",columns-1);
    scanf("%d",&move);


}


