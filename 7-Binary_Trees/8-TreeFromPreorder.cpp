#include "0-BinaryTreeNode.h"

BinaryTreeNode<int>* buildTreeHelper(int *preorder, int preStart, int preEnd, int *inorder, int inStart, int inEnd){
    if(preStart > preEnd || inStart > inEnd){
        return NULL;
    }

    int rootVal = preorder[preStart];
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootVal);

    //root element index
    int k = 0;
    for(int i = inStart; i <= inEnd; i++){
        if(rootVal == inorder[i]){
            k = i;
            break;
        }
    }

    root->left = buildTreeHelper(preorder, preStart+1, preStart+(k-inStart),inorder, inStart, k-1);
    root->right = buildTreeHelper(preorder, preStart+(k-inStart)+1, preEnd, inorder, k+1, inEnd);
}

BinaryTreeNode<int>* buildTree(int *preorder, int preLength, int *inorder, int inLength) {
    int preStart = 0;
    int preEnd = preLength - 1;
    int intStart = 0;
    int inEnd = inLength - 1;

    return buildTreeHelper(preorder, preStart, preEnd, inorder, intStart, inEnd);
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