#include <stdio.h>
#include "WinCheck.h"


int checkWinner(int player, int moveRows, int moveColumns, int (*board)[rows][columns]) {
    if ((check_horizontal(player, moveRows, board) == 1)
        || (check_vertical(player, moveColumns, board) == 1)
        || (check_diagonal(player, moveRows, moveColumns, board) == 1))
        return player;
    else
        return -1;
}

int check_horizontal(int player, int moveRows, int (*board)[rows][columns]) {
    int count = 0;
    for (int i = 0; i < columns; ++i) {
        if ((*board)[moveRows][i] == player)
            count++;
        if (count == wincon) {
            return 1;
        }
        if ((*board)[moveRows][i] != player) {
            count = 0;
        }
    }
    return 0;
}

int check_vertical(int player, int moveColumn, int (*board)[rows][columns]) {
    int count = 0;
    for (int i = 0; i < rows; ++i) {
        if ((*board)[i][moveColumn] == player)
            count++;
        if (count == wincon) {
            return 1;
        }
        if ((*board)[i][moveColumn] != player) {
            count = 0;
        }
    }
    return 0;
}

int check_diagonal(int player, int moveRows, int moveColumns, int (*board)[rows][columns]) {
    int tempboard[rows][columns];     //duplicates the array allocated in game_of_lines to avoid an
    for (int i = 0; i < rows; i++) {  //endless recursive call in diagonal_main and diagonal_anti
        for (int j = 0; j < columns; j++) {
            tempboard[i][j] = (*board)[i][j];
        }
    }
    if (diagonal_main(player, moveRows, moveColumns, tempboard) == wincon) {
        return 1;
    }

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < columns; j++) {
            tempboard[i][j] = (*board)[i][j];
        }
    }
    if (diagonal_anti(player, moveRows, moveColumns, tempboard) == wincon) {
        return 1;
    }
    return 0;
}

int diagonal_main(int player, int moveRows, int moveColumns, int tempboard[rows][columns]) {
    if ((moveRows <= rows) && (moveRows >= 0) && ((moveColumns <= columns) && (moveColumns >= 0))) {
        if (tempboard[moveRows][moveColumns] == player) {
            tempboard[moveRows][moveColumns] = 0; //Sets current coordinate to 0 avoid endless recursive call
            return 1 +
                   diagonal_main(player, moveRows - 1, moveColumns - 1, tempboard) + //keeps calling 1 + itself until functions
                   diagonal_main(player, moveRows + 1, moveColumns + 1, tempboard);  //return 0 which means that there are no
        }                                                                                                 //more connected pieces. Then returns the
        return 0;                                                                                         //the value equal to the number of recursive calls
    }                                                                                                     //where the tempboard[x][y] = player.
    return 0;
}

int diagonal_anti(int player, int moveRows, int moveColumns, int tempboard[rows][columns]) {
    if ((moveRows < rows) && (moveRows >= 0) && ((moveColumns < columns) && (moveColumns >= 0))) {
        if (tempboard[moveRows][moveColumns] == player) {
            tempboard[moveRows][moveColumns] = 0;
            return 1 +
                   diagonal_anti(player, moveRows + 1, moveColumns - 1, tempboard) +
                   diagonal_anti(player, moveRows - 1, moveColumns + 1, tempboard);
        }
        return 0;
    }
    return 0;
}