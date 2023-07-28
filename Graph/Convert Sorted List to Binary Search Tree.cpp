/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
 
TreeNode* build(vector<int> &nodes, int lo, int hi){
    int n = nodes.size();
    if(lo < 0 || hi >= n || lo > hi) return NULL;
    
    int mid = (lo + hi)/2;
    TreeNode* root = new TreeNode(nodes[mid]);
    root->left = build(nodes, lo, mid-1);
    root->right = build(nodes, mid+1, hi);
    
    return root;
}
 
TreeNode* Solution::sortedListToBST(ListNode* A) {
    // middle element would be root, then left part of that is left subtree, similar for right
    vector<int> nodes;
    
    ListNode* curr = A;
    while(A != NULL){
        nodes.push_back(A->val);
        A = A->next;
    }
    
    int n = nodes.size();
    TreeNode* root = build(nodes, 0, n-1);
    return root;
}
