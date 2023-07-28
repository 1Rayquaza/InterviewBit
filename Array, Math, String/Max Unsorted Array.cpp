vector<int> Solution::subUnsort(vector<int> &A) {
    int n = A.size();
    
    int l=-1, r=-1;
    for(int i=0; i<n-1; i++){
        if(A[i] > A[i+1]){
            l = i;
            break;
        }
    }
    
    for(int i=n-1; i>0; i--){
        if(A[i] < A[i-1]){
            r = i;
            break;
        }
    }
    
    vector<int> ans;
    if(l == -1 && r == -1){
        ans.push_back(-1);
        return ans;
    } 
    
    int mn = INT_MAX, mx = INT_MIN;
    for(int i=l; i<=r; i++){
        mn = min(mn, A[i]);
        mx = max(mx, A[i]);
    }
    
    for(int i=0; i<l; i++){
        if(A[i] > mn){
            l = i;
            break;  // ***
        }
    }
    
    for(int i=n-1; i>r; i--){
        if(A[i] < mx){
            r = i;
            break;  // ***
        }
    }
    
    if(l == r){
        ans.push_back(l);
        return ans;
    }
    else{
        ans.push_back(l);
        ans.push_back(r);
        return ans;
    }
}
