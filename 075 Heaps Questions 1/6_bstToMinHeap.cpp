/*
1. inorder traversal and store val in array
2. preorder traversal and update tree with arr values
*/

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Node {
    public:
        int data;
        Node* left;
        Node* right;

    Node(int d) {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    } 
};

void insertInBst(Node* &root, int d) {

    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root->data) {
        insertInBst(root->left , d);
    }
    else {
        insertInBst(root->right, d);
    }
}

void buildTree(Node* &root) {

    int d;
    cin >> d;

    while(d != -1) {
        insertInBst(root, d);
        cin >> d;
    }
}

void levelOrder(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        if(front == NULL) {
            cout << endl;
            if(!q.empty()) {
                q.push(NULL);
            }
        }
        else {
            cout << front->data << " ";
            if(front->left) {
                q.push(front->left);
            }
            if(front->right) {
                q.push(front->right);
            }
        }
    }
}

void inorder(Node* &root, vector<int>& arr) {

    if(root == NULL) {
        return;
    }

    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

void preorder(Node* &root, vector<int>& arr, int &i) {

    if(root == NULL) {
        return;
    }

    root->data = arr[i];
    i++;
    preorder(root->left, arr, i);
    preorder(root->right, arr, i);
}


int main()
{
    Node* root = NULL;
    buildTree(root);
    levelOrder(root);
    cout << endl;

    vector<int> arr;
    inorder(root, arr);
    int i = 0;
    preorder(root, arr, i);

    levelOrder(root);

    return 0;
}