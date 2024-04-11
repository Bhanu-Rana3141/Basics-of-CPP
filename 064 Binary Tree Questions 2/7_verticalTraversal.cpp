#include<iostream>
#include<map>
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

void buildTree(Node*& root) {

    int d;
    cout << "Enter root data : ";
    cin >> d;

    root = new Node(d);
    queue<Node*> q;
    q.push(root);

    while(q.size() != 0) {

        Node* front = q.front();
        q.pop();

        int leftData;
        cout << "Enter leftdata for " << front -> data << " : ";
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

vector<int> verticalOrderTraversal(Node* root) {

    vector<int> ans;
    if(root == NULL) return ans;

    map<int, vector<int>> hdToNodeData;
    queue<pair<Node*, int>> q;
    q.push({root, 0});

    while(q.size() != 0) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;

        hdToNodeData[hd].push_back(front -> data);

        if(front -> left) {
            q.push({front -> left, hd - 1});
        }

        if(front -> right) {
            q.push({front -> right, hd + 1});
        }
    }

    // mapping 
    cout << endl << "mapping: " << endl;
    for(auto i : hdToNodeData) {
        cout << i.first << " -> ";
        for(auto j : i.second) {
            cout << j << " ";
        }
        cout << endl;
    }

    for(auto i : hdToNodeData) {
        for(auto j : i.second) {
            ans.push_back(j);
        }
    }

    return ans;
}

int main()
{
    Node* root = NULL;
    buildTree(root);

    vector<int> ans = verticalOrderTraversal(root);

    cout << endl << "printing ans : ";
    for(auto it : ans) {
        cout << it << " ";
    }

    return 0;
}