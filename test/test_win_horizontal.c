#include <assert.h>
#include "../src/WinCheck.h"

int gameMode;
int rows;
int columns;
int wincon;

int main() {

    rows = 4;
    columns = 4;
    wincon = 3;

    int grid[4][4] = {{0, 0, 0, 0},
                      {1, 1, 1, 0},
                      {1, 1, 2, 0},
                      {1, 2, 1, 2}};

    assert(check_horizontal(1, 1, grid) == 1);

    int grid2[4][4] = {{0, 2, 0, 0},
                       {0, 2, 1, 0},
                       {1, 2, 2, 2},
                       {1, 1, 1, 2}};

    assert(check_horizontal(2, 2, grid2) == 1);


    rows = 6;
    columns = 2;
    wincon = 2;

    int grid3[6][2] = {{0, 2},
                       {0, 2},
                       {1, 2},
                       {1, 2},
                       {2, 2},
                       {1, 2}};

    assert(check_horizontal(4, 2, grid3) == 1);


    rows = 2;
    columns = 6;
    wincon = 3;

    int grid4[2][6] = {{0, 1, 1, 0, 0, 0},
                       {1, 1, 2, 2, 2, 1},};

    assert(check_horizontal(1, 2, grid4) == 1);

    rows = 4;
    columns = 4;
    wincon = 3;

    int grid5[4][4] = {{0, 0, 0, 0},
                      {3, 3, 3, 0},
                      {1, 1, 2, 0},
                      {1, 2, 1, 2}};

    assert(check_horizontal(1, 3, grid5) == 1);


}