#define pp pair<int, int>

int Solution::solve(int V, vector<vector<int> > &edges, int start, int end, vector<vector<int> > &E) {
    // Floyd Warshall Algorithm - find shortest distances b/w every nodes then update from E, if any
    // but why N3 when only 2 nodes distance array is reqd. :/
    // 2 times dijkstra !
    
    vector<pp> adj[V];
    for(auto it: edges){
        int u = it[0]-1;    // made it 0-based indexing node
        int v = it[1]-1;
        int wt = it[2];
        
        adj[u].push_back({v, wt});
        adj[v].push_back({u, wt});
    }
    
    start--; end--; // 0-based !
    
    vector<int> distS(V, INT_MAX);
    vector<int> distE(V, INT_MAX);
    distS[start] = 0, distE[end] = 0;
    
    priority_queue<pp, vector<pp>, greater<pp>> pqs, pqe;
    pqs.push({0, start});
    pqe.push({0, end});
    
    while(!pqs.empty()){
        auto it = pqs.top();
        pqs.pop();
        int wt = it.first;
        int node = it.second;
        
        for(auto it: adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            
            if(wt + edW < distS[adjNode]){
                distS[adjNode] = wt + edW;
                pqs.push({wt + edW, adjNode});
            }
        }
    }
    
    while(!pqe.empty()){
        auto it = pqe.top();
        pqe.pop();
        int wt = it.first;
        int node = it.second;
        
        for(auto it : adj[node]){
            int adjNode = it.first;
            int edW = it.second;
            
            if(wt + edW < distE[adjNode]){
                distE[adjNode] = wt + edW;
                pqe.push({wt + edW, adjNode});
            }
        }
    }
    
    // now we need to iterate over each road and check if it helps in decreasing distance b/w s and e
    int mn = INT_MAX;
    mn = min(distE[start], distS[end]); // distE stores distance of each node from end, distS stores dist from start, so compared dist of start from end and end from start
    
    for(auto it: E){
        int u = it[0] - 1;
        int v = it[1] - 1;  // 0-based !!
        int wt = it[2];
        
        if(distS[u] != INT_MAX && distE[v] != INT_MAX){
            if(distS[u] + distE[v] + wt < mn){
                mn = distS[u] + distE[v] + wt;
            }
        }
        
        if(distS[v] != INT_MAX && distE[u] != INT_MAX){
            if(distS[v] + distE[u] + wt < mn){
                mn = distS[v] + distE[u] + wt;
            }
        }
    }
    
    if(mn == INT_MAX){
        return -1;
    }
    return mn;
}
