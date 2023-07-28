int dp[451][451];

int LCS(string &A, string &B, int m, int n){
    if(m == 0) return n;    // deleted extra
    if(n == 0) return m;    // insert reqd.
    
    if(dp[m][n] != -1) return dp[m][n];
    
    if(A[m-1] == B[n-1]){
        return dp[m][n] = LCS(A, B, m-1, n-1);  // no operation needed, No +1(op.) reqd.
    }
    else{
        int mn = min( LCS(A, B, m, n - 1), LCS(A, B, m - 1, n)); // insert and delete operation
        return dp[m][n] = 1 + min(mn, LCS(A, B, m - 1, n-1));   // Replace operation
        // return dp[m][n] = max(LCS(A, B, m-1, n), LCS(A, B, m, n-1));
    }
}

int Solution::minDistance(string A, string B) {
    memset(dp, -1, sizeof(dp));
    int m = A.size();
    int n = B.size();
    return LCS(A, B, m, n);
}
