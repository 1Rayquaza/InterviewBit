
int Solution::lastNode(TreeNode* A) {
    queue<TreeNode*> q;
    q.push(A);
    int rm;
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        rm = tmp->val;
        
        if(tmp->left)  q.push(tmp->left);
        if(tmp->right) q.push(tmp->right);
    }
    return rm;
}

/* We need to find the rightmost leaf, keep going right until hit with NULL WAITTTTTTT AAAAAA
We need to find the rightmost node in the ***last level*** of the binary tree i.e. it may lie on either side 
Last level - rightmost node value :/ 
*** Level order Traversal to the rescue, rightmost of last level will come in the end */