void solve(vector<int> A, vector<int> tmp, set< vector<int>> &ans, int i){  // no &A WHY?
// we need the updated, smaller input A since v1, v2 are taking care of the erased element
    if(i == A.size()){  
        ans.insert(tmp);
        return;
    }
    vector<int> v1 = tmp;
    vector<int> v2 = tmp;
    
    // excluding the ith element
    solve(A, v1, ans, i+1);
    
    // including the ith element
    v2.push_back(A[i]);
    solve(A, v2, ans, i+1);
    v2.pop_back();
    return;
}

// Using recursion to approach this problem

vector<vector<int> > Solution::subsetsWithDup(vector<int> &A) {
    int n=A.size();
    sort(A.begin(), A.end());   // to ensure that the elements of subset are in non-descending order as 
                                // elements will be considered in ascending order
    
    set< vector<int>> ans;
    vector<int> tmp;    // for creating subsets
    solve(A, tmp, ans, 0);
    vector<vector<int>> finalAns(ans.begin(), ans.end());
    return finalAns;
    
}
