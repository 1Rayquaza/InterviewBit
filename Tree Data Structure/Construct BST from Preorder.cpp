TreeNode* Solution::constructBST(vector<int> &A) {
    stack<TreeNode*> s;
    TreeNode* root = new TreeNode(A[0]);
    TreeNode* ans = root;
    s.push(root);
    
    for(int i=1; i<A.size(); i++){
        TreeNode* prev = NULL;
        
        while(!s.empty() && s.top()->val <= A[i]){
            prev = s.top(); // if a greater ele is found, we need to see where it belongs
            s.pop();
        }
        
        TreeNode* curr = new TreeNode(A[i]);
        if(prev != NULL) prev->right = curr;
        else s.top()->left = curr; 
        s.push(curr);
    }
    return ans;
}

/* NSR is root->left, NGR is root->right. However, bounded by the NGR of first element

jbtk smaller ho rha h left jaate rehna h, greater milne pr biggest smaller ele ka ->right
howww ???
*/
