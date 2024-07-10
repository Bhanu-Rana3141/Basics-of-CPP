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


/*
1. left subtree except leaf node
2. leaf nodes of left subtree
3. leaf nodes of right subtree
4. right subtree in reverse order except leaf node
*/

void leftTraversal(Node* &root, vector<int>& ans) {

    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    ans.push_back(root -> data);

    if(root -> left) {
        leftTraversal(root -> left, ans);
    }
    else {
        leftTraversal(root -> right, ans);
    }
}


void leafNodeTraversal(Node* &root, vector<int>& ans) {

    if(root == NULL) {
        return;
    }

    if(root -> left == NULL && root -> right == NULL) {
        ans.push_back(root -> data);
        return;
    }

    leafNodeTraversal(root -> left, ans);
    leafNodeTraversal(root -> right, ans);
}

void rightTraversal(Node* &root, vector<int>& ans) {

    if((root == NULL) || (root -> left == NULL && root -> right == NULL)) {
        return;
    }

    if(root -> right) {
        rightTraversal(root -> right, ans);
    }
    else {
        rightTraversal(root -> left, ans);
    }

    ans.push_back(root -> data);
}


void boundaryTraversal(Node* &root, vector<int>& ans) {

    if(root == NULL) {
        return;
    }

    ans.push_back(root -> data);

    leftTraversal(root -> left, ans);

    leafNodeTraversal(root -> left, ans);
    leafNodeTraversal(root -> right, ans);

    rightTraversal(root -> right, ans);
}


int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    cout << endl;

    vector<int> ans;
    boundaryTraversal(root, ans);

    for(auto it : ans) {
        cout << it << " ";
    }
    
    return 0;
}