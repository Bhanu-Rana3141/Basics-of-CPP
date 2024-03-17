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

void buildTreeFromLevelOrder(Node* &root) {

    queue<Node*> q;
    
    int d;
    cout << "Enter root data : ";
    cin >> d;

    root = new Node(d);
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

// APPROACH 1 - TC : O(N^2)
int height(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int left = height(root -> left);
    int right = height(root -> right);

    int ans = max(left, right) + 1;

    return ans;
}

int diameter_1(Node* root) {

    if(root == NULL) {
        return 0;
    }

    int left = diameter_1(root -> left);
    int right = diameter_1(root -> right);
    int leftAndRight = height(root -> left) + height(root -> right);

    int ans = max(left, max(right, leftAndRight));

    return ans;
}


// APPROACH 2 - TC : O(N)
pair<int, int> diameter_2(Node* &root) {

    if(root == NULL) {
        return {0, 0};
    }

    pair<int, int> left = diameter_2(root -> left);
    pair<int, int> right = diameter_2(root -> right);

    int op1 = left.first;
    int op2 = right.first;
    int op3 = left.second + right.second;

    pair<int, int> ans;
    ans.first = max(op1, max(op2, op3));
    ans.second = max(left.second, right.second) + 1;

    return ans; 
} 


int main() {

    Node* root = NULL;
    
    buildTreeFromLevelOrder(root);
    levelOrderTraversal(root);

    // int diameter = diameter_1(root);

    cout << "diameter: " << diameter_2(root).first;

    return 0;
}