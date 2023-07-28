vector<int> Solution::solve(vector<int> &A, vector<int> &B, vector<int> &C) {
    // store count of all integers in the given vectors, whoever count>2, push in ans vector
    // Note: a no. might be present multiple times in an array but to be included in ans, it shmust be 
    // present in other arrays too
    map<int, set<int>> m;   // sorted array return krna h
    for(int i=0; i<A.size(); i++){
        m[A[i]].insert(1);
    }
    for(int i=0; i<B.size(); i++){
        m[B[i]].insert(2);
    }
    for(int i=0; i<C.size(); i++){
        m[C[i]].insert(3);
    }
    
    vector<int> ans;
    for(auto it=m.begin(); it!=m.end(); it++){
        if(it->second.size()>1) {
            ans.push_back(it->first);
        }
    }
    return ans;
}
