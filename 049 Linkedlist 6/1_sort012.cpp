/*
APPROACH 1 
* Count 0 1 2 - TC : O(N)
* Place them in sorting order - TC : O(N)
* BUT HERE DATA IS REPLACED
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

void insertAtTail(Node* &head, Node* &tail, int element) {
    Node* newNode = new Node(element);
    if(tail == NULL) {
        head = newNode;
        tail = newNode;
    }
    else {
        tail->next = newNode;
        tail = newNode;
    }
}

Node* sort(Node* &head) {
    int zeroCount = 0;
    int oneCount = 0;
    int twoCount = 0;

    Node* temp = head;
    while(temp != NULL) {
        if(temp->data == 0) {
            zeroCount++;
        }
        else if(temp->data == 1) {
            oneCount++;
        }
        else {
            twoCount++;
        }
        temp = temp->next;
    }

    temp = head;
    while(temp != NULL) {
        if(zeroCount != 0) {
            temp->data = 0;
            zeroCount--;
        }
        else if(oneCount != 0) {
            temp->data = 1;
            oneCount--;
        }
        else {
            temp->data = 2;
        }
        temp = temp->next;
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

    Node* head = NULL;
    Node* tail = NULL;

    int n;
    cout << "Enter size of list: ";
    cin >> n;

    for(int i=0; i<n; i++) {
        int element;
        cin >> element;
        insertAtTail(head, tail, element);
    }

    Node* ans = sort(head);
    print(ans);

    return 0;
}