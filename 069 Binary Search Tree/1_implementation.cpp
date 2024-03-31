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

// delete node
Node* deleteFromBST(Node* root, int val) {

    if(root == NULL) {
        return NULL;
    }

    if(root -> data == val) {
        // 0 child
        if(root -> left == NULL && root -> right == NULL) {
            delete root;
            return NULL;
        }

        // 1 child
        // left child
        if(root -> left != NULL && root -> right == NULL) {
            Node* temp = root -> left;
            delete root;
            return temp;
        }

        // right child
        if(root -> right != NULL && root -> left == NULL) {
            Node* temp = root -> right;
            delete root;
            return temp;
        }

        // 2 child
        if(root -> left != NULL && root -> right != NULL) {
            int mini = minValue(root -> right);
            root -> data = mini;
            root -> right = deleteFromBST(root -> right, mini);
            return root;
        }
    }
    else if(root -> data > val) {
        root -> left = deleteFromBST(root -> left, val);
        return root;
    }
    else {
        root -> right = deleteFromBST(root -> right, val);
        return root;
    }
}

int main() {

    Node* root = NULL;
    
    cout << "Enter data to create BST : ";
    takeInput(root);

    cout << "level order traversal: " << endl;
    levelOrderTraversal(root);

    cout << endl;

    root = deleteFromBST(root, 50);

    levelOrderTraversal(root);

/*
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
    cout << "max value : " << maxValue(root) << endl;
*/
    return 0;
}