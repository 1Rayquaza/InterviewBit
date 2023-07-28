int static dp[101][100001]; // sum, min ct of elements

int minCount(const vector<int> &A, int sum, int n){
    if(n == 0) return INT_MAX-1;
    if(sum == 0) return 0;
    // Careful about order of base conditions
    if(n == 1){
        if(sum == A[0]) return 1;
        else return INT_MAX-1;
    }
    
    if(dp[n][sum] != -1) return dp[n][sum];
    
    if(A[n-1] <= sum){
        return dp[n][sum] = min(1 + minCount(A, sum-A[n-1], n-1), minCount(A, sum, n-1));    // 1+ for including coin
    }
    else{
        return dp[n][sum] = minCount(A, sum, n-1);
    }
}

bool subsetSumPresent(const vector<int> &A, int sum, int n){
    if(sum == 0) return 1;  // empty subset !
    if(n == 0) return 0;    
    
    if(dp[n][sum] != -1){
        return dp[n][sum];
    }
    
    if(A[n-1] <= sum){
        return dp[n][sum] = (subsetSumPresent(A, sum-A[n-1], n-1) || subsetSumPresent(A, sum, n-1));
    }
    else{
        return dp[n][sum] = subsetSumPresent(A, sum, n-1);
    }
}

int Solution::solve(const vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    
    int n = A.size();
    int range = 0;
    for(int i=0; i<n; i++){
        range += A[i];
    }
    
    vector<bool> v;
    for(int sum=0; sum<=range; sum++){
        bool b = subsetSumPresent(A, sum, n);
        v.push_back(b);
    }
    
    // Now we have the valid subset sums, find min
    int mn = INT_MAX;
    int d;
    for(int i=0; i<=range/2; i++){
        if(v[i] == 1){
            d = (range - 2*i);
            mn = min(mn, d);
        }
    }
    
    int ssmin = (range - d)/2; // Now I've to see how to get ssmin with min. count of elements
    // cout << ssmin << " ";
    
    memset(dp, -1, sizeof(dp));  
    return minCount(A, ssmin, n);   
}

/* min(S2 - S1) = ? -> min(Range - 2*S1)
no. of elements in S1(since that + needs to be flipped to -)
Min. subset diff. + Coin change problem || 

If ans comes out to be 0/1 when it should be more, check if value is not being updated 
*/ 