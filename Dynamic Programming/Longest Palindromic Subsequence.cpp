// Memoization approach
int dp[1006][1006];

int Solution::solve(string A) {
    memset(dp, -1, sizeof(dp));
    // Longest Palindromic Subsequence would be LCS of A and reverse A ezzzz
    string Ar = A;
    reverse(Ar.begin(), Ar.end());
    int m = A.size();
    int n = Ar.size();
    
    for(int i=0; i<=m; i++){
        for(int j=0; j<=n; j++){
            if(i == 0 || j == 0) dp[i][j] = 0;
            else{
                if(A[i-1] == Ar[j-1])   dp[i][j] = 1 + dp[i-1][j-1];
                else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
            }
        }
    }
    
    return dp[m][n];
}
