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

void buildFromLevelOrder(Node* &root) {

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

vector<vector<int>> zigZag(Node* root) {

    vector<vector<int>> result;

    queue<Node*> q;
    q.push(root);

    bool leftToRight = true;

    while(q.size() != 0) {

        int size = q.size();
        vector<int> ans(size);

        for(int i=0; i<size; i++) {

            Node* front = q.front();
            q.pop();

            int index = leftToRight ? i : size - i - 1;
            ans[index] = front -> data;

            if(front -> left) {
                q.push(front -> left);
            }

            if(front -> right) {
                q.push(front -> right);
            }
        }

        leftToRight = !leftToRight;
        result.push_back(ans);
    }

    return result;
}

int main() {

    Node* root = NULL;

    buildFromLevelOrder(root);
    levelOrderTraversal(root);

    cout << endl;
    
    vector<vector<int>> ans = zigZag(root);

    for(int i=0; i<ans.size(); i++) {
        for(int j=0; j<ans[i].size(); j++) {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}