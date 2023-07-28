int dp[101][101];

int path(vector<vector<int> > &A, int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(A[i][j] == 1){   // 1 means obstacle !
        return dp[i][j] = 0;
    }
    if(i==0 && j==0){
        return dp[i][j] = 1;
    } 
    
    int left = 0, up = 0;
    if(j>0 && A[i][j-1] == 0)  // up
        left = path(A, i, j-1);
    
    if(i>0 && A[i-1][j] == 0)  // left
        up = path(A, i-1, j);
        
    return dp[i][j] = left + up;
}

int Solution::uniquePathsWithObstacles(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = A[0].size();
    return path(A, n-1, m-1);
}
