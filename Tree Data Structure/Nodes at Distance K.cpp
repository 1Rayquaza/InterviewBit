void findNode(TreeNode* apex, int d, TreeNode* prev, vector<int> &ans){
    if(apex == NULL) return;
    if(d == 0){
        ans.push_back(apex->val);
        return;
    }
    
    if(apex->left == prev){
        findNode(apex->right, d-1, prev, ans);
    }
    else if(apex->right == prev){
        findNode(apex->left, d-1, prev, ans);
    }
    else{
        findNode(apex->right, d-1, prev, ans);
        findNode(apex->left, d-1, prev, ans);
    }
}

void findPath(TreeNode* A, int B, vector<TreeNode*> &tmp, vector<TreeNode*> &path){
    if(A == NULL) return;
    
    tmp.push_back(A);
    if(A->val == B){
        reverse(tmp.begin(), tmp.end());    // path from B to root
        path = tmp;
        return;
    }
    
    findPath(A->left,  B, tmp, path);
    findPath(A->right, B, tmp, path);
    
    tmp.pop_back();
}

vector<int> Solution::distanceK(TreeNode* A, int B, int C) {    
    vector<TreeNode*> tmp;
    vector<TreeNode*> path;
    findPath(A, B, tmp, path);  
    
    vector<int> ans;
    int n = path.size();
    for(int i=0; i<n; i++){
        if(i == 0) findNode(path[i], C, NULL, ans);
        else findNode(path[i], C-i, path[i-1], ans);
    }
    return ans;
}