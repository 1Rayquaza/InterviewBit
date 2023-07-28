int dp[501][501];

int solve(vector<int> &A, int i, int j){
    if(i>j){
        return 0;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    // I need not select the max. value but I'll surely be left with min. to select by the opponent
    int w1 = A[i] + min(solve(A, i+1, j-1), solve(A, i+2, j));
    int w2 = A[j] + min(solve(A, i+1, j-1), solve(A, i, j-2));
    
    return dp[i][j] = max(w1, w2);
}

int Solution::maxcoin(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    return solve(A, 0, n-1);
}

// You can assume that opponent is clever and plays optimally.