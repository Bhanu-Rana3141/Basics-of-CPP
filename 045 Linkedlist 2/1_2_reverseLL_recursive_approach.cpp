#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int d) {
        this->data = d;
        this->next = NULL;
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

void reverse(Node* &head, Node* &curr, Node* &prev) {
    // base case 
    if(curr == NULL) {
        head = prev;
        return;
    }

    reverse(head, curr->next, curr);
    curr->next = prev;
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
    Node* prev = NULL;
    Node* curr = head;

    reverse(head, curr, prev);
    print(head);

    return 0;
}