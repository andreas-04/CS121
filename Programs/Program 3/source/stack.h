/* stack.h
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * prototype for Stack Class
 *---------------------------------------------------------------------
 */

#include <iostream>
#include "linkedList.h"

class Stack{
    private:
        linkedList top;
    public:

//constructor/destructor
        Stack()
        {
        }
        ~Stack()
        {
            while(!isEmpty())
            {
                char c = top.firstNode();
                top.deleteNode(c);
            }
        }

//Function prototypes
        void push(char);
        char pop();
        char peek();
        bool isEmpty();
        void print();
};