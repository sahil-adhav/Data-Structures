#include "0-BinaryTreeNode.h"


bool isNodePresent(BinaryTreeNode<int> *root, int x) {
    if(root == NULL){
        return false;
    }

    if(root->data == x){
        return true;
    }

    bool leftNode = isNodePresent(root->left, x);
    if(leftNode){
        return true;
    }

    bool rightNode = isNodePresent(root->right, x);
    if(rightNode){
        return true;
    }

    return false;    
}

int main(){
    BinaryTreeNode<int> *root = takeInput();
    int x;
    cin >> x;
    cout << ((isNodePresent(root, x)) ? "true" : "false");
}