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

/*
APPROACH 1 - USING A EXTRA DATA STRUCTURE - VECTOR

APPROACH 2 - RECURSIVE 
- kth largest is : (n-k) + 1 smallest
*/

// APPROACH 1
void kthLargest(Node* root, vector<int>& nodeData) {

    if(root == NULL) {
        return;
    }

    kthLargest(root -> left, nodeData);
    nodeData.push_back(root -> data);
    kthLargest(root -> right, nodeData);
    
}

// APPROACH 2
void countNodes(Node* root, int &cnt) {

    if(root == NULL) {
        return;
    }

    countNodes(root -> left, cnt);
    cnt++;
    countNodes(root -> right, cnt);
}

void kthLargest_2(Node* root, int k, int n, int& i, int& ans) {

    if(root == NULL) {
        return;
    }

    kthLargest_2(root -> left, k, n, i, ans);

    i++;
    if(i == (n-k)+1) {
        ans = root -> data;
        return;
    }

    kthLargest_2(root -> right, k, n, i, ans);
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Printing BST: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    int k;
    cout << "Enter K: ";
    cin >> k;

    cout << endl;

    // vector<int> nodeData;
    // kthLargest(root, nodeData);
    // int idx = nodeData.size() - k;
    // cout << "ans: " << nodeData[idx];

    int cnt = 0;
    countNodes(root, cnt);
    int n = cnt;
    int ans = -1;
    int i = 0;
    
    kthLargest_2(root, k, n, i, ans);

    cout << "ans : " << ans;

    return 0;
}