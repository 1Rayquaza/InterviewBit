int dp[20001];

int sum(vector<vector<int> > &A, int j){ 
    //cout<<i<<" "<<j<<";";
    if(j >= A[0].size()){
        return 0;
    }
    
    if(j == A[0].size()-1){
        return dp[j] = max(A[0][j], A[1][j]);
    }
    
    if(dp[j] != -1){
        return dp[j];
    }
    
    int take = max(A[0][j], A[1][j]) + sum(A, j+2);
    int not_take = sum(A, j+1);
    return dp[j] = max(take, not_take);
}

int Solution::adjacent(vector<vector<int> > &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = A[0].size();
    return sum(A, 0);
}
