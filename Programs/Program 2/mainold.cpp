#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>


int rows, cols, positX, positY, MxVS;

void getData(){
    std::ifstream myfile;
    myfile.open("input.txt");
    myfile >> rows >> cols >> positX >> positY >> MxVS;
}

class Xyz{
    private:

    int length, width, positionX, positionY, maxVisits;

    int** cellVisits;
    char** roboArray;
    public:
    Xyz(){
        length = cols;
        width = rows;
        positionX = positX;
        positionY = positY;
        maxVisits = MxVS;

        cellVisits = new int* [length];
        roboArray = new char* [length];

        for( int i = 0; i < width; i++){
            cellVisits[i] = new int[width];
            roboArray[i] = new char[width];
        }
        
        for( int i = 0; i < length; i++){
            for( int j = 0; j < width; j++){
                cellVisits[i][j] = 0;
                roboArray[i][j] = 'a';
            }
        }
        roboArray[positionX][positionY] = 'r';
        cellVisits[positionX][positionY] += 1;
        

    }
    // ~Xyz(){
    //     for(int i = 0; i < width; i++)
    //         {
    //             delete[] cellVisits[i];
    //             delete[] roboArray[i];
    //         }
    //     // delete outer arrays
    //     delete[] cellVisits;
    //     delete[] roboArray;
    // }
    void printRoboArr(){
        for( int i = 0; i < length; i++){
            for( int j = 0; j < width; j++){
                std::cout << roboArray [i][j];
            }
            std::cout << "\n ";
        }
    }
    void printCellVisitsArr(){
        for( int i = 0; i < length; i++){
            for( int j = 0; j < width; j++){
                std::cout << cellVisits [i][j];
            }
            std::cout << "\n ";
        }
    }
    void updateBoard(){
        roboArray[positionX][positionY] = 'r';
        cellVisits[positionX][positionY]+=1;
        for( int i = 0; i < length; i++){
            for( int j = 0; j < width; j++){
                if(cellVisits[i][j] > maxVisits){
                    roboArray[i][j] = 'u';
                }

            }
        }

    }
    void moveRobot(){
        /* give me random cell, int 1-8
             check cell available
               / yes       \ no
               move there       from the top
            */
        bool hasMoved = false;

        while (hasMoved != true)
        {
            int randCell = (rand() % 7);
                if(randCell == 4){
                    randCell++;
                }
            std::cout <<"\nSelected cell: "<< randCell<< std::endl;
            int counter = 0;
            for(int i = positionX - 1; i < positionX + 2; i++ ){
                for (int j = positionY - 1; j < positionY + 2; j++ ){
                    if(roboArray[i][j] == 'a' && counter == randCell){
                        std::cout << counter<< "\n";
                        std::cout<< i<<", "<<j<<"\n";
                        
                        positionX = i;
                        positionY = j;
                        updateBoard();
                        hasMoved = true;
                        counter++;
                    }else{
                    counter++;
                    }
                }
            }
            
        }
    }

};

int main(){
    srand(time(0));
    getData();
    Xyz myXYZ = Xyz();
    myXYZ.printRoboArr();
    myXYZ.printCellVisitsArr();
    for(int i = 0; i < 20;i++){
        myXYZ.moveRobot();
    }
    myXYZ.printRoboArr();
    myXYZ.printCellVisitsArr();


}

