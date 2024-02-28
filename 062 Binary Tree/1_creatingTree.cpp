#include<iostream>
#include<queue>
using namespace std;

class node {

    public:
        int data;
        node* left;
        node* right;

    node(int d) {
        this -> data = d;
        this -> left = NULL;
        this -> right = NULL;
    }
};

node* buildTree(node* root) {

    int data;
    cin >> data;

    root = new node(data);

    if(data == -1) {
        return NULL;
    }

    cout << "Enter data to insert in left of : " << data << endl;
    root -> left = buildTree(root -> left);
    cout << "Enter data to insert in right of : " << data << endl;
    root -> right = buildTree(root -> right);

    return root;
}

void buildFromLevelOrderTraversal(node* &root) {

    // 1 3 5 7 11 17 -1 -1 -1 -1 -1 -1 -1

    queue<node*> q;
    cout << "Enter data for root: ";
    int d;
    cin >> d;
    root = new node(d);
    q.push(root);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        cout << "Enter left data for : " << temp -> data << endl;
        int leftData;
        cin >> leftData;

        if(leftData != -1) {
            temp -> left = new node(leftData);
            q.push(temp -> left);
        }

        cout << "Enter right data for: " << temp -> data << endl;
        int rightData;
        cin >> rightData;

        if(rightData != -1) {
            temp -> right = new node(rightData);
            q.push(temp -> right);
        }
    }
}

void levelOrderTraversal(node* root) {

    // level order traversal is done by using separator
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()) {
        node* temp = q.front();
        q.pop();

        if(temp == NULL) {
            cout << endl;
            if(!q.empty()) {
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

// LNR
void inorderTraversal(node* root) {
    
    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}

// NLR
void preorderTraversal(node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

// LRN
void postorderTraversal(node* root) {

    if(root == NULL) {
        return;
    }

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}

int main() {

    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    node* root = NULL;

    // root = buildTree(root);

    // cout << endl << "level order traversal: " << endl;
    // levelOrderTraversal(root);

    // cout << endl;

    // cout << "Inorder traversal: ";
    // inorderTraversal(root);

    // cout << endl;

    // cout << "Preorder traversal: ";
    // preorderTraversal(root);

    // cout << endl;

    // cout << "Postorder traversal: ";
    // postorderTraversal(root);

    buildFromLevelOrderTraversal(root);
    levelOrderTraversal(root);
    
    return 0;
}