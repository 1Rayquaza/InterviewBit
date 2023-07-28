int dp[2][50001];

// int ways(vector<int> &A, int sum, int n, int m){
//     if(n == 0){
//         if(sum == 0){
//             return 1;   // 1 way to make sum 0 ! (i.e. 0 coins)
//         }
//         else return 0;
//     }
    
//     if(dp[n][sum] != -1){
//         return dp[n][sum];
//     }
    
//     if(A[n-1] <= sum){
//         return dp[n][sum] = (ways(A, sum-A[n-1], n, m)%m + ways(A, sum, n-1, m)%m)%m;
//     }
//     else{
//         return dp[n][sum] = ways(A, sum, n-1, m)%m;
//     }
// }

int Solution::coinchange2(vector<int> &A, int B) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = 1e6+7;
    // return ways(A, B, n, m);
    
    for(int j=0; j<=B; j++){
        dp[0][j] = 0;
    }
    for(int i=0; i<2; i++){ // ab bss 2 rows hai !! as only that is required
        dp[i][0] = 1;
    }
    
    int bi;
    for(int i=1; i<=n; i++){
        bi = i&1;
        for(int j=1; j<=B; j++){
            if(A[i-1] <= j){
                dp[bi][j] = ((dp[bi][j-A[i-1]])%m + (dp[1-bi][j])%m)%m;
            }
            else{
                dp[bi][j] = dp[1-bi][j]%m;
            }
        }
    }
    
    return dp[bi][B];
}


