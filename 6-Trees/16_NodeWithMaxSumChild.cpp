#include <iostream>
#include <queue>
#include <vector>
#include <climits>
using namespace std;

template <typename T>
class TreeNode {
   public:
    T data;
    vector<TreeNode<T>*> children;

    TreeNode(T data) { this->data = data; }

    ~TreeNode() {
        for (int i = 0; i < children.size(); i++) {
            delete children[i];
        }
    }
};

TreeNode<int>* takeInputLevelWise() {
    int rootData;
    cin >> rootData;
    TreeNode<int>* root = new TreeNode<int>(rootData);

    queue<TreeNode<int>*> pendingNodes;

    pendingNodes.push(root);
    while (pendingNodes.size() != 0) {
        TreeNode<int>* front = pendingNodes.front();
        pendingNodes.pop();
        int numChild;
        cin >> numChild;
        for (int i = 0; i < numChild; i++) {
            int childData;
            cin >> childData;
            TreeNode<int>* child = new TreeNode<int>(childData);
            front->children.push_back(child);
            pendingNodes.push(child);
        }
    }

    return root;
}

template <typename T>
class maxNodePair{
public:
    TreeNode<int>* node;
    int sum;
};

maxNodePair<int>* maxSumNodeHelper(TreeNode<int>* root){
    if(root == NULL){
        maxNodePair<int>* pair = new maxNodePair<int>();
        pair->node = NULL;
        pair->sum = INT_MIN;
        return pair;
    }

    int sum = root->data;

    for (int i = 0; i < root->children.size(); i++)
    {
      sum += root->children[i]->data;
    }
    
    maxNodePair<int> *ans = new maxNodePair<int>();
    ans->node = root;
    ans->sum = sum;

    for (int i = 0; i < root->children.size(); i++)
    {
        maxNodePair<int>* childAns = maxSumNodeHelper(root->children[i]);
        if(childAns->sum > ans->sum){
            ans = childAns;
        }
    }
    return ans;
}

TreeNode<int>* maximumSumOfNodes(TreeNode<int>* root) {
    return maxSumNodeHelper(root)->node;
}

int main() {
    TreeNode<int>* root = takeInputLevelWise();

    TreeNode<int>* ans = maximumSumOfNodes(root);

    if (ans != NULL) {
        cout << ans->data;
    }
}