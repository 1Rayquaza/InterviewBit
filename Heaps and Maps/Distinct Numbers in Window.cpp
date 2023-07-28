vector<int> Solution::dNums(vector<int> &A, int B) {
    int n=A.size();
    vector<int> ans;
    if(n<B) return ans;
    // sliding window problem, fixed window
    int i=0, j=0;
    unordered_map<int, int> m;
    while(j<n){
        m[A[j]]++;  
        
        if(j-i+1 < B) j++;
        
        else if(j-i+1 == B){
            ans.push_back(m.size());
            m[A[i]]--;
            if(m[A[i]]==0) m.erase(A[i]);
            i++;
            j++;
        }      
    }
    
    return ans;
}
