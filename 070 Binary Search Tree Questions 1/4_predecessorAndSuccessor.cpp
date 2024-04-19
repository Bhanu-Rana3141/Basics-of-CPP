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

// APPROACH 1
void inorder(Node* root, vector<int>& nodeData) {

    if(root == NULL) {
        return;
    }

    inorder(root -> left, nodeData);
    nodeData.push_back(root -> data);
    inorder(root -> right, nodeData);
}

pair<int, int> preAndSucc_1(Node* root, int key) {

    vector<int> nodeData;
    inorder(root, nodeData);

    int pre = -1;
    int succ = -1;

    int idx = -1;
    for(int i=0; i<nodeData.size(); i++) {
        if(nodeData[i] == key) {
            idx = i;
            break;
        }
    }

    if(idx > 0) {
        pre = nodeData[idx-1];
    }

    if(idx < nodeData.size()-1) {
        succ = nodeData[idx+1];
    }

    pair<int,int> ans = make_pair(pre, succ);
    return ans;
}

// APPROACH 2
int successor(Node* root, int key) {

    int succ = -1;

    while(root != NULL) {
        if(key >= root -> data) {
            root = root -> right;
        }
        else {
            succ = root -> data;
            root = root -> left;
        }
    }

    return succ;
}

int predecessor(Node* root, int key) {

    int pre = -1;

    while(root != NULL) {
        if(root -> data < key) {
            pre = root -> data;
            root = root -> right;
        }
        else {
            root = root -> left;
        }
    }

    return pre;
}

int main() {

    Node* root = NULL;

    cout << "Enter data to create BST: ";
    takeInput(root);

    cout << "Printing tree: " << endl;
    levelOrderTraversal(root);
    
    int key;
    cout << "Enter key: ";
    cin >> key;

    // pair<int, int> ans = preAndSucc_1(root, key);
    // cout << ans.first << " , " << ans.second;

    int pre = predecessor(root, key);
    int succ = successor(root, key);

    cout << "pre : " << pre << " , " << "succ : " << succ;

    return 0;
}