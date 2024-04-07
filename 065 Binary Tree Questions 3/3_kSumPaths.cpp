#include<iostream>
#include<queue> 
#include<vector>
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

        if(leftData != 0) {
            front -> left = new Node(leftData);
            q.push(front -> left);
        }

        int rightData;
        cout << "Enter right data for " << front -> data << " : ";
        cin >> rightData;

        if(rightData != 0) {
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

// TC - O(N^2) && SC - O(N)
void totalPaths(Node* root, int k, int &count, vector<int> path) {

    if(root == NULL) return;

    path.push_back(root -> data);

    totalPaths(root -> left, k, count, path);
    totalPaths(root -> right, k, count, path);

    int size = path.size();
    int sum = 0;

    for(int i=size-1; i>=0; i--) {
        sum += path[i];
        if(sum == k) {
            count++;
        }
    }
}

int main() {

    Node* root = NULL;

    buildTree(root);
    levelOrderTraversal(root);

    int k;
    cout << "Enter k: ";
    cin >> k; 

    vector<int> path;

    int count = 0;
    totalPaths(root, k, count, path);

    cout << "total paths: " << count;
        
    return 0;
}