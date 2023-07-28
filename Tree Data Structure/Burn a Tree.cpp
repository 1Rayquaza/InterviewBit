int findMaxTime(TreeNode* apex, TreeNode* prev){
    if(apex == NULL){
        return 0;
    }

    int lh, rh;
    if(apex->left == prev){
        lh = 0;
        rh = findMaxTime(apex->right, prev);
        
    }
    
    else if(apex->right == prev){
        lh = findMaxTime(apex->left, prev);
        rh = 0;
    }
    
    else{
        lh = findMaxTime(apex->left, prev);
        rh = findMaxTime(apex->right, prev);
    }
    
    return 1 + max(lh, rh);
}

void findpath(TreeNode* A, int B, vector<TreeNode*> &tmp, vector<TreeNode*> &path){
    if(A == NULL) return;
    tmp.push_back(A);
    
    if(A->val == B){
        reverse(tmp.begin(), tmp.end());
        path = tmp;
        return;
    }
    
    findpath(A->left,  B, tmp, path);
    findpath(A->right, B, tmp, path);
    
    tmp.pop_back();
}

int Solution::solve(TreeNode* A, int B) {
    vector<TreeNode*> path;
    vector<TreeNode*> tmp;
    findpath(A, B, tmp, path);
    
    int n = path.size();
    int mx = INT_MIN;
    int d;
    for(int i=0; i<n; i++){
        if(i == 0) d = findMaxTime(path[i], NULL);
        else d = i + findMaxTime(path[i], path[i-1]);
        mx = max(mx, d);
    }
    return mx-1;
}
