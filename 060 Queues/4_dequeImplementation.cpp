#include<iostream>
using namespace std;

class Dequeue {

    public:
        int *arr;
        int size;
        int front;
        int rear;

    Dequeue(int size) {
        this -> size = size;
        arr = new int[size];
        front = -1;
        rear = -1;
    }

    void pushFront(int value) {

        if(front == -1) {
            front = rear = 0;
        }
        else if(front == 0 && rear == size - 1) {
            cout << "Queue is full" << endl;
        }
        else if(front == 0 && rear != size - 1) {
            front = size - 1;
        }
        else if(front == rear + 1) {
            cout << "Queue is full" << endl;
        }
        else {
            front--;
        }
        arr[front] = value;
    } 

    void pushBack(int value) {

        if(front == -1) {
            front = rear = 0;
        }
        else if(front == 0 && rear == size-1) {
            cout << "Queue is full" << endl;
        }
        else if(rear == size-1 && front != 0) {
            rear = 0;
        }
        else if(rear == front - 1) {
            cout << "Queue is full" << endl;
        }
        else {
            rear++;
        }
        arr[rear] = value;
    }

    void popFront() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = rear = -1;
        }
        else if(front == size-1){
            front = 0;
        }
        else {
            arr[front] = -1;
            front++;
        }
    }

    void popBack() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        }
        else if(front == rear) {
            arr[front] = -1;
            front = rear = -1;
        }
        else if(rear == 0) {
            rear = size-1;
        }
        else {
            arr[rear] = -1;
            rear--;
        }
    }

    void getFront() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        } 
        else {
            cout << arr[front] << endl;
        }
    }

    void getRear() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        } 
        else {
            cout << arr[rear] << endl;
        }
    }

    void isEmpty() {

        if(front == -1) {
            cout << "Queue is empty" << endl;
        }
        else {
            cout << "NOT empty" << endl;
        }
    }

    void isFull() {

        if((front == 0 && rear == size - 1) || (rear == front - 1)) {
            cout << "Queue is FULL" << endl;
        }
        else {
            cout << "NOT FULL" << endl;
        }
    }
};

int main() {

    Dequeue dq(5);

    dq.pushBack(1);
    dq.pushBack(2);
    dq.pushBack(3);
    dq.pushBack(4);
    dq.pushBack(5);

    dq.getFront();
    dq.getRear();
    
    dq.popFront();
    dq.popBack();

    dq.getFront();
    dq.getRear();

    dq.isEmpty();
    dq.isFull();
    
    return 0;
}