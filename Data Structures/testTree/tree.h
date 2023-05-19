#include <iostream>

using namespace std;

struct btn{
    int data;
    btn* left;
    btn* right;
};

class tree
{
private:
    btn* root;
    void insertNode(btn* &root, int data) {
        if (!root) { // if root is nullptr
            root = new btn;
            root->data = data;
            return;
        }
        if (data < root->data) {
            insertNode(root->left, data); // recurse on left subtree
        }
        else {
            insertNode(root->right, data); // recurse on right subtree
        }
    }

public:
    tree(){root = NULL;}
    btn* getRoot(){
        return root;
    }

    int leafCount(btn* n){
        if(n == NULL)
            return 0;
        else{
            if(n->left != NULL && n->right != NULL){
                return leafCount(n->left)+leafCount(n->right);
            }else if(isLeaf(n))
                return 1;
        }
    }
    
    bool isLeaf(btn* n){
        return((n->left == NULL) && (n->right == NULL));
    }
    void insertNodeP(int data){
        insertNode(root, data);
    }
};
