TreeNode* build(vector<int> &A, int s, int e){
    if(s > e) return NULL;
    int mx = INT_MIN;
    int idx = -1;
    
    for(int i=s; i<=e; i++){
        if(A[i]>mx){
            mx = A[i];  // get the ROOT !!
            idx = i;
        }
    }
    
    TreeNode* root = new TreeNode(mx);
    root->left =  build(A, s, idx-1);
    root->right = build(A, idx+1, e);
    return root;
}

TreeNode* Solution::buildTree(vector<int> &A) {
    return build(A, 0, A.size()-1);
}

// Take an eg. and ezzz : 4 5 2 '6' 3 1
// Inorder traversal : (Left tree) root (Right tree)