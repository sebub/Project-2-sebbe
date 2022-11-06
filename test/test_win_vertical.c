#include <assert.h>
#include "../src/WinCheck.h"

int gameMode;
int rows;
int columns;
int wincon;

int main(){

    rows = 4;
    columns = 4;
    wincon = 3;

    int grid[4][4] = {{0, 0, 0, 0},
                      {1, 0, 1, 0},
                      {1, 1, 2, 0},
                      {1, 2, 1, 2}};

    assert(check_vertical(1, 0, grid) == 1);

    int grid2[4][4] = {{0, 2, 0, 0},
                       {0, 2, 1, 0},
                       {1, 2, 2, 0},
                       {1, 1, 1, 2}};

    assert(check_vertical(2, 1, grid2) == 1);


    rows = 6;
    columns = 2;
    wincon = 6;

    int grid3[6][2] = {{0, 2},
                       {0, 2},
                       {1, 2},
                       {1, 2},
                       {1, 2},
                       {1, 2}};

    assert(check_vertical(2, 1, grid3) == 1);


    rows = 2;
    columns = 6;
    wincon = 2;

    int grid4[2][6] = {{0, 1, 1, 0, 0, 0},
                       {0, 2, 1, 2, 0, 0},};

    assert(check_vertical(1, 2, grid4) == 1);

    rows = 4;
    columns = 4;
    wincon = 3;

    int grid5[4][4] = {{0, 0, 0, 0},
                       {3, 3, 3, 0},
                       {3, 1, 2, 0},
                       {3, 2, 1, 2}};

    assert(check_vertical(3, 0, grid5) == 1);


}