// QUEUE - is a data structure , follows the principle of FIFO(first in first out)

#include<iostream>
using namespace std;

class Queue {

    public:
        int *arr;
        int size;
        int front;
        int rear;

    Queue() {
        size = 10000;
        arr = new int[size];
        front = 0;
        rear = 0;
    }

    void isEmpty() {
        if(front == rear) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "Queue is NOT empty" << endl;
        }
    }

    void frontElement() {
        if(front == rear) {
            cout << "Queue is empty" << endl; 
        }
        else {
            cout << "front element: " << arr[front] << endl;
        }
    }

    void enqueue(int element) {
        if(rear == size) {
            cout << "Queue is FULL" << endl;
        }
        else {
            arr[rear] = element;
            rear++;
        }
    }

    void dequeue() {
        if(rear == size) {
            cout << "Queue is empty" << endl;
        }
        else {
            arr[front] = -1;
            front++;
            // If after removing elements from queue, front and rear points to same memory location, it means now queue is empty but still the removed part occupies memory which results in WASTAGE OF MEMORY, to save that memory the new front and rear are declared as the starting point of queue and the removed part is no more considered as the part of queue
            if(front == rear) { 
                front = 0;
                rear = 0;
            }
        }
    }
};

int main() {

    Queue q;

    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);
    q.enqueue(1);

    return 0;
}
