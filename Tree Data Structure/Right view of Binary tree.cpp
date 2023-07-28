vector<int> Solution::solve(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    vector<int> ans;
    ans.push_back(A->val);
    
    while(!q.empty()){
        int n = q.size();
        
        while(n--){
            TreeNode* tmp = q.front();
            q.pop();
            if(tmp->left)  q.push(tmp->left);
            if(tmp->right) q.push(tmp->right);
        }
        ans.push_back(q.back()->val);
        // last level mei loop do baar chal jaa rha hai isliye ans mei 2 times push_back ho rha so just pop
    }
    ans.pop_back();
    return ans;
}

/* We need to find right view of the tree i.e. rightmost node of each level (or left node if only that exists)
Level order traversal: on each level, push all elements in queue, push the last one in ans vector hehe
*/