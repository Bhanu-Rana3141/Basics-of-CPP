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

void inorder(Node* root, vector<int>& nodeData) {

    if(root == NULL) {
        return;
    }

    inorder(root -> left, nodeData);
    nodeData.push_back(root -> data);
    inorder(root -> right, nodeData);
}

bool isValidateBST(Node* root) {

    vector<int> nodeData;

    inorder(root, nodeData);

    for(int i=1; i<nodeData.size(); i++) {
        if(nodeData[i-1] > nodeData[i]) {
            return false;
        }
    }
    return true;
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Printing tree: " << endl;
    levelOrderTraversal(root);
    
    bool ans = isValidateBST(root);

    ans ? cout << "true" : cout << "false";

    return 0;
}