#include<iostream>
#include "TreeNode.h"
using namespace std;

TreeNode<int>* takeInput(){
    int rootData;
    cout << "Enter the data : ";
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    int n;
    cout << "Enter number of children of " << rootData << " : ";
    cin >> n;
    for(int i = 0; i < n; i++){
        TreeNode<int>* child = takeInput();
        root->children.push_back(child);
    }
    return root;
}

void print(TreeNode<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    for(int i = 0; i < root->children.size(); i++){
        cout << root->children.at(i)->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++)
    {
         print(root->children.at(i));
    }
}

int main()
{
    TreeNode<int>* root = takeInput();
    print(root);    
}