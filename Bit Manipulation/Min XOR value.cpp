int Solution::findMinXor(vector<int> &A) {
    sort(A.begin(), A.end());
    
    int n=A.size();
    int mn=A[0]^A[n-1];
    
    for(int i=0; i<n-1; i++){
        mn=min(mn, A[i]^A[i+1]);
    }
    
    return mn;
}
