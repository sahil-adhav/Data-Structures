#include "0-BinaryTreeNode.h"
#include <map>

BinaryTreeNode<int>* buildTreeHelper(int *postordre, int pS, int pE, int *inorder, int iS, int iE, map<int,int> &mp){
    if(pS > pE || iS > iE) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postordre[pE]);
    int rootIndex = mp[postordre[pE]];
    int numsLeft = rootIndex-iS;    root->left = buildTreeHelper(postordre, pS, pS+numsLeft-1, inorder, iS, rootIndex-1, mp);

    root->right = buildTreeHelper(postordre, pS+numsLeft, pE-1,inorder, rootIndex+1, iE, mp);
    return root;
}


BinaryTreeNode<int>* buildTree(int *postorder, int postLength, int *inorder, int inLength) {
    if(postLength != inLength) return NULL;

    map <int, int> mp;
    for (int i = 0; i < inLength; i++)
    {
        mp[inorder[i]] = i;
    }

    return buildTreeHelper(postorder, 0, postLength-1, inorder, 0, inLength-1, mp);
}

/*
7
4 5 2 6 7 3 1 
4 2 5 1 6 3 7 
*/
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input.txt", "r", stdin);
        freopen("output.txt", "w", stdout);
        freopen("error.txt", "w", stderr);
    #endif    


    int size;
    cin >> size;
    int *post = new int[size];
    int *in = new int[size];
    for (int i = 0; i < size; i++) cin >> post[i];
    for (int i = 0; i < size; i++) cin >> in[i];
    BinaryTreeNode<int> *root = buildTree(post, size, in, size);
    printLevelATNewLine(root);
}