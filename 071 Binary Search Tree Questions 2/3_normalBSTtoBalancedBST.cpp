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

void balancedBST(Node* &root, int s, int e, vector<int>& arr) {

    if(s > e) {
        return;
    }

    int mid = (s+e)/2;

    root = new Node(arr[mid]);

    balancedBST(root -> left, s, mid-1, arr);
    balancedBST(root -> right, mid+1, e, arr);
}

int main() {

    Node* root = NULL;
    
    takeInput(root);
    levelOrderTraversal(root);
    cout << endl;

    vector<int> arr;
    inorder(root, arr);

    Node*newRoot = NULL;
    balancedBST(newRoot, 0, arr.size()-1, arr);

    levelOrderTraversal(newRoot);

    return 0;
}