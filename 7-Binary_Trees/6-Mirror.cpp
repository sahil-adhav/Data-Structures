#include "0-BinaryTreeNode.h"


void printLevelATNewLine(BinaryTreeNode<int> *root) {
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    q.push(NULL);
    while (!q.empty()) {
        BinaryTreeNode<int> *first = q.front();
        q.pop();
        if (first == NULL) {
            if (q.empty()) {
                break;
            }
            cout << endl;
            q.push(NULL);
            continue;
        }
        cout << first->data << " ";
        if (first->left != NULL) {
            q.push(first->left);
        }
        if (first->right != NULL) {
            q.push(first->right);
        }
    }
}

void mirrorBinaryTree(BinaryTreeNode<int>* root) {
    if(root == NULL){
        return;
    }
    mirrorBinaryTree(root->right);
    mirrorBinaryTree(root->left);

    BinaryTreeNode<int>* temp = root->left;
    root->left = root->right;
    root->right = temp; 
}

int main() {
    BinaryTreeNode<int> *root = takeInput();
    mirrorBinaryTree(root);
    printLevelATNewLine(root);
}