// Recursion is NOT allowed. Stack helps to avoid recursion
 
vector<int> Solution::inorderTraversal(TreeNode* A) {
    TreeNode* curr = A;
    stack<TreeNode*> s;    
    vector<int> ans;
    
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
}


/*  Use stack for iterative approach and to void recursion
    We need to go left first, leftmost element is our first, sooo...
    Store all the left elements, top will be leftmost! the coming back on each node call the right node, 
    and repeat.
    
    if(A == NULL){
        return;
    }
    inorder(A->left, ans);
    ans.push_back(A->val);
    inorder(A->right, ans);
*/