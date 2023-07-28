vector<int> dp;
int m = 1e9+7;

int solve(string &A, int i){
    if(i >= A.size()){
        return 1;
    }
    
    if(dp[i] != -1){
        return dp[i];
    }
    
    int ans = 0;
    if(A[i] == '0'){
        ans = 0;
    }
    
    else{   // limit is 26 only !!!
        ans += solve(A, i+1)%m; // single digit
        if(i+1 < A.size() && ((A[i] == '1') || (A[i] == '2' && A[i+1] <= '6'))){    // double| CAREFUL
            ans += solve(A, i+2)%m;
        }
    }
    return dp[i] = ans%m;
}

int Solution::numDecodings(string A) {
    int n = A.size();
    dp.clear();
    dp.resize(n+1, -1);
    return solve(A, 0);
}
