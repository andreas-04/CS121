#include <iostream>




class Stack{
    private:
        struct coordinate{
            int x;
            int y;
        };
        struct node
        {
            coordinate posit;
            node * next;
        };

        node * topOfStack;
    public:
        Stack(){topOfStack = NULL;}
        void push(int,int);
        coordinate pop();
        coordinate peek();
        bool isEmpty();
        void print();
};