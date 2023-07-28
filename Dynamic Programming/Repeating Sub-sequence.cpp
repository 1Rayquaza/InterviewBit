// Repeating Sub-Sequence

int dp[101][101];

int LCS(string &A, string &B, int m, int n){
    if(m==0 || n==0) return 0;
    
    if(dp[m][n] != -1) return dp[m][n];
    
    if(A[m-1] == B[n-1] && m != n){ // m != n since we need repeating subsequence
        return dp[m][n] = 1 + LCS(A, B, m-1, n-1);
    }
    else{
        return dp[m][n] = max(LCS(A, B, m-1, n), LCS(A, B, m, n-1));
    }
}

int Solution::anytwo(string A) {
    memset(dp, -1, sizeof(dp));
    string B = A;
    int m = A.size();
    int n = B.size();
    int ans = LCS(A, B, m, n);
    // cout << ans;
    return ans >= 2 ? 1 : 0;
}
