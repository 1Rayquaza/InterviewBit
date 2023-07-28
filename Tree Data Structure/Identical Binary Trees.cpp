bool compare(TreeNode* A, TreeNode* B){
    if(A == NULL || B == NULL) return (A==B);
    if(A->val != B->val) return 0;
    
    return (compare(A->left, B->left) && compare(A->right, B->right));
}

int Solution::isSameTree(TreeNode* A, TreeNode* B) {
    if(A == NULL || B == NULL) return (A==B);
    if((A->left == NULL && A->right == NULL) && (B->left == NULL && B->right == NULL)){
        if(A->val == B->val) return 1;
        else return 0;
    }
    
    return compare(A, B);
}

/* We need to traverse both trees and return 0 if any value at same position does not match
Just Traverse. And take care of the edge cases T_T
*/
