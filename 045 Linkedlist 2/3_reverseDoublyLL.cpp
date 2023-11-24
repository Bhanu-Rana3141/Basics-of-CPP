#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* back;

    Node(int d) {
        this->data = d;
        this->next = NULL;
        this->back = NULL;
    }
};

void insertAtHead(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* node1 = new Node(data);
        head = node1;
        tail = node1;
    }
    else{
        Node* node1 = new Node(data);
        node1->next = head;
        head = node1;
    }
    return;
}

void insertAtTail(Node* &tail, int data) {
    if(tail == NULL) {
        Node* node1 = new Node(data);
        tail = node1;
    }
    else{
        Node* node1 = new Node(data);
        tail->next = node1;
        tail = node1;
    }
    return;
}

void print(Node* &head) {
    Node* curr = head;
    while(curr != NULL) {
        cout << curr->data << " ";
        curr = curr->next;
    }
    cout << endl;
    return;
}

void reverseLL(Node* &head) {
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = prev;
        curr->back = curr->next;
        prev = curr;
        curr = forward;
    }
    head = prev;
    return;
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 3);
    insertAtTail(tail, 5);
    insertAtTail(tail, 7);
    insertAtTail(tail, 9);

    cout << "Input Linked List: ";
    print(head);

    cout << "Reversed Linked List: ";
    reverseLL(head);
    print(head);

    return 0;
}