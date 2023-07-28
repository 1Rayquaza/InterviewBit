int Solution::maxp3(vector<int> &A) {
    int n = A.size();
    sort(A.begin(), A.end());
    // return max(A[0]*A[1]*A[n-1], A[n-1]*A[n-2]*A[n-3]);
    // Let's see the generalized case - 
    int p = 1;
    int ans = INT_MIN;
    int i = n-1, k = 3; // here we need max product for 3 elements
    
    while(k--){
        p *= A[i];  
        A[i] = p; //  ******suffix product array, doing so for easy comparison later
        i--;
    }
    
    ans = max(p, ans);
    k = 3;
    p = 1;
    
    for(int i=0; i<k; i++){
        // replace (n-k+i)th element and keep i, now check
        int r = n-k+1+i;  
        p *= A[i];
        if(r != n){
            ans = max(ans, p * A[r]);   // A[r] stores product of all elements till this index, ez
        }
        else{
            ans = max(ans, p);
        }
    }
    
    return ans;
}