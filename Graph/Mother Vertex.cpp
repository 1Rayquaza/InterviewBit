int delrow[] = {-1, 0, +1, 0};
int delcol[] = {0, -1, 0, +1};

void dfs(int node, vector<int> adj[], vector<int> &vis){
    vis[node] = 1;
    
    for(auto it: adj[node]){
        if(!vis[it]){
            dfs(it, adj, vis);
        }
    }
}

int Solution::motherVertex(int A, vector<vector<int> > &B) {
    int n = B.size();

    vector<int> adj[A+1];
    for(int i=0; i<n; i++){
        int u = B[i][0];
        int v = B[i][1];
        adj[u].push_back(v);
    }
    
    vector<int> vis(A+1, 0);
    
    // Mother vertex is thr last value visited, 'cause -
    // If a value is visited earlier, it means aage kuch unvisited values bhi hain so mother can not reach
    // all and hence, not a mother vertex
    int mother;
    for(int i=1; i<=A; i++){
        if(!vis[i]){
            dfs(i, adj, vis);
            mother = i;
        }
    }
    
    for(int i=1; i<=A; i++) vis[i] = 0;
    dfs(mother, adj, vis);
    for(int i=1; i<=A; i++){
        if(!vis[i]) return 0;
    }
    
    return 1;
}