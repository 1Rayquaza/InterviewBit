void dfs(int node, vector<int> adj[], int vis[]){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int Solution::breakRecords(int A, vector<vector<int> > &B) {    
    int n = B.size();
    int m = B[0].size();
    
    vector<int> adj[A+1];
    
    for(int i=0; i<n; i++){
        int u = B[i][0];
        int v = B[i][1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    int vis[A+1] = {0};
    int ct = 0;
    for(int i=1; i<=A; i++){
        if(!vis[i]){
            ct++;
            dfs(i, adj, vis);
        }
    }
    // TC: O(V + 2E) : 2E only once 'cause ensured by vis array
    // SC: O(N + )
    
    return ct;
}