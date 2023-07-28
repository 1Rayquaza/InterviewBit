vector<vector<int>> vis;
int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, -1, 0, +1};

void dfs(int row, int col, vector<vector<char> > &A){ 
    vis[row][col] = 1;
       
    int n = A.size();
    int m = A[0].size();
        
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && A[nrow][ncol] == 'O'){
            dfs(nrow, ncol, A);
        }
    }
}

void Solution::solve(vector<vector<char> > &A) {
    int n = A.size();
    int m = A[0].size();
    // no connected to border -> capture
    vis.clear();    // aaaaaaaaannnnnnnnnnnnnnnnnnn
    vis.resize(n, vector<int> (m,0));
    
    for(int i=0; i<n; i++){
        if(!vis[i][0] && A[i][0] == 'O'){
            dfs(i, 0, A);
        }
        
        if(!vis[i][m-1] && A[i][m-1] == 'O'){
            dfs(i, m-1, A);
        }
    }
    
    for(int j=0; j<m; j++){
        if(!vis[0][j] && A[0][j] == 'O'){
            dfs(0, j, A);
        }
        
        if(!vis[n-1][j] && A[n-1][j] == 'O'){
            dfs(n-1, j, A);
        }
    }
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(!vis[i][j] && A[i][j] == 'O'){
                A[i][j] = 'X';
            }
        }
    }
}

// 8 7 OOOXXXO XXXOOOO XXOXOXO OXOXOXO XXOXOXX XOOOXXO OXXOXOO OXOOXOX
// OOOXXXO XXXOOOO XXOXOXO OXOXOXO XXOXOXX XOOOXXO OXXOXOO OXOOXOX