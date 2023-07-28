int dp[1001][1001];

int solve(vector<vector<int> > &A, int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(i == A.size()-1){
        return dp[i][j] = A[i][j];
    }
    
    int down = A[i][j] + solve(A, i+1, j);
    int cross = A[i][j] + solve(A, i+1, j+1);
    
    return dp[i][j] = min(down, cross);  
}


int Solution::minimumTotal(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    if(n==1) return A[0][0];
    return solve(A, 0, 0);
}
