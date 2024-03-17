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

bool isSame(Node* r1, Node* r2) {

    if(r1 == NULL && r2 == NULL) {
        return true;
    }

    if(r1 == NULL && r2 != NULL) {
        return false;
    }

    if(r1 != NULL && r2 == NULL) {
        return false;
    }

    bool left = isSame(r1 -> left, r2 -> left);
    bool right = isSame(r1 -> right, r2 -> right);
    bool value = r1 -> data == r2 -> data;

    if(left && right && value) {
        return true; 
    }
    else {
        return false;
    }
}

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;

    cout << "Tree 1  " << endl;
    buildTree(root1);
    levelOrderTraversal(root1);
    
    cout << endl;

    cout << "Tree 2  " << endl;
    buildTree(root2);
    levelOrderTraversal(root2);
    
    cout << endl << endl;

    bool ans = isSame(root1, root2);

    if(ans) {
        cout << "Trees are identical" << endl;
    }
    else {
        cout << "Trees are NOT identical" << endl;
    }

    return 0;
}