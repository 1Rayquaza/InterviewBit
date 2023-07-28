// TC: O(V+E)+O(V)
// SC: O(N) + O(N)`for vis and pathVis
vector<int> vis;

bool dfs(int node, vector<int> adj[], int pathVis[]) {
    vis[node] = 1;
    pathVis[node] = 1;

    // traverse for adjacent nodes
    for (auto it : adj[node]) {
        
        // when the node is not visited
        if (!vis[it]) {
            if (dfs(it, adj, pathVis) == true)
                return true;
        }
        
        // if the node has been previously visited but it has to be visited on the same path
        else if (pathVis[it]) {
            return true;
        }
    }

    pathVis[node] = 0;
    return false;
}


int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];   // 1-based indexing so- A+1
    
    vis.clear();
    vis.resize(A+1, 0);
    
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        // adj[v].push_back(u);     DIRECTED GRAPH 
    }
    
    bool ans;
    
    // The graph may or may not be connected i.e. multiple components possible therefore,
    int pathVis[A] = {0};
    for (int i=1; i<=A; i++) {
        if (!vis[i]) {
            if (dfs(i, adj, pathVis) == true) return true;
        }
    }
    return false;