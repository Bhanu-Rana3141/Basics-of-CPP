/*
APPROACH 1
1. inorder traversal of both bst and store values in array in a sorted manner
2. merge 2 sorted arrays
3. inorder to BST - THIS IS ANSWER

TC - O(M+N)
SC - O(M+N)



APPROACH 2
1**. Convert bst into sorted LL 
TC - O(M) , SC - O(h1)
TC - O(N) , SC - O(h2)

by using LL , space complexity is improved, discarding use of vectors

2**. merge 2 sorted LL
TC - O(M+N)
SC - O(1)

ALGO - 
1. Convert right subtree in LL, it will give head
root -> right = head 
head -> left = root
head = root
2. convert left subtree in LL, it will give head


3**. convert sorted LL in BST
1. total n nodes
2. *left = create left tree from starting n/2 nodes 
3. create root node
root -> left = left
4. head = head -> next
5. create right subtree


Q. This question is combination of 3 questions ?
1. Convert a BST into LL
2. Merger 2 sorted LL
3. Sorted LL  -> BST
 
*/

#include<iostream>
#include<queue>
#include<vector>
using namespace std;

class Node {

    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

void insertInBst(Node* &root, int d) {

    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root -> data) {
        insertInBst(root -> left, d);
    }
    else {
        insertInBst(root -> right, d);
    }
}

void takeInput(Node* &root) {

    int d;
    cout << "Enter root : ";
    cin >> d;

    while(d != -1) {
        insertInBst(root, d);
        cin >> d;
    }
}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() != 0) {

        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(q.size() != 0) {
                q.push(NULL);
            }
        }
        else {
            cout << front -> data << " ";

            if(front -> left) {
                q.push(front -> left);
            }

            if(front -> right) {
                q.push(front -> right);
            }
        }
    } 
}

// convert bst in sorted list
void convertIntoSortedDLL(Node* root, Node* &head) {

    if(root == NULL) {
        return;
    }

    // Q. why root -> right is called first ?
    convertIntoSortedDLL(root -> right, head);
    root -> right = head;
    if(head != NULL) {
        head -> left = root;
    }
    head = root;

    convertIntoSortedDLL(root -> left, head);
}

// merge ll
Node* merge(Node* head1, Node* head2) {

    Node* head = NULL;
    Node* tail = NULL;

    while(head1 != NULL && head2 != NULL) {

        if(head1 -> data < head2 -> data) 
        {
            if(head == NULL) 
            {
                head = head1;
                tail = head1;
                head1 = head1 -> right;
            }
            else 
            {
                tail -> right = head1;
                head1 -> left = tail;
                tail = head1;
                head1 = head1 -> right;
            }
        }
        else {
            if(head == NULL) 
            {
                head = head2;
                tail = head2;
                head2 = head2 -> right;
            }
            else 
            {
                // insert at end
                tail -> right = head2;
                head2 -> left = tail;
                tail = head2;
                head2 = head2 -> right;
            }
        }
    }

    while(head1 != NULL) {
        tail -> right = head1;
        head1 -> left = tail;
        tail = head1;
        head1 = head1 -> right;   
    }

    while(head2 != NULL) {
        tail -> right = head2;
        head2 -> left = tail;
        tail = head2;
        head2 = head2 -> right;   
    }

    return head;
}

// convert sorted LL in bst
int countNodes(Node* head) {

    Node* temp = head;
    int cnt = 0;

    while(temp != NULL) {
        cnt++;
        temp = temp -> right;
    }

    return cnt;
}

Node* sortedLLToBST(Node* head, int n) {

    if(n <= 0 || head == NULL) {
        return NULL;
    }

    Node* left = sortedLLToBST(head, n/2);

    Node* root = head;
    root -> left  = left;

    head = head -> right;

    root -> right = sortedLLToBST(head, n-n/2-1);

    return root;
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;
    
    takeInput(root1);
    takeInput(root2);

    levelOrderTraversal(root1);
    levelOrderTraversal(root2);

    // 1. convert bst into DLL inplace 
    Node* head1 = NULL;
    convertIntoSortedDLL(root1, head1);
    head1 -> left = NULL;

    Node* head2 = NULL;
    convertIntoSortedDLL(root2, head2);
    head2 -> left = NULL;

    //  2. merge sorted LL
    Node* head = merge(head1, head2);

    // 3. convert sorted LL into BST
    Node* root = sortedLLToBST(head, countNodes(head));

    levelOrderTraversal(root);

    return 0;
}