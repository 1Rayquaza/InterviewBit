int dp[502][502];

bool isPalindrome(string A, int i, int j){
    while(i<j){
        if(A[i] != A[j]){
            return false;
        }
        else{
            i++;
            j--;
        }
    }
    return true;
}

int solve(string &A, int i, int j){
    if(i >= j){ // letter itself is a Palindrome so no need of partition
        return 0;
    }
    
    if(isPalindrome(A, i, j) == true){
        return 0;
    }
    
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int left, right;
        if(dp[i][k] != -1){
            left = dp[i][k];
        }
        else{
            left = solve(A, i, k);
        }
        
        if(dp[k+1][j] != -1){
            right = dp[k+1][j];
        }
        else{
            right = solve(A, k+1, j);
        }
        
        int tmp = 1 + left + right;
        if(tmp < mn){
            mn = tmp;
        }
    }
    return dp[i][j] = mn;
}

int Solution::minCut(string A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    return solve(A, 0, n-1);
}
