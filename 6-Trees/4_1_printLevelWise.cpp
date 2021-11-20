#include <iostream>
#include <vector>
#include <queue>
using namespace std;

template <typename T>
class Tree
{
public:
    T data;
    vector<Tree *> children;
    Tree(T data)
    {
        this->data = data;
    }
};

Tree<int> *takeInput()
{
    int rootData;
    cout << "Enter the root data : ";
    cin >> rootData;
    Tree<int> *root = new Tree<int>(rootData);
    queue<Tree<int> *> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        Tree<int> *front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "Enter number of children at " << front->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int childData;
            cout << "Enter child data at " << i << "th Node : ";
            cin >> childData;
            Tree<int> *child = new Tree<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }
    return root;
}

void printTree(Tree<int> *root)
{
    queue<Tree<int> *> pendingTreeNode;
    pendingTreeNode.push(root);
    while (!pendingTreeNode.empty())
    {
        Tree<int> *front = pendingTreeNode.front();
        pendingTreeNode.pop();
        cout << front->data << " : ";

        for (int i = 0; i < front->children.size(); i++)
        {
            if(i < (front->children.size() -1)){
                cout << front->children.at(i)->data << ", ";
            }else{
                cout << front->children.at(i)->data << ", ";
            }
            pendingTreeNode.push(front->children.at(i));
        }
        cout << endl;
    }
}

int main()
{
    Tree<int> *root = takeInput();
    printTree(root);
}