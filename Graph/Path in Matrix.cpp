int Solution::checkPath(vector<vector<int> > &A) {
    int n = A.size();
        
    pair<int, int> src, des;
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            if(A[i][j] == 1) src = {i,j};
            if(A[i][j] == 2) des = {i,j};
        }
    } 
    
    //int vis[n] = {0};, same does not work for 2D
    vector<vector<int>> vis(n, vector<int> (n, 0));
    queue<pair<int, int>> q;    // O(N^2)
    q.push(src);
    
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};
    
    while(!q.empty()){
        pair<int, int> p = q.front();
        int row = p.first;
        int col = p.second;
        vis[row][col] = 1;
        q.pop();
        
        if(p == des) return 1;
        
        for(int i=0; i<4; i++){
            int nrow = row + delrow[i];
            int ncol = col + delcol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < n && !vis[nrow][ncol] && A[nrow][ncol] != 0){
                vis[nrow][ncol] = 1;    
                // removed TLE, 'cause repeatation removed as q mei pushed that but no track of vis
                q.push({nrow, ncol});
            }
        }
    }    
    return 0;
}

// TC: O(V + E)
// SC: O(N^2)
