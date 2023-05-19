#include <iostream>

struct Node
{
    int data;
    Node* next;
};

class linkedList
{
private:
    Node * head;
public:
    linkedList();
    void addToFront( int x );
    void addToBack(int x);
    void deleteFirst();
    void deleteLast();
    void print();
};

