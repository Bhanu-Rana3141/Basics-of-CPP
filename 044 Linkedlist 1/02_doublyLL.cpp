#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* prev;
    Node* next;

    // constructor
    Node(int d) {
        this->data = d;
        this->prev = NULL;
        this->next = NULL;
    }
};

void print(Node* &head){
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

int getLength(Node* &head) {
    Node* temp = head;
    int count = 0;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    return count;
}

void insertionAtHead(Node* &head, int d) {
    Node* temp = new Node(d);
    temp->next = head;
    head->prev = temp;
    head = temp;
}

void insertionAtTail(Node* & tail, int d) {
    Node* temp = new Node(d);
    tail->next = temp;
    temp->prev = tail;
    tail = temp;
}

void insertAtPosition(Node* &head, Node* &tail, int d, int pos){
    if(pos == 1) {
        insertionAtHead(head,d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertionAtTail(tail, d);
        return;
    }
    // creating new node
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
} 

int main() {

    Node* node1 = new Node(10);

    Node* head = node1;
    Node* tail = node1;
    print(head);

    cout << "length: " << getLength(head) << endl;

    insertionAtHead(head,12);
    print(head);

    insertionAtHead(head,15);
    print(head);

    insertionAtHead(head,22);
    print(head);

    insertionAtTail(tail, 25);
    print(head);

    insertAtPosition(head, tail, 100, 2);
    print(head);

    insertAtPosition(head, tail, 200, 1);
    print(head);


    return 0;
}