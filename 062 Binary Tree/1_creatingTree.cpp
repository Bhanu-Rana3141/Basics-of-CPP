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

    int d;
    cout << "Enter root element data: ";
    cin >> d;

    root = new node(d);
    q.push(root);

    while(q.size() != 0) {

        int leftData;  
        cout << "Enter left data for " << q.front() -> data << " : "; 
        cin >> leftData;

        if(leftData != -1) {
            q.front() -> left = new node(leftData);
            q.push(q.front() -> left);
        }

        int rightData;
        cout << "Enter right data for " << q.front() -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            q.front() -> right = new node(rightData);
            q.push(q.front() -> right);
        }

        q.pop();
    }
}

void levelOrderTraversal(node* root) {

    // level order traversal is done by using separator, here NULL is used as separator
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() != 0) {

        node* temp = q.front();
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