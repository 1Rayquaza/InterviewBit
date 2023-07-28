/* We need level wise no.s so do Level order traversal, similar to vertical order traversal
Start from root, go right: slope remains same so same line, go left then change line -1, and so on
Making diagrams makes things easier hehe

Test case failed tells that we need to do this in a Preorder manner :)
*/
void Preorder(TreeNode* A, int line, map<int, vector<int>> &m){
    if(A == NULL) return;
    m[line].push_back(A->val);
    
    Preorder(A->left, line+1, m);
    Preorder(A->right, line, m);
}

vector<int> Solution::solve(TreeNode* A) {
    map<int, vector<int>> m;
    vector<int> ans;
    Preorder(A, 0, m);
    
    for(auto x: m){
        for(auto it: x.second){
            ans.push_back(it);
        }
    }
    return ans;
}
