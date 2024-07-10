#include<iostream>
#include<vector>
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

void build(Node* &root) {
    
    int d;
    cin >> d;

    root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(!q.empty()) {
        Node* front = q.front();
        q.pop();

        int ld;
        cin >> ld;
        if(ld != -1) {
            front->left = new Node(ld);
            q.push(front->left);
        }

        int rd;
        cin >> rd;
        if(rd != -1) {
            front->right = new Node(rd);
            q.push(front->right);
        }
    }
} 

void print(Node* root) {

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

void inorder(Node* root, vector<int>& arr) {

    if(root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

int bst(Node* root) {

    vector<int> arr;
    inorder(root, arr);

    int n = arr.size();
    bool ans = true;
    for(int i = 1; i<n; i++) {
        if(arr[i-1] >= arr[i]) {
            ans = false;
            break;
        }
    }

    if(ans) return n;
    return 0;
}

void preorder(Node* root, int &maxCnt) {

    if(root == NULL) return;
    int cnt = bst(root);
    maxCnt = max(cnt, maxCnt);
    preorder(root->left, maxCnt);
    preorder(root->right, maxCnt);
}

int main()
{
    Node* root = NULL;
    build(root);
    print(root);
    cout << endl;

    int maxCnt = 0;
    preorder(root, maxCnt);
    cout << maxCnt;

    return 0;
}