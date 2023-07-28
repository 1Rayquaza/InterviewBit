TreeNode* Solution::solve(TreeNode* A) {
    if(A == NULL) return NULL;
    if(A->left == NULL && A->right == NULL){
        return A;
    }
    
    if(A->left == NULL){
        return solve(A->right);
    }
    
    if(A->right == NULL){
        return solve(A->left);
    }
    
    A->left = solve(A->left);
    A->right = solve(A->right);
    
    return A;
}

/* Half nodes are nodes which have only one child. Use condition but how to remove ?
We need to remove from in-between levels as well

How to remove ?? i.e. how to connect while skipping a node ??
Post order traversal ? process left and right children then the node itself ***

jbb tree mei change krna hai toh address se pass hoga na T_T

The idea is to use post-order traversal
First process the left children, then right children, and finally the node itself.
So we form the new tree bottom up, starting from the leaves towards the root.
By the time we process the current node, both its left and right subtrees were already processed.

TC: O(N) as it does a simple traversal of binary tree.
SC: O(1)
*/