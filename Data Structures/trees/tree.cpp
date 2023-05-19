#include <iostream>

#include "tree.h"
Tree::Tree()
{
    root = NULL;
}
// treeNode* Tree::createNode(int n)
// {
//     treeNode* newChild = new treeNode;
//     newChild->data = n;
//     newChild->leftChild = NULL;
//     newChild->rightChild = NULL;

//     return newChild;
// }
// bool Tree::isLeaf(treeNode* myNode)
// {
//     return((myNode->leftChild == NULL) && (myNode->rightChild==NULL));
// }
// int Tree::getSize(treeNode* root)
// {
//     if(root == NULL)
//         return 0;
//     else
//     {
//         return 1 + getSize(root->leftChild)+getSize(root->rightChild);
//     }
// }
// void Tree::preOrderPrint(treeNode* root)
// {
//     std::cout << root->data << std::endl;
//     preOrderPrint(root->leftChild);
//     preOrderPrint(root->rightChild);
// }
// void Tree::inOrderPrint(treeNode* root)
// {
//     inOrderPrint(root->leftChild);
//     std::cout << root->data << std::endl;
//     inOrderPrint(root->rightChild);
// }
// void Tree::postOrderPrint(treeNode* root)
// {
//     postOrderPrint(root->leftChild);
//     postOrderPrint(root->rightChild);
// }