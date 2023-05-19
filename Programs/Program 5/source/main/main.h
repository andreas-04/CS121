/*
This code defines several functions that create an interface for the user to interact with the Tree database.
The interface includes options for displaying the entire database, displaying all actors for a particular series,
displaying all series for a particular actor, displaying all series within a specified range, and exiting the program.
Each option corresponds to a specific function call for the corresponding operation on the Tree object.
*/
#ifndef MAIN_H
#define MAIN_H

#include <iostream>
#include "../tree/tree.h"

// This function displays the entire database of TV series in the tree.
// It calls the public display_data_public() function of the Tree class to accomplish this.
void display_database(Tree tree)
{

// Call the public display_data_public() function of the Tree class to display the database.
    tree.display_data_public();
}

// This function prompts the user to enter the name of an actor and
// then calls the get_series_from_actor function of the provided tree object
// to find all the TV series that the actor has acted in.
void get_series_of_actor(Tree tree){

// Declare a variable to store the user's input actor name
    std::string user_actor;
    std::cout << "[INPUT] Enter Actor Name \n[INPUT] > ";

// Get the user's input for actor name and store it in user_actor
    std::getline(std::cin, user_actor);

// Clear the input buffer
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Call the get_series_from_actor function of the provided tree object
// to find all the TV series that the actor has acted in.
    tree.get_series_from_actor(user_actor);
}

// This function gets the actors who have acted in a particular TV series.
void get_actors(Tree tree){

// Ask the user to input the TV series name.
    std::string user_series;
    std::cout << "[INPUT] Enter Series Name \n[INPUT] > ";
    std::getline(std::cin, user_series);

// Clear any remaining input in the buffer.
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Call the Tree class's get_actor_from_series function to get the actors.
    tree.get_actor_from_series(user_series);
}

// This function prompts the user to input a range of years and then
// calls the get_series_within_range function of the Tree class to retrieve
// all the TV series that aired within that range.
void get_series_of_range(Tree tree){
    int user_range_start, user_range_end;

// Prompt the user to input the start of the range
    std::cout << "[INPUT] Enter Range Start\n[INPUT] > ";
    std::cin >> user_range_start;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

// Prompt the user to input the end of the range
    std::cout << "[INPUT] Enter Range End\n[INPUT] > ";
    std::cin >> user_range_end;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear input buffer

// Call the get_series_within_range function of the Tree class to retrieve all the
// TV series that aired within the range specified by the user.
    tree.get_series_within_range(user_range_end, user_range_start);
}

// This function acts as an interface for the user to interact with the database stored in the tree.
void database_interface(Tree tree){
    int selectoriovario = 0;

// Continue running the interface until the user chooses to exit.
    while(selectoriovario!=4){

// Display the options for the user to select.
        std::cout << "[OUTPUT][MAIN::database_interface]\n\t[0] Display Database\n\t[1] Display all actors of a series\n\t[2] Display all series of a actor\n\t[3] Display all series within a range\n\t[4] Exit\n[INPUT] > ";

// Get user input for the selected option.
        std::cin >> selectoriovario;

// Clear input buffer to prevent any issues.
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

// Perform the action corresponding to the selected option.
        switch (selectoriovario)
        {
        case 0:
// Display the entire database.
            display_database(tree);
            break;
        case 1:
// Display all actors of a particular TV series.
            get_actors(tree);
            break;
        case 2: 
// Display all TV series that a particular actor has acted in.
            get_series_of_actor(tree);
            break;
        case 3:
// Display all TV series that fall within a given range.
            get_series_of_range(tree);
            break;
        default:
// Exit the interface.
            break;
        }
    }
}
#endif