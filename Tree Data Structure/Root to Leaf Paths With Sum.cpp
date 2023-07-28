void findingPaths(TreeNode* A, int B, vector<int> &tmp, vector<vector<int>> &ans, int sum){
    if(A == NULL) return;
    
    sum += A->val;
    tmp.push_back(A->val);
    
    // if(sum > B){
    //     tmp.pop_back();
    //     return;
    // }    NEGATIVE elements can also be there
    // jahan jahan return ho rhe hain, usse pehle change ko undo bhi krna hota hai
    
    if(A->left == NULL && A->right == NULL){
        if(sum == B){
            ans.push_back(tmp);
        }
        tmp.pop_back(); // 'cause leaf node ke case mei value nhi hat rhi normally
        return;
    }
    
    if(A->left){
        findingPaths(A->left, B, tmp, ans, sum);
    }
    if(A->right){
        findingPaths(A->right, B, tmp, ans, sum);
    }
    
    tmp.pop_back();
}
vector<vector<int> > Solution::pathSum(TreeNode* A, int B) {
    vector<int> tmp;
    vector<vector<int> > ans;
    
    findingPaths(A, B, tmp, ans, 0);
    return ans;
}
