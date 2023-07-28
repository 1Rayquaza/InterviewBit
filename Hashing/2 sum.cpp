vector<int> Solution::twoSum(const vector<int> &A, int B) {
    int n=A.size();
    // find the diff no. in map, if found nicey but how to see for the constraits i.e.
    // we need to find s.t. idx2 is min. and if that same then idx is min.
    unordered_map<int, int> m;    // no. and it's index
    int idx1 = -1;
    int idx2 = -1;
    for(int i=0; i<n; i++){
        int temp = B-A[i];
        if(m[temp]){
            if(idx1 == -1){
                idx1 = min(i+1, m[temp]);
                idx2 = max(i+1, m[temp]);
            }
            
            int i1 = min(i+1, m[temp]);
            int i2 = max(i+1, m[temp]);
            if((i2 < idx2) || (i2 == idx2 && i1 < idx1)){
                idx2 = i2;
                idx1 = i1;
            }
        }
        
        if(m[A[i]] == 0) m[A[i]] = i+1;    
        // since index will become higher so we only need to store the min. index for a number's occurance
    }
    
    vector<int> ans;
    if(idx1 != -1){
        ans.push_back(idx1);
        ans.push_back(idx2);
    }
    return ans;
}
