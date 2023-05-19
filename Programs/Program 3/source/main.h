/* main.h
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * definitions of main functions
 *---------------------------------------------------------------------
 */

#include <iostream>
using namespace std;
#include "stack.h"
#include <ctype.h>


//Function Prototypes
string getInfix();
int getPrecedence(char);
string inToPost(string);
string addWhitespaceBetweenChars(string); 

//get user input for infix expression
string getInfix(){
    string myString;
    cout<< "Enter Infix Expression: ";
    getline(cin, myString);
    return myString;
}

//return op precedence
int getPrecedence(char c){
    switch (c)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    default:
        return 0;
    }
}

//Convert infix to postfix
string inToPost(string infixExpression){

    string postFixExpression;
    Stack infixToPostfixStack;

//Push a ’(’ onto the stack
    infixToPostfixStack.push('(');

//Add a ’)’ to the end of the infix expression
    infixExpression.push_back(')');

    int i = 0;
    
//while the end of the expression has not been reached
    while (i < infixExpression.length())
    {

//Get (read) the next token from the infix expression
        char c = infixExpression[i];

//if the token is a ’(’
//  Push the token onto the stack 
        if(c == '('){
            infixToPostfixStack.push(c);
            i++;
        }

//else if the token is a number
        else if(isdigit(c)){

//Add the number to the end of the postfix expression
            postFixExpression.push_back(c);
            i++;
        }

//else if the token is a ’)’
        else if(c == ')'){

//Pop the element c from the stack
            char popped = infixToPostfixStack.pop();

//while c is not a ’(’
            while(popped != '(' ){

//Place c at the end of the postfix expression
//Pop another element c from the stack
                postFixExpression.push_back(popped);
                popped = infixToPostfixStack.pop();
            }
            i++;
        }

//else (the token must be an operator)
        else{

//while the top of the stack is an operator with precedence greater than or equal to the token
            while (!infixToPostfixStack.isEmpty() && getPrecedence(infixToPostfixStack.peek()) >= getPrecedence(c)){

//Pop the element c from the stack
//Place c at the end of the postfix expression
                char p = infixToPostfixStack.pop();
                postFixExpression.push_back(p);
            }

//Push the token onto the stack
            infixToPostfixStack.push(c);
            i++;
        }
    }
//Add whitespace to postfix
    string postFixExpressionWithWhiteSpace = addWhitespaceBetweenChars(postFixExpression);
    return postFixExpressionWithWhiteSpace;
}

//This function adds whitespace between the characters of a string 
string addWhitespaceBetweenChars(string str) {
    string result;
    for (size_t i = 0; i < str.size(); ++i) {
        result += str[i];
        if (i < str.size() - 1) {
            result += ' ';
        }
    }
    return result;
}