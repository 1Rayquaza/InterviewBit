int static dp[102][100002];

bool check(vector<int> &A, int B, int n){
    if(n == 0 && B == 0) return 1;  // empty subset can have zero sum
    
    if(B == 0) return 1;
    
    if(n == 0) return 0;
    
    if(dp[n][B] != -1){
        return dp[n][B];
    }
    
    if(A[n-1] <= B){
        return dp[n][B] = check(A, B-A[n-1], n-1) || check(A, B, n-1);
    }
    else if(A[n-1] > B){
        return dp[n][B] = check(A, B, n-1);
    }
}

int Solution::solve(vector<int> &A, int B) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    return check(A, B, n);
}
