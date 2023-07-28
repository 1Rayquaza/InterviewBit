#define ppi pair<int, pair<int, int>> 

int Solution::solve(int A, int B, vector<string> &C) {
    // no vis, since we can visit a node multiple times
    priority_queue<ppi, vector<ppi>, greater<ppi>> pq;
    pq.push({0, {0, 0}});
    
    int delrow[] = {-1, 0, +1, 0};
    int delcol[] = {0, -1, 0, +1};
    
    vector<vector<int>> dist(A, vector<int> (B, INT_MAX));
    dist[0][0] = 0;
    
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        
        int cost = it.first;
        int r = it.second.first;
        int c = it.second.second;
        
        int dir;
        if(C[r][c] == 'U') dir = 0;
        if(C[r][c] == 'L') dir = 1;
        if(C[r][c] == 'D') dir = 2;
        if(C[r][c] == 'R') dir = 3;
        
        for(int i=0; i<4; i++){
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            
            if(nrow >= 0 && nrow < A && ncol >= 0 && ncol < B){
                if(i == dir){
                    if(cost < dist[nrow][ncol]){
                        dist[nrow][ncol] = cost;
                        pq.push({cost, {nrow, ncol}});
                    }
                }
                
                else{
                    if(cost + 1 < dist[nrow][ncol]){
                        dist[nrow][ncol] = cost + 1;
                        pq.push({cost + 1, {nrow, ncol}});
                    }
                }
            }
        } 
    }   
    
    if(dist[A-1][B-1] == INT_MAX) return -1;
    return dist[A-1][B-1];
}
