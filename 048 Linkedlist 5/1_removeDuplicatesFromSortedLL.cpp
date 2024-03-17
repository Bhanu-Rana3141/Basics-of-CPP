/*
APPROACH 1 - Convert linkedlist in array and then: USE SET OR 2 POINTER APPROACH
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

Node* removeDuplicates(Node* &head) {

    if(head == NULL || head -> next == NULL) {
        return head;
    }

    Node* temp = head;

    while(temp -> next != NULL) {
        if(temp -> data == temp -> next -> data) {
            temp -> next = temp -> next -> next;
        }
        else {
            temp = temp -> next;
        }
    }   
    return head;
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
    head = removeDuplicates(head);
    print(head);
    
    return 0;
}