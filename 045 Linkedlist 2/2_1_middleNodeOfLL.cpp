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

int getLength(Node* head) {
    int count = 0;
    while(head != NULL) {
        count++;
        head = head->next;
    }
    return count;
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

    insertAtHead(head, tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);

    cout << "Input Linked List: ";
    print(head);

    int length = getLength(head);
    cout << "Length of Linked list: " << length << endl;
    
    for(int i=0; i<length/2; i++) {
        head = head->next;
    }

    print(head);
    return 0;
}