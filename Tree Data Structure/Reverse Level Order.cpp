vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    stack<int> s;
    vector<int> ans;
    
    q.push(A);
    if(A==NULL) return ans;
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        s.push(tmp->val);
        
        if(tmp->right) q.push(tmp->right);
        if(tmp->left)  q.push(tmp->left);
    }
    
    while(!s.empty()){
        ans.push_back(s.top());
        s.pop();
    }
    return ans;
}

/* We'll traverse the tree normally from root to leaf like in Level order Traversal but since we need to 
print the reverse, store values in stack then print.
This poses another issue: left ones pushed first, printed later so-
We'll push the right ones first, to have the correct order */