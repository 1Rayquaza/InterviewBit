TreeNode* build(const vector<int> &A, int lo, int hi){
    if(lo > hi) return NULL;   // base condition

    int mid = (lo + hi)/2;  // get the middle element and make it root    
    TreeNode* tmp = new TreeNode(A[mid]);
    
    // Hypothesis(jo fn. kaam kr rha hai, indirectly making inputs smaller)
    tmp->left  = build(A, lo, mid-1);   // recursively make left subtree
    tmp->right = build(A, mid+1, hi);   // recursively make right subtree
    
    return tmp; // Induction
}
TreeNode* Solution::sortedArrayToBST(const vector<int> &A) {
    return build(A, 0, A.size()-1);
}

/* need to convert an array into /\ binart tree with equal or atmost 1 level differene i.e. simply dividing 
in half and forming tree - Binary search to the rescue 
************ Trust Recursion !!! Let it do the magic !! ************
*/
