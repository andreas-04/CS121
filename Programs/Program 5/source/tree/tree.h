/*
This code defines a header file named "tree.h" that contains the class definition 
for a binary tree data class. The header file includes necessary dependencies 
and contains definitions for public and private functions used to initialize the tree 
database, search for and retrieve data from the tree, and display the data to the user.
The binary tree consists of tree nodes with movie data and pointers to their left and right child nodes.
*/
#ifndef TREE_H
#define TREE_H
#include <iostream>
#include "../file_reader/file_reader.h"

// Definition of the tree_node struct
struct tree_node{
        movie_data node_data;
        tree_node* left_child;
        tree_node* right_child;
};

class Tree
{
    private:
        tree_node* root_node;
// Definitions for the for the private functions used in initializing the tree database
        void insert_node_private(tree_node*&, tree_node*);

// Definitions for private functions used for display and program requirement 0
        void display_data_private(tree_node*);

// Definitions for the private functions used for program requirement one
        tree_node* search_series_name_private(std::string, tree_node*);

// Definitions for the private functions used for program requirement two
        void get_series_vector_from_actor(std::vector<std::string>&,  tree_node*, std::string);

// Definitions for the private functions used for program requirement three
        void get_series_vector_from_range(std::vector<std::string>&, tree_node*, int, int);

    public:
        ~Tree();

// Definitions for the for the public functions used in initializing the tree database
        Tree();
        void create_tree(std::vector<movie_data>);
        void insert_node_public(tree_node*);
        tree_node* create_node(movie_data);

// Definitions for the public functions used for program requirement one
        tree_node* search_series_name_public(std::string);
        void get_actor_from_series(std::string);

// Definitions for the public functions used for program requirement two
        bool search_actor_list_of_node(tree_node*, std::string);
        void get_series_from_actor(std::string);

// Definitions for the public functions used for program requirement three
        void get_series_within_range(int, int);

// Definitions for the public functions used for display and program requirement 0
        void display_data_public();
        void display(tree_node*);
        void display_actors(tree_node*);
};
#endif
