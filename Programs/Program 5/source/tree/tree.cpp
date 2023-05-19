/*
This code defines the implementation of the Tree class declared in the "tree.h" header file. 
It includes various functions that can be used to perform different operations on 
the tree data structure, including inserting nodes, searching for nodes, and displaying node data.

The implementation uses a binary search tree structure, where nodes are inserted based on 
the value of a specific field (in this case, the "series_name" field of the "movie_data" struct). 
The insert_node_private() function is used to recursively insert nodes into the tree based 
on the value of this field. The display_data_private() function is used to recursively 
display the data of each node in the tree.

The Tree class also includes other functions to search the tree for nodes based on 
different criteria, such as search_series_name_private(), which searches for a node based 
on the series name, and get_actor_from_series(), which displays the actors for a given series.

The code also includes various debugging statements that can be enabled or disabled 
by commenting out the #define DEBUG statement at the beginning of the file. Overall, 
this code provides a useful implementation of a binary search tree data structure for 
storing and searching movie data.
*/
// The ifndef directive checks if the TREE_CPP header has already been included in the file
// If not, it includes the header and defines TREE_CPP to avoid multiple inclusion
#ifndef TREE_CPP 
#define TREE_CPP

// DEBUG is a preprocessor macro used to enable/disable debug statements
// Here, it is commented out to disable debug statements
//#define DEBUG

// Include the header file for the Tree class
#include "tree.h"

// Include the necessary standard libraries
#include <iostream> 
#include <string>

// Private member function that recursively inserts a node in the tree
void Tree::insert_node_private(tree_node*& target, tree_node* insertable_node)
{

// DEBUG statement that prints a message when the function is entered
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::insert_node_private] Entering" << std::endl;
    #endif


// If the target node is null, set it to the insertable node
    if(target == NULL ){
        target = insertable_node;
        return;
    }

// If the series name of the insertable node is the same as the target node, do nothing
    if (insertable_node->node_data.series_name == target->node_data.series_name) 
        return;

// If the series name of the insertable node is less than the target node's series name, insert it in the left subtree
    else if( insertable_node->node_data.series_name < target->node_data.series_name )
        insert_node_private(target->left_child, insertable_node);

// Otherwise, insert it in the right subtree
    else
        insert_node_private(target->right_child, insertable_node);


// DEBUG statement that prints a message when the function is exited
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::insert_node_private] Exiting" << std::endl;
    #endif
}

// Private member function that recursively displays the data in the tree
void Tree::display_data_private(tree_node* entry)
{

// If the entry is not null, recursively display the left subtree, the node, and the right subtree
    if(entry != NULL)
    {
        display_data_private(entry->left_child);
        display(entry);
        display_data_private(entry->right_child);
    }
}

// Private member function that recursively searches for a node with a given series name
tree_node* Tree::search_series_name_private(std::string key, tree_node* n)
{

// If the node is not null, check if its series name matches the given key
    if(n != NULL){
        if(n->node_data.series_name == key)
        {

// DEBUG statement that prints a message when the function finds the entry
            #ifdef DEBUG
            std::cout << "[DEBUG][TREE::search_series_name_priv] Found Entry " << std::endl;
            #endif
            return n;
        }

// If the key is less than the node's series name, search the left subtree
        else if(key < n -> node_data.series_name)
            return search_series_name_private(key, n->left_child);

// Otherwise, search the right subtree
        else
            return search_series_name_private(key, n->right_child);

    }

// DEBUG statement that prints an error message when the entry is not found
    #ifdef DEBUG
    std::cout << "[ERROR][TREE::search_series_name_priv] Entry was not found in database..." << std::endl;
    #endif

    return NULL;
}

// This function searches for all the TV series present in the tree
// that a particular actor has acted in and adds them to the shows_of_actor vector.
void Tree::get_series_vector_from_actor(std::vector<std::string> &shows_of_actor, tree_node* entry, std::string actor)
{
    // If the current node is not NULL
    if(entry != NULL)
    {
        
// If the current node contains the actor we are looking for
        if(search_actor_list_of_node(entry, actor))

// Add the TV series to the shows_of_actor vector
            shows_of_actor.push_back(entry->node_data.series_name);

// Recursively search the left subtree for TV series that the actor has acted in
        get_series_vector_from_actor(shows_of_actor, entry->left_child, actor);

// Recursively search the right subtree for TV series that the actor has acted in
        get_series_vector_from_actor(shows_of_actor, entry->right_child, actor);
    }
}

