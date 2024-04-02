/*
APPROACH 1 
- insert in bst
TC - O(N^2)

APPROACH 2
- create a inorder traversal (sort) -> O(N*LOG N)
- create tree using inorder & preorder
TC - O(N*LOG N)

APPROACH 3 - USING RANGE MIN-MAX
- here each node is traversed thrice - TC:O(3N)
*/

#include<iostream>
#include<queue>
#include<vector>
#include<limits.h>
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

void createBST(Node* &root, int min, int max, int& i, vector<int>& preorder) {

    if(i > preorder.size()) {
        return;
    }

    // if value out of range
    if(preorder[i] < min || preorder[i] > max) {
        return;
    }

    root = new Node(preorder[i]);
    i++;

    createBST(root -> left, min, root -> data, i, preorder);
    createBST(root -> right, root -> data, max, i, preorder);
}

int main() {

    vector<int> preorder = {8, 5, 1, 7, 10, 12};

    Node* root = NULL;
    int min = INT_MIN;
    int max = INT_MAX;
    int i = 0;

    createBST(root, min, max, i, preorder);
    
    levelOrderTraversal(root);

    return 0;
}