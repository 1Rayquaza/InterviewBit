bool dfs(int node, int col, vector<int> adj[], vector<int> &color){
    color[node] = col;
    
    for(auto it: adj[node]){
        if(color[it] == -1){
            if(dfs(it, !col, adj, color) == false) return false;
        }
        
        else if(color[it] == color[node]){
            return false;
        }
    }
    
    return true;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // Bipartite graph !!
    int n = B.size();
    int m = B[0].size();
    
    // B[i][0] and B[i][1] both are enemies of each other
    // enemies should be joined by edges - diff. colors !
    
    vector<int> adj[A+1];
    for(auto it: B){
        int u = it[0];
        int v = it[1];
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    vector<int> color(A+1, -1); // visited array
    
    for(int i=1; i<=A; i++){
        if(color[i] == -1){
            if(dfs(i, 0, adj, color) == false){
                return false;
            }
        }
    }
	    
	return true;
}
