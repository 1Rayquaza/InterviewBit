vector<vector<vector<int>>> dp;
// Using DP for O(N*M*K)

int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, -1, 0, +1};
    
bool dfs(int row, int col, vector<string> &A, string &B, int idx){
    if(idx == B.size()) return true;
    
    if(dp[row][col][idx] != -1){
        return dp[row][col][idx];
    }
    
    int n = A.size();
    int m = A[0].size();
    
    for(int i=0; i<4; i++){
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        
        if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && A[nrow][ncol] == B[idx]){
            if(dfs(nrow, ncol, A, B, idx + 1)) return dp[nrow][ncol][idx+1] = 1;
            else dp[nrow][ncol][idx+1] = 0;
        }
    }
    
    return dp[row][col][idx] = 0;
}    

int Solution::exist(vector<string> &A, string B) {
    int n = A.size();
    int m = A[0].size();
    int len = B.size();
    // no vis, since we may need to visit a cell again
    
    dp.clear();
    dp.resize(n, vector<vector<int>> (m, vector<int> (len, -1)));
    
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++){
            if(A[i][j] == B[0]){
                // 0th index match hone pr 1 onwards call krdiya
                if(dfs(i, j, A, B, 1) == true) return 1;
            }
        }
    }    
    
    return 0;        
}
