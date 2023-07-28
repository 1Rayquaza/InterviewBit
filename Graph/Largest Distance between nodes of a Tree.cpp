int ans;

int dfs(int node, int parent, vector<int> adj[]){
    
    int mx1 = 0, mx2 = 0;
    int child = 0;
    
    for(auto it: adj[node]){
        if(it != parent){
            child++;
            int ht = dfs(it, node, adj); // ht: it se leaf node tk max kitna
            
            // mx1 and mx2 will keep getting updated with every iteration and eventually we'll 
            if(mx1 < ht){
                mx2 = mx1;
                mx1 = ht;
            }
            else if(mx2 < ht){
                mx2 = ht;
            }
        }
    }
    
    int tmp = mx1 + mx2;
    if(child >= 2) tmp += 2;
    if(child == 1) tmp += 1;
    
    ans = max(ans, tmp);
    
    if(child == 0){
        return 0;    
    }
    else{
        return 1 + mx1;
    }
}
                                         
// mx1 = 2, mx2 =1, got ht = 3

int Solution::solve(vector<int> &A) {
    ans = 0;
    
    int n = A.size();
    if(n==1) return 0;
    vector<int> adj[n];
    int root;
    for(int i=0; i<n; i++){
        int u = A[i];
        int v = i;
        
        if(u == -1){
            root = i;
            continue;
        }
        
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    // if(!vis[node]) not reqd. since it's a tree
    dfs(root, -1, adj);
    return ans;
}
/* 
        root
        / | \
       /. |  \
      /.      \
               \ 
*/