// int solve(vector<vector<int> > &A, int m, int n, vector<vector<int> > &dp){
//     if(m == 0 && n == 0) return 0;
//     if(m == 1 && n == 1){
//         return A[0][0];
//     }
    
//     if(dp[m][n] != -1){
//         return dp[m][n];
//     }
    
//     int left = INT_MAX, up = INT_MAX;
//     if(m == 1){
//         left = A[m-1][n-1] + solve(A, m, n-1, dp);    // can only go left
//     }
//     else if(n == 1){
//         up = A[m-1][n-1] + solve(A, m-1, n, dp);
//     }
//     else{
//         left = A[m-1][n-1] + solve(A, m, n-1, dp);
//         up = A[m-1][n-1] + solve(A, m-1, n, dp);
//     }
    
//     return dp[m][n] = min(left, up);
// }

int Solution::minPathSum(vector<vector<int> > &A) {
    int m = A.size();
    int n = A[0].size();
    vector<vector<int> > dp(3, vector<int> (n+1, -1));
    // return solve(A, m, n, dp);
    // (m, n) -> (i, j)
    
    dp[0][0] = 0;
    int bi;
    for(int i=1; i<=m; i++){
        bi = i&1;
        for(int j=1; j<=n; j++){
            if(i == 1 && j == 1){
                dp[bi][j] = A[0][0];
            }
            else if(i == 1){
                dp[bi][j] = A[i-1][j-1] + dp[bi][j-1];
            }
            else if(j == 1){
                dp[bi][j] = A[i-1][j-1] + dp[1-bi][j];
            }
            else{
                dp[bi][j] = A[i-1][j-1] + min(dp[bi][j-1], dp[1-bi][j]);
            }
        }
    }
    return dp[bi][n];
}
