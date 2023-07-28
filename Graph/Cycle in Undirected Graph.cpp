// TC: O(N + 2E) + O(N)
// SC: O(N) + O(N)

// vector<int> vis;

// bool dfs(int node, int parent, vector<int> adj[]) {
//     vis[node] = 1; 
    
//     // now visit adjacent nodes
//     for(auto adjacentNode: adj[node]) {
//         // unvisited adjacent node
//         if(!vis[adjacentNode]) {
//             if(dfs(adjacentNode, node, adj) == true) 
//                 return true; 
//         }
//         // visited node but not a parent node
//         else if(adjacentNode != parent) return true; 
//     }
//     return false; 
// }


void Union(int p1, int p2, vector<int> &parent, vector<int> &rank){
    if(rank[p1] < rank[p2]){
        parent[p1] = p2;
    }
    else if(rank[p1] > rank[p2]){
        parent[p2] = p1;
    }
    else{
        parent[p1] = p2;
        rank[p2]++;
    }
}

int find(int node, vector<int> &parent){
    if(parent[node] == node){
        return node;
    }
    else{
        return parent[node] = find(parent[node], parent);
    }
}

bool isCycle(vector<vector<int>> &edges, int V){
    vector<int> parent(V+1);
    for(int i=1; i<=V; i++){
        parent[i] = i;
    }
    
    vector<int> rank(V+1, 0);
    
    for(auto it: edges){
        int p1 = find(it[0], parent);
        int p2 = find(it[1], parent);   // ancestral parent
        
        if(p1 == p2) return 1;  // cycle present 
        
        else Union(p1, p2, parent, rank);
    }
    
    return 0;
}

int Solution::solve(int A, vector<vector<int> > &B) {
    // if(A<3) return 0;
    return isCycle(B, A);
    // vector<int> adj[A+1];   // 1-based indexing so- A+1
    
    // vis.clear();
    // vis.resize(A+1, 0);
    
    // for(int i=0; i<B.size(); i++){
    //     int u = B[i][0];
    //     int v = B[i][1];
        
    //     adj[u].push_back(v);
    //     adj[v].push_back(u);  
    // }
    
    // bool ans;
    // // The graph may or may not be connected i.e. multiple components possible therefore,
    // for(int i=1; i<=A; i++){
    //     if(!vis[i]){
    //         if(dfs(i, -1, adj) == true) return true;
    //     }
    // }
    // return false;
}
