int dp[701][701];

// Using memoisation
int solve(string &A, string &B, int m, int n){
    if(n == 0){
        return 1;
    }
    if(m == 0){
        return 0;
    }
    
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    
    if(A[m-1] == B[n-1]){
        return dp[m][n] = solve(A, B, m-1, n-1) + solve(A, B, m-1, n);
        // we cannot skip parts of B 'cause wahi toh subsequence bnana h ! "+" for all ways
    }
    else{
        return dp[m][n] = solve(A, B, m-1, n);
    }
}

int Solution::numDistinct(string A, string B) {
    memset(dp, -1, sizeof(dp));
    int m = A.size();
    int n = B.size();
    if(m < n){
        return 0;
    }
    // return solve(A, B, m, n);
    // m,n -> i,j
    int bi;
    
    // Using tabular method
    for(int j=0; j<=n; j++){
        dp[0][j] = 0; 
    }
    for(int i=0; i<2; i++){
        dp[i][0] = 1;
    }
    
    for(int i=1; i<=m; i++){
        bi = i&1;
        for(int j=1; j<=n; j++){
            if(A[i-1] == B[j-1]){
                dp[bi][j] = dp[1-bi][j-1] + dp[1-bi][j];
            }
            else{
                dp[bi][j] = dp[1-bi][j];
            }
        }
    }
    
    return dp[bi][n];
}