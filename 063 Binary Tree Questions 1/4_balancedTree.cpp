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


void buildFromLevelOrder(Node* &root) {

    int d;
    cout << "Enter root element data : ";
    cin >> d;

    root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {

        Node* temp = q.front();
        q.pop();

        int leftData;
        cout << "Enter left data for " << temp -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new Node(leftData);
            q.push(temp -> left);
        }

        int rightData;
        cout << "Enter right data for " << temp -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new Node(rightData);
            q.push(temp -> right);
        }
    }
}


void levelOrderTraversal(Node* &root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() != 0) {

        Node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(q.size() != 0) {
                q.push(NULL);
            }
        }
        else {
            cout << temp -> data << " ";

            if(temp -> left) {
                q.push(temp -> left);
            }

            if(temp -> right) {
                q.push(temp -> right);
            }
        }
    }
}


// APPROACH 1 - O(N^2)

int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);
    int ans = max(left, right) + 1;

    return ans;
}

bool isBalanced_1(Node* &root) {

    if(root == NULL) {
        return true;
    }

    bool left = isBalanced_1(root -> left);
    bool right = isBalanced_1(root -> right);
    bool leftAndRight = abs(height(root -> left) - height(root -> right)) <= 1;

    if(left && right && leftAndRight) {
        return true;
    }
    else {
        return false;
    }
}


// APPROACH 2 - O(N)
pair<bool, int> balanced(Node* root) {

    if(root == NULL) {
        return {true, 0};
    }

    pair<bool, int> left = balanced(root -> left);
    pair<bool, int> right = balanced(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool diff = abs(left.second - right.second) <= 1;

    pair<bool, int> ans;
    ans.second = max(left.second, right.second) + 1;

    if(leftAns && rightAns && diff) {
        ans.first = true;    
    }
    else {
        ans.first = false;
    }

    return ans;
} 

bool isBalanced_2(Node* root) {

    return balanced(root).first;
}


int main() {

    Node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    bool ans = isBalanced_1(root);
    // bool ans = isBalanced_2(root);

    ans ? cout << "true" : cout << "false";

    return 0;
}