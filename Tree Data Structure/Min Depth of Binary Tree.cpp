void minH(TreeNode* A, int d, int &ans){
    if(A == NULL) return;
    if(A->left == NULL && A->right == NULL){
        d++;
        ans = min(ans, d);
        return;
    }
    
    d++;
    
    if(A->left)  minH(A->left,  d, ans);
    if(A->right) minH(A->right, d, ans);
}
int Solution::minDepth(TreeNode* A) {
    int d = 0;
    if(A == NULL) return 0;
    int ans = INT_MAX;
    minH(A, d, ans);
    return ans;
}

// Check all depths and return the minimum