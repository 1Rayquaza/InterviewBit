void traverse(TreeNode* A, map<int, int> &m, int line){
    if(A == NULL){
        return;
    }
    
    m[line] += A->val;
    
    if(A->left)  traverse(A->left,  m, line-1);
    if(A->right) traverse(A->right, m, line+1);
}

vector<int> Solution::verticalSum(TreeNode* A) {
    map<int, int> m;
    traverse(A, m, 0);
    vector<int> ans;
    for(auto x: m){
        ans.push_back(x.second);
    }
    return ans;
}

// Imagine we draw vertical lines, ab lines ke corresponding values store kra lenge then add, simple traversal 
