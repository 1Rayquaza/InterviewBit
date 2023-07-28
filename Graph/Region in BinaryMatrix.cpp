vector<vector<int>> vis;

void dfs(int row, int col, vector<vector<int>> &A, int &c, int &ans){   // why &c and not c ?? branch miss hojayegi
    vis[row][col] = 1;
    c++;
    ans = max(ans, c);
    
    int n = A.size();
    int m = A[0].size();
    
    for(int dx=-1; dx<=1; dx++){
        for(int dy=-1; dy<=1; dy++){
            int nrow = row + dx;
            int ncol = col + dy;
            
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && !vis[nrow][ncol] && A[nrow][ncol] == 1){
                dfs(nrow, ncol, A, c, ans);
            }
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    int m = A[0].size();
    
    vis.clear();
    vis.resize(n, vector<int> (m, 0));
    
    int ans = 0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && A[i][j] == 1){
                int c = 0;
                dfs(i, j, A, c, ans);
            }
        }
    }
    
    return ans;
}
