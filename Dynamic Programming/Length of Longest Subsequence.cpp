int Solution::longestSubsequenceLength(const vector<int> &A) {
    // memset(dp, -1, sizeof(dp));
    int n = A.size();
    if(n <= 1) return n;
    
    vector<int> dp(n, 1);
    vector<int> dp2(n, 1);  // no. itself is a length 1 in a sequence
    
    // for increasing subsequence
    for(int curr=0; curr<n; curr++){
        for(int head=0; head<curr; head++){
            if(A[curr] > A[head]){
                dp[curr] = max(1+dp[head], dp[curr]);
            }
        }
    }
    
    // for decreasing subsequence
    for(int curr=n-1; curr>=0; curr--){
        for(int head=n-1; head>curr; head--){
            if(A[curr] > A[head]){
                dp2[curr] = max(1+dp2[head], dp2[curr]);
            }
        }
    }
    
    int ans = 0;
    for(int i=0; i<n; i++){
        ans = max(ans, dp[i]+dp2[i]-1);
    }
    return ans;
}

