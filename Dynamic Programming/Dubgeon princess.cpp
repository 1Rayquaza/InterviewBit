vector<vector<int>> dp;

int solve(int i, int j, vector<vector<int> > &A){
    int m=A.size();
    int n=A[0].size();
    
    if(i>=m || j>=n){
        return INT_MIN;
    }
    
    int ans = 0;
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(i == m-1 && j == n-1){
        return dp[i][j] = min(0, A[i][j]);
    }
    
    ans = min(0, A[i][j]+max(solve(i+1, j, A), solve(i, j+1, A)));  // +ve health ke liye 0 reqd.
                      // max mtlb km -ve hua !!!!! ufff
    return dp[i][j] = ans;
}


int Solution::calculateMinimumHP(vector<vector<int> > &A) {
    int m=A.size();
    int n=A[0].size();
    
    dp.clear();
    dp.resize(m+1, vector<int> (n+1, -1));
    
    int ans = solve(0, 0, A);
    // If at any point his health point drops to 0 or below, he dies immediately.
    // abs(worst -ve) + 1 
    return abs(ans) + 1;
}
