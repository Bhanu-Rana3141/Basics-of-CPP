/*
APPROACH 1
* Using nested loops(2 loops), here 1 loop will fix on one node and another loop will traverse through whole list to check duplicates and delete them
* TC - O(N^2)
* SC - O(1)

APPROACH 2
* SORT list (Merge Sort) - O(N LOG N)
* Delete duplicates - O(N)
* TC - O(N*LOG N) 
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

void print(Node* head) {
    while(head != NULL) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

// APPROACH 1
void removeDuplicates(Node* head) {
    Node* curr = head;
    while(curr != NULL) {
        Node* temp = curr;
        while(temp->next != NULL) {
            if(curr->data == temp->next->data) {
                Node* next_next = temp->next->next;
                Node* nodeToDelete = temp->next;
                delete nodeToDelete;
                temp->next = next_next;
            }
            else {
                temp = temp->next;
            }
        }
        curr = curr->next;
    }
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

    removeDuplicates(head);
    cout << "Linkedlist After removing duplicates: ";
    print(head);
    
    return 0;
}