// This function searches for all the TV series present in the tree that were aired
// between a particular range of years and adds them to the series_of_range vector.
void Tree::get_series_vector_from_range(std::vector<std::string> &series_of_range, tree_node* entry, int high, int low)
{
    
// If the current node is not NULL
    if(entry != NULL)
    {

// If the current node's airing year falls within the given range
        if(
        (entry->node_data.year_start <= high && entry->node_data.year_end >= low)||
        (entry->node_data.year_end >= low && entry->node_data.year_end <= high)  ||
        (entry->node_data.year_start <= low && entry->node_data.year_end >= high)||
        (entry->node_data.year_start <= low && entry->node_data.year_end >= high)
        )

// Add the TV series to the series_of_range vector
            series_of_range.push_back(entry->node_data.series_name);

// Recursively search the left subtree for TV series that aired in the given year range
        get_series_vector_from_range(series_of_range, entry->left_child, high, low);

// Recursively search the right subtree for TV series that aired in the given year range
        get_series_vector_from_range(series_of_range, entry->right_child, high, low);
    }
}
// Constructor for the Tree class. It initializes the root_node to NULL and
// creates a vector of movie_data objects. Then, it creates a tree based on the
// data in the vector.
Tree::Tree()
{
    root_node = NULL;
    std::vector<movie_data> data_vector = create_movie_data_vector();
    create_tree(data_vector);
}

// Destructor for the Tree class. It deallocates the memory used by the root node.
Tree::~Tree()
{
    //delete root_node;
}

// This function creates a new tree_node object with the given movie_data object.
// It returns a pointer to the newly created node.
tree_node* Tree::create_node(movie_data dat)
{
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::create_node] Entering" << std::endl;
    #endif

    tree_node* new_node  = new tree_node;
    new_node->left_child = NULL;
    new_node->right_child = NULL;
    new_node->node_data = dat;

    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::create_node] Exiting" << std::endl;
    #endif

    return new_node;
}

// This function inserts a node into the tree. It is called by the public insert_node
// function and recursively searches the tree to find the correct position for the new node.
void Tree::insert_node_public(tree_node* insertable_node)
{
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::insert_node_public] Entering" << std::endl;
    #endif

// If the root_node is not NULL, recursively search the tree for the correct position for the new node.
    if(root_node != NULL){
        insert_node_private(root_node, insertable_node);
    }else
        root_node = insertable_node;
    
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::insert_node_public] Exiting" << std::endl;
    #endif
}

// This function creates a tree using the given vector of movie_data objects.
// It creates a new tree_node for each movie_data object and inserts it into the tree.
void Tree::create_tree(std::vector<movie_data> data_vector)
{
    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::create_tree] Entering" << std::endl;
    #endif

    for(int i=0; i < data_vector.size(); i++)
    {
        #ifdef DEBUG
        std::cout << "[DEBUG][TREE::create_tree] Creating node "<< data_vector[i].series_name << std::endl;
        #endif

// Create a new node for the current movie_data object
        tree_node* new_node = create_node(data_vector[i]);

// Insert the new node into the tree
        insert_node_public(new_node);
    }

    #ifdef DEBUG
    std::cout << "[DEBUG][TREE::create_tree] Exiting" << std::endl;
    #endif
}

// This function searches for a particular TV series name in the tree and
// returns the node that contains that TV series.
tree_node* Tree::search_series_name_public(std::string series_name)
{

// Call the private search_series_name function with the root node of the tree.
// This is the public interface for the search_series_name function.
    return search_series_name_private(series_name, root_node);
}

// This function searches for a TV series in the tree and displays all the actors who have acted in it.
void Tree::get_actor_from_series(std::string series_title)
{

// Search for the node containing the TV series
    tree_node* target_node = search_series_name_public(series_title);

// If the node is found
    if(target_node != NULL)

// Display the list of actors who have acted in the TV series
        display_actors(target_node);
    else

// Display an error message if the TV series is not found in the database
        std::cout << "[OUTPUT]" << series_title << " not found in database." << std::endl;
}

