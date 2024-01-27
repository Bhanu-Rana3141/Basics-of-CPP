/*
APPROACH 1 - MAP
* TC - O(N)
* SC - O(N)

APPROACH 2 - 
* Traverse List and delete duplicate
* TC - O(N)
* SC - O(1)
*/

#include<iostream>
using namespace std;

class Node {
    public:
        int data;
        Node* next;

    Node(int data) {
        this->data = data;
        this->next = NULL;
    }
};

void insertAtTail(Node* &head, Node* &tail, int data) {
    Node* newNode = new Node(data);
    if(head == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

void removeDuplicates(Node* &head) {
    Node* curr = head;
    while(curr->next != NULL) {
        if(curr->data == curr->next->data) {
            Node* next_next = curr->next->next;
            Node* nodeToDelete = curr->next;
            delete nodeToDelete;
            curr->next = next_next;
        }
        else {
            curr = curr->next;
        }
    }
}

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main() {

    int n;
    cout << "Enter no of nodes: ";
    cin >> n;

    Node* head = NULL;
    Node* tail = NULL;

    for(int i=0; i<n; i++) {
        int input;
        cin >> input;
        insertAtTail(head, tail, input);
    }

    cout << "Linkedlist: ";
    print(head);

    cout << "Linkedlist after removing duplicates: ";
    removeDuplicates(head);
    print(head);
    
    return 0;
}