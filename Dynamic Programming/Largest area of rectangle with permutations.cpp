int maxArea(vector<int> &A){
    int n = A.size();
    
    // NSE LEFT
    vector<int> left(n, -1);
    stack<int> l;
    
    for(int i=0; i<n; i++){
        if(l.empty()){
            left[i] = -1;
        }
        
        else if(!l.empty() && A[l.top()] < A[i]){
            left[i] = l.top();
        }
        
        else if(!l.empty() && A[l.top()] >= A[i]){
            while(!l.empty() && A[l.top()] >= A[i]){
                l.pop();
            }
            if(l.empty()) left[i] = -1;
            else left[i] = l.top();
        }
        
        l.push(i);
    }
    
    // NSE RIGHT
    vector<int> right(A.size(), n);
    stack<int> r;
    
    for(int i=n-1; i>=0; i--){
        if(r.empty()){
            right[i] = n;
        }
        
        else if(!r.empty() && A[r.top()] < A[i]){
            right[i] = r.top();
        }
        
        else if(!r.empty() && A[r.top()] >= A[i]){
            while(!r.empty() && A[r.top()] >= A[i]){
                r.pop();
            }
            if(r.empty()) right[i] = n;
            else right[i] = r.top();
        }
        
        r.push(i);
    }
    
    // I need largest area from both the NSE
    int mx = INT_MIN;
    for(int i=0; i<n; i++){
        int area = A[i]*(right[i]-left[i]-1); //sdfgjhh
        mx = max(mx, area);
    }
    
    return mx;
}

int Solution::solve(vector<vector<int> > &R) {
    int n=R.size();
    int m=R[0].size();
    
    vector<vector<int>> hash = R;
    for(int j=0; j<m; j++){
        for(int i=1; i<n; i++){
            if(R[i][j] == 0){
                hash[i][j] = 0;
            }
            else{
                hash[i][j] = hash[i-1][j] + R[i][j];
            }
        }
    }
    
    // finding max histogram area for each row of hash =  1D in 2D, 1D only :/
    int mx = INT_MIN;
    vector<int> tmp;
    for(int i=0; i<n; i++){
        sort(hash[i].begin(), hash[i].end());
        int area = maxArea(hash[i]);
        mx = max(mx, area);
    }
    
    return mx;
}
