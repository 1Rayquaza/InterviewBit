vector<vector<int> > dp;
int solve(string A, int S, int i, int j){
    if(i == j){
        if(S == 0) return 0;
        else return INT_MAX;
    }
    
    if(dp[i][S] != -1){
        return dp[i][S];
    }
    
    if(S == 0){
        if(i < j){
            int b=0, w=0;
            for(int k=i; k<=j; k++){
                if(A[k] == 'W') w++;
                else b++;
            }
            return dp[i][S] = (b*w);
        }
        else return dp[i][S] = INT_MAX;
    }
    
    // i to j ke liye fn. to ct B/W and have cost
    int mn = INT_MAX;
    int cb=0, cw=0;
    for(int k=i; k<=j-1; k++){
        if(A[k] == 'W') cw++;
        else cb++;
        
        int cost = cb*cw;
        int tmp = solve(A, S-1, k+1, j); // k+1 'cause agla jaanwar; S-1 to take care of stable ct
        if(tmp!=INT_MAX && ((tmp+cost) < mn)){
            mn = tmp+cost;
        }
    }
    return dp[i][S] = mn;
}

int Solution::arrange(string A, int S) {
    dp.clear();
    int n = A.size();
    dp.resize(n, vector<int> (S, -1));
    int ans=solve(A, S-1, 0, n-1);
    return (ans==INT_MAX)?-1:ans;
}
