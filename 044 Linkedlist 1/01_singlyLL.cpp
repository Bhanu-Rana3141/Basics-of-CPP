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

void insertAtHead(Node* &head, int d) {

    Node* temp = new Node(d);
    temp->next = head;
    head = temp;
}

void print(Node* &head) { // here copy is not created, actual head is passed i.e pass by reference
    
    Node* temp = head;
    while(temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}

void insertAtTail(Node* &tail, int d) {  // here copy is not created, actual head is passed i.e pass by reference

    Node* temp = new Node(d);
    tail->next = temp;
    tail = temp;
}

void insertAtPosition(Node*tail, Node* &head, int pos, int d){ // here copy is not created, actual head is passed i.e pass by reference

    // insert at start
    if(pos == 1) {
        insertAtHead(head,d);
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
        insertAtTail(tail,d);
        return;
    }

    Node* nodeToInsert = new Node(d);
    nodeToInsert->next = temp->next;
    temp->next = nodeToInsert;
}

// deleting node
void deleteNode(Node* &head, int pos) {

    if(pos == 1) {
        Node*temp = head;
        head = head->next;
        // start node free from memory
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
        curr->next = NULL;
        delete curr;
    }
}

int main() {

    Node* node1 = new Node(10);

    // pointing head and tail at node 1
    Node* head = node1;
    Node* tail = node1;
    print(head);

    // insertAtHead(head, 12);
    insertAtTail(tail, 12);
    print(head);

    // insertAtHead(head, 15);
    insertAtTail(tail,15);
    print(head);

    insertAtPosition(tail, head, 4, 22);
    print(head);

    cout << "head : " << head->data << endl; 
    cout << "tail : " << tail->data << endl; 
    cout << endl << endl;

    cout << "deletion: ";

    deleteNode(head,4);
    print(head);

    cout << "head : " << head->data << endl; 
    cout << "tail : " << tail->data << endl; 

    return 0;
}       