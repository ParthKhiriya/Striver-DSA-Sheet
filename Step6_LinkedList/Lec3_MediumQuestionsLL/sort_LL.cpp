#include<bits/stdc++.h>
using namespace std;

class Node {
public:
    int data;
    Node* next;

    Node (int data, Node* next) {
        this->data = data;
        this->next = next;
    }

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void printLL(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
}

Node* mergeSortedLL(Node* left, Node* right) {
    Node* dummyNode = new Node(-1);
    Node* temp = dummyNode;

    while(left != nullptr && right != nullptr) {
        if(left->data <= right->data) {
            temp->next = left;
            left = left->next;
        } else {
            temp->next = right;
            right = right->next;
        }
        temp = temp->next;
    }

    if(left != nullptr) {
        temp->next = left;
    } else {
        temp->next = right;
    }

    return dummyNode->next;
}

Node* findMiddle(Node* head) {

    if(head == nullptr || head->next == nullptr) return head;

    Node* slow = head;
    Node* fast = head->next;

    while(fast != nullptr && fast->next != nullptr) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow;
}

Node* sortLL(Node* head) {
    if(head == nullptr || head->next == nullptr) return head;

    Node* middle = findMiddle(head);

    Node* right = middle->next;
    middle->next = nullptr;
    Node* left = head;

    left = sortLL(left);
    right = sortLL(right);

    return mergeSortedLL(left, right);
}

int main () {
    // Linked List: 3 2 5 4 1
    Node* head = new Node(3);
    head->next = new Node(2);
    head->next->next = new Node(5);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(1);

    cout << "Original Linked List: ";
    printLL(head);

    // Sort the linked list
    head = sortLL(head);

    cout << "Sorted Linked List: ";
    printLL(head);

    return 0;
}