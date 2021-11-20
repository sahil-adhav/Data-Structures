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

Tree<int>* takeInputLevelwise(){
    int rootData;
    cout << "Enter the Root Data : ";
    cin >> rootData;
    Tree<int>* root = new Tree<int>(rootData);

    queue<Tree<int>*> pendingNodes;

    pendingNodes.push(root);
    while(!pendingNodes.empty()){
        Tree<int>* frontNode = pendingNodes.front();
        pendingNodes.pop();
        cout << "Enter number of Chidren at " << frontNode->data << " : ";
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++)
        {
            int childData;
            cout << "Enter the data of children at " << i << "th Node of " << frontNode->data << " : ";
            cin >> childData;
            Tree<int>* child = new Tree<int>(childData);
            frontNode -> children.push_back(child);
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
    for(int i = 0; i < root->children.size(); i++){
        cout << root->children.at(i)->data << ", ";
    }
    cout << endl;
    for (int i = 0; i < root->children.size(); i++){
        print(root->children.at(i));
    }
    
}

int main()
{
    Tree<int>* root = takeInputLevelwise();
    print(root);
}