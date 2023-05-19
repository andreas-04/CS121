#include <iostream>
#include <fstream>
#include "maze.h"
using namespace std;

//Class Constructor 
Maze::Maze()
{
//User selects a maze from maze folder
    ifstream myMazeFile;
    int selectVar;
    cout << "Select a Maze: [0-2] \n> ";
    cin >> selectVar;
    switch (selectVar)
    {
    case 0:
        myMazeFile.open("mazes/maze1.txt");
        printNums = 5;
        break;
    case 1:
        myMazeFile.open("mazes/maze2.txt");
        printNums = 100;
        break;
    case 2:
        myMazeFile.open("mazes/maze3.txt");
        printNums = 250;
    default:
        break;
    }

//Read into private class variables
    myMazeFile >> length >> width;

//Initialize the 2d char array
    grid = new char*[length];
    for( int i = 0; i < width; i++)
    {
        grid[i] = new char[length];
    }

//Loop through now initialized 2d array to find S and G in order to initialize 
//startPosit and endPosit both of which are coordinate structs, 2 ints, x and y

    for( int i = 0; i < length; i++)
    {
        for( int j = 0; j < width; j++)
        {
            myMazeFile >> grid[i][j];
            if(grid[i][j] == 'S')
            {
                startPosit.x = i;
                startPosit.y = j;
            }
            if(grid[i][j] == 'G')
            {
                endPosit.x = i;
                endPosit.y = j;
            }
        }
    }

//create a 2d array of bools for the visited squares, initially all '#' will be marked as visited
    visited = new bool*[length];
    for( int i = 0; i < width; i++)
    {
        visited[i] = new bool[length];
    }

    for( int i = 0; i < length; i++)
    {
        for( int j = 0; j < width; j++)
        {
            if (grid[i][j] == '#'||grid[i][j] == 'S')
            {
                visited[i][j] = true; 
            }else{
                visited[i][j] = false;
            }
        }
    }
}

//Class Destructor
Maze::~Maze()
{
    for (int i = 0; i < length; i++){
        //delyeet inner
        delete [] grid[i];
        delete [] visited[i];
    }
    //delyeet outer
    delete [] grid;
    delete [] visited;
}

//Breath first search solution to the maze problem
void Maze::solveMaze()
{
    cout <<"Beginning To Solve... Beep Boop\n";
    printMaze();
    //initialize queue for Coordinate data type
    queue<Coordinate> myQueue;
    //enqueue start position
    myQueue.push(startPosit);

    int counter = 0;

    while (!myQueue.empty())
    {
        counter++;

        //dequeue a coordinate off the stack, this will be the coordinate 
        //referenced for the rest of the loop
        Coordinate currentSq = myQueue.front();
        myQueue.pop();

        //check if we've reached the goal
        if(currentSq.x == endPosit.x && currentSq.y == endPosit.y){
            cout <<"Bingo!! Goal Reached After The "<<counter<<"th iteration\n";
            break;
        }
        //goal not reached, enqueue all available nearby unvisited nodes, from NESW
        else{
            //if available create a new temp coord and enqueue, mark as visited and change the value 
            // in the char 2d array
            if(available(currentSq.x, currentSq.y - 1)){
                
                Coordinate nextVert;
                nextVert.x = currentSq.x;
                nextVert.y = currentSq.y - 1;
                myQueue.push(nextVert);
                visited[currentSq.x][currentSq.y - 1] = true;
                if(grid[currentSq.x][currentSq.y - 1] != 'G') grid[currentSq.x][currentSq.y - 1] = '<';
            }
            if(available(currentSq.x + 1, currentSq.y)){
                Coordinate nextVert;
                nextVert.x = currentSq.x + 1;
                nextVert.y = currentSq.y;
                myQueue.push(nextVert);
                visited[currentSq.x + 1][currentSq.y] = true;
                if(grid[currentSq.x + 1][currentSq.y] != 'G') grid[currentSq.x + 1][currentSq.y] = 'v';
            }
            if(available(currentSq.x, currentSq.y + 1)){
                Coordinate nextVert;
                nextVert.x = currentSq.x;
                nextVert.y = currentSq.y + 1;
                myQueue.push(nextVert);
                visited[currentSq.x][currentSq.y + 1] = true;
                if(grid[currentSq.x][currentSq.y + 1] != 'G') grid[currentSq.x][currentSq.y + 1] = '>';
            }
            if(available(currentSq.x - 1, currentSq.y)){
                Coordinate nextVert;
                nextVert.x = currentSq.x - 1;
                nextVert.y = currentSq.y;
                myQueue.push(nextVert);
                visited[currentSq.x - 1][currentSq.y] = true;
                if(grid[currentSq.x - 1][currentSq.y] != 'G') grid[currentSq.x - 1][currentSq.y] = '^';
            }
        }
        //Print maze on every tenth iteration 
        if(counter % printNums == 0){
            cout << "After the " << counter <<"th iteration...\n";
            printMaze();
        }
    }
    //print when finished
    printMaze();
}

//check if coords i,j are available
bool Maze::available(int i, int j)
{
    //check if within bounds and not visited
    return (i >= 0 && i < length && j >= 0 && j < width && !visited[i][j]);
}

//print maze
void Maze::printMaze(){
    for(int i = 0; i < length; i++)
        cout << "-_";
    
    cout << endl;
    for( int i = 0; i < length; i++)
    {
        for( int j = 0; j < width; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    for(int j = 0; j < length; j++){
        cout << "-_";
    }
    cout << endl << endl;
}