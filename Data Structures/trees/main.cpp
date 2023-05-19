#include <iostream>
#include "tree.h"

int main(){
    Tree myTree;
    int myVals[9] = {9,1,2,8,3,7,4,6,5};
    myTree.createTree(myVals, 7);
    myTree.preformAction(0);
    myTree.searchTreePub(1);
}