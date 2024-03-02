#include<iostream>
#include<queue>
using namespace std;

class Queue {

    public:
        int *arr;
        int size;
        int front;
        int rear;

    Queue() {
        size = 5;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void push(int value) {

        if(front == -1) {
            front = 0;
            rear = 0;
        }
        else if(rear == size-1) {
            cout << "queue is full" << endl;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else if(rear == front-1) {
            cout << "queue is full" << endl;
        }
        else {
            rear++;
        }
        arr[rear] = value;
    }

    void pop() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front == size -1) {
            front = 0;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }
};

int main() {

    Queue q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    q.push(5);

    return 0;
}