#include<iostream>
#include<queue>
#include<limits.h>
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

void buildTreeFromLevelOrder(Node*& root) {

    queue<Node*> q;

    int d;
    cout << "Enter root element: ";
    cin >> d;

    root = new Node(d);
    q.push(root);

    while(q.size() != 0) {

        int leftData;
        cout << "Enter left data for " << q.front() -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            q.front() -> left = new Node(leftData);
            q.push(q.front() -> left);
        }

        int rightData;
        cout << "Enter right data for " << q.front() -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            q.front() -> right = new Node(rightData);
            q.push(q.front() -> right);
        }

        q.pop();
    }
}

void levelOrderTraversal(Node* root) {

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

            if(temp -> left != NULL) {
                q.push(temp -> left);
            }

            if(temp -> right != NULL) {
                q.push(temp -> right);
            }
        }
    }
}

void maxDepth_1(Node* root, int& maxDepth, vector<int> arr) {

    if(root == NULL) {
        return;
    }

    arr.push_back(root -> data);

    if(root -> left == NULL && root -> right == NULL) {
        int depth = arr.size();
        maxDepth = max(maxDepth, depth);
    }

    maxDepth_1(root -> left, maxDepth, arr);
    maxDepth_1(root -> right, maxDepth, arr);

}

int maxDepth_2(Node* root) {

    if(root == NULL) {
        return 0;
    } 

    int left = maxDepth_2(root -> left);
    int right = maxDepth_2(root -> right);

    int ans = max(left, right) + 1;

    return ans;
}

int main() {

    Node* root = NULL;

    buildTreeFromLevelOrder(root);
    levelOrderTraversal(root);
    
    int maxDepth = INT_MIN;
    vector<int> arr;
    maxDepth_1(root, maxDepth, arr);
    cout << "Max depth : " << maxDepth;

    // int ans = maxDepth_2(root);
    // cout << "Max depth : " << ans;

    return 0;
}