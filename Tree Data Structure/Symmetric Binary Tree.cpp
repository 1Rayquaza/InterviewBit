bool check(TreeNode* L, TreeNode* R){
    if(L == NULL || R == NULL) return (L==R);   // || not && since if both NULL then okay else 0
    if(L->val != R->val) return 0;
    
    return (check(L->left, R->right) && check(L->right, R->left));
}

int Solution::isSymmetric(TreeNode* A) {
    if(A->left == NULL && A->right == NULL) return 1;
    
    return check(A->left, A->right);
}

/* We need to check the symmetry, now, we cannot store and check the values because 2 nodes having same 
right nodes is NOT symmetric, however the array will tell otherwise, find smth else !!

let Recursion do it's magic ! hehe. call a nodes right and left and check, if unequal then return 0
*/