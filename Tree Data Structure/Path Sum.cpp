int doesExist(TreeNode* A, int B, int sum){
    // if(A == NULL) return 0;
    if(A->left == NULL && A->right == NULL){
        if((sum+(A->val)) == B) return 1;
        else return 0;
    }
    
    int s1 = (A->left == NULL)  ? 0 : doesExist(A->left,  B, (sum + A->val));
    int s2 = (A->right == NULL) ? 0 : doesExist(A->right, B, (sum + A->val));
    return(s1 || s2);   // if sum is found in either direction or both
}

int Solution::hasPathSum(TreeNode* A, int B) {
    return doesExist(A, B, 0);
}

/* We can traverse the tree and backtrack if sum TILL THE LEAF becomes == B
Let recursion do it's magic !
In every call there's a new sum variable carrying previous sum data, dw about storing and following values,
recursion takes care of that. REMEMEBER TO REMEMEBER :D
*/
