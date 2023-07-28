vector<int> vis;

void dfs(int node, vector<int> adj[]){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        
        if(!vis[it]){
            dfs(it, adj);
        }
    }
}

int Solution::solve(int A, vector<vector<int> > &B) {
    vector<int> adj[A+1];   // 1-based indexing so- A+1
    
    vis.clear();
    vis.resize(A+1, 0);
    
    for(int i=0; i<B.size(); i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        // adj[v].push_back(u);     DIRECTED GRAPH !!  
    }
    
    dfs(1, adj);
    return vis[A];
    // path from 1-A so- for i=1, traverse, if node = A, then yes else meh
}
