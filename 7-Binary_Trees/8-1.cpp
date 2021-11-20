#include "0-BinaryTreeNode.h"

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd){
    //check if, i can form a tree or not
    if(preStart > preEnd || inStart > inEnd) return NULL;

    int rootVal = preorder[preStart];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootVal);
 
    //checking for index in inorder
    int rootInorder = 0;
    for (int i = inStart; i <= inEnd; i++)
    {
        if(rootVal == inorder[i]){
            rootInorder = i;
            break;
        }
    }

    int numsLeft = rootInorder - inStart;
    root->left = buildTreeHelper(preorder, preStart+1, preStart+numsLeft, inorder, inStart, rootInorder-1);
    
    root->right = buildTreeHelper(preorder, preStart+numsLeft+1,preEnd, inorder, rootInorder+1, inEnd);
    return root;
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    int preStart = 0;
    int preEnd = preLength - 1;
    int inStart = 0;
    int inEnd = inLength - 1;
    return buildTreeHelper(preorder, preStart, preEnd, inorder, inStart, inEnd);
}

/*
7
1 2 4 5 3 6 7 
4 2 5 1 6 3 7 
*/

int main() {
    int size;
    cin >> size;
    int *pre = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> pre[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(pre, size, in, size);
    printLevelATNewLine(root);
}