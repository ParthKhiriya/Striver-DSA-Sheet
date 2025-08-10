#include<bits/stdc++.h>
using namespace std;

class Node {
    public: 
    int data;
    Node* left;
    Node* right;

    Node(int val) : data(val), left(nullptr), right(nullptr) {}

};

void preorder(Node* root, vector<int> &arr) {
    if(root == nullptr) return;
    arr.push_back(root->data);
    preorder(root->left, arr);
    preorder(root->right, arr);
}

vector<int> preOrder(Node* root) {
    vector<int> arr;
    preorder(root, arr);
    return arr;

}

int main () {
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    vector<int> preorder = preOrder(root);

    for(int val: preorder) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}