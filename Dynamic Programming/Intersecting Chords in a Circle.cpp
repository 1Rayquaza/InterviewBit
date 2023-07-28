long long int dp[1001];

int Solution::chordCnt(int n) {
    memset(dp, 0, sizeof(dp));
    
    int m = 1e9+7;
   
    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 2;
   
    for(int i=3; i<n+1; i++){
        for(int j=0; j<i; j++){
            dp[i]=(dp[i] + (dp[i-j-1] * dp[j]))%m;
        }
    }
   
    return dp[n]%m;
}

// Catalan series, write first few values manually and OBSERVE, how we are obtaining new values from 
// old values, selecting any 2 points divides the points in smaller subsets, add all and get ans
// Ways(n) = sum[i=0 to n-1] { Ways(i)*Ways(n-i-1) }.