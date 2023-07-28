// sensitive edge cases - careful

vector<int> Solution::equal(vector<int> &A) {
    int n=A.size();
    // similar to 4sum problem, with a slight modification
    // first store pair wise sum of the elements in a map, then iterate to find if there exist 
    // another pair with same sum but no common indices
    // no precomputation of map else ek for loop aayega ek sum ke corresponding pairs check krne but O(N2) allowed
    unordered_map<int, pair<int, int>> m;
    vector<int> ans(4, n); 
    for(int i=0; i<n-1; i++){
        for(int j=i+1; j<n; j++){
            int sum = A[i] + A[j];
            // now I need to see the elements in vector corresponding to key sum, but ensure that i,j are 
            // not common to the pair
            // we need to return indices in the form A1 B1 C1 D1 so no sorting, 
            // already sorted from the way we're running the loops and storing in map
            // ans.insert(v); - MLE
            //  A1 < B1, C1 < D1, A1 < C1***, B1 != D1, B1 != C1
            if(m.find(sum) != m.end()){
                vector<int> v(4);
                v[0]=m[sum].first;
                v[1]=m[sum].second;
                v[2]=i;
                v[3]=j;
                if(v[0] != v[2] && v[1] != v[2] && v[0] != v[3] && v[1] != v[3]){
                    if(v[0] < v[2]){
                        if(v < ans) {   // same sized vectors can be compared like this hehe
                            // for(int i=0; i<4; i++){
                            //     cout << v[i] << " ";
                            // }
                            // cout << endl;
                            ans = v;
                        }
                    }
                }
            }
            else m[sum] = {i, j};    
        }
    }
    if(ans[0]==n) return {};
    return ans;
}