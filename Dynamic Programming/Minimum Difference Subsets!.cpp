int static dp[101][10001];

bool subsetSumPresent(vector<int> &A, int sum, int n){
    if(sum == 0) return 1;  // empty subset !!
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

int Solution::solve(vector<int> &A) {
    memset(dp, -1, sizeof(dp));
    
    int n = A.size();
    int range = 0;
    for(int i=0; i<n; i++){
        range += A[i];
    }
    
    vector<int> v;
    for(int sum=0; sum<=range; sum++){
        bool b = subsetSumPresent(A, sum, n);
        v.push_back(b);
    }
    
    int mn = INT_MAX;
    int d;
    for(int i=0; i<=range/2; i++){  // v.size() = range+1 hai, but we need range/2 tk so-
        if(v[i] == 1){
            d = range - 2*i;
            mn = min(mn, d);
        }
    }
    
    return mn;
}

/* S1 + S2 = range -> S2 = range - S1 -> variables reduced, find ans = min(range - 2*S1);
   sum : [0, range]; both inclusive, now I need to check for each value if present or not then simply 
   minimise using a for loop.
   
   S1 presence can be checked using subsetSumPresent problem hehe ezzz
*/

/*  If the q. is to count the number of subset with a given difference, then we'll make few changes in 
    line 36 for loop -
    
    int ct = 0
    for(int i=0; i<=range/2; i++){  // v.size() = range+1 hai, but we need range/2 tk so-
        if(v[i] == 1){
            d = range - 2*i;    // ****** this will only work for distinct elements
            if(d == givenD) ct++;
        }
    }
    
    For general case, 2 eq. (sum and diff of S1 and S2) -
    We'll obtain S1 = (givenD + Range)/2;
    The problem is reduced to finding count of subset sum
*/
