#include <iostream>
#include <vector>

using namespace std;

// Node structure for the binary tree
struct Node {
    int data;
    Node* left;
    Node* right;
    // Constructor to initialize
    // the node with a value
    Node(int val) : data(val), left(nullptr), right(nullptr) {}
};

class Solution {
public:
    bool isLeaf(Node* root) {
        return !root->left && !root->right;
    }

    void addLeftBoundary(Node* root, vector<int>& result) {
        Node* current = root->left;
        while(current != nullptr) {
            if(!isLeaf(current)) {
                result.push_back(current->data);
            }

            if(current->left) current = current->left;
            else current = current->right;
        }
    }

    void addLeafNodes(Node* root, vector<int>& result) {
        if(isLeaf(root)) {
            result.push_back(root->data);
            return;
        }

        if(root->left) addLeafNodes(root->left, result);
        if(root->right) addLeafNodes(root->right, result);
    }

    void addRightBoundary(Node* root, vector<int>& result) {
        Node* current = root->right;
        vector<int> temp;
        while(current != nullptr) {
            if(!isLeaf(current)) temp.push_back(current->data);

            if(current->right) current = current->right;
            else current = current->left;
        }
        for(int i = temp.size()-1; i>=0; i--) {
            result.push_back(temp[i]);
        }
    }

    vector<int> printBoundary(Node* root) {
       vector<int> result;

       if(root == nullptr) return result;

       if(!isLeaf(root)) {
        result.push_back(root->data);
       }

       addLeftBoundary(root, result);
       addLeafNodes(root, result);
       addRightBoundary(root, result);

       return result;
    }
};

// Helper function to
// print the result
void printResult(const vector<int>& result) {
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);
    root->right->left = new Node(6);
    root->right->right = new Node(7);

    Solution solution;

    // Get the boundary traversal
    vector<int> result = solution.printBoundary(root);

    // Print the result
    cout << "Boundary Traversal: ";
    printResult(result);

    return 0;
}