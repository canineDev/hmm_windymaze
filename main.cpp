#include <iostream>
#include <vector>

// maze definitions
#define ROWS 5
#define COLS 6
#define START_ROW 0
#define START_COL 0

// probabilities
constexpr double DETECT_OBSTACLE = 0.95;    // chance to correctly detects an obstacle
constexpr double DETECT_OBSTACLE_FALSE = 0.15;  // chance to incorrectly detect an open square as an obstacle
constexpr double MOVEMENT_STRAIGHT = 0.70;  // chance to move straight
constexpr double MOVEMENT_LEFT = 0.20;  // chance to drift left
constexpr double MOVEMENT_RIGHT = 0.10; // chance to drift right

using namespace std;    // bc im lazy

// maze i made using a 2D int
// open spaces = 0
// obstacles = 1
int maze[ROWS][COLS] = {
    {0, 0, 0, 0, 0, 0},
    {0, 1, 1, 1, 1, 0},
    {0, 1, 0, 0, 1, 0},
    {0, 1, 0, 0, 0, 0},
    {0, 0, 0, 0, 0, 0},
};

// parses maze to a readable output
void printMaze(){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 1){cout << "#### ";}
            else{cout << "[  ] ";}
        }
        cout << endl;
    }
    cout << endl;
};

int main(){
    printMaze();
    return 0;
}