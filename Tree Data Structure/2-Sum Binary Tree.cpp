int Solution::t2Sum(TreeNode* A, int B) {
    queue<TreeNode*> q;
    unordered_map<int, int> m;
    
    q.push(A);
    if(A->right == NULL && A->left == NULL) return 0;
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        int d = tmp->val;
        if(m.find(B-d) != m.end()){
            return 1;
        }
        else m[d]++;
        
        if(tmp->left)  q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
        
    }
    
    return 0;
}

/* We'll traverse the tree, for each curr node we'll look for node with val B-curr node */