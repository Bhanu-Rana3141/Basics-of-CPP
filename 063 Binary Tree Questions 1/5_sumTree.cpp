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
    cout << "Enter root element data : ";
    cin >> d;

    root = new Node(d);

    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {

        Node* frontNode = q.front();
        q.pop();

        int leftData;
        cout << "Enter left data for " << frontNode -> data << " : ";
        cin >> leftData;

        if(leftData != -1) {
            frontNode -> left = new Node(leftData);
            q.push(frontNode -> left);
        }

        int rightData;
        cout << "Enter right data for " << frontNode -> data << " : ";
        cin >> rightData;

        if(rightData != -1) {
            frontNode -> right = new Node(rightData);
            q.push(frontNode -> right);
        }
    }
}

void levelOrderTraversal(Node* root) {

    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(q.size() != 0) {

        Node* frontNode = q.front();
        q.pop();

        if(frontNode == NULL) {
            cout << endl;
            if(q.size() != 0) {
                q.push(NULL);
            }
        }
        else {
            cout << frontNode -> data << " ";

            if(frontNode -> left) {
                q.push(frontNode -> left);
            }

            if(frontNode -> right) {
                q.push(frontNode -> right);
            }
        }
    }
}

pair<bool, int> isSum(Node* root) {

    if(root == NULL) {
        return {true, 0};
    }

    if(root -> left == NULL && root -> right == NULL) {
        return {true, root -> data};
    }

    pair<bool, int> left = isSum(root -> left);
    pair<bool, int> right = isSum(root -> right);

    bool leftAns = left.first;
    bool rightAns = right.first;
    bool isSumVal = root -> data == left.second + right.second;

    pair<bool, int> ans;

    if(leftAns && rightAns && isSumVal) {
        ans.first = true;
        ans.second = root -> data * 2;
    }
    else {
        ans.first = false;
    }
    return ans;
}

bool isSumTree(Node* root) {

    return isSum(root).first;
}

int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    bool ans = isSumTree(root);

    ans ? cout << "True" : cout << "false";
    
    return 0;
}