int Solution::solve(const vector<int> &A) {
    int n = A.size();
    if(n==1 || n==2) return n;
    vector<vector<int>> dp(n, vector<int> (n, 2));
    unordered_map<int, int> mp;
    
    for(int curr=n-2; curr>=0; curr--){
        mp.clear();
        for(int head=n-1; head>=curr+1; head--){ // <n-1 'cause 3rd element bhi chaiye
            int x = 2*A[head] - A[curr];
            // int x = A[head]+d; !! or as above
            if(mp.find(x) != mp.end()){
                dp[curr][head] = max(1+dp[head][mp[x]], dp[curr][head]);
            }
            mp[A[head]] = head;
        }
    }
    
    int mx=INT_MIN;
    for(int i=0; i<n; i++){
        for(int j=i+1; j<n; j++){
            mx = max(mx, dp[i][j]);
        }
    }   
    return mx;
}





// LIS but with fixed d
// for [curr][d] approach +1 for the no. itself, ismei predefined nhi ho rha 1 for itself ka ct, only incrementing
