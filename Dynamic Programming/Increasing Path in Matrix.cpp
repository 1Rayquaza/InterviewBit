int dp[1001][1001];

bool path(vector<vector<int> > &A, int i, int j){
    if(i == 0 && j == 0){
        return dp[i][j] = 1;
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    bool left = 0, up = 0;
    if(i == 0){
        if(A[i][j-1] < A[i][j])
            left = path(A, i, j-1);
    }
    else if(j == 0){
        if(A[i-1][j] < A[i][j])
            up = path(A, i-1, j);
    }
    else{
        if(A[i][j-1] < A[i][j])
            left = path(A, i, j-1);
        
        if(A[i-1][j] < A[i][j])
            up = path(A, i-1, j);
    }
    
    return dp[i][j] = (left || up);
}

int Solution::solve(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = A[0].size();
    int ans = path(A, n-1, m-1);
    return (ans == 0) ? -1 : (n+m-1);
}
