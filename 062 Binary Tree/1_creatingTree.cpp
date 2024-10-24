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

    if(d == -1) {
        return;
    }

    root = new Node(d);
    
    cout << "Enter left data for " << root -> data << " : ";
    buildTree(root -> left);

    cout << "Enter right data for " << root -> data << " : ";
    buildTree(root -> right);
}


void buildFromLevelOrder(Node* &root) {

    int d;
    cout << "Enter root element: ";
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
void inorderTraversal(Node* &root) {

    if(root == NULL) {
        return;
    }

    inorderTraversal(root -> left);
    cout << root -> data << " ";
    inorderTraversal(root -> right);
}


// NLR
void preorderTraversal(Node* &root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}  


// LRN
void postorderTraversal(Node* &root) {

    if(root == NULL) {
        return;
    }

    postorderTraversal(root -> left);
    postorderTraversal(root -> right);
    cout << root -> data << " ";
}

int main() {

    Node* root = NULL;

    // buildTree(root);
    // levelOrderTraversal(root);

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    cout << endl << "Inorder Traversal: ";
    inorderTraversal(root);

    cout << endl << "Preorder Traversal: ";
    preorderTraversal(root);

    cout << endl << "Postorder Traversal: ";
    postorderTraversal(root);
     
    return 0;
}