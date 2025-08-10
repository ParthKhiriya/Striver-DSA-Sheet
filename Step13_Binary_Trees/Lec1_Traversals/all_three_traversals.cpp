#include <iostream>
#include <vector>
#include <stack>

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

// Function to get the Preorder,
// Inorder and Postorder traversal
// Of Binary Tree in One traversal
vector<vector<int>> preInPostTraversal(Node* root) {
    vector<int> preorder;
    vector<int> inorder;
    vector<int> postorder;
    if(root == nullptr) return {};

    stack<pair<Node*, int>> st;
    st.push({root, 1});

    while(!st.empty()) {
        auto it = st.top();
        st.pop();

        if(it.second == 1) {
            preorder.push_back(it.first->data);
            it.second = 2;
            st.push(it);
            if(it.first->left != nullptr) st.push({it.first->left, 1});
        } else if(it.second == 2) {
            inorder.push_back(it.first->data);
            it.second = 3;
            st.push(it);
            if(it.first->right != nullptr) st.push({it.first->right, 1});
        } else {
            postorder.push_back(it.first->data);
        }
    }

    vector<vector<int>> result;
    result.push_back(preorder);
    result.push_back(inorder);
    result.push_back(postorder);

    return result;
}


// Function to print the
// elements of a vector
void printVector(const vector<int>& vec) {
    // Iterate through the vector
    // and print each element
    for (int num : vec) {
        cout << num << " ";
    }
    cout << endl;
}

// Main function
int main()
{
    // Creating a sample binary tree
    Node* root = new Node(1);
    root->left = new Node(2);
    root->right = new Node(3);
    root->left->left = new Node(4);
    root->left->right = new Node(5);

    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = preInPostTraversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
                            
         