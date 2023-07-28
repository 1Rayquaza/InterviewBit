int height(TreeNode* A){
    if(A == NULL){  // Base condition
        return 0;
    }
    int lh = height(A->left);   // Hypothesis
    int rh = height(A->right);
    
    return (1 + max(lh, rh));   // Induction    
} 
 
int Solution::maxDepth(TreeNode* A) {
    return height(A);
}
