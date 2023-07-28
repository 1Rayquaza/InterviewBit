void letsCount(TreeNode* A, int &c){
    if(A == NULL){
        return;
    }
    
    if(A->left){
        if(abs(A->val - A->left->val) == 1) c++;
    }
    if(A->right){
        if(abs(A->val - A->right->val) == 1) c++;
    }
    
    letsCount(A->left, c);
    letsCount(A->right, c);
}

int Solution::consecutiveNodes(TreeNode* A) {
    int c = 0;
    if(A->left == NULL && A->right == NULL) return c;
    
    letsCount(A, c);
    return c;
}

/* Either of parent-child can be the larger or smaller one, we just need to find consecutive nodes in 
whatever order, 
*/