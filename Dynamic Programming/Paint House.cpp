int dp[3][100001];

int minCost(vector<vector<int> > &A, int prev, int n){
    if(n == 0){
        return 0;
    }
    
    int mn = INT_MAX;
    
    if(prev != -1 && dp[prev][n] != -1){
        return dp[prev][n];
    }
    
    for(int i=0; i<=2; i++){
        if(i != prev){
            int cost = A[n-1][i] + minCost(A, i, n-1);
            mn = min(mn, cost);
        }
    }
    if(prev == -1) return mn;
    return dp[prev][n] = mn;
}

int Solution::solve(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    return minCost(A, -1, n);
}
