int delrow[] = {-1, 0, 1, 0};
int delcol[] = {0, -1, 0, 1};

void dfs(int row, int col, vector<vector<int>> &A, vector<vector<int>> &vis){
    vis[row][col] = 1;
    int n =  A.size();
    int m = A[0].size();
    
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && A[nrow][ncol] >= A[row][col] 
            && !vis[nrow][ncol]){
            dfs(nrow, ncol, A, vis);
        }
    }
}

int Solution::solve(vector<vector<int> > &A) {
    int n =  A.size();
    int m = A[0].size();
    
    vector<vector<int>> visR(n, vector<int> (m, 0)); 
    vector<vector<int>> visB(n, vector<int> (m, 0));  
    queue<pair<int, int>> q;
    
    for(int i=0; i<n; i++){
        if(!visB[i][0]){    // 1st column, B
            dfs(i, 0, A, visB);
        }
        
        if(!visR[i][m-1]){  // last column, R
            dfs(i, m-1, A, visR);
        }
    }
    
    for(int j=0; j<m; j++){
        if(!visB[0][j]){ // 1st row, B
            dfs(0, j, A, visB);
        }
        
        if(!visR[n-1][j]){
            dfs(n-1, j, A, visR);
        }
    }
    
    int ct=0;
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(visB[i][j] == 1 && visR[i][j] == 1) ct++;
        }
    }
    
    return ct;
}
