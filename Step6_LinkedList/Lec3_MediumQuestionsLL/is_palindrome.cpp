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

Node* reverseLL(Node* head) {

    if(head == nullptr || head->next == nullptr) return head;
    Node* newHead = reverseLL(head->next);

    Node* front = head->next;
    front->next = head;
    head->next = nullptr;

    return newHead;
}

bool isPalindrome(Node* head) {

    if(head == nullptr || head->next == nullptr) return true;

    Node* slow = head; 
    Node* fast = head;

    while(fast->next != nullptr && fast->next->next != nullptr) {
        fast = fast->next->next;
        slow = slow->next;
    }

    Node* newHead = reverseLL(slow->next);

    Node* first = head;
    Node* second = newHead;

    while(second != nullptr) {
        if(first->data != second->data) {
            reverseLL(newHead);
            return false;
        }
        first = first->next;
        second = second->next;
    }

    reverseLL(newHead);

    return true;
}

int main () {
    // Create a linked list with
    // values 1, 5, 2, 5, and 1 (15251, a palindrome)
    Node* head = new Node(1);
    head->next = new Node(5);
    head->next->next = new Node(2);
    head->next->next->next = new Node(5);
    head->next->next->next->next = new Node(1);

    // Print the original linked list
    cout << "Original Linked List: ";
    printLL(head);

    // Check if the linked list is a palindrome
    if (isPalindrome(head)) {
        cout << "The linked list is a palindrome." << endl;
    } else {
        cout << "The linked list is not a palindrome." << endl;
    }

    return 0;
}