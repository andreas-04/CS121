# Programming Log

## Day 1

- Met with a friend and discussed the assignment
- began planning and pseudo-coding
- started writing basic functions such as the class constructor and print function 
### Total Time: 80 mins

## Day 2

- Continued coding, started writing the main function `solveMaze()`
- ran into an issue as my code was accessing all 8 cardinal directions N, NE, E, SE, S, SW, W, NW, instead of just N E S W 
- identified this issue was coming from a nested for loop I was using to get all neighboring coordinates
- fixed by creating a function called `available()` checking coordinates are within bounds and not visited already
  then used 4 if statements on all 4 cardinal directions 
### Total time: 120 Mins

## Day 3

- added capability for more than 1 maze
- added visual indication of how the program was moving ie:(^,>,v,<)
- added feature that prints the maze only every x iterations, where x is dependant on the size of the maze
- commented most of the code
- wrote a destructor
### Total time: 120 Mins

