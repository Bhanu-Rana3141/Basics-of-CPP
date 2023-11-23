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

    // destructor
    ~Node(){
        cout << "memory free for: " << this->data << endl;
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

void insertionAtHead( Node* &tail, Node* &head, int d) {
    // empty list
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head->prev = temp;
        head = temp;
    }
}

void insertionAtTail(Node* & tail,Node* &head, int d) {
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        temp->prev = tail;
        tail = temp;
    }
}

void insertAtPosition(Node* &head, Node* &tail, int d, int pos){
    if(pos == 1) {
        insertionAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1) {
        temp = temp->next;
        count++;
    }

    if(temp->next == NULL) {
        insertionAtTail(tail, head, d);
        return;
    }
    // creating new nodef
    Node* nodeToInsert = new Node(d);

    nodeToInsert->next = temp->next;
    temp->next->prev = nodeToInsert;
    temp->next = nodeToInsert;
    nodeToInsert->prev = temp;
} 

void printHeadTail(Node* &head, Node* &tail) {
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;
}

void deleteNode(Node* &head, Node* &tail, int pos) {
    if(pos == 1) {
        Node* temp = head;
        head = head->next;
        head->prev = NULL;
        temp->next = NULL;
        delete temp;
    }
    else{
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < pos){
            prev = curr;
            curr = curr->next;
            count++;
        }
        prev->next = curr->next;
        curr->prev = NULL;
        if(curr->next == NULL) tail = prev;
        curr->next = NULL;
        delete curr;
    }
}

int main() {

    Node* head = NULL;
    Node* tail = NULL;

    // cout << "length: " << getLength(head) << endl;

    insertionAtHead(tail, head, 12);
    print(head);
    printHeadTail(head, tail);

    insertionAtHead(tail, head, 15);
    print(head);
    printHeadTail(head, tail);

    insertionAtHead(tail, head, 22);
    print(head);
    printHeadTail(head, tail);

    insertionAtTail(tail, head, 25);
    print(head);
    printHeadTail(head, tail);

    insertAtPosition(head, tail, 200, 1);
    print(head);
    printHeadTail(head, tail);

    insertAtPosition(head, tail, 100, 6);
    print(head);
    printHeadTail(head, tail);

    insertAtPosition(head, tail, 300, 7);
    print(head);
    printHeadTail(head, tail);

    cout << "DELETION: " << endl;
    deleteNode(head, tail, 1);
    print(head);
    printHeadTail(head, tail);

    deleteNode(head, tail, 3);
    print(head);
    printHeadTail(head, tail);

    deleteNode(head, tail, 5);
    print(head);
    printHeadTail(head, tail);

    return 0;
}