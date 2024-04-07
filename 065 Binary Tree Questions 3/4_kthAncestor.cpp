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

void buildTree(Node* &root) {

    int d;
    cout << "Enter data for root element: ";
    cin >> d;

    root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {

        Node* front = q.front();
        q.pop();

        int leftData;
        cout << "Enter left data for " << front -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            front -> left = new Node(leftData);
            q.push(front -> left);
        }

        int rightData;
        cout << "Enter right data for " << front -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            front -> right = new Node(rightData);
            q.push(front -> right);
        }
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

// TC - O(N) && SC - O(N)
void kthAncestor(Node* root, int k, int node, int &ans, vector<int> path) {

    if(root == NULL) return;

    path.push_back(root -> data);

    if(root -> data == node) {
        int size = path.size();
        int idx = size - k - 1;

        if(idx >= 0) {
            ans = path[idx];
        }
        return;
    }

    kthAncestor(root -> left, k, node, ans, path);
    kthAncestor(root -> right, k, node, ans, path);
}

int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    int k;
    cout << "Enter k: ";
    cin >> k;

    int node;
    cout << "Enter node data : ";
    cin >> node; 

    int ans = -1;
    vector<int> path;
    kthAncestor(root, k, node, ans, path);

    cout << "ans : " << ans;

    return 0;
}