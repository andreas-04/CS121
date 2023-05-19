/* linkedList.cpp
 *
 * CS 121.Bolden.......Compiler Version: 12.0.5...........Andreas Neacsu
 * 3/1/2023, ............M1 Macintosh.......neac9115@vandals.uidaho.edu
 *
 * definition for Linked List class
 *---------------------------------------------------------------------
 */
#include <iostream>
#include "linkedList.h"

linkedList::linkedList()
{
//Init head to NULL and count to 0
    head = NULL;
    count = 0;
}

linkedList::~linkedList()
{
//dealloc memory and free pointers
    node * p = head;
    node * n;
    while(p != NULL)
    {
        n = p;
        p = p->next;
        delete n;
    }
}

//Add x to front of list
void linkedList::addToFront(char x)
{
    node * n = new node; 
    n -> info = x;
    n -> next = NULL;
    if( head==NULL) 
        head = n;
    else
    {
    n -> next = head; 
    head = n;
    }
}

//delete first x from list
void linkedList::deleteNode(char x)
{
    node * prev;
    node * curr = head;

    while( curr != NULL && x > curr->info )
    {
        prev = curr;
        curr = curr->next;
    }
    if( x == curr->info )
    {
        if( curr == head )
            head = head->next;
        else
            prev->next = curr->next;
        delete curr;
        count--;
    }
}

//return info from first node
char linkedList::firstNode()
{
    return head -> info;
}

//delete first node
void linkedList::deleteFirst()
{
    if(head != NULL)
    {
    node * n = head;
    head = head -> next;
    n ->next = NULL;
    delete n;
    }
}

//print list
void linkedList::print()
{
    node * p = head;
    while(p != NULL){
        std::cout << p->info <<"\n";
        p = p ->next;
    }
}

//return size
int linkedList::size()
{
return count;
}
