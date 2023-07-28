void solve(int &n, vector<int> &ans, int i, int A){
    if(i < 0){
        ans.push_back(n);
        return;
    }
        
    solve(n, ans, i-1, A);
    
    n = n^(1<<i);
    solve(n, ans, i-1, A);
    // n = n^(1<<i);    why did removing the backtracking step worked ?? 
    // 'cause
}

vector<int> Solution::grayCode(int A) {
    vector<int> ans;
    int n = 0;
    int i = A-1;
    solve(n, ans, i, A);
    return ans;
}

// we got a choice at every step, to change the particular bit, or skip it
// Toggle(use XOR operation):  a^(1<<i)    
// Submitted on LeetCode so okayyy