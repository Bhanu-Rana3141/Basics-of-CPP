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
    cout << "Enter data for root element : ";
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

// TC - O(N) && SC - O(N) in worst case skewed tree , otherwise O(H) -> height of tree
void sumOfLongestPath(Node* &root, int sum, int &maxSum, int len, int &maxLen) {

    if(root == NULL) {
        return;
    }

    sum += root -> data;
    len++;

    if(root -> left == NULL && root -> right == NULL) {
        if(len > maxLen) {
            maxLen = len;
            maxSum = sum;
        }
        else if(len == maxLen) {
            maxSum = max(sum, maxSum);
        }
    }

    sumOfLongestPath(root -> left, sum, maxSum, len, maxLen);
    sumOfLongestPath(root -> right, sum, maxSum, len, maxLen);
}  


int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    int len = 0;
    int maxLen = 0;

    int sum = 0;
    int maxSum = 0;

    sumOfLongestPath(root, sum, maxSum, len, maxLen);

    cout << "max sum : " << maxSum;
        
    return 0;
}