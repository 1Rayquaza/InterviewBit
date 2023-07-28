void path(TreeNode* A, int B, vector<int> tmp, vector<int> &ans){
    if(A == NULL) return;
    
    tmp.push_back(A->val);
    
    if(A->val == B){
        ans = tmp;
        return;
    }
    
    if(A->left)  path(A->left,  B, tmp, ans);
    if(A->right) path(A->right, B, tmp, ans);
}


vector<int> Solution::solve(TreeNode* A, int B) {
    vector<int> v;
    vector<int> ans;
    path(A, B, v, ans);
    return ans;
}

/* I need to find the path :/ similar to another q. I can't recall 
*/
