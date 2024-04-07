#include<iostream>
#include<vector>
#include<queue>
#include<map>
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

void buildTree(Node* &root, vector<int>& arr) {

    root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(i < arr.size()) {

        Node* front = q.front();
        q.pop();

        front -> left = new Node(arr[i]);
        i++;
        q.push(front -> left);

        front -> right = new Node(arr[i]);
        i++;
        q.push(front -> right);
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
void leftView(Node* &root, vector<int>& ans, int level) {

    if(root == NULL) {
        return;
    }

    // new level started
    if(level == ans.size()) {
        ans.push_back(root -> data);
    }

    leftView(root -> left, ans, level+1);
    leftView(root -> right, ans, level+1);
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = NULL;

    buildTree(root, arr);   
    levelOrderTraversal(root);
    cout << endl;

    vector<int> ans;
    int level = 0;
    leftView(root, ans, level);

    cout << "left view : ";
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}