TreeNode* Solution::invertTree(TreeNode* A) {
    if(A == NULL) return A;
    
    TreeNode* l = A->left;
    TreeNode* r = A->right;
    A->left = invertTree(r);
    A->right = invertTree(l);
    return A;
}

/* We need to reverse all levels hehe, make queue, traverse levels and store its reverse WAITTTT
we're not printing reverse BUT we NEED TO reverse it fr hmmm
Let's traverse each node and reverse it's left and right child by level order traversal


TreeNode* Solution::invertTree(TreeNode* A) {
    if(A->left == NULL && A->right == NULL) return A;
    queue<TreeNode*> q;
    q.push(A);
    
    while(!q.empty()){
        TreeNode* tmp = q.front();
        q.pop();
        
        if(tmp->left)  q.push(tmp->left);
        else tmp->left == NULL;
        if(tmp->right) q.push(tmp->right);
        else tmp->right == NULL;
        swap(tmp->left, tmp->right);
    }
    return A;
}

*/