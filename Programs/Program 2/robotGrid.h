/* robotGrid.h
 *
 * CS 121.Bolden.........Compiler Version: 12.0.5...........Andreas Neacsu
 * 2/10/2023, .................M1 Macintosh.............neac9115@vandals.uidaho.edu
 *
 * prototype for robotGrid Class
 *---------------------------------------------------------------------
 */
class RobotGrid
{
    private:
//grid length size
        int length;
//grid width size
        int width;
//robots initial starting x coordinate
        int positionX;
//robots initial starting y coordinate
        int positionY;
//each cells number of visits allowed before its innaccesible
        int maxVisits;
//2d array of cells
        int** cellVisits;
    public:
        RobotGrid();
        //~RobotGrid();
        bool checkForAvailableCells();
        void moveRobot();
        void printCells();
};