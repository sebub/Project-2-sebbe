#include "game_of_lines.h"

int main() {
    printf("%d %d %d %d\n", gameMode, rows, columns, wincon);
    scan_setting();
    game_of_lines();
};

void scan_setting() { //Scans input for the game
    while (1) //Runs loop until user inputs valid game mode: 1 for singleplayer 2 for multiplayer
    {
        printf("Enter 1 for singleplayer, enter 2 for multiplayer");
        fflush(stdin);
        scanf("%d", &gameMode);
        if ((gameMode == 1) || (gameMode == 2))
            break;
    }

    while (1) //Runs loop until user inputs columns greater than 2
    {
        printf("Enter size of map");
        printf("Columns:");
        fflush(stdin);
        scanf("%d", &columns);
        if (columns > 1)
            break;
    }
    while (1) //Runs loop until user inputs rows greater than 2
    {
        printf("Rows:");
        fflush(stdin);
        scanf("%d", &rows);
        if (rows > 1)
            break;
    }

    printf("Enter number of connections to win:");
    scanf("%d", &wincon);

}//Takes user input to define gameMode: single or multiplayer, rows and columns in the game arena and how many you need to connect to win
void game_of_lines() {
    int (*arena)[rows][columns] = malloc(sizeof(int[rows][columns]));

    reset_arena(arena);
    print_arena(arena);

    scan_move(arena);
}

void print_arena(int (*arena)[rows][columns]) {
    for (int i = 0; i < columns; ++i) {
        printf("|%d| ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if ((*arena)[i][j] == 1)
                printf("|x| ");
            else if ((*arena)[i][j] == 2 || (*arena)[i][j] == 3) {
                printf("|o| ");
            } else
                printf("|_| ");
        }
        printf("\n");
    }
}

void reset_arena(int (*arena)[rows][columns]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*arena)[i][j] = 0;
        }
    }
}

int scan_move(int (*arena)[rows][columns]) {
    for (int i = 0; i < (rows * columns) / 2; ++i) {
        int moveColumn;
        int moveRow;
        if (gameMode == 1) {
            update_arena(1, &moveColumn, &moveRow, arena);
            if ((check_horizontal(moveColumn, moveRow, 1, arena)) == 1
                || (check_vertical(1, moveColumn, arena) == 1)
                || (check_diagonal(1, moveColumn, moveRow, arena) == 1)) {
                print_arena(arena);
                break;
            }

            update_arena(3, &moveColumn, &moveRow, arena);
            if (check_horizontal(moveColumn, moveRow, 1, arena) == 1
                || check_vertical(3, moveColumn, arena) == 1
                || check_diagonal(3, moveColumn, moveRow, arena) == 1) {
                print_arena(arena);
                break;
            }
            print_arena(arena);

        }
        if (gameMode == 2) {
            update_arena(1, &moveColumn, &moveRow, arena);
            if (check_horizontal(moveColumn, moveRow, 1, arena) == 1
                || check_vertical(1, moveColumn, arena) == 1
                || check_diagonal(1, moveColumn, moveRow, arena) == 1
                || (check_diagonal2(1,moveColumn,moveRow,arena)== 1)){
                print_arena(arena);
                break;
            }
            print_arena(arena);


            update_arena(2, &moveColumn, &moveRow, arena);
            if ((check_horizontal(moveColumn, moveRow, 2, arena) == 1)
                || (check_vertical(2, moveColumn, arena) == 1)
                || (check_diagonal(2, moveColumn, moveRow, arena) == 1)
                || (check_diagonal2(2,moveColumn,moveRow,arena)== 1)) {
                print_arena(arena);
                break;
            }
            print_arena(arena);
        }
        if (i == ((rows * columns) / 2) - 1)
            printf("Its a tie no one wins");
    }
}

void update_arena(int player, int *moveColumn, int *moveRows, int(*board)[rows][columns]) {
    int i = 0;
    while (1) {
        if (player != 3)
            printf("Player %d choose column between 1 and %d \n", player, columns);
        if (player == 3)
            *moveColumn = ai_move();
        else
            scanf("%d", moveColumn);
        if ((*moveColumn > columns) || (*moveColumn < 0)) {
            printf("Please choose valid column");
        } else {
            if ((*board)[0][*moveColumn - 1] != 0) {
                if (player != 3)
                    printf("Row full please choose another one\n");
            } else break;
        }
    }
    while (i <= rows) {
        if ((*board)[rows - i - 1][*moveColumn - 1] == 0) {
            (*board)[rows - i - 1][*moveColumn - 1] = player;

            *moveRows = rows - i - 1;
            *moveColumn = *moveColumn - 1;
            break;
        }
        i++;
    }
}

int check_horizontal(int moveColumn, int moveRows, int player, int (*board)[rows][columns]) {
    int count = 0;
    for (int j = 0; j < columns; ++j) {
        if ((*board)[moveRows][j] == player)
            count++;
        if (count == wincon) {
            return winnerMessage(player);
        }
        if ((*board)[moveRows][j] != player) {
            count = 0;
        }
    }
    return 0;
}

int check_vertical(int player, int moveColumn, int (*board)[rows][columns]) {
    int count = 0;
    for (int j = 0; j < columns; ++j) {
        if ((*board)[j][moveColumn] == player)
            count++;
        if (count == wincon) {
            return winnerMessage(player);
        }
        if ((*board)[j][moveColumn] != player) {
            count = 0;
        }
    }

    return 0;
}

int check_diagonal(int player, int moveColumn, int moveRows, int (*board)[rows][columns]) {
    int count = 0;
    int j = 0;
    int i = 0;
    while ((moveRows - j >= 0) && (moveColumn - j >= 0)) {
        if ((*board)[moveRows - j][moveColumn - j] == player) {
            printf("%d %d", moveRows - j, moveColumn - j);
            count++;
        } else if (count == wincon) {
            printf("'Fail 1'");
            return winnerMessage(player);
        } else if ((*board)[moveRows - j][moveColumn - j] != player) {
            count = 0;
            while (moveRows + i <= rows && moveColumn + i <= columns) {
                if ((*board)[moveRows + i][moveColumn + i] == player)
                    count++;
                if (count == wincon) {
                    printf("'Fail 2'");
                    return winnerMessage(player);
                }
                i++;
            }
        }
        j++;
    }
    return 0;
}

int check_diagonal2(int player, int moveColumn, int moveRows, int (*board)[rows][columns]) {
    int count = 0;
    int count2 =0;
    int j = 0;
    int i = 0;
    while ((moveRows + j < rows) && (moveColumn - j >= 0)) {
        printf("hello\n");
        printf("(%d,%d) dirgo 2\n", moveRows + j, moveColumn - j);
        if ((*board)[moveRows + j][moveColumn - j] == player) {
            ++count;
            printf("Count is %d\n",count);
        }
        if (count == wincon) {
            printf("'Fail 3'");
            return winnerMessage(player);
        } else if ((*board)[moveRows + j][moveColumn - j] != player) {
            while (moveRows - i <= 0 && moveColumn + i <= columns) {
                if ((*board)[moveRows - i][moveColumn + i] == player) {
                    count2++;
                    printf("count 2 is %d",count2);
                }
                if (count2 == wincon) {
                    printf("'Fail 4'");
                    return winnerMessage(player);
                }
                i++;
            }
        }
        j++;
    }
    return 0;
}


int ai_move() {
    return (rand() % columns);
}

int winnerMessage(int player) {
    printf("\nPlayer %d won by connecting %d\n", player, wincon);
    printf("__________________________\n");
    return 1;
}
