void findPath(TreeNode* A, int num, vector<int> &tmp, vector<int> &ans){
    if(A == NULL) return;
    
    tmp.push_back(A->val);
    if(A->val == num){
        ans = tmp;
        return;
    }
    
    if(A->left)  findPath(A->left,  num, tmp, ans);
    if(A->right) findPath(A->right, num, tmp, ans);
    // fn. ek hi baar call hua h, return hokr uspr aa rhe hain so TC: O(N) 'cause 1 node pr 1 hi baar ja rhe
    // 2 paths hain so SC: O(h) 'cause height jitna max. store hoga ek baar mei
    tmp.pop_back(); // dry run to understand better, jbb pb unconditionally kiya toh pop conditionally y
}

int Solution::lca(TreeNode* A, int B, int C) {
    vector<int> t1;
    vector<int> pB;
    findPath(A, B, t1, pB);
    
    vector<int> t2;
    vector<int> pC;
    findPath(A, C, t2, pC);
    
    // root to lca nodes same rhenge, so mismatch hone ke pehle waala node will be answer
    // what about direct descendent ?       3, 5 and 3, 5, 2
    if(pC.size()!=0 && pB.size()!=0){
        int i;
        for(i=0; i<pB.size() && i<pC.size(); i++){
            if(pB[i] != pC[i]){
                break;
            }
        }
        return pB[i-1]; // whether or not the pB[i] exists, pB[i-1] will return
    }
    return -1;
}

/* It's not guaranteed that the values exist so we need to verify first, or, find them first
We need the deepest node which has both B and C as it's descendents
If one is a direct descendent of the other, first one would be the answer

if we find the path from nodes to root, first common node in the path is LCA sooo
- find path for both nodes and store in vector
- Traverse both until values are same(can use a map :/ )

How to find paths ??? how to traverse ?
*/
