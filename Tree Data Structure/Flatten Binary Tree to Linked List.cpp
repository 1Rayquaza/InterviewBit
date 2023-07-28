void build(TreeNode* A){
    if(A == NULL) return;
    if(A->left == NULL && A->right == NULL) return;    
    
    TreeNode* tmp = A->right;
    
    A->right = A->left;
    A->left = NULL;
    
    TreeNode* node = A;
    while(node->right != NULL){
        node = node->right;
    }
    
    node->right = tmp;
    // Let say 4 is not there in input 2, whether mai 2 ke right mei tmp bnaun ya last level left node ke r
    // mei, it'll be the same
    build(A->right);
}

TreeNode* Solution::flatten(TreeNode* A) {
    build(A);
    return A;
}

/* Inorder TRaversal but make it Linked list instead of vector but MLE so do it in-place
left subtree hai toh usko FLATTEN krke right mei daalna hai
*/