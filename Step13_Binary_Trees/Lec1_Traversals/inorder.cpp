#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

};

void inorder(Node* root, vector<int> &ans) {
    if(root == nullptr) return;
    inorder(root->left, ans);
    ans.push_back(root->data);
    inorder(root->right, ans);
}

vector<int> inOrder(Node* root) {
    vector<int> ans;
    inorder(root, ans);
    return ans;
}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> inorder = inOrder(root);

    for(int val : inorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}