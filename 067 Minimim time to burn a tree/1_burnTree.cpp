#include<iostream>
#include<queue>
#include<vector>
#include<map>
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

void buildTreeFromLevelOrder(Node*& root) {

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

Node* createMapping(Node* root, int target, map<Node*,Node*>& nodeToParent) {

    Node* res = NULL;
    queue<Node*> q;
    q.push(root);
    nodeToParent[root] = NULL;

    while(q.size() != 0) {

        Node* front = q.front();
        q.pop();

        if(front -> data == target) {
            res = front;
        }

        if(front -> left) {
            nodeToParent[front -> left] = front;
            q.push(front -> left);
        }

        if(front -> right) {
            nodeToParent[front -> right] = front;
            q.push(front -> right);
        }
    }
    return res;
}

int burnTree(Node* root, map<Node*, Node*>& nodeToParent) {

    map<Node*, bool> visited;
    int ans = 0;
    queue<Node*> q;
    q.push(root);
    visited[root] = true;

    while(q.size() != 0) {

        bool flag = false;
        int size = q.size();

        for(int i=0; i<size; i++) {

            Node* front = q.front();
            q.pop();

            if(front -> left && !visited[front -> left]) {
                flag = true;
                q.push(front -> left);
                visited[front -> left] = true;
            }

            if(front -> right && !visited[front -> right]) {
                flag = true;
                q.push(front -> right);
                visited[front -> right] = true;
            }

            if(nodeToParent[front] && !visited[nodeToParent[front]]) {
                flag = true;
                q.push(nodeToParent[front]);
                visited[nodeToParent[front]] = true;
            }
        }

        if(flag == true) {
            ans++;
        }
    }

    return ans;
}

int main() {

    Node* root = NULL;

    buildTreeFromLevelOrder(root);
    cout << endl;
    
    int target = 8;
   
    map<Node*, Node*> nodeToParent;
    Node* targetNode = createMapping(root, target, nodeToParent);

    int minTime = burnTree(targetNode, nodeToParent);

    cout << "min time: " << minTime;

    return 0;
}