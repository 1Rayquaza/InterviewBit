vector<vector<int> > dp;

int war(vector<vector<int> > &A, int i, int j){
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    if(i == A.size()-1 && j == A[0].size()-1){
        return dp[i][j] = A[i][j];
    }
    
    else if(i == A.size()-1){
        return dp[i][j] = A[i][j] + war(A, i, j+1);
    }
    
    else if(j == A[0].size()-1){
        return dp[i][j] = A[i][j] + war(A, i+1, j);
    }
    
    int tsum = war(A, i+1, j) + war(A, i, j+1) - war(A, i+1, j+1);
    return dp[i][j] = (A[i][j] + tsum);
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    dp.clear();
    dp.resize(n+1, vector<int> (m+1, -1));
    
    war(A, 0, 0);
    // index pass kiye hain, size nhi so n, m tk hi loop chalega 'cause wahin tk values update hui hain !
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            mx = max(mx, dp[i][j]);
        }
    }
    return mx;
}
