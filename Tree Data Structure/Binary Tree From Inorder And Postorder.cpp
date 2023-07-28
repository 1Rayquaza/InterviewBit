TreeNode* construct(vector<int> &ino, vector<int> &post, int postIdx, int inS, int inE, unordered_map<int, int> &m){
    if(inS > inE){
        return NULL;
    }
    if(postIdx < 0){
        return NULL;
    }
    
    TreeNode* root = new TreeNode(post[postIdx]);
    if(inS == inE){
        return root;
    }
    
    int rootIdx = m[root->val];
    int ct = (inE - rootIdx + 1);
     
    root->left = construct(ino, post, postIdx-ct, inS, rootIdx-1, m);
    root->right = construct(ino, post, postIdx-1, rootIdx+1, inE, m);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A, vector<int> &B) {
    int n = A.size();
    
    unordered_map<int, int> m;
    for(int i=0; i<n; i++){
        m[A[i]] = i;
    }
    
    return construct(A, B, n-1, 0, n-1, m);
}
