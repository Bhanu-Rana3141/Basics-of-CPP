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

// TC - O(N) && SC - O(H)
// include - exclude pattern 
pair<int, int> solve(Node* root) {

    if(root == NULL) 
    {
        return {0, 0};
    }

    pair<int, int> left = solve(root -> left);
    pair<int, int> right = solve(root -> right);

    pair<int, int> res;
    // including curr value
    res.first = root -> data + left.second + right.second;

    // exclude
    res.second = max(left.first, left.second) + max(right.first, right.second);

    return res;
}

int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    pair<int, int> ans = solve(root);

    int maxSum = max(ans.first, ans.second);

    cout << "max adjacent sum: " << maxSum;

    return 0;
}