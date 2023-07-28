int minCost(vector<int> &A, int i, int j, vector<vector<int> > &dp){
    if(i == j){ // single element -> no cost !!
        return dp[i][j] = 0; 
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int mn = INT_MAX;
    int sum = 0;
    for(int k=i; k<=j; k++){
        sum += A[k];
    }
    for(int k=i; k<=j-1; k++){
        int tmp = sum + minCost(A, i, k, dp) + minCost(A, k+1, j, dp);
        if(tmp < mn){
            mn = tmp;
        }
    }
    return dp[i][j] = mn;
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    vector<vector<int> > dp(n+1, vector<int> (n+1, -1)); 
    
    int i=0, j=n-1;
    return minCost(A, i, j, dp);
}
