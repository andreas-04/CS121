#include <iostream>
#include <queue>

struct Coordinate{
    int x;
    int y;
};
class Maze
{
    private:
    //private data 
        int length; 
        int width;
        Coordinate startPosit, endPosit;
        char **grid;
        bool **visited;


int printNums;
    public:
    //class methods
        Maze();
        ~Maze();
        void solveMaze();
        void printMaze();
        bool available(int, int);


};