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

    int data;
    cin >> data;

    while(data != -1) {
        insertInBST(root, data);
        cin >> data;
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

void inorder(Node* root) {

    if(root == NULL) {
        return;
    }

    inorder(root -> left);
    cout << root -> data << " ";
    inorder(root -> right);
}

void preOrder(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preOrder(root -> left);
    preOrder(root -> right);
}

void postOrder(Node* root) {

    if(root == NULL) {
        return;
    }

    postOrder(root -> left);
    postOrder(root -> right);
    cout << root -> data << " ";
}

int minValue(Node* root) {

    Node* temp = root;

    while(temp -> left != NULL) {
        temp = temp -> left;
    }

    return temp -> data;
}

int maxValue(Node* root) {

    Node* temp = root;

    while(temp -> right != NULL) {
        temp = temp -> right;
    }

    return temp -> data;
}

int main() {

    Node* root = NULL;
    
    cout << "Enter data to create BST : ";
    takeInput(root);

    cout << "level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    cout << "Inorder traversal: ";
    inorder(root);

    cout << endl;

    cout << "Preorder traversal: ";
    preOrder(root);

    cout << endl;

    cout << "Postorder traversal: ";
    postOrder(root);

    cout << endl;

    cout << "min value : " << minValue(root) << endl;
    cout << "max value : " << maxValue(root)<< endl;

    return 0;
}