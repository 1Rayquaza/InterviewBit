int dp[1001][1001];

// int sum(vector<vector<int> > &A, int i, int j){
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
    
//     if(i == A.size()-1){
//         return dp[i][j] = A[i][j];
//     }
    
//     int down = A[i][j] + sum(A, i+1, j);
//     int cross = A[i][j] + sum(A, i+1, j+1);
//     return dp[i][j] = max(down, cross);  
// }

int Solution::solve(vector<vector<int> > &A) {
    // return sum(A, 0, 0);
    int n = A.size();
    
    for(int j=0; j<n; j++){
        dp[n-1][j] = A[n-1][j];
    }
    
    for(int i=n-2; i>=0; i--){
        for(int j=0; j<n; j++){
            dp[i][j] = A[i][j] + max(dp[i+1][j], dp[i+1][j+1]);
        }
    }
    return dp[0][0];
}
