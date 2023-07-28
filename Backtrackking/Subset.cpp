void solve(vector<int> A, vector<int> tmp, vector< vector<int>> &ans, int i){  // no &A WHY?
// we need the updated, smaller input A since v1, v2 are taking care of the erased element
    if(i == A.size()){  
        ans.push_back(tmp);
        return;
    }
    vector<int> v1 = tmp;
    vector<int> v2 = tmp;
    
    // ignored the ith element
    solve(A, v1, ans, i+1);
    
    // considered the ith element
    v2.push_back(A[i]);
    solve(A, v2, ans, i+1);
    v2.pop_back();
    return;
}

// Using recursion to approach this problem

vector<vector<int> > Solution::subsets(vector<int> &A) {
    vector< vector<int>> ans;
    vector<int> tmp;    // for creating subsets
    sort(A.begin(), A.end());   // to ensure that the elements of subset are in non-descending order as 
                                // elements will be considered in ascending order
    solve(A, tmp, ans, 0);
    sort(ans.begin(), ans.end());
    return ans;
}