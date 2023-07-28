vector<vector<int> > Solution::verticalOrderTraversal(TreeNode* A) {    
    map<int, vector<int>> m;
    // traverse(A, m, 0);
    vector<vector<int>> ans;
    if(A == NULL) return ans;
    queue<pair<TreeNode*, int>> q;  // need to store line also, 'cause order maintain krna so LOT
    q.push({A, 0});
    
    while(!q.empty()){        
        TreeNode* tmp = q.front().first;
        int line = q.front().second;
        m[line].push_back(tmp->val);
        q.pop();
            
        if(tmp->left)  q.push({tmp->left, line-1});
        if(tmp->right) q.push({tmp->right, line+1});        
    }
    
    for(auto x: m){
        ans.push_back(x.second);
    }
    return ans;
}
