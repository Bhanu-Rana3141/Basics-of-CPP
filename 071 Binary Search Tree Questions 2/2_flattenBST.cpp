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

void inorder(Node* root, vector<int>& arr) {

    if(root == NULL) {
        return;
    }

    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
}

Node* flattenBST(Node* &root, vector<int> arr) {

    Node* newRoot = new Node(arr[0]);
    Node* temp = newRoot;

    for(int i=1; i<arr.size(); i++) {
        temp -> right = new Node(arr[i]);
        temp = temp -> right;
    }
    return newRoot;
}

void print(Node* root) {

    Node* temp = root;

    while(temp != NULL) {
        cout << temp -> data << " ";
        temp = temp -> right;
    }
}

int main() {

    Node* root = NULL;
    
    takeInput(root);
    levelOrderTraversal(root);

    vector<int> arr;
    inorder(root, arr);

    Node* newRoot = flattenBST(root, arr);

    cout << endl;
    print(newRoot);

    return 0;
}