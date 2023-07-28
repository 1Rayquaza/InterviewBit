// Approach 1 - Greedy
int Solution::canJump(vector<int> &A) {

    int n = A.size();
    int reach = 0;

    for(int i = 0 ; i < n ; i++){
        if(reach < i){
            return 0;
        }
        reach = max(reach, i + A[i]);
    }
    
    return 1;
}

// Approach 2 - DP
bool solve(vector<int> &A, int n, vector<int> &dp){
    if(dp[n] != -1){
        return dp[n];
    }
    
    if(n <= 0){
        return dp[n] = 0;
    }
    
    if(n == 1){
        return dp[n] = 1;
    }
    
    if(A[n-1] == 0){
        return dp[n] = 0;
    }
    
    int flag = 0;
    for(int i=1; i<=A[n-1]; i++){
        if(solve(A, n-i, dp)){
            flag = 1;
            break;
        }
    }
    return dp[n] = flag;
}

int Solution::canJump(vector<int> &A) {
    int n = A.size();
    vector<int> dp(n+1, -1);
    reverse(A.begin(), A.end());
    return solve(A, n, dp);
}