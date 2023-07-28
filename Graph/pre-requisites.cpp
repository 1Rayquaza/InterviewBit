int Solution::solve(int A, vector<int> &B, vector<int> &C) {
    int n = B.size();
    vector<int> adj[A+1];   // 1-based
    for(int i=0; i<n; i++){
        adj[B[i]].push_back(C[i]);
    }
    
    // Topo sort - Directed Acyclic Graph
    // Linear ordering s.t. u->v : u will be written before v : similar to situation here
    
    int inDegree[A+1] = {0};
    for(int i=1; i<=A; i++){
        for(auto it: adj[i]){
            inDegree[it]++;
        }
    }   
    
    queue<int> q;
    for(int i=1; i<=A; i++){
        if(inDegree[i] == 0){
            q.push(i);
        }
    }
    
    // vector<int> topo;
    int ct = 0;
    while(!q.empty()){
        int node = q.front();
        q.pop();
        ct++;
        // topo.push_back(node);
        
        for(auto it: adj[node]){
            inDegree[it]--;
            if(inDegree[it] == 0) q.push(it);
        }
    }
    
    return (ct == A);
}

// TC: O(V+E) simple bfs
// SC: O(3N)