vector<int> Solution::preorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> ans;  
    if(A == NULL) return ans;  
    s.push(A);
    
    while(!s.empty()){
        TreeNode* tmp = s.top();
        s.pop();
        ans.push_back(tmp->val);
        
        if(tmp->right) s.push(tmp->right);
        if(tmp->left) s.push(tmp->left);   
    }
    return ans;
}

/*  preorderTraversal - NLR
    We need the node value, then left value, then right value
    push right value later, left node later, then left will be on top and it's ;left child will be dealt 
    first followed by right child and so on
*/