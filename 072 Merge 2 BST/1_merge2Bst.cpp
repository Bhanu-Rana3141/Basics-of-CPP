/*
APPROACH 1
1. inorder traversal of both bst and store values in array in a sorted manner
2. merge 2 sorted arrays
3. inorder to BST - THIS IS ANSWER

TC - O(M+N)
SC - O(M+N)


APPROACH 2
1. Convert bst into sorted LL 
TC - O(M) , SC - O(h1)
TC - O(N) , SC - O(h2)

by using LL , space complexity is improved, discarding use of vectors

2. merge 2 sorted LL
TC - O(M+N)
SC - O(1)

3. convert sorted LL in BST

ALGO - 
1. Convert right subtree in LL, it will give head
root -> right = head 
head -> left = root
head = root
2. convert left subtree in LL, it will give head



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

int main() {

    Node* root = NULL;
    
    takeInput(root);
    levelOrderTraversal(root);

   

    return 0;
}