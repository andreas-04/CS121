#include <iostream>
#include "stack.h"
void Stack::push(int x, int y){
    node* newNode = new node;
    coordinate newCoord;
    newCoord.x = x;
    newCoord.y = y;
    newNode -> posit = newCoord;

    if(topOfStack == NULL)
        topOfStack = newNode;
    else{
        newNode -> next = topOfStack;
        topOfStack = newNode;
    }
}
coordinate Stack::pop(){
    node * delNode;
    coordinate poppedCoords;
    if( topOfStack == NULL ){
        std::cout << "Error::Pop: stack empty" << std::endl;
    }else{

        delNode = topOfStack;
        poppedCoords.x = delNode -> posit.x;
        poppedCoords.y = delNode -> posit.y;
        topOfStack =  topOfStack -> next;
        delNode -> next = NULL;
        delete delNode;
    }
    return poppedCoords;
}
void Stack::print()
{
    node * p = topOfStack;
    while ( p != NULL ){
        std::cout << p ->posit.x << ", " << p -> posit.y << "\n";
        p = p -> next;
    }
}
coordiante Stack::peek(){
    coordinate poppedCoords;
    
    if( topOfStack == NULL ){
        std::cout << "Error::Pop: stack empty" << std::endl;
    }else{
        poppedCoords.x = topOfStack -> posit.x;
        poppedCoords.y = topOfStack -> posit.y;
    }
    return poppedCoords;
}
bool Stack::isEmpty(){
    return topOfStack == NULL;
}