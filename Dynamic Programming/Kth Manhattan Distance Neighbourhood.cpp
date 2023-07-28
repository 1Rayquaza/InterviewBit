vector<vector<vector<int>>> dp;
vector<pair<int, int>> v;
int isValid(vector<vector<int> > &B, int i, int j){
    int n=B.size();
    int m=B[0].size();
    
    return (i<n && j<m && i>=0 && j>=0);
}

int solv(vector<vector<int> > &B, int i, int j, int k){  // max element at d == k 
    if(k == 0){
        return B[i][j];
    }
    
    int mx = INT_MIN;
    
    if(dp[i][j][k] != -1){
        return dp[i][j][k];
    }
    
    for(int z=0; z<v.size(); z++){
        int x = i + v[z].first;
        int y = j + v[z].second;
        
        if(isValid(B, x, y)){
            mx = max(mx, solv(B, x, y, k-1));
        } 
    }
    
    return dp[i][j][k] = mx;
}

vector<vector<int> > Solution::solve(int K, vector<vector<int> > &B) {
    int n=B.size();
    int m=B[0].size();
    
    dp.clear();
    dp.resize(n, vector<vector<int>> (m, vector<int> (K+1, -1)));
    
    v = {{-1,0}, {1,0}, {0,1}, {0,-1}};
    vector<vector<int>> ans(n, vector<int> (m, -1));
    if(B.empty()) return ans;
    
    for(int k=0; k<=K; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] = max(ans[i][j], solv(B, i, j, k));  // returns max ele at d<=k
            }
        }
    }
    
    return ans;
}
