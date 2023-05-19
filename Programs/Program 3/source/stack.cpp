/* stack.cpp
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * definition of Stack class
 *---------------------------------------------------------------------
 */
#include <iostream>
#include "stack.h"

//Push char onto the stack
void Stack::push(char x){
    top.addToFront(x);
}

//delete the first char off the stack
//return the deleted char
char Stack::pop()
{
    char c = top.firstNode();
    top.deleteFirst();
    return c;
}

//print the stack
void Stack::print()
{
   top.print();
}

//return the first item off the stack
char Stack::peek()
{

    char c = top.firstNode();
    return c;
}

//return true if stack is empty, false if otherwise
bool Stack::isEmpty()
{
    int n = top.size();
    return(n == 0);
}