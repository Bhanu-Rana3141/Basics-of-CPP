/*
* check if tree is complete binary tree
* check if it folloes max order property
*/

#include<iostream>
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

void buildTree(Node* &root) {

    int d;
    cout << "Enter root data: ";
    cin >> d;
    root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        int ld;
        cout << "Enter left data for " << front->data << " : ";
        cin >> ld;
        if(ld != -1) {
            front->left = new Node(ld);
            q.push(front->left);
        }

        int rd;
        cout << "Enter right data for " << front->data << " : ";
        cin >> rd;
        if(rd != -1) {
            front->right = new Node(rd);
            q.push(front->right);
        }
    }
}

void totalNodes(Node* root , int& cnt) {

    if(root == NULL) {
        return;
    }

    totalNodes(root->left, cnt);
    cnt++;
    totalNodes(root->right, cnt);
}

bool CBT(Node* root, int i, int cnt) {

    if(root == NULL) {
        return true;
    }
    if(i >= cnt) {
        return false;
    }

    bool left = CBT(root->left, 2*i + 1, cnt);
    bool right = CBT(root->right, 2*i + 2, cnt);
    return left && right;
}

bool isMaxHeap(Node* &root) {

    if(root == NULL) {
        return true;
    }
    if(root->left && root->left->data > root->data) {
        return false;
    }
    if(root->right && root->right->data > root->data) {
        return false;
    }

    bool left = isMaxHeap(root->left);
    bool right = isMaxHeap(root->right);
    return left && right;
}

int main()
{
    Node* root = NULL;
    buildTree(root);  

    int cnt = 0;
    totalNodes(root, cnt);

    if(CBT(root, 0, cnt) && isMaxHeap(root)) {
        cout << "Is binary heap";
    }
    else {
        cout << "Not binary heap";
    }

    return 0;
}