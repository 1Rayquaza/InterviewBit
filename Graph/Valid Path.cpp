bool check(int r, int c, vector<int> &X, vector<int> &Y, int R){
    int n = X.size();
    for(int i=0; i<n; i++){
        if( ((X[i]-r)*(X[i]-r) + (Y[i]-c)*(Y[i]-c)) <= R*R ){
            return 0;
        }
    }
    
    return 1;
}

string Solution::solve(int x, int y, int n, int r, vector<int> &X, vector<int> &Y) {
    // Ambuigity regarding given note
    // Don't touch circle boundary, that's all
    // Use distance from centre condn. to check hehe - Simple BFS ezzz
    queue<pair<int, int>> q;
    q.push({0, 0});
    
    vector<vector<int>> vis(x+1, vector<int> (y+1, 0));
    vis[0][0] = 1;
    
    while(!q.empty()){
        auto it = q.front();
        q.pop();
        int row = it.first;
        int col = it.second;
        
        if(row == x && col == y) return "YES";
        
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                int nrow = row + i;
                int ncol = col + j;
                
                if(nrow >=0 && nrow <=x && ncol >= 0 && ncol <= y && !vis[nrow][ncol] && check(nrow, ncol, X, Y, r)){
                    q.push({nrow, ncol});
                    vis[nrow][ncol] = 1;
                }
            }
        }
    }
    
    return "NO";
}
/*
41
67
5
0
5 17 16 12 0 40 
5 52 61 61 25 31 
YES
*/