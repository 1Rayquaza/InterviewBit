vector<vector<int> > dp;

int square(vector<vector<int> > &A, int i, int j){
    if(i == 0 || j == 0){
        return A[i][j];
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int mn = INT_MAX;
    mn = min(min(square(A, i-1, j), square(A, i, j-1)), square(A, i-1, j-1));
    if(A[i][j] == 1){
        return dp[i][j] = 1 + mn;
    }
    else{
        return dp[i][j] = 0;
    }
}

int Solution::solve(vector<vector<int> > &A) {
    // memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = A[0].size();
    dp.clear();
    dp.resize(n+1, vector<int> (m+1, -1));
    square(A, n-1, m-1);
    int mx = INT_MIN;
    for(int i=0; i<=n; i++){
        for(int j=0; j<=m; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    return (mx*mx);
}
