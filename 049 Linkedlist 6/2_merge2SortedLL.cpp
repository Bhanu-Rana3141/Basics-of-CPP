/*
HERE BOTH THE APPROACHES HAVE SAME TC AND SC BUT DIFFERENT NO OF LOOPS

APPROACH 1 - 3 loops
APPROACH 2 - 1 loop
TC - O(N)
SC - O(1)
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

void insertAtTail(Node* &head, Node* &tail, int digit) {
    Node* newNode = new Node(digit);
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

// APPROACH 1 - MERGE
Node* mergeLists(Node* list1, Node* list2) {
    
    Node* ans = new Node(-1);
    Node* temp = ans;

    while(list1 != NULL && list2 != NULL) {
        if(list1->data <= list2->data) {
            temp->next = list1;
            temp = list1;
            list1 = list1->next;
        }
        else {
            temp->next = list2;
            temp = list2;
            list2 = list2->next;
        }
    }

    while(list1 != NULL) {
        temp->next = list1;
        temp = list1;
        list1 = list1->next;
    }

    while(list2 != NULL) {
        temp->next = list2;
        temp = list2;
        list2 = list2->next;
    }
    return ans->next;
}

// APPROACH 2 - MERGE
Node* merge(Node* head1, Node* head2) {
    
    // EGDE CASE - If list1 have only 1 node
    if(head1->next == NULL) {
        head1->next = head2;
        return head1;
    }

    Node* curr1 = head1;
    Node* next1 = curr1->next;
    Node* curr2 = head2;
    Node* next2 = curr2->next;

    while(next1 != NULL && curr2 != NULL) {
        if((curr2->data >= curr1->data) && (curr2->data <= next1->data)) {
            curr1->next = curr2;
            next2 = curr2->next;
            curr2->next = next1;
            curr1 = curr2;
            curr2 = next2;
        }
        else {
            curr1 = next1;
            next1 = next1->next;
            if(next1 == NULL) {
                curr1->next = head2;
                return head1;
            }
        }
    }
    return head1;
}

int main() {

    int n1;
    cout << "Enter size of list 1: ";
    cin >> n1;

    Node* head1 = NULL;
    Node* tail1 = NULL;

    for(int i=0; i<n1; i++) {
        int digit;
        cin >> digit;
        insertAtTail(head1, tail1, digit);
    }
    
    int n2;
    cout << "Enter size of list 2: ";
    cin >> n2;

    Node* head2 = NULL;
    Node* tail2 = NULL;

    for(int i=0; i<n2; i++) {
        int digit;
        cin >> digit;
        insertAtTail(head2, tail2, digit);
    }
    
    cout << "list 1: ";
    print(head1);

    cout << "list 2: ";
    print(head2);

    // EDGE CASES
    if(head1 == NULL) {
        print(head2);
        return 0;
    }
    if(head2 == NULL) {
        print(head1);
        return 0;
    }

    // if(head1->data <= head2->data) {
    //     head1 = merge(head1, head2);
    // }
    // else {
    //     head1 = merge(head2, head1);
    // }
    // cout << "Merged list: ";
    // print(head1);

    // Approach 2
    Node* ans = mergeLists(head1, head2);
    print(ans);

    return 0;
}