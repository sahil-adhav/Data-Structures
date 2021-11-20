#include "0-BinaryTreeNode.h"

int countNodes(BinaryTreeNode<int>* root){
    if(root == NULL){
        return 0;
    }

    int ans = 1;

    return ans + countNodes(root->left) + countNodes(root->right);
}

// 1 2 3 4 5 6 7 -1 -1 -1 -1 8 9 -1 -1 -1 -1 -1 -1 

int main()
{
    BinaryTreeNode<int>* root = takeInput();
    printLevelWise(root);
    cout << "Num of nodes : " << countNodes(root);
}
