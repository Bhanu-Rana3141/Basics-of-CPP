/*
APPROACH 1
1. inorder traversal of both bst : bst1, bst2
2. merge 2 sorted arrays in a ans vector
3. return ans if it is mentioned to return array as ans
4. In case you have to return BST after merge , inorderToBST

TC - O(M+N)
SC - O(M+N)


APPROACH 2
1**. Convert bst into sorted LL 
TC - O(M) , SC - O(h1)
TC - O(N) , SC - O(h2)

by using LL , space complexity is improved, discarding use of vectors

2**. merge 2 sorted LL
TC - O(M+N)
SC - O(1)

ALGO - 
1. Convert right subtree in LL, it will give head
root -> right = head 
head -> left = root
head = root
2. convert left subtree in LL, it will give head


3**. convert sorted LL in BST
1. total n nodes
2. *left = create left tree from starting n/2 nodes 
3. create root node
root -> left = left
4. head = head -> next
5. create right subtree


Q. This question is combination of 3 questions ?
1. Convert a BST into LL
2. Merger 2 sorted LL
3. Sorted LL  -> BST
 
*/

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

void insertInBst(Node* &root, int d) {

    if(root == NULL) {
        root = new Node(d);
        return;
    }

    if(d < root -> data) {
        insertInBst(root -> left, d);
    }
    else {
        insertInBst(root -> right, d);
    }
}

void takeInput(Node* &root) {

    int d;
    cout << "Enter root : ";
    cin >> d;

    while(d != -1) {
        insertInBst(root, d);
        cin >> d;
    }
}

void levelOrderTraversal(Node* root) {

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

// APPROACH 1
void inorder(Node* root, vector<int>& arr) {

    if(root == NULL) return;
    inorder(root->left, arr);
    arr.push_back(root->data);
    inorder(root->right, arr);
}

vector<int> merge(vector<int> bst1, vector<int> bst2) {

    int i = 0;
    int j = 0;
    int n = bst1.size();
    int m = bst2.size();

    vector<int> ans;

    while(i < n && j < m) {
        if(bst1[i] <= bst2[j]) {
            ans.push_back(bst1[i]);
            i++;
        }
        else {
            ans.push_back(bst2[j]);
            j++;
        }
    }    

    while(i < n) {
        ans.push_back(bst1[i]);
        i++;
    }

    while(j < m) {
        ans.push_back(bst2[j]);
        j++;
    }

    return ans;
}

Node* inorderToBalancedBst(int s, int e, vector<int> arr) {

    if(s > e) {
        return NULL;
    }
    int mid = s + (e-s)/2;
    Node* root = new Node(arr[mid]);
    root->left = inorderToBalancedBst(s, mid-1, arr);
    root->right = inorderToBalancedBst(mid, e , arr);
    return root;
}   

// APPROACH 2 

int main() {

    Node* root1 = NULL;
    Node* root2 = NULL;
    
    takeInput(root1);
    takeInput(root2);

    levelOrderTraversal(root1);
    levelOrderTraversal(root2);

    // APPROACH 1
    // vector<int> bst1, bst2;
    // inorder(root1, bst1); 
    // inorder(root2, bst1); 
    // vector<int> mergedArray = merge(bst1, bst2);

    // // convert merged array in bst
    // int s = 0;
    // int e = mergedArray.size() - 1;
    // Node* root = inorderToBalancedBst(s, 0, mergedArray);
    

    return 0;
}