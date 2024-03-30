// TC - O(N^2) && SC - O(N)

#include<iostream>
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

int findPosition(vector<int>& inorder, int n, int element) {

    for(int i=0; i<n; i++) {
        if(inorder[i] == element) {
            return i;
        }
    }
    return -1;
}

Node* buildTree(vector<int>& preorder, vector<int>& inorder, int n, int& index, int inorderStart, int inorderEnd) {

    if(index >= n || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = preorder[index];
    index++;
    Node* root = new Node(element);
    int position = findPosition(inorder, n, element);

    root -> left = buildTree(preorder, inorder, n, index, inorderStart, position - 1);
    root -> right = buildTree(preorder, inorder, n, index, position + 1, inorderEnd);

    return root;
}

void preorderTraversal(Node* root) {

    if(root == NULL) {
        return;
    }

    cout << root -> data << " ";
    preorderTraversal(root -> left);
    preorderTraversal(root -> right);
}

int main() {

    vector<int> preorder = {3, 9, 20, 15, 7};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int preOrderIndex = 0;
    int n = inorder.size();
    int inorderStart = 0;
    int inorderEnd = n-1;

    Node* root = buildTree(preorder, inorder, n, preOrderIndex, inorderStart, inorderEnd);

    preorderTraversal(root);
    
    return 0;
}