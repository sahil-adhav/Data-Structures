#include<iostream>
#include<vector>
#include<queue>
using namespace std;

template <typename T>
class Tree{
public:
    T data;
    vector<Tree*> children;
    Tree(T data){
        this -> data = data;
    }    
};

Tree<int>* takeInput(){
    int rootData;
    cout << "Enter the RootData : ";
    cin >> rootData;
    Tree<int>* root = new Tree<int>(rootData);
    queue<Tree<int>*> pendingNodes;
    pendingNodes.push(root);
    while (!pendingNodes.empty())
    {
        Tree<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int n;
        cout << "Enter number of children at "<< front->data << " : ";
        cin >> n;
        for (int i = 0; i < n; i++)
        {
          int childData;
          cout << "Enter the child data at " << i << "th Node : ";
          cin >> childData;
          Tree<int>* child = new Tree<int>(childData);
          front->children.push_back(child);
          pendingNodes.push(child);  
        }
    }
    return root;
}

void print(Tree<int>* root){
    if(root == NULL){
        return;
    }
    cout << root->data << " : ";
    for (int i = 0; i < root->children.size(); i++)
    {
        cout << root->children.at(i)->data << ", ";
    }
    cout <<  endl;
    for (int i = 0; i < root->children.size(); i++)
    {
        print(root->children.at(i));
    }
}

int main()
{
    Tree<int>* root = takeInput();
    print(root);    
}