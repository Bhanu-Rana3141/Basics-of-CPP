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

void insertInBST(Node* &root, int d) {

    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root->data) {
        insertInBST(root->left, d);
    }
    else {
        insertInBST(root->right, d);
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

void levelOrderTraversal(Node* root) {

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
            if(front->left) q.push(front->left);
            if(front->right) q.push(front->right);
        }
    }
}

Node* lca(Node* root, Node* p, Node* q) {

    if(root == NULL) return NULL;

    if(p->data < root->data && q->data < root->data) {
        return lca(root->left, p, q);
    }
    if(p->data > root->data && q->data > root->data) {
        return lca(root->right, p, q);
    }

    return root;
}

int main() {

    Node* root = NULL;
    takeInput(root);
    levelOrderTraversal(root);

    Node* p = new Node(2);
    Node* q = new Node(8);
    Node* ans = lca(root, p, q);

    cout << "ans: " << ans->data;
    
    return 0;
}