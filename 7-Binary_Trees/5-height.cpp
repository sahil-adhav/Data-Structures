#include "0-BinaryTreeNode.h"
#include <algorithm>

int height(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return 0;
    }
    int leftHeight = height(root->left);     
    int rightHeight = height(root->right);     
    return (max(leftHeight, rightHeight) + 1);
}

//10 20 30 40 50 -1 -1 -1 -1 -1 -1

int main() {
    BinaryTreeNode<int>* root = takeInput();
    cout << height(root);
}