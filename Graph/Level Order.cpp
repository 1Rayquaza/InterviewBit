vector<vector<int> > Solution::levelOrder(TreeNode* A) {
    // Tree q. - level order traversal/BFS   
    queue<TreeNode* > q;
    q.push(A);
    q.push(NULL); // for flagging ki kbb level push krna h
    vector<int> v;
    vector<vector<int>> ans;
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        if(tmp != NULL){
            v.push_back(tmp->val);
            if(tmp->left)  q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        
        else if(tmp == NULL){
            ans.push_back(v);
            v.clear();
            if(!q.empty()) q.push(NULL);
        }
    }
    
    return ans;
}