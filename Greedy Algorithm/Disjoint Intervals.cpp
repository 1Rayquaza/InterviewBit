bool cmp(vector<int> v1, vector<int> v2){
    return (v1[1] < v2[1]);
}

int Solution::solve(vector<vector<int> > &A) {
    int n = A.size();
    // same as max meetings possible q.
    
    sort(A.begin(), A.end(), cmp);
    int mx = 1;
    int setEnd = A[0][1];
    
    for(int i=1; i<n; i++){
        int s = A[i][0];
        int e = A[i][1];
        
        if(s > setEnd){    // no point in common so no >=
            mx++;
            setEnd = e;
        }
    }
    
    return mx;
}
