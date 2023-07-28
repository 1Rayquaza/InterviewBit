int Solution::kthsmallest(TreeNode* A, int B) {
    priority_queue<int> maxH;
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        maxH.push(tmp->val);
        if(maxH.size() > B){
            maxH.pop();
        }
        
        if(tmp->left)  q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    
    return maxH.top();
}

/* we can use heap ?? kth smallest -> max heap(big elements will be discarded) 
Traverse the entire tree then return the top element after the full traversal*/
