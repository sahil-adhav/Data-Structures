// #include<bits/stdc++.h>
#include "0-BinaryTreeNode.h"
#include <map>

BinaryTreeNode<int>* buildTreeHelper(int *postordre, int pS, int pE, int *inorder, int iS, int iE, map<int,int> &mp){
    if(pS > pE || iS > iE) return NULL;

    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(postordre[pE]);
    int rootIndex = mp[postordre[pE]];

    int numsLeft = rootIndex-iS;
    root->left = buildTreeHelper(postordre, pS, pS+numsLeft-1, inorder, iS, rootIndex-1, mp);

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

int main()
{	
	ios_base::sync_with_stdio(false);cin.tie(NULL);
	#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("error.txt", "w", stderr);
		freopen("output.txt", "w", stdout);
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
