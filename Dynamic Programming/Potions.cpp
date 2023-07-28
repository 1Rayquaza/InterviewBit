int dp[101][101];
vector<int> prefix;
int m = 100;

int merge2P(int i, int j, int k, vector<int> &A){
    int c1 = A[i], c2 = A[j];
    
    if(i >= 1) c1 = (prefix[k] - prefix[i-1])%m;
    else c1 = prefix[k]%m;
        
    if(k >= 0) c2 = (prefix[j] - prefix[k])%m;
    else c2 = prefix[j]%m;    
        
    return c1*c2;
}

int solve(vector<int> &A, int i, int j){
    if(j-i == 1){
        return A[i]*A[j];
    }
    if(i >= j){
        return 0;   // element is same !  
    }
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    int mn = INT_MAX;
    for(int k=i; k<=j-1; k++){
        int smoke = solve(A, i, k) + solve(A, k+1, j);
        smoke += merge2P(i, j, k, A);
        if(smoke < mn){
            mn = smoke;
        }
    }
    return dp[i][j] = mn;
}

int Solution::minSmoke(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    
    prefix.clear();
    prefix.resize(n, 0);
    prefix[0] = A[0];
    for(int i=1; i<n; i++){
        prefix[i] = A[i] + prefix[i-1];
        // cout << prefix[i] << " ";
    }
    
    return solve(A, 0, n-1);
}
