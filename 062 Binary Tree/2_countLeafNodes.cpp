/*

void postorder(BinaryTreeNode<int> *root, int& count) {

    if(root == NULL) {
        return;
    }

    postorder(root->left, count);
    postorder(root -> right, count);

    if(root -> left == NULL && root -> right == NULL) {
        count++;
    }
}

int noOfLeafNodes(BinaryTreeNode<int> *root){

    int cnt = 0;
    postorder(root, cnt);

    return cnt;
}

*/