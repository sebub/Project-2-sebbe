#include <assert.h>
#include "../src/WinCheck.h"

int gameMode;
int rows;
int columns;
int wincon;

int main(){
    rows = 4;
    columns = 4;

    //Player 1, last move placed (1,2): Expecting to find 3 connected pieces
    int grid[4][4] = {{0,0,0,0},
                      {0,0,1,0},
                      {0,1,2,0},
                      {1,2,1,2}};

    assert(diagonal_anti(1,1,2,grid)==3);

    //Player 2, last move placed (2,0): Expecting to find 3 connected pieces
    int grid2[4][4] = {{0,0,2,0},
                      {0,2,1,0},
                      {2,1,2,0},
                      {1,2,1,2}};

    assert(diagonal_anti(2,2,0,grid2)==3);

    //Player 2, last move placed (0,0): Expecting to find 4 connected pieces
    int grid3[4][4] = {{2,0,0,0},
                      {1,2,1,0},
                      {1,1,2,0},
                      {1,2,1,2}};

    assert(diagonal_main(2,0,0,grid3)==4);


    //Player 1, last move placed (1,0): Expecting to find 3 connected pieces
    int grid4[4][4] = {{0,0,0,1},
                       {1,2,1,2},
                       {1,1,2,1},
                       {1,2,1,2}};


    assert(diagonal_main(1,1,0,grid4)==3);


    //AI, last move placed (0,0): Expecting to find 3 connected pieces
    int grid5[4][4] = {{3, 0, 0, 0},
                       {3, 3, 3, 0},
                       {1, 1, 3, 0},
                       {1, 2, 1, 2}};

    assert(diagonal_main(3, 0,0, grid5) == 3);




}