# Day 1
>  Goals:
- Break Program in into modular functions
- work on program design
- start coding?
> Notes:
- hardest part will definetly be moving the robot around the grid, should be pretty simple with the 2 2d array setup going
> Recap
- finishined program design
- started writing the first function, not working atm, trouble with fstream...
- total time: 100 mins


# Day 2
> Goals:
- get getData() function working
- write arraySetup()
> Notes: 
- getData() fixed, input file was named "input. txt".... typo
- ended up creating a class to store robot position, grid size, the 2d array that hold the robots position and available squares, and the 2d array that holds the current visits of each square
> Recap
- As of now the basics of the class have been written, and a constructor has been written this entails creating the 2d arrays aswell as filling them with the correct data. Next time will work on a deconstructor because memory for the 2d arrays was allocated at runtime. Dynamic... ;)
- going to need a moveRobot() function aswell this will update the position of r, update the appropriate sqares to available/unavailable and update the visit count.
- total time: 90 mins

# Day 3
> Goals:
- write a deconstructor
- finish moverobo function
> Notes
- ended up deleting the roboArray, because it was pointless and just complicating my program. Dont know why i even thought about implementing it??? i was probably sleep deprived
- anyway, got moveRobot() working, need to fix issue with going out of bounds
  - current ideas, somehow check before hand? make sure i,j is within X[1, collumns] Y[1, rows]
- added a barrier to fix above issue
> Recap
- scrapped half of the original plan, ended up working out.
- program runs without errors
- fixed seg fault issue by adding barriers
- total time: 180 mins
  
# Day 4
> Goals:
- comment code
- clean up and seperate into 3 files
> Recap
- total time:  120 mins
