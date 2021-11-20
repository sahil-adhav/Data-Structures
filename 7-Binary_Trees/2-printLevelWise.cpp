#include "0-BinaryTreeNode.h"

void printLevelWise(BinaryTreeNode<int> *root)
{
    if (root == NULL)
    {
        return;
    }
    queue<BinaryTreeNode<int> *> pendingNodes;
    pendingNodes.push(root);

    while (!pendingNodes.empty())
    {
        BinaryTreeNode<int> *frontNode = pendingNodes.front();
        pendingNodes.pop();
        if (frontNode == NULL)
        {
            cout << endl;
            if (!pendingNodes.empty())
            {
                pendingNodes.push(NULL);
            }
        }
        else
        {
            cout << frontNode->data << ":";
            cout << "L:";

            if (frontNode->left)
            {
                pendingNodes.push(frontNode->left);
                cout << frontNode->left->data << ",";
            }
            else
            {
                cout << -1 << ",";
            }
            cout << "R:";

            if (frontNode->right)
            {
                pendingNodes.push(frontNode->right);
                cout << frontNode->right->data << endl;
            }
            else
            {
                cout << -1 << endl;
            }
        }
    }
}

int main()
{
    BinaryTreeNode<int> *root = takeInput();
    printLevelWise(root);
}