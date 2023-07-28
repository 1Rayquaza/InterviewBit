#define ll long long

int dfs(int node, vector<int> adj[], vector<int> &vis, vector<ll> &subSum, vector<int> &A){
    vis[node] = 1;
    subSum[node] = A[node];
    
    for(auto it: adj[node]){
        if(!vis[it]){
            subSum[node] += dfs(it, adj, vis, subSum, A);
        }
    }
    
    return subSum[node];   // this way, we'll get subtree sum for all nodes
}

int Solution::deleteEdge(vector<int> &A, vector<vector<int> > &B) {
    // braek tree in 2 parts such that their product is max.
    // nodes have weight, not edges
    int n = A.size();
    vector<int> adj[n];
    for(int i=0; i<B.size(); i++){
        int u = B[i][0] - 1;
        int v = B[i][1] - 1;
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // need subtree sum at all nodes !
    vector<ll> subSum(n, 0);
    vector<int> vis(n, 0);
    ll sum = dfs(0, adj, vis, subSum, A);
    
    ll mod = 1e9+7;
    long long ans = -1;
    
    for(int i=1; i<n; i++){
        long long x = subSum[i] ;
        long long y = sum - subSum[i];
        ans = max(ans, x*y);
    }
    
    return ans%mod;
}
