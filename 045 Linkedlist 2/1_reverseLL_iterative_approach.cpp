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
};

void insertAtHead(Node* &head, int d) {
    if(head == NULL) {
        Node* temp = new Node(d);
        head = temp;
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

Node* reverseLL(Node* &head) {
    if(head == NULL || head->next == NULL) {
        return head;
    } 
    Node* prev = NULL;
    Node* curr = head;
    Node* forward = curr->next;

    while(curr != NULL) {
        curr->next = prev;
        prev = curr;
        curr = forward;
        forward = curr->next;
    }
    head = prev;
    print(head);
}

int main() {

    Node* head = NULL; 

    insertAtHead(head, 9);
    insertAtHead(head, 7);
    insertAtHead(head, 5);
    insertAtHead(head, 3);
    print(head);
       
    reverseLL(head);


    return 0;
}       