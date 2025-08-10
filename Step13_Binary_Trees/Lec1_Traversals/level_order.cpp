#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node() : data(0), left(nullptr), right(nullptr) {}
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
    Node(int val, Node* left, Node* right) : data(val), left(left), right(right) {}

};

vector<vector<int>> levelOrder(Node* root) {
    vector<vector<int>> ans;
    if(root == nullptr) return ans;
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        int size = q.size();
        vector<int> level;

        for(int i=0; i<size; i++) {
            Node* node = q.front();
            q.pop();
            level.push_back(node->data);

            if(node->left != nullptr) q.push(node->left);
            if(node->right != nullptr) q.push(node->right);
        }
        ans.push_back(level);
    }

    return ans;
}

void printTree(const vector<int> &level) {
    for(int num : level) {
        cout << num << " ";
    }
    cout << endl;
}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<vector<int>> result = levelOrder(root);

    for(const vector<int> &level : result) {
        printTree(level);
    }

    return 0;
}