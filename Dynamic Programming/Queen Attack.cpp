vector<pair<int, int>> v;
vector<vector<int> > ans;
vector<vector<vector<int>>> dp;

bool isVaild(int i, int j, int n, int m){
    return (i>=0 && j>=0 && j<m && i<n);
}

int solve(vector<string> &A, int i, int j, int k){
    int x = i + v[k].first;
    int y = j + v[k].second;
    
    if(!isVaild(x, y, A.size(), A[0].size())){
        return 0;
    }
    
    if(dp[i][j][k]!=-1){
        return dp[i][j][k];
    }
    
    if(A[x][y]=='1'){
        return dp[i][j][k] = 1;
    }
    
    else{
        return dp[i][j][k] = solve(A, x, y, k);
    }
    
}

vector<vector<int> > Solution::queenAttack(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    ans.clear();
    ans.resize(n, vector<int> (m, 0));
    
    dp.clear();
    dp.resize(n, vector<vector<int>> (m, vector<int> (8,-1)));
    
    v = {{0,1}, {1,0}, {1,1}, {1,-1}, {-1,1}, {-1,-1}, {0,-1}, {-1,0}};
    
    for(int k=0; k<8; k++){
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                ans[i][j] +=solve(A, i, j, k);
            }
        }
    }
    
    return ans;
}
