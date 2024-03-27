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

    root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {

        Node* front = q.front();
        q.pop();

        int leftData;
        cout << "Enter left data for " << front -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            front -> left = new Node(leftData);
            q.push(front -> left);
        }

        int rightData;
        cout << "Enter right data for " << front -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            front -> right = new Node(rightData);
            q.push(front -> right);
        }
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


Node* lca(Node* root, Node* p, Node* q) {

    if(root == NULL) {
        return NULL;
    }

    if(root == p || root == q) {
        return root;
    }

    Node* left = lca(root -> left, p, q);
    Node* right = lca(root -> right, p, q);

    if(left != NULL && right != NULL) {
        return root;
    }
    else if(left != NULL && right == NULL) {
        return left;
    }
    else if(left == NULL && right != NULL) {
        return right;
    }
    else {
        return NULL;
    }
}


int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    cout << endl;

    int pData;
    cout << "Enter p data: ";
    cin >> pData;

    Node* p = new Node(pData);


    int qData;
    cout << "Enter q data: ";
    cin >> qData;

    Node* q = new Node(qData);

    Node* ans = lca(root, p, q);

    if(ans != NULL) {
        cout << "Lowest common ancestor : " << ans -> data;
    }
    else {
        cout << "Lowest common ancestor not found";
    }

    return 0;
}