#include <stdio.h>
#include "WinCheck.h"

int check_horizontal(int moveRows, int player, int (*board)[rows][columns]) {
    int count = 0;
    for (int j = 0; j < columns; ++j) {
        if ((*board)[moveRows][j] == player)
            count++;
        if (count == wincon) {
            printf("horizontal");
            return 1;
        }
        if ((*board)[moveRows][j] != player) {
            count = 0;
        }
    }
    return 0;
}

int check_vertical(int player, int moveColumn, int (*board)[rows][columns]) {
    int count = 0;
    for (int j = 0; j < rows; ++j) {
        if ((*board)[j][moveColumn] == player)
            count++;
        if (count == wincon) {
            printf("vertical");
            return 1;
        }
        if ((*board)[j][moveColumn] != player) {
            count = 0;
        }
    }
    return 0;
}

int check_diagonal(int player, int moveRows, int moveColumns, int (*board)[rows][columns]) {
    int tempgird[rows][columns];
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tempgird[i][j] = (*board)[i][j];
        }
    }
    if (diagonal_left(player, moveRows, moveColumns, tempgird) == wincon) {
        printf("(%d,%d)\n",moveColumns, moveRows);
        printf("%d\n",wincon);
        printf("left\n");
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tempgird[i][j] = (*board)[i][j];
        }
    }
    if (diagonal_right(player, moveRows, moveColumns, tempgird) == wincon) {
        printf("right");
        return 1;
    }
    return 0;
}

int checkWinner(int player, int moveRows, int moveColumns, int (*board)[rows][columns]) {
    if ((check_horizontal(moveRows, player, board) == 1)
        || (check_vertical(player, moveColumns, board) == 1)
        || (check_diagonal(player, moveRows, moveColumns, board) == 1))
        return player;
    else
        return -1;
}

int diagonal_left(int player, int moveRows, int moveColumns, int tempgird[rows][columns]) {
    if ((moveRows <= rows) && (moveRows >= 0) && ((moveColumns <= columns) && (moveColumns >= 0))) {
        if (tempgird[moveRows][moveColumns] == player) {
            tempgird[moveRows][moveColumns] = 0;
            return 1 +
                   diagonal_left(player, moveRows - 1, moveColumns - 1, tempgird) +
                   diagonal_left(player, moveRows + 1, moveColumns + 1, tempgird);
        }
        return 0;
    }
    return 0;
}

int diagonal_right(int player, int moveRows, int moveColumns, int tempgird[rows][columns]) {
    if ((moveRows < rows) && (moveRows >= 0) && ((moveColumns < columns) && (moveColumns >= 0))) {
        if (tempgird[moveRows][moveColumns] == player) {
            tempgird[moveRows][moveColumns] = 0;
            return 1 +
                   diagonal_right(player, moveRows + 1, moveColumns - 1, tempgird) +
                   diagonal_right(player, moveRows - 1, moveColumns + 1, tempgird);
        }
        return 0;
    }
    return 0;
}