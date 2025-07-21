#include<bits/stdc++.h>
using namespace std;

class QueueNode {
    public:
    int data;
    QueueNode* next;

    QueueNode(int data) {
        this->data = data;
        this->next = NULL;
    }
};

QueueNode* front = NULL;
QueueNode* rear = NULL;

class Queue {
    public:
    int size = 0;

    void Enqueue(int x) {
        QueueNode* temp = new QueueNode(x);
        if(temp == NULL) {
            cout << "The Queue is Full" << endl;
        } else {
            if(front == NULL) {
                front = temp;
                rear = temp;
            } else {
                rear->next = temp;
                rear = temp;
            }

            cout << "Value inserted into the Queue: " << x << endl;
            size++;
        }
    }

    void Dequeue() {
        if(front == NULL) {
            cout << "Queue is Empty" << endl;
        } else {
            cout << "Removed from Queue: " << front->data << endl;
            QueueNode* temp = front;
            front = front->next;
            delete temp;
            size--;
        }
    }

    bool Empty () {
        return front == NULL;
    }

    int Peek () {
        if(Empty()) {
            cout << "Queue is Empty" << endl;
            return -1;
        } else {
            return front->data;
        }
    }
};

int main () {
    Queue Q;
    Q.Enqueue(10);
    Q.Enqueue(20);
    Q.Enqueue(30);
    Q.Enqueue(40);
    Q.Enqueue(50);
    Q.Dequeue();
    cout<<"The size of the Queue is "<<Q.size<<endl;
    cout<<"The Peek element of the Queue is "<<Q.Peek()<<endl;
    return 0;
}