// This function prints out all the TV series present in the tree
// that a particular actor has acted in.
void Tree::get_series_from_actor(std::string actor)
{

// Create a vector to store the TV series of the actor
    std::vector<std::string> series_of_actor;

// Get the TV series of the actor by calling the helper function
    get_series_vector_from_actor(series_of_actor, root_node, actor);
    
// Print the actor's name
    std::cout << "[OUTPUT] Actor: " << actor << "\n";

// Print the TV series the actor has acted in
    std::cout << "[OUTPUT] Seen in: ";
    for(int k = 0; k < series_of_actor.size(); k++)
    {
        std::cout << series_of_actor[k];

// If there are more TV series, print a comma to separate them
        if(k != series_of_actor.size()-1)
            std::cout << ", ";
    }

// Print a newline character at the end
    std::cout << "\n";
}

// This function searches for all the TV series present in the tree
// that fall within a given range of years and prints them to the console.
void Tree::get_series_within_range(int high, int low){

// Create a vector to hold the TV series that fall within the given range
    std::vector<std::string> series_of_range;

// Call the get_series_vector_from_range function to populate the series_of_range vector
    get_series_vector_from_range(series_of_range, root_node, high, low);

// Print the TV series to the console
    std::cout << "[OUTPUT] Series from " << high << "-" << low << ":\n\t";
    for(int q = 0; q < series_of_range.size(); q++)
    {
        std::cout << series_of_range[q];
        if(q != series_of_range.size()-1)
            std::cout << ", ";
    }
    std::cout << "\n";
}

// This function searches for a particular actor in the actor vector of a given node.
// It returns true if the actor is present in the vector, and false otherwise.
bool Tree::search_actor_list_of_node(tree_node* target, std::string actor)
{

// Loop through the actor vector of the node
    for(int j = 0; j < target->node_data.actor_vector.size(); j++)
    {

// If the current actor matches the one we are searching for, return true
        if(target->node_data.actor_vector[j] == actor)
            return true;
    }

// If the actor is not found, return false
    return false;
}

// This function displays the names of actors associated with a particular TV series
// stored in the node pointed to by displayable_node.
void Tree::display_actors(tree_node* displayable_node){

// Iterate through the vector of actors and display each actor's name
    for(int i = 0; i < displayable_node->node_data.actor_vector.size(); i++){
        std::cout << displayable_node->node_data.actor_vector[i];
        if(i != displayable_node->node_data.actor_vector.size()-1)
            std::cout << ", ";
    }

// Move to the next line for better readability
    std::cout << "\n";
}

// This function displays the data present in the tree to the user.
// It calls a private function, display_data_private(), with the root_node as the argument.
void Tree::display_data_public(){
    
// Call the private function, display_data_private(), with the root_node as the argument.
    display_data_private(root_node);
}

// This function displays the TV series name of the current node.
// It can also display additional information about the series (currently commented out).
void Tree::display(tree_node* displayable_node){

// Display the name of the TV series.
    std::cout <<"[OUTPUT][TREE::DISPLAY] Series Name: " << displayable_node->node_data.series_name << "\n";

// The following lines can be uncommented to display additional information about the TV series.

// Display the genre of the TV series.
    // std::cout <<"[OUTPUT][TREE::DISPLAY] Series Genre: " << displayable_node->node_data.series_category << "\n";

// Display the years during which the TV series aired.
    // std::cout <<"[OUTPUT][TREE::DISPLAY] Series Air: " << displayable_node->node_data.year_start << "-" << displayable_node->node_data.year_end << "\n";

// Display the IMDB webpage URL for the TV series.
    // std::cout <<"[OUTPUT][TREE::DISPLAY] Series IMDB WebPage: " <<displayable_node->node_data.series_URL << "\n";

// Display the list of actors who have appeared in the TV series.
    // std::cout <<"[OUTPUT][TREE::DISPLAY] Series Actor List: "; display_actors(displayable_node);
}
#endif