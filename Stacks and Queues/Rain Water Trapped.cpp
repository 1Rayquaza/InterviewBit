int Solution::trap(const vector<int> &A){
    int n=A.size();
    // we don't need nearer Greater but rather greatest in the neighbourhood
    vector<int> L(n);
    L[0]=A[0];
    for(int i=0; i<n; i++){
        L[i] = max(L[i-1], A[i]);
    }
    
    vector<int> R(n);
    R[n-1]=A[n-1];
    for(int i=n-2; i>=0; i--){
        R[i] = max(R[i+1], A[i]);
    }
    
    int water=0;
    for(int i=0; i<n; i++){
        int h = min(L[i], R[i]) - A[i];
        if(h>0){
            water += h;
        }
    }
    return water;
}

// /* from eg. given we can clearly see that we need Greater elements to contain water so 
// we need to find the NGL & NGR, min. of which would be considered 
// Then, for water trapped we'll do: (min(NGL, NGR) - A[i])*1 */
