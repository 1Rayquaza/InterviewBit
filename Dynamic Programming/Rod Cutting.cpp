vector<vector<long long>> dp;
vector<vector<int>> v;

void path(vector<int> &B, vector<int> &ans, int i, int j){
    int k = v[i][j];
    
    if((j-i) <= 1 || k==-1){
        return;
    }
    
    ans.push_back(B[k]);
    
    path(B, ans, i, k);
    path(B, ans, k, j);
}

long long solve(vector<int> &B, int i, int j){
    if((j-i) <= 1){
        return 0;
    }
    // 'cause ab indices le rhe toh 1 index diff. mtlb no partitions in-between
    
    if(dp[i][j] != -1){
        return dp[i][j];
    }
    
    long long mn = LONG_MAX;
    for(int k=i+1; k<=j-1; k++){ // jth index chor kr
        // starting and last index of B are for length calculations
        long long cost = 1ll*(B[j]-B[i]) + solve(B, i, k) + solve(B, k, j);
        if(cost < mn){
            mn = cost;
            v[i][j] = k;    // for path
        }
    }
    
    return dp[i][j] = mn;
}

vector<int> Solution::rodCut(int A, vector<int> &B) {
    B.insert(B.begin(), 0); // A is 1e9 !! so need to do with B only, but need length too sooo- :D
    B.push_back(A);     // hehehehehe
    int n = B.size();
    
    dp.clear();
    dp.resize(n, vector<long long> (n, -1));
    
    v.clear();
    v.resize(n, vector<int> (n, -1));
        
    long long cost = solve(B, 0, n-1);
    // cout << cost << " ";
    
    vector<int> ans;
    path(B, ans, 0, n-1);
    return ans;
}
