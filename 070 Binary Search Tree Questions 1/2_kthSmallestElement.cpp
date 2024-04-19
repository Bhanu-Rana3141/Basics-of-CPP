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
APPROACH 1 -
* STORE VALUES OF NODE IN VECTOR BY INORDER TRAVERSAL(sorted order)
* kth element from the start will be the answer

APPROACH 2 - 
* DON'T STORE VALUE IN VECTOR JUST CREATE A VARIABLE AND INCREASE IT BY 1 WHEN IT POINTS TO ANY NODE AND WHEN IT BECOMES EQUAL TO K, THE DATA OF CURRENT NODE WILL BE THE ANSWER
*/

void kthSmallest(Node* root, int k, int &i, int &ans) {

    if(root == NULL) {
        return;
    }

    kthSmallest(root -> left, k, i, ans);

    i++;
    if(i == k) {
        ans = root -> data;
        return;
    }

    kthSmallest(root -> right, k, i, ans);
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: " << endl;
    takeInput(root);

    cout << "Printing BST: ";
    levelOrderTraversal(root);

    cout << endl;

    int k;
    cout << "Enter K: ";
    cin >> k;

    cout << endl;

    int ans = -1;
    int i = 0;

    kthSmallest(root, k, i, ans);

    cout << "ans: " << ans;
    
    return 0;
}