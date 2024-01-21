#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    // constructor
    Node(int d){
        this->data = d;
        this->next = NULL;
        // cout << "constructor called for " << d << endl;
    }  

    // creating destructor
    ~Node() {
        cout << "memory free for: " << this->data << endl;
    }
};

void insertAtHead(Node* &tail, Node* &head, int d) {
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
        tail = temp;
    }
    else{
        Node* temp = new Node(d);
        temp->next = head;
        head = temp;
    }
}

void print(Node* &head) { // here copy is not created, actual head is passed i.e pass by reference
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &head ,Node* &tail, int d) {  
    if(tail == NULL) {
        Node* temp = new Node(d);
        tail = temp;
        head = temp;
    }
    else{
        Node* temp = new Node(d);
        tail->next = temp;
        tail = temp;
    }
}

void insertAtPosition(Node*tail, Node* &head, int pos, int d){ 
    // insert at start
    if(pos == 1) {
        insertAtHead(tail, head, d);
        return;
    }

    Node* temp = head;
    int count = 1;
    while(count < pos-1) {
        temp = temp->next;
        count++;
    }

    // inserting at last position
    if(temp->next == NULL){
        insertAtTail(head, tail, d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

void printHeadTail(Node* &head, Node* &tail) {
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;
}

// deleting node
void deleteNode(Node* &tail, Node* &head, int pos) {
    if(pos == 1) {
        Node*temp = head;
        head = head->next;
        // deleting first node from memory
        temp->next = NULL;
        delete temp;
    }
    else{
        // delete node from middle or last
        Node* curr = head;
        Node* prev = NULL;

        int count = 1;
        while(count < pos) {
            prev = curr;
            curr = curr->next;
            count++;
        }  
        prev->next = curr->next;
        if(curr->next == NULL) {
            tail = prev;
        }
        curr->next = NULL;
        delete curr;
    }
}

int main() {

    Node* head = NULL; 
    Node* tail = NULL;

    // insertAtHead(head, 12);
    insertAtTail(head, tail, 12);
    print(head);
    printHeadTail(head, tail);

    // insertAtHead(head, 15);
    insertAtTail(head, tail, 15);
    print(head);
    printHeadTail(head, tail);

    insertAtTail(head, tail, 22);
    print(head);
    printHeadTail(head, tail);

    insertAtPosition(tail, head, 1, 100);
    print(head);
    printHeadTail(head, tail);

    insertAtPosition(tail, head, 5, 500);
    print(head);
    printHeadTail(head, tail);

    deleteNode(tail, head, 4);
    print(head);
    printHeadTail(head, tail);

    deleteNode(tail, head, 1);
    print(head);
    printHeadTail(head, tail);

    return 0;
}       