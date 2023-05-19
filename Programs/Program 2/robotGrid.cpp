/* robotGrid.cpp
 *
 * CS 121.Bolden.........Compiler Version: 12.0.5...........Andreas Neacsu
 * 2/10/2023, .................M1 Macintosh.............neac9115@vandals.uidaho.edu
 *
 * Function defenitions for robotGrid Class
 *---------------------------------------------------------------------
 */
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>
#include "robotGrid.h"

RobotGrid::RobotGrid()
{
//Retrive  values corresponding with grid length and width, initial position, and max visits from a file, and initialize private data members.

    std::ifstream myfile;
    myfile.open("input.txt");
    myfile >> length >> width >> positionX >> positionY >> maxVisits;

//dynamically allocate memory for 2d array

    cellVisits = new int* [length];
    for( int i = 0; i < width; i++)
    {
        cellVisits[i] = new int[width];
    }

//fill 2D array with 0's

    for( int i = 0; i < length; i++)
    {
        for( int j = 0; j < width; j++)
        {
            cellVisits[i][j] = 0;
        }
    }

//set our robots starting position visit count to 1

    cellVisits[positionX][positionY] = 1;

}

bool RobotGrid::checkForAvailableCells()
{
    /*
    Function Overview:
        - loop through all surrounding cells neighboring the current cell
        - check that each iteration is within bounds
        - compare the value to the max visits allowed
        - for each cell with less than the max visits allowed, a variable will be incremented
        - once done checking all cells, determine the return value based on the variable from the previous step
    */
    int availableCells = 0;

//loop through all surrounding cells neighboring the current cell

    for(int i = positionX - 1; i <= positionX + 1; i++ )
    {
        for (int j = positionY - 1; j <= positionY + 1; j++ )
        {

//check that the iteration is within bounds

            if(i >= 0 && i < width && j >= 0 && j < length)
            {

//compare the value to the max visits allowed

                if(cellVisits[i][j] < maxVisits)
                {

//for each cell with less than the max visits allowed, a variable will be incremented

                    availableCells ++;
                }
            }
        }
    }
    
//once done checking all cells, determine the return value based on the incremented variable

    if(availableCells > 0)
    {
        return true;
    }else
    {
        return false;
    }
}

void RobotGrid::moveRobot()
{
/*
    Function overview:
        - Choose a random integer 0-8 (not including 4, as that is the current position), 
          this will represent the selected cell.
        - With the use of a iterator variable to keep track of which cell we are accessing,
          begin looping through our robots neighbors.
        - Check that the iteration or cell is within our specified bounds.
        - Check if we have arrived at our desired cell by comparing our current cell number to the 
          random integer selected earlier
        - Check that the cell we want to move to has not reached its max visits
        - If we have arrived, iterate our next cell's visit count by one, 
          set our position and terminate the loop.
        
        Note:
           -The above is contained in a while loop, if the random cell picked isnt available the function will
            continue picking cells until the robot has moved

           -This function could create an infinte loop if not used properly with checkForAvailableCells(),
            make sure to confirm that there are available cells within a vicinity before calling moveRobot()
*/
    bool hasMoved = false;
    while (!hasMoved)
    {

//Choose a random integer 0-8 (not including 4, as that is the current position)

        int randCell;
        while(true)
        {
            randCell = (rand() % 9);
            if(randCell != 4)
            {
                break;
            }
        }

//Iterator variable to keep track of which cell we are accessing

        int currentCell = 0;

//Begin looping through our robots neighbors.

        for(int i = positionX - 1; i <= positionX + 1; i++ )
        {
            for (int j = positionY - 1; j <= positionY + 1; j++ )
            {

//Check that the iteration or cell is within our specified bounds.

                if(i >= 0 && i < length && j >= 0 && j < width)
                {

//Check if we have arrived at our desired cell by comparing our current cell number to the random integer
//Check that the cell we want to move to has not reached its max visits
                
                    if(cellVisits[i][j] < maxVisits && currentCell == randCell)
                    {

//iterate our next cell's visit count by one, set our position and terminate the loop.

                        cellVisits[i][j] +=1;
                        positionX = i;
                        positionY = j;
                        currentCell++;
                        hasMoved = true;
                    }else
                    {
                        currentCell++;
                    }
                }
            }
        }
    }
}

void RobotGrid::printCells()
{
/*
    Function overview:
        -Print out the 2d array of cells, using 2 nested for loops.
*/
    for( int i = 0; i < length; i++)
    {
        for( int j = 0; j < width; j++)
        {
            std::cout <<"{"<< cellVisits [i][j]<<"} ";
        }
        std::cout << "\n";
    }

}