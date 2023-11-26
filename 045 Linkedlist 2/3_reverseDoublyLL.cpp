#include<iostream>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data) {
        this->data = data;
        this->next = NULL;
        this->prev = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    if(head == NULL) {
        Node* newNode = new Node(data);
        head = newNode;
        tail = newNode;
    }
    else{
        Node* newNode = new Node(data);
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

void print(Node* &head) {
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
    return;
}

void printHeadTail(Node* &head, Node* &tail) {
    cout << "head: " << head->data << endl;
    cout << "tail: " << tail->data << endl;
    cout << endl;
}

void reverse(Node* &head) {
    Node* curr = head;
    Node* back = NULL;  
    Node* forward = NULL;

    while(curr != NULL) {
        forward = curr->next;
        curr->next = back;
        curr->prev = forward;
        back = curr;
        curr = forward;
    }
    head = back;
    return;
}

int main(){

    Node* head = NULL;
    Node* tail = NULL;

    insertAtTail(head, tail, 1);
    print(head);
    printHeadTail(head, tail);

    insertAtTail(head, tail, 2);
    print(head);
    printHeadTail(head, tail);

    insertAtTail(head, tail, 3);
    print(head);
    printHeadTail(head, tail);

    insertAtTail(head, tail, 4);
    print(head);
    printHeadTail(head, tail);

    cout << "Input linked list : ";
    print(head);

    cout << "Reversed Linked list: ";
    reverse(head);
    print(head);
   
    return 0;
}