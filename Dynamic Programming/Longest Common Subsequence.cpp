int dp[1006][1006];

int LCS(string &A, string &B, int m, int n){
    if(m==0 || n==0) return 0;
    
    if(dp[m][n] != -1) return dp[m][n];
    
    if(A[m-1] == B[n-1]){
        return dp[m][n] = 1 + LCS(A, B, m-1, n-1);
    }
    else{
        return dp[m][n] = max(LCS(A, B, m-1, n), LCS(A, B, m, n-1));
    }
}

int Solution::solve(string A, string B) {
    memset(dp, -1, sizeof(dp));
    int m = A.size();
    int n = B.size();
    return LCS(A, B, m, n);
}
