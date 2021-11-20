#include "0-BinaryTreeNode.h"
#include "input.h"
void inorder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
 
    //left->root->right
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}

void preOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    //root->left->right
    cout << root->data << " ";
    preOrder(root->left);
    preOrder(root->right);
}

void postOrder(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }
    //left->right->root
    postOrder(root->left);
    postOrder(root->right);
    cout << root->data << " ";
}

// 1 2 3 4 5 -1 -1 -1 -1 -1 -1 
int main(){
    init();
    BinaryTreeNode<int>* root = takeInput();
    cout << "Inorder : ";
    inorder(root);
    cout << "\nPreorder : ";
    preOrder(root);
    cout << "\nPostorder : ";
    postOrder(root);
    delete(root); 
}