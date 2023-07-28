void find(TreeNode* A, vector<int> &v, TreeNode* &prev){
    if(A == NULL) return;
    
    // L N R
    find(A->left, v, prev);
    
    if(prev && A->val < prev->val){
        v.push_back(prev->val);
        v.push_back(A->val);
    }
    
    prev = A;
    
    find(A->right, v, prev);
}

vector<int> Solution::recoverTree(TreeNode* A) {
    vector<int> v;
    TreeNode* prev = NULL;
    find(A, v, prev);
    return {min(v[0], v[v.size()-1]), max(v[0], v[v.size()-1])};
}

/* Inorder T(inc. order for BST): \ \ is where swapped elements lie - O(N) space soln.
For constant space - draw diagram of e.g. input and multiple cases for clarification
We'll get atmost 2 places with flaw, so store prev and curr for finding ans

Inorder mei prev is left, curr is Node: prev is Node, curr is right
In both cases, curr > prev
*/