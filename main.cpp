#include <iostream>
#include <vector>
#include <iomanip>

// maze definitions
#define ROWS 5
#define COLS 6

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

double mazeProb[ROWS][COLS] = {};   // buffer maze for storing probabilities

// parses maze to a readable output
void printMaze(int m[ROWS][COLS]){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(m[r][c] == 1){cout << "#### ";}
            else if(m[r][c] == 0){cout << "[  ] ";}
            else{cout << fixed << setprecision(2) << m[r][c] << " ";}
        }
        cout << endl;
    }
    cout << endl;
};

// overload function for prob buffer maze
void printMaze(double m[ROWS][COLS]){
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 1){cout << "#### ";}
            else{cout << fixed << setprecision(2) << m[r][c] << " ";}
        }
        cout << endl;
    }
    cout << endl;
};


int getTotal(){return (ROWS*COLS);} // returns total squares in maze

int getObstacles(){ // returns obstacles in maze
    int obstacles = 0;
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 1){obstacles++;}
        }
    }
    return obstacles;
}

int getOpen(){  // returns open squares in maze
    int open = 0;
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 0){open++;}
        }
    }
    return open;
}

double getProb(int t, int op, int ob){
    if(op == 0){return 0.0;} // incase theres no open squares?
    return 1.0/op;
}

void exploreMaze(){
    int total = getTotal();
    int open = getOpen();
    int obstacles = getObstacles();
    for(int r = 0; r < ROWS; r++){
        for(int c = 0; c < COLS; c++){
            if(maze[r][c] == 0){
                mazeProb[r][c] = getProb(total, open, obstacles)*100;
            }
            else{
                mazeProb[r][c] = 1;
            }
        }
    }
    cout << "Initial Location Probabilities: " << endl;
    printMaze(mazeProb);

    // TODO
    /*
    cout << "Filtering after Evidence [0, 0, 0, 1]: " << endl;
    printMaze();

    cout << "Prediction after Action N: " << endl;
    printMaze();

    cout << "Filtering after Evidence [1, 0, 0, 0]: " << endl;
    printMaze();

    cout << "Prediction after Action N: " << endl;
    printMaze();

    cout << "Filtering after Evidence [1, 1, 0, 0]: " << endl;
    printMaze();

    cout << "Prediction after Action E: " << endl;
    printMaze();

    cout << "Filtering after Evidence [0, 1, 1, 0]: " << endl;
    printMaze();
    */
}

int main(){
    exploreMaze();
    return 0;
}