#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    int data;
    Node* next;
    Node* back;

    Node(int data, Node* next, Node* back) {
        this->data = data;
        this->next = next;
        this->back = back;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->back = NULL;
    }
};

Node* convertArr2DLL(vector<int> &arr) {
    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i=1; i<arr.size(); i++) {
        Node* temp = new Node(arr[i], NULL, prev);
        prev->next = temp;
        prev = temp;
    }

    return head;
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* reverseList(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;
    Node* current = head;
    Node* prev = nullptr;

    while(current != nullptr) {
        prev = current->back;
        current->back = current->next;
        current->next = prev;
        current = current->back;
    }

    return prev->back;
}

int main () {
    vector<int> arr = {12, 5, 8, 7, 4};
    Node* head = convertArr2DLL(arr);

    cout << "Doubly Linked List Initially: " << endl;
    print(head);

    cout << endl << "Doubly Linked List After Reversing: " << endl;
     // Insert a node with value 10 at the end
    head = reverseList(head);

    print(head);

    return 0;
}