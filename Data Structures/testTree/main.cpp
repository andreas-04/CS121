#include "tree.h"

int main(){
    tree myTree;
    myTree.insertNodeP(5);
    myTree.insertNodeP(3);
    myTree.insertNodeP(7);

    int x = myTree.leafCount(myTree.getRoot());
    std::cout << x << "\n";
}