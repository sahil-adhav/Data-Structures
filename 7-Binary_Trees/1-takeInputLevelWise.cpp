#include "0-BinaryTreeNode.h"

BinaryTreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter root data: ";
    cin >> rootData;
    if(rootData == -1){
        return NULL;
    }
    BinaryTreeNode<int>* root = new BinaryTreeNode<int>(rootData);
    queue<BinaryTreeNode<int>*> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter left child of " << front->data << ": ";
        int leftChildData;
        cin >> leftChildData;
        if(leftChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(leftChildData);
            front->left = child;
            pendingNodes.push(child);
        } 

        cout << "Enter right child of " << front->data << ": ";
        int rightChildData;
        cin >> rightChildData;
        if(rightChildData != -1){
            BinaryTreeNode<int>* child = new BinaryTreeNode<int>(rightChildData);
            front->right = child;
            pendingNodes.push(child);
        } 
    }
    return root;
}

void print(BinaryTreeNode<int>* root){
    if(root == NULL){
        return;
    }

    cout << root->data << " : " ;
    if(root->left){
        cout << "L" << root->left->data;
    } 
    if(root->right){
        cout << "R" << root->right->data;
    }
    cout << endl;
    print(root->left);
    print(root->right);
}

int main(){
    BinaryTreeNode<int>* root = takeInput();
    print(root);
    delete root;
}