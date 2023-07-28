int dp[37];

int solve(int A){
    if(A == 0) return 1;
    if(A == 1) return 1;
    
    if(dp[A] != -1){
        return dp[A];
    }
    
    if(A >= 2){
        return dp[A] = solve(A-2) + solve(A-1);
    }
}

int Solution::climbStairs(int A) {
    memset(dp, -1, sizeof(dp));
    if(A == 1){
        return 1;
    }
    return solve(A);
}
