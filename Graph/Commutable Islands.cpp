#define pi pair<int, int>

int Solution::solve(int A, vector<vector<int> > &B) {
    // read q. carefully ! - MINIMUM SPANNING TREE - Prim's Algorithm
    vector<pair<int, int>> adj[A+1];
    for(auto it: B){
        int u = it[0];
        int v = it[1];
        int w = it[2];
        
        adj[u].push_back({v, w});
        adj[v].push_back({u, w});
    }

    priority_queue<pi, vector<pi>, greater<pi>> pq;
    pq.push({0, 1});    // ({wt, node}) kahin se bhi shuru kr skte
    
    vector<int> vis(A+1, 0);
    int minCost = 0;
    
    // traversing in priority_queue ensures greedy logic for min. cost - GREEDY !
    while(!pq.empty()){
        auto it = pq.top();
        pq.pop();
        int node = it.second;
        int cost = it.first;
        
        if(vis[node] == 1) continue;    // no need to visit a visited bridge again, min cost !!
        vis[node] = 1;
        minCost += cost;
        
        for(auto x: adj[node]){
            int adjNode = x.first;
            int edW = x.second;
            
            if(!vis[adjNode]){
                pq.push({edW, adjNode});
            }
        } 
    }
    
    return minCost;
}

// If I need to find the associated edges too, initialise pq with ppi {wt, {node, parent node}}
// push_back in MST along with marking visited