#include<iostream>
#include<queue>
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

void insertInBST(Node* &root, int d) {

    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root -> data) {
        insertInBST(root -> left, d);
    }
    else {
        insertInBST(root -> right, d);
    }
}

void takeInput(Node* &root) {

    int d;
    cin >> d;

    while(d != -1) {
        insertInBST(root, d);
        cin >> d;
    }
}

void levelOrderTraversal(Node* &root) {

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


//  Recursive Approach
Node* searchNode_1(Node* root, int &value) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data == value) {
        return root;
    }

    if(root -> data > value) {
        return searchNode_1(root -> left, value);
    }
    else {
        return searchNode_1(root -> right, value);
    }
}

// Iterative Approach
Node* searchNode_2(Node* root, int &value) {

    Node* temp = root;
    
    while(temp != NULL) {

        if(temp -> data == value) {
            return temp;
        }
        else if(temp -> data > value) {
            temp = temp -> left;
        }
        else {
            temp = temp -> right;
        }
    }
    return NULL;
}


int main() {

    Node* root = NULL;

    cout << "Enter data for BST: ";
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root); 

    cout << endl;

    int value;
    cout << "Enter val: ";
    cin >> value;

    cout << endl;

    // Node* ans = searchNode_1(root, value);
    Node* ans = searchNode_2(root, value);

    if(ans == NULL) {
        cout << "NULL";
    }
    else {
        levelOrderTraversal(ans); 
    }
    
    return 0;
}