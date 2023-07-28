int sum(vector<int> v, int target){
    for(int i=1; i<v.size(); i++){
        v[i] += v[i-1];
    }
    
    unordered_map<int, int> m;
    int ans = 0;
    
    for(int i=0; i<v.size(); i++){
        if(v[i] == target){
            ans++;
        }
        if(m.find(v[i]-target) != m.end()){
            ans += m[v[i]-target];
        }
        
        m[v[i]]++;
    }
    
    return ans;
}

int Solution::solve(vector<vector<int> > &A) {
    if(A.empty()) return 0;
    int n = A.size();
    int m = A[0].size();
    
    int res = 0;
    vector<int> tmp(m, 0);
    
    for(int base=n-1; base>=0; base--){
        tmp.clear();
        tmp.resize(m, 0);
        for(int h=base; h>=0; h--){
            for(int c=0; c<m; c++){
                tmp[c] += A[h][c];
            }
            res += sum(tmp, 0);
        }
    }
    return res;
}

// TC: O(r2(c+c)) = O(r2c)
// SC: O(m+m) = O(m)
