#include "game_of_lines.h"


int main(void) {
    srand(time(NULL)); //initiates srand to be able to make a simple AI.

    game_of_lines();
}


void game_of_lines() {
    char playAgain = 'y';
    while (playAgain != 'n') {
        scan_setting();
        int (*board)[rows][columns] = malloc(sizeof *board);

        reset_board(board);
        print_board(board);

        update_board(board);

        printf("Want to play again?  y/n: ");
        fflush(stdin);
        scanf("%c", &playAgain);
        free(board);
    }
}

void scan_setting() {
    while (1) {
        printf("Enter 1 for singleplayer, enter 2 for multiplayer");
        fflush(stdin);//clears buffer to make sure scanf is not skipped
        scanf("%d", &gameMode);
        if ((gameMode == 1) || (gameMode == 2))
            break;
    }

    while (1) {
        printf("Enter size of map\n");
        printf("Columns:");
        fflush(stdin);
        scanf("%d", &columns);
        if (columns > 1)
            break;
    }
    while (1) {
        printf("Rows:");
        fflush(stdin);
        scanf("%d", &rows);
        if (rows > 1)
            break;
    }

    printf("Enter number of connections to win:");
    scanf("%d", &wincon);

}

void reset_board(int (*board)[rows][columns]) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            (*board)[i][j] = 0;
        }
    }
}

void print_board(int (*board)[rows][columns]) {
    for (int i = 0; i < columns; ++i) {
        printf("| %d |", i + 1);
    }
    printf("\n");
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < columns; ++j) {
            if ((*board)[i][j] == 1) {
                printf("| x |");
            } else if ((*board)[i][j] == 2 || (*board)[i][j] == 4) {
                printf("| o |");
            } else
                printf("| - |");
        }
        printf("\n");
    }
}

void update_board(int (*board)[rows][columns]) {
    int Tiecount = 0;
    while (Tiecount < (rows * columns)) {
        int moveColumn;
        int moveRow;
        if (gameMode == 1) {
            scan_move(1, &moveColumn, &moveRow, board);
            Tiecount++;
            if (checkWinner(1, moveRow, moveColumn, board) == 1) {
                printf("You won!\n");
                print_board(board);
                break;
            }

            if (Tiecount >= (rows * columns)) {
                printf("its a tie!\n");
                print_board(board);
                break;
            }
            scan_move(4, &moveColumn, &moveRow, board);
            Tiecount++;
            if (checkWinner(4, moveRow, moveColumn, board) == 4) {
                printf("AI won you suck\n");
                print_board(board);
                break;
            }
            print_board(board);

        }
        if (gameMode == 2) {
            scan_move(1, &moveColumn, &moveRow, board);
            Tiecount++;
            if (checkWinner(1, moveRow, moveColumn, board) == 1) {
                printf("player 1 won\n");
                print_board(board);
                break;
            }
            print_board(board);

            if (Tiecount >= (rows * columns)) {
                printf("its a tie!\n");
                print_board(board);
                break;
            }
            scan_move(2, &moveColumn, &moveRow, board);
            Tiecount++;
            if (checkWinner(2, moveRow, moveColumn, board) == 2) {
                printf("player 2 won\n");
                print_board(board);
                break;
            }
            print_board(board);
        }
        if (Tiecount >= (rows * columns)) {
            printf("its a tie!\n");
        }
    }
}

void scan_move(int player, int *moveColumn, int *moveRows, int(*board)[rows][columns]) {
    int i = 0;
    while (1) {
        if (player != 4)
            printf("Player %d choose column between 1 and %d \n", player, columns);
        if (player == 4)
            *moveColumn = ai_move() + 1;
        else
            scanf("%d", moveColumn);
        if ((*moveColumn > columns) || (*moveColumn < 0)) {
            printf("Please choose valid column");
        } else {
            if ((*board)[0][*moveColumn - 1] != 0) {//If every element in chosen row is filled runs loop again
                if (player != 4)
                    printf("Row full please choose another one\n");
            } else
                break;
        }
    }
    while (i <= rows) {
        if ((*board)[rows - i - 1][*moveColumn - 1] == 0) {   //Checks value of each element in a column until it finds
            (*board)[rows - i - 1][*moveColumn - 1] = player; //0 then replaces it with value of current player

            *moveRows = rows - i - 1;       //when value is replaced moveRows and moveColumn is defined to be able
            *moveColumn = *moveColumn - 1;  //check this move have triggered a win
            break;
        }
        i++;
    }
}

int ai_move() {
    return (rand() % columns);
}