#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

};

void postorder(Node* root, vector<int> &ans) {
    if(root == nullptr) return;
    postorder(root->left, ans);
    postorder(root->right, ans);
    ans.push_back(root->data);
}

vector<int> postOrder(Node* root) {
    vector<int> ans;
    postorder(root, ans);
    return ans;
}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> postorder = postOrder(root);

    for(int val : postorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}