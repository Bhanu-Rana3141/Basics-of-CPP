/*
APPROACH - MERGE SORT
* Find middle of list
* Divide in 2 parts left and right
* Sort both parts recursively
* Merge both parts
* TC - O(N LOG N)
* SC - O(LOG N)

Q. Why quick sort is preferred in arrays and merge sort in linkedlists ?
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

Node* findMid(Node* head) {
    Node* slow = head;
    Node* fast = head->next;
    
    while(fast != NULL && fast->next != NULL) {
        fast = fast->next->next;
        slow = slow->next;
    }
    return slow;
}

Node* merge(Node* left, Node* right) {

    Node* ans = new Node(-1);
    Node* temp = ans;

    while(left != NULL && right != NULL) {
        if(left->data <= right->data) {
            temp->next = left;
            temp = left;
            left = left->next;
        }
        else {
            temp->next = right;
            temp = right;
            right = right->next;
        }
    }

    while(left != NULL) {
        temp->next = left;
        temp = left;
        left = left->next;
    }

    while(right != NULL) {
        temp->next = right;
        temp = right;
        right = right->next; 
    }
    return ans->next;
}

// SORT
Node* mergeSort(Node* head) {
    if(head == NULL || head->next == NULL) {
        return head;
    }

    Node* mid = findMid(head);

    Node* left = head;
    Node* right = mid->next;
    mid->next = NULL;

    left = mergeSort(left);
    right = mergeSort(right);

    Node* ans = merge(left, right);
    return ans;
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

    Node* ans = mergeSort(head);
    print(ans);
    
    return 0;
}