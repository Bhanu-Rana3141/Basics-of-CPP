/*
OPTIMISED - 2 POINTER(TORTOISE-HARE)
TC - O(N/2) - O(N)
SC - O(1)
*/

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
    else {
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

Node* middle(Node* head) {
    Node* slow = head;
    Node* fast = head->next;

    while(fast != NULL) {
        fast = fast->next;
        if(fast != NULL) {
            fast = fast->next;
        }
        slow = slow->next;
    }
    return slow;
}

int main() {
    
    Node* head = NULL;
    Node* tail = NULL;

    insertAtHead(head, tail, 1);
    insertAtTail(tail, 2);
    insertAtTail(tail, 3);
    insertAtTail(tail, 4);
    insertAtTail(tail, 5);
    insertAtTail(tail, 6); 

    cout << "Input Linked List: ";
    print(head);

    cout << "Linked list from middle node: ";
    Node* ans = middle(head);
    print(ans);

    return 0;
}