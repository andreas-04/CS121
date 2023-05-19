# Program 3 Overview

## Description

- Program 3 is a Infix to Postfix expression algorithm. Making use of a stack data structure implemented using a linked list. The program takes a properly formatted infix expression and returns the postfix of the said expression ex: (3+4) = 3 4 +

## Main Functions

- `string getInfix();`
  - This function gets user input for the infix string
    - Function uses `getline()` to avoid whitespace errors

- `int getPrecedence(char);`
  - This function determines precedence of a operator
    - Making use of a switch statement, we return a 1 if '+' or '-', 2 if '*' or '/', and 0 by default

- `string inToPost(string);`
  - This is the main function of the program and implements the algorithm we were given by Professor Bolden
    - We iterate through the given infix string and return a postfix string once we complete all steps required.
- `string addWhitespaceBetweenChars(string str);`
  - This function adds whitespace between the characters of a string 
    - Ex: '34+' -> '3 4 +'

