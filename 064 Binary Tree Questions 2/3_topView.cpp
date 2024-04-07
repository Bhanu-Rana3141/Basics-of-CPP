#include<iostream>
#include<vector>
#include<queue>
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

void buildTree(Node* &root, vector<int>& arr) {

    root = new Node(arr[0]);
    queue<Node*> q;
    q.push(root);

    int i = 1;
    while(i < arr.size()) {

        Node* front = q.front();
        q.pop();

        front -> left = new Node(arr[i]);
        i++;
        q.push(front -> left);

        front -> right = new Node(arr[i]);
        i++;
        q.push(front -> right);
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

/*
TC - O(N * LOG N) -> N is number of nodes and find function of map takes O(LOG N) 
SC - O(N) -> QUEUE stores n nodes, MAP can have n entries in worst case, ANS vector 
*/
void topView(Node* &root, vector<int>& ans) {

    map<int, int> hdToNodeData;
    queue<pair<Node*, int>> q;
    q.push(make_pair(root, 0));

    while(q.size() != 0) {

        pair<Node*, int> temp = q.front();
        q.pop();

        Node* front = temp.first;
        int hd = temp.second;

        if(hdToNodeData.find(hd) == hdToNodeData.end()) {
            hdToNodeData[hd] = front -> data;
        }

        if(front -> left) {
            q.push({front -> left, hd-1});
        }

        if(front -> right) {
            q.push({front -> right, hd+1});
        }
    }

    for(auto i : hdToNodeData) {
        ans.push_back(i.second);
    }
}

int main() {

    vector<int> arr = {1, 2, 3, 4, 5, 6, 7};
    Node* root = NULL;

    buildTree(root, arr);   
    levelOrderTraversal(root);
    cout << endl;

    vector<int> ans;
    topView(root, ans);

    cout << "top view : ";
    for(auto i : ans) {
        cout << i << " ";
    }

    return 0;
}


/*
map<int, int> hdToNodeData;: Initializes a map to store the horizontal distance to node data mapping.
queue<pair<Node*, int>> q;: Initializes a queue to perform level order traversal along with maintaining horizontal distances.
q.push(make_pair(root, 0));: Pushes the root node with horizontal distance 0 into the queue.
while(q.size() != 0) {: Begins the while loop to process nodes until the queue becomes empty.
pair<Node*, int> temp = q.front(); q.pop();: Dequeues the front element from the queue and extracts the node and its horizontal distance.
Node* front = temp.first; int hd = temp.second;: Extracts the node and horizontal distance from the temporary pair.
if(hdToNodeData.find(hd) == hdToNodeData.end()) { hdToNodeData[hd] = front -> data; }: Checks if the horizontal distance already exists in the map. If not, it inserts the node data into the map with the current horizontal distance.
if(front -> left) { q.push({front -> left, hd-1}); }: If the left child exists, it enqueues it with a horizontal distance decreased by 1.
if(front -> right) { q.push({front -> right, hd+1}); }: If the right child exists, it enqueues it with a horizontal distance increased by 1.
for(auto i : hdToNodeData) { ans.push_back(i.second); }: Transfers the node data from the map to the result vector ans.
*/