vector<int> Solution::postorderTraversal(TreeNode* A) {
    stack<TreeNode*> s;
    vector<int> ans;
    TreeNode* curr = A;
    
    while(curr != NULL || !s.empty()){
        while(curr != NULL){
            s.push(curr);
            ans.push_back(curr->val);
            curr = curr->right;
        }
        
        TreeNode* tmp = s.top();    // rightmost node in last level
        s.pop();                    
        curr = tmp->left;           // uske corresponding left waale pr aagye
                                    // if not present, pichle rm ke ek level upar ke rm, then uske left pr
    }
    
    reverse(ans.begin(), ans.end());
    return ans;
}

/* postorderTraversal - L R N

Make diagram of stack with some eg., makes things easier :p postorderT: right edge, then right-1 and so on

    Inorder Traversal - L N R
    while(curr != NULL || !s.empty()){  // *** || !
        while(curr != NULL){
            s.push(curr);
            curr = curr->left;
        }
        int d = s.top()->val;
        ans.push_back(d);
        curr = s.top()->right;
        s.pop();    // the node may have a right child so pop it later
    }
   return ans;
*/