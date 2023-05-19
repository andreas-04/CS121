/* main.cpp
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * algorithm implementation
 *---------------------------------------------------------------------
 */
#include <iostream>
using namespace std;
#include "main.h"

int main(){

//get user input for infix
    string infixExpression = getInfix();

//convert infix to postfix
    string postFixExpression = inToPost(infixExpression);

//print postfix
    cout << postFixExpression << endl;

    return 0;
}
