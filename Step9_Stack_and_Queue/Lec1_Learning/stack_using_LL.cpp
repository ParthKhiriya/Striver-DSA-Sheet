#include<bits/stdc++.h>
using namespace std;

class stackNode {
    public:
    int data;
    stackNode* next;

    stackNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

class Stack {
    public:
    stackNode* top;
    int size;

    Stack () {
        top = NULL;
        size = 0;
    }

    void stackPush(int x) {
        stackNode* element = new stackNode(x);
        element->next = top;
        top = element;
        size++;
    }

    int stackPop() {
        if(top == NULL) return -1;
        int topData = top->data;
        stackNode* temp = top;
        top = top->next;
        delete temp;
        size--;
        return topData;
    }

    int stackSize() {
        return size;
    }

    bool stackIsEmpty() {
        if(top == NULL) return true;
        return false;
    }

    int stackPeek() {
        if(top == NULL) return -1;
        return top->data;
    }

    void printStack() {
        stackNode* current = top;
        while(current != NULL) {
            cout << current->data << endl;
            current = current->next; 
        }
    }
};

int main () {
    Stack s;
    s.stackPush(10);
    cout << "Element popped: " << s.stackPop() << "\n";
    cout << "Stack size: " << s.stackSize() << "\n";
    cout <<"Stack empty or not? "<<s.stackIsEmpty()<<"\n";
    cout << "stack's top element: " << s.stackPeek() << "\n";
    return 0;
}