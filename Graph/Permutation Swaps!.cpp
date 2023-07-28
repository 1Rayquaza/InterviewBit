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

// bool isCycle(vector<pair<int, int>> &edges, int V, int E){
//     vector<int> parent(V);
//     for(int i=0; i<V; i++){
//         parent[i] = i;
//     }
    
//     vector<int> rank(V, 0);
    
//     for(auto it: edges){
//         int p1 = find(it.first, parent);
//         int p2 = find(it.second, parent);   // ancestral parent
        
//         if(p1 == p2) return 1;  // cycle present 
        
//         else Union(p1, p2, parent, rank);
//     }
// }

int Solution::solve(vector<int> &A, vector<int> &B, vector<vector<int> > &C) {
    // C contains indices which can be swapped, if they are reacheable(share common ancestor!)
    int n = A.size();
    if(A == B) return 1;
     
    // make sets, return 0 if common parent is not present at any moment
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    
    vector<int> rank(n+1, 0);
    
    for(auto it: C){
        int p1 = find(A[it[0]-1], parent);  // 1 based index given h C mei !!
        int p2 = find(A[it[1]-1], parent);   // ancestral parent
        
        if(p1 == p2) continue;  // cycle present 
        
        else Union(p1, p2, parent, rank);
    }
    
    // for(int i=1; i<=n; i++){
    //     cout << parent[i] << " ";
    // }
    
    for(int i=0; i<n; i++){
        if(A[i] != B[i]){
            int p1 = find(A[i], parent);
            int p2 = find(B[i], parent); 
            // cout << i << " " << p1 << " " << p2 << " ";
            if(p1 != p2) return 0;
        }
    }
      
    return 1;  
}
