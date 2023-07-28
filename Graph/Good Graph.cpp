void Union(int p1, int p2, vector<int> &parent, vector<int> &rank){
    if(p1 == 1){
        parent[p2] = p1;
    }
    else{
        parent[p1] = p2;
    }
    // if(rank[p1] < rank[p2]){
    //     parent[p1] = p2;
    // }
    // else if(rank[p1] > rank[p2]){
    //     parent[p2] = p1;
    // }
    // else{
    //     parent[p1] = p2;
    //     rank[p2]++;
    // }
}

int findPar(int node, vector<int> &parent){
    if(parent[node] == node || node == 1){  // modified
        return node;
    }
    else{
        return parent[node] = findPar(parent[node], parent);
    }
}

int Solution::solve(vector<int> &A) {
    int n = A.size();
    
    vector<int> parent(n+1);
    for(int i=1; i<=n; i++){
        parent[i] = i;
    }
    vector<int> rank(n+1, 0);
    
    for(int i=0; i<n; i++){
        int u = i+1;
        int v = A[i];
        
        int p1 = findPar(u, parent);
        int p2 = findPar(v, parent);
        
        if(p1 != p2){
            Union(p1, p2, parent, rank);
        }
    }
    
    int ct = 0;
    int flag = 0;
    for(int i=1; i<=n; i++){
        if(i == parent[i]) ct++;
        if(parent[i] == 1 && i == parent[i]) flag = 1;
    }
    
    if(flag == 0) return ct;
    return ct - 1;
}