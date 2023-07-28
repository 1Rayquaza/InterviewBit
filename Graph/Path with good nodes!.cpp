void dfs(int node, int C, vector<int> adj[], vector<int> &vis, vector<int> &A, int &ct){
    vis[node] = 1;
    
    if(A[node-1] == 1) C--; // 0-based A but 1-based nodes
    
    // == 1 implies leaf node so check C here
    if(adj[node].size() == 1){ // till leaf node we should've had atmost C good goods i.e. C >= remains
        if(C >= 0) ct++;
        return;
    }
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, C, adj, vis, A, ct);
        }
    }
}

int Solution::solve(vector<int> &A, vector<vector<int> > &B, int C) {
    int N = A.size();
    // A contains nodes, 0-based indexing !!
    
    vector<int> adj[N+1];
    for(auto it: B){
        int u = it[0];
        int v = it[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> vis(N+1, 0);
    int ct = 0;
    
    dfs(1, C, adj, vis, A, ct);
    return ct;