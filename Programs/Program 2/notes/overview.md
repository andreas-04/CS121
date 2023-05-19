# Program Reqs
- Read grid size, start position and max iterations
- alloc 2d array based on specifications
- move robot around
- Display contents of array when done

# Functions

  > getData()

  -read an input file and initialize  -> nRows, nCols, roboStartX, roboStartY, maxIterations

  > checkForAvailableCells()

  -will check all surrounding cells for availability based on max iterations

  > moveRobot()

  -will move the robo to a random *available* cell, meaning that hasnt its maximum visits yet. Function will also update the appropriate cells visitor count and the interation counter.

  > printArray()

  -prints array and its contents
