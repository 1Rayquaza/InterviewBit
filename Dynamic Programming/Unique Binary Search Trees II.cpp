int Solution::numTrees(int A) {
    int dp[A+1];
    memset(dp, 0, sizeof(dp));  // initialize with 0 !! ct chaiye 
    
    dp[0] = 1;
    dp[1] = 1;
    
    for(int i=2; i<=A; i++){
        for(int j=0; j<i; j++){
            dp[i] += (dp[j]*dp[i-1-j]);
        }
    }
    
    return dp[A];
}
