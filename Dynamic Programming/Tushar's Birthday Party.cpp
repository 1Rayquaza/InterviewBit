int dp[1001][1001];

int knapsack(const vector<int> &val, const vector<int> &wt, int C, int n){
    if(n == 0){
        if(C%wt[0] == 0){
            return (C/wt[0])*val[0];
        }
        else{
            return 1e9;
        }
    }
    
    if(dp[n][C] != -1){
        return dp[n][C];
    }
    
    int not_take = knapsack(val, wt, C, n-1);
    int take = 1e9;
    if(wt[n-1] <= C){
        take = val[n-1] + knapsack(val, wt, C-wt[n-1], n);
    }
    
    return dp[n][C] = min(take, not_take);
}

int Solution::solve(const vector<int> &A, const vector<int> &wt, const vector<int> &val) {
    memset(dp, -1, sizeof(dp));
    int n = A.size();
    int m = wt.size();
    // Unbounded knapsack but multiple times i.e. for all of tushar's frinds and minimizing the value
    // similar to coin problem
    // B is weight array, C is val array; min(val) ??
    int minCost = 0;
    int capacity, cost;
    for(int i=0; i<n; i++){
        capacity = A[i];
        cost = knapsack(val, wt, capacity, m); // (wt, val) -> (dish, cost) -> (B, C)
        minCost += cost;
    }
    
    return minCost;
}

// Coin change problem, but minimizing the cost attached to each coint(there ct=1 was the cost, here different)
// 