#include <iostream>
#include <vector>

#define ROWS 5
#define COLS 6
#define START_ROW 0
#define START_COL 0

using namespace std;    // bc im lazy

int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
};

void printMaze(){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 1){cout << "#### ";}
            else{cout << "[  ] ";}
        }
        cout << "\n";
    }
};

int main(){
    printMaze();
    return 0;
}