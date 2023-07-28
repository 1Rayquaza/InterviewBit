int m = 1e9+7;
int count(int n, int k, int target, vector<vector<int> > &dp){
    // When target is too high
    if (n*k <= target)
        return (n*k == target);
    
    // When target is  too low
    if (n >= target)
        return (n == target);

    if(dp[n][target] != -1){
        return dp[n][target];
    }
    
    if(n == 0){
        if(target == 0){
            return dp[n][target] = 1;
        }
        else return dp[n][target] = 0;
    }
    
    if(target == 0){
        return dp[n][target] = 0;
    }

    // as N dice and target sum either has some ways or no ways so for no ways initialize with 0;
    long long x1 = count(n, k, target-1, dp), x2 = count(n-1, k, target-1, dp), x3 =count(n-1, k, target-k-1, dp);
    dp[n][target] = (m + (x1%m + x2%m)%m - x3%m)%m;
    // for(int i=1; i<=k; i++){
    //     if(target >= i){
    //         dp[n][target] = (dp[n][target]%m + count(n-1, k, target-i, dp)%m)%m;
    //     }
    // }
    return dp[n][target]%m;

}

int Solution::findDiceSum(int n, int k, int target) {
    vector<vector<int> > dp(n+1, vector<int> (target+1, -1));
    return count(n, k, target, dp);
}
  
/* 
A : 226
B : 607
C : 809

The expected return value: 
237985022 
*/ 
