#include <iostream>
struct treeNode
{
    int data;
    treeNode* leftChild;
    treeNode* rightChild;

};
class Tree
{
    private:
        treeNode* root;
		treeNode* searchTree(int key, treeNode* n){
            if( n->data == key){ 
                std::cout<<"Found Node";
                return n;
            }else{
                if(key < n -> data)
                    searchTree(key, n->leftChild);
                if(key > n -> data)
                    searchTree(key, n->rightChild);
            }
                std::cout<<"NOt Found Node";
            return NULL;
        }
        
    public:
        Tree();
        treeNode* createNode(int newData){
            treeNode* newNode = new treeNode;
            newNode -> data = newData;
            newNode->leftChild = NULL; newNode->rightChild = NULL;
            return newNode;
        }
        void insertNode(int newData){
            treeNode* newNode = createNode(newData);
            if(root == NULL)
                root = newNode;
            else{
                treeNode* treePtr = root;
                treeNode* targetNodePtr;
                while(treePtr != NULL){
                    targetNodePtr = treePtr;
                    if(newData == treePtr -> data)
                        return;
                    else if(newData < treePtr->data)
                        treePtr = treePtr->leftChild;
                    else if(newData > treePtr->data)
                        treePtr = treePtr->rightChild;
                }
                if( newData < targetNodePtr->data )
                    targetNodePtr->leftChild = newNode;
                else // insert it as its right child
                    targetNodePtr->rightChild = newNode;
            }
        }
        void createTree(int* Values, int size){
            char index;
            int n = 0;
            while (n <= size){
                insertNode(Values[n]);
                index = Values[n + 1];
                n++;
                
            }
        }
        void printTree(treeNode* n){
            if (n == nullptr) { // base case
            return;
            }
            printTree(n->leftChild);
            std::cout << n -> data << std::endl;
            printTree(n->rightChild);
        }
        void orderChildren(treeNode* n){
            // v assumes not duplicate vals in tree;
            if(n->leftChild->data > n->rightChild->data){
                int helperInt = n -> rightChild->data;
                n -> rightChild->data = n -> leftChild->data;
                n -> leftChild->data = helperInt;
            }
        }
        
        treeNode* searchTreePub(int key){
            return searchTree(key, root);
        }
        void preformAction(int traversalActionKey){
            switch (traversalActionKey)
            {
            case 0:
                //Print
                printTree(root);
                break;
            case 1:
                orderChildren(root);
                break;
            case 2:
            default:
                break;
            }
        }

        
};
