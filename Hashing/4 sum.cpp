vector<vector<int> > Solution::fourSum(vector<int> &A, int B) {
    int n = A.size();
    sort(A.begin(), A.end());
    
    // pair wise sum array
    unordered_map<int, vector<pair<int, int>>> m;
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum = A[i]+A[j];
            m[sum].push_back({i, j}); 
        }
    }
    
    set<vector<int>> ans; // to avoid duplicates
    for(int i=0; i<n-3; i++){
        for(int j=i+1; j<n-2; j++){
            int sum = B - (A[i] + A[j]);
            // now I need to see the elements in vector corresponding to key sum, but ensure that i,j are 
            // not common to the pair
            if(!m[sum].empty()){
                int nn = m[sum].size();
                vector<int> v(4);
                for(int k=0; k<nn; k++){
                    if(m[sum][k].first != i && m[sum][k].second != i && m[sum][k].first != j && m[sum][k].second != j){
                        v[0]=A[i];
                        v[1]=A[j];
                        v[2]=A[(m[sum][k].first)];
                        v[3]=A[(m[sum][k].second)];
                        sort(v.begin(), v.end());
                        ans.insert(v);
                    }
                }
            }
        }
    }
    
    vector<vector<int>> final(ans.begin(), ans.end());  // copying set to vector
    return final;
}
