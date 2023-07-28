int dp[151][151];

int LCS(string &s, string &C, int m, int n){
    if(m==0 || n==0){
        return 0;
    }
    
    if(dp[m][n] != -1){
        return dp[m][n];
    }
    
    if(s[m-1] == C[n-1]){
        return dp[m][n] = 1 + LCS(s, C, m-1, n-1);
    }
    else{
        return dp[m][n] = max(LCS(s, C, m, n-1), LCS(s, C, m-1, n));
    }
}

int Solution::isInterleave(string A, string B, string C) {
    memset(dp, -1, sizeof(dp));
    int m = C.size();
    int n1 = A.size();
    int n2 = B.size();
    
    int a = LCS(C, A, m, n1);
    int b = LCS(C, B, m, n2);
    if(a+b == m) return 1;
    else return 0;
}
