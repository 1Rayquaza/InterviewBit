int Solution::knight(int n, int m, int currR, int currC, int endR, int endC) {
    currR--, currC--, endR--, endC--;
    
    vector<vector<int>> dist(n, vector<int> (m, 0));
    vector<vector<int>> vis(n, vector<int> (m, 0));
    vis[currR][currC] = 1;
    
    queue<pair<int, int>> q;
    q.push({currR, currC});
    
    int delRow[] = {-1, -1, 1, 1, -2, -2, 2, 2};
    int delCol[] = {-2, 2, -2, 2, -1, 1, -1, 1};
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it.first;
        int col = it.second;
        
        if(row == endR && col == endC) return dist[endR][endC];
        
        for(int i=0; i<8; i++){
            int nrow = row + delRow[i];
            int ncol = col + delCol[i];
            
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol]){
                dist[nrow][ncol] = 1 + dist[row][col];
                q.push({nrow, ncol});
                vis[nrow][ncol] = 1;    // bfs se apne aap shortest d mei pahunchenge jahan bhi pahunchenge
            }
        }
    }
    
    return -1;
}
