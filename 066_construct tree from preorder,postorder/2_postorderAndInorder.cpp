//  TC - O(N) && SC - O(N)

#include<iostream>
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

void createMapping(vector<int>& inorder, int n, map<int,int>& elementToIndex) {

    for(int i=0; i<n; i++) {
        elementToIndex[inorder[i]] = i;
    }
}

Node* buildTree(vector<int>& postorder, vector<int>& inorder, int n, int& index, int inorderStart, int inorderEnd, map<int,int>& elementToindex) {

    if(index < 0 || inorderStart > inorderEnd) {
        return NULL;
    }

    int element = postorder[index];
    index--;
    Node* root = new Node(element);
    int position = elementToindex[element];

    root -> right = buildTree(postorder, inorder, n, index, position + 1, inorderEnd, elementToindex);
    root -> left = buildTree(postorder, inorder, n, index, inorderStart, position - 1, elementToindex);

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

    vector<int> postorder = {9, 15, 7, 20, 3};
    vector<int> inorder = {9, 3, 15, 20, 7};

    int n = inorder.size();
    int postorderIndex = n-1;
    int inorderStart = 0;
    int inorderEnd = n-1;

    map<int, int> elementToindex;
    createMapping(inorder, n, elementToindex);

    Node* root = buildTree(postorder, inorder, n, postorderIndex, inorderStart, inorderEnd, elementToindex);

    preorderTraversal(root);
    
    return 0;
}