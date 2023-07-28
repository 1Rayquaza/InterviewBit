int Solution::solve(vector<int> &A, int B) {
    /* bitonic sequence: first strictly increasing then after a point strictly decreasing
    Predicate fn., have to find the last T before F (peak)  /\  Need to do this in O(logN) */
    int n=A.size();
    int lo=0, hi=n-1;
    while(hi - lo > 1){
        int mid = (hi+lo)/2;
        if(A[mid] < A[mid+1]){ //inc.
            lo = mid+1;
        }
        else{
            hi = mid;
        }
    }
    
    // Ab inc. and dec. part mei separately Binary Search implement krna hai
    int l=0, h=lo;
    //cout << A[lo] << " " <<endl;
    while(h - l > 1){
        int mid=(l+h)/2;
        if(A[mid]<B){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(A[l]==B) return l;
    else if(A[h]==B) return h;
    
    l=lo+1;
    h=n-1;
    // dec. slope, diff. pointer update values
    while(h - l > 1){
        int mid=(l+h)/2;
        if(A[mid]>B){
            l=mid+1;
        }
        else{
            h=mid;
        }
    }
    if(A[l]==B) return l;
    else if(A[h]==B) return h;
    
    return -1;
}
