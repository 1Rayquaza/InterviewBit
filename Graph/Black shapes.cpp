vector<vector<int>> vis;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, -1, 0, +1};
  
void dfs(int row, int col, vector<string> &A){
    vis[row][col] = 1;
    
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && A[nrow][ncol] == 'X'){
            dfs(nrow, ncol, A);
        }
    }
}  
    
    
int Solution::black(vector<string> &A) {
    int n = A.size();
    int m = A[0].size();
    
    vis.clear();
    vis.resize(n, vector<int> (m, 0));
    
    int ct = 0;
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && A[i][j] == 'X'){
                ct++;
                dfs(i, j, A);
            }
        }
    }
    return ct;
}