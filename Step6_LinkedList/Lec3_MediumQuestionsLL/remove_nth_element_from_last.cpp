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

Node* DeleteNthNodefromEnd(Node* head, int N) {

    // Optimal Approach:
    Node* fast = head;
    Node* slow = head;

    for(int i=0; i<N; i++) {
        fast = fast->next;
    }

    if(fast == NULL) {
        return head->next;
    }

    if(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    Node* delNode = slow->next;
    slow->next = slow->next->next;
    delete delNode;
    return head;

    // The below is the Brute Force Approach:

    // if(head == NULL) return NULL;
    // int count = 0;
    // Node* temp = head;

    // while(temp != NULL) {
    //     count++;
    //     temp = temp->next;
    // }

    // if(count == N) {
    //     Node* newHead = head->next;
    //     delete(head);
    //     return newHead;
    // }

    // int res = count - N;
    // temp = head;

    // while(temp != NULL) {
    //     res--;
    //     if(res == 0) break;
    //     temp = temp->next;
    // }

    // Node* delNode = temp->next;
    // temp->next = temp->next->next;
    // delete(delNode);
    // return head;
}

int main () {
    vector<int> arr = {1, 2, 3, 4, 5};
    int N = 3;
    Node* head = new Node(arr[0]);
    head->next = new Node(arr[1]);
    head->next->next = new Node(arr[2]);
    head->next->next->next = new Node(arr[3]);
    head->next->next->next->next = new Node(arr[4]);

    // Delete the Nth node from the end
    // and print the modified linked list
    head = DeleteNthNodefromEnd(head, N);
    printLL(head);
}