#include "linkedList.h"
#include <iostream>

linkedList::linkedList()
{
    head = NULL;
}
void linkedList::print(){
    Node * p = head;
    while(p != NULL){
        std::cout << p->data <<"\n";
        p = p ->next;
    }
}

void linkedList::addToFront(int x)
{
    Node * n = new Node; 
    n -> data = x;
    n -> next = NULL;
    if( head==NULL) 
        head = n;
    else
    {
    n -> next = head; 
    head = n;
    }
}
void linkedList::addToBack(int x){
    Node * n = new Node;
    n -> data = x;
    Node * p = head;
    if(head == NULL) 
        head = n;
    else
    {
        while (p ->next != NULL)
        {
            p = p -> next;
        }
        p -> next = n;
        n -> next = NULL;
    }
}

void linkedList::deleteFirst(){
if(head != NULL){
    Node * n = head;
    head = head -> next;
    n ->next = NULL;
    delete n;
}
}
void linkedList::deleteLast(){
    Node * n = head;
    Node * Dn = head;
    while (Dn -> next != NULL){
        Dn = Dn -> next;
    }
    while ((n->next)->next != NULL){
        n = n->next;
    }
    delete Dn;
    n -> next = NULL;
}

