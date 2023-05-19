/* linkedList.h
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * prototype for Linked List Class
 *---------------------------------------------------------------------
 */

#include <iostream>

class linkedList
{
    private:
//node struct, next and info
    struct node {
        char info;
        node * next;
    };

    node* head;
    int count;

    public:
//constructor/destructor
    linkedList();
    ~linkedList();

//Function prototypes
    void addToFront(char x);
    void deleteNode(char x);
    char firstNode();
    void deleteFirst();
    void print();
    int size();
};

