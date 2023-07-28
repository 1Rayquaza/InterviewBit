int height(TreeNode* A, int &ans){
    if(A == NULL) return 0; // ghtrjgnvd
    
    int lh = height(A->left, ans);
    int rh = height(A->right, ans);
    
    if(abs(lh - rh) > 1){
        ans = 0;
        return 0;
    }
    return 1+max(lh, rh);   // for comparing heights
}

int Solution::isBalanced(TreeNode* A) {
    int ans;
    height(A, ans);
    if(ans == 0) return 0;
    else return 1;
}

/* Recursion to the rescue! 
Keep finding and comparing height recursively
*/
