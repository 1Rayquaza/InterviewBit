TreeNode* Solution::solve(TreeNode* A, TreeNode* B) {
    if(A == NULL) return B;
    if(B == NULL) return A;
    if(A == B && B == NULL) return NULL;
    if(A != NULL && B != NULL){
        A->val += B->val;
    }
    
    A->left = solve(A->left, B->left);
    A->right = solve(A->right, B->right);
    return A;
}

// Let the recursion do it's magic !!
