# Program Log

## Day 1


### Objective
  1. Work through the given algorithm by hand to fully understand how it works.
   
  2. add `char peak()` function to stack class for step 15
   
  3. implement the algorithm in c++
       - using a stack to store elements of infix expression, as per instruction

### Recap
- 80% of algorithm implemented successfully
- Program currently compiles but when running, results in an infinite loop
- bug tested and narrowed the problem down to the while loop when the token is an operator
- solution is most likely to implement operator precedence correctly, I will write a function for that tomorrow.


>Total Time: 180 mins

## Day 2

### Objective

  1. Fix infinite loop

### Recap
- Successfully fixed the infinite loop issue, added a condition to check if the stack was empty 
  
- Wrote a separate function `int getPrecedence(char)` to determine operator precedence
  
- checked if the top element of the stack had greater precedence before entering the loop

>Total Time: 90 mins

## Day 3

### Objective

  1. Add comments to code, and write the program overview

>Total Time: 30 mins

