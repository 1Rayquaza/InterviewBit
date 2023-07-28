
int Solution::solve(vector<vector<int> > &A) {
    vector<int> dp(1001, 1);
    // memset(dp, 1, sizeof(dp));
    int n = A.size();
    
    for(int curr=n-1; curr>=0; curr--){
        for(int head=n-1; head>curr; head--){
            if(A[curr][1] < A[head][0]){
                dp[curr] = max(1+dp[head], dp[curr]);
            }
        }
    }
    
    return *max_element(dp.begin(), dp.end());
}
