/*
This code defines the main function for the program, which creates a Tree 
object named "database" and passes it to the database_interface function. 
The database_interface function allows the user to interact with the database 
and perform various operations such as searching for data and displaying 
the data in the tree
*/
#ifndef MAIN_CPP
#define MAIN_CPP
#include <iostream>

// The following line includes the header file for the main function in the program.
#include "main.h"

// The main function is the entry point for the program and initializes a Tree object
// named database. It then passes the database object to the database_interface function
// which allows the user to interact with the database.
int main(){
    Tree database;
    database_interface(database);
    return 0;
}
#endif