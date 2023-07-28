vector<vector<long long> > dp;
int m = 1e9+7;
int count(int n, int sum){
    if(n == 0 && sum == 0) return 1;
    if(n == 0 || sum == 0) return 0;
    
    if(9*n < sum) return 0;
    
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    
    int res = 0;
    for(int i=0; i<=9; i++){    // careful about 0 !! should NOT be leading
        if(n == 1 && i == 0) continue;
        
        if(sum >= i){
            if(count(n-1, sum-i)){
                res = (res + count(n-1, sum-i))%m;
            }
        }
        
        else{
            break;
        }
    }
    return dp[n][sum] = res;
}

int Solution::solve(int n, int sum) {
    dp.clear();
    dp.resize(n+1, vector<long long> (sum+1, -1));
    if(9*n < sum) return 0;
    return count(n, sum); 
}

// long long n1 = 1e(n-1);
// long long n2 = 1en - 1;
// TOO BIG no.s. can happen !! traverse digit-wise n-times hehe Ezz
