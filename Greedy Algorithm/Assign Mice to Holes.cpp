int Solution::mice(vector<int> &A, vector<int> &B) {
    int n = A.size();
    sort(A.begin(), A.end());
    sort(B.begin(), B.end());
    
    int mn = INT_MIN;
    for(int i=0; i<n; i++){
        int d = abs(A[i]-B[i]);
        mn = max(mn, d);
    }
    
    // time when the last mouse gets inside a hole is minimized
    // we need to ensure that maximum time is minimised, our greedy selection appoining mice the nearest 
    // location ensures that
    return mn;
